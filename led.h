#ifndef LED_H_
#define LED_H_
#include "stm32f4xx.h"

class LED {
public:
    LED(void);
    void turnOn(void);
    void turnOff(void);

private:
    const int ledSetBit = 1 << 5;
    const int ledClearBit = ledSetBit << 16;
    const int ledOutputBit = 0x400;
};


#endif /* LED_H */