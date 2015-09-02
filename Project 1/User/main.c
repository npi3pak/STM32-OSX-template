#include "stm32f4xx.h"
 
int main( void ) {
 
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // clocking
 
    GPIOD->MODER |= 0x1<<(12*2); // pin settings
    GPIOD->OTYPER |= 0x0<<(12);
    GPIOD->OSPEEDR |= 0x2<<(12*2);
    GPIOD->PUPDR |= 0x0<<(12*2);
 
    GPIOD->BSRRL = 0x1<<(12); // enable led
 
    while (1);
}