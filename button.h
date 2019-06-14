#ifndef BTTN_H_
#define BTTN_H_
#include "stm32f4xx.h"

class BTTN {

public:
    BTTN(void);
    bool isPressed(void);

private:
    const int buttonClockBit = 1 << 2;
    const int buttonBit = 1 << 13;
};



#endif /* BTTN_H */