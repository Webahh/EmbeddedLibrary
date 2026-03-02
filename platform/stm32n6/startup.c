#include <stdint.h>

extern int main(void);

extern uint32_t _estack;

/* Provided by linker */
extern uint32_t _sidata; /* start address for the initialization values of .data (in FLASH) */
extern uint32_t _sdata;  /* start address for .data (in RAM) */
extern uint32_t _edata;  /* end address for .data (in RAM) */
extern uint32_t _sbss;   /* start address for .bss (in RAM) */
extern uint32_t _ebss;   /* end address for .bss (in RAM) */

void Reset_Handler(void)
{
    /* Copy .data from FLASH to RAM */
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    /* Zero .bss */
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    (void)main();

    while (1) { }
}

__attribute__((section(".isr_vector")))
const void *vector_table[] =
{
    (void *)&_estack,
    Reset_Handler
};