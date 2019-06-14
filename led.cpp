#include "led.h"

LED::LED(void) {
    RCC->AHB1ENR |= 1;
    GPIOA->MODER |= ledOutputBit;
}

void LED::turnOn(void){
    GPIOA->BSRR = ledSetBit;
}

void LED::turnOff(void){
    GPIOA->BSRR = ledClearBit;
}