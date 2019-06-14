#include "button.h"

BTTN::BTTN(void){
    RCC->AHB1ENR |= buttonClockBit;
}

bool BTTN::isPressed(void){
    return (GPIOC->IDR & buttonBit) == 0;
}