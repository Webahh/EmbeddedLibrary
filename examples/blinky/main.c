#include "stm32n6xx.h"

int main(void)
{
    /* Enable GPIOA clock */
    RCC->AHB4ENR |= RCC_AHB4ENR_GPIOAEN;

    /* Configure PA5 as output */
    GPIOA->MODER &= ~(3 << (5 * 2));
    GPIOA->MODER |=  (1 << (5 * 2));

    while (1)
    {
        GPIOA->ODR ^= (1 << 5);

        for (volatile int i = 0; i < 1000000; i++)
        {
        }
    }
}