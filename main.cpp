// PA5
// AHB1
// RCC->RCC_AHB1ENR
// GPIOx_MODER
// GPIOx_ODR

//#include "mbed.h"
#include "stm32f4xx.h"
#include "led.h"
#include "button.h"

void delayMs(int delay);

int main(void)
{
	LED led;
	BTTN button;

	while(1){
        if (button.isPressed()) 
			led.turnOn();
        else
			led.turnOff();

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
