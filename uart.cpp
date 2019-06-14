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

	GPIOA->MODER |= 0x400;	// Write 1 to make PA5 output

	const int led = 1 << 5;

	while(1){
		GPIOA->BSRR = led;      // Bit Set / Reset Register method
		//GPIOA->ODR |= 0x20;	// Output Data Register method 
		printf("Set led high\n");
		delayMs(10);

		GPIOA->BSRR = led << 16; // Upper 16 bits of BSRR are reset, lower 16 are set
		//GPIOA->ODR &= ~0x20;
		printf("Clear led\n");
		delayMs(50);
	}

	return 0;
}

void delayMs(int delay)
{
	volatile int i;
	int ms = 18 * 10e3;

	for (i = 0; i < delay * ms; ++i) {}
}
