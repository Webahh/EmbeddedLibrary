ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 1M
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 512K
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

/* Define program headers to avoid RWX LOAD segments */
PHDRS
{
  flash PT_LOAD FLAGS(5); /* R=4, X=1 => 5 */
  ram   PT_LOAD FLAGS(6); /* R=4, W=2 => 6 */
}

SECTIONS
{
  .isr_vector :
  {
    KEEP(*(.isr_vector))
  } > FLASH :flash

  .text :
  {
    *(.text*)
    *(.rodata*)
    *(.init)
    *(.fini)
  } > FLASH :flash

  _sidata = LOADADDR(.data);

  .data :
  {
    _sdata = .;
    *(.data*)
    _edata = .;
  } > RAM AT > FLASH :ram

  .bss (NOLOAD) :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } > RAM :ram
}