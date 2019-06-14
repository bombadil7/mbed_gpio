//#include "mbed.h"

// PA5
// AHB1
// RCC->RCC_AHB1ENR
// GPIOx_MODER
// GPIOx_ODR

#include "stm32f4xx.h"
//#include "mbed.h"

void delayMs(int delay);

int main(void)
{
	RCC->AHB1ENR |= 1;		// enable GPIOA clock
	RCC->AHB1ENR |= 4;		// enable GPIOC clock, which has PC13 pin with button

	GPIOA->MODER |= 0x400;	// Write 1 to make PA5 output, PC13 stays input

	const int led = 1 << 5;
    volatile int button;

	while(1){
        button = GPIOC->IDR & (1 << 13);
        if (!button) 
            GPIOA->BSRR = led;
        else
            GPIOA->BSRR = led << 16;

		delayMs(10);
	}

	return 0;
}

void delayMs(int delay)
{
	volatile int i;
	int ms = 18 * 10e3;

	for (i = 0; i < delay * ms; ++i) {}
}
