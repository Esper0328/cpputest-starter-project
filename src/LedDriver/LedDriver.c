#include "LedDriver.h"

#define BIT(n) (1 << n)

static uint16_t* ledsAdrress;
void LedDriver_Create(uint16_t* address) {
    ledsAdrress = address;
    *ledsAdrress = 0;
}

void LedDriver_TurnOn(int ledNumber) {
    const int ledNo = ledNumber - 1;
    if ((0 <= ledNo) && (ledNo < 16)) {
        *ledsAdrress |= BIT(ledNo);
    }
}

void LedDriver_TurnOff(int ledNumber) {
    const int ledNo = ledNumber - 1;
    if ((0 <= ledNo) && (ledNo < 16)) {
        *ledsAdrress &= ~BIT(ledNo);
    }
}

void LedDriver_Destroy(void) {}

