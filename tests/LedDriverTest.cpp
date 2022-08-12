#include "CppUTest/TestHarness.h"

extern "C"
{
#include "LedDriver.h"
	/*
	 * Add your c-only include files here
	 */
}

TEST_GROUP(LedDriver)
{
    uint16_t virtualleds;
    void setup()
    {
    LedDriver_Create(&virtualleds);
    }

    void teardown()
    {
    }
};

TEST(LedDriver, LedsOffAfterCreate)
{
    virtualleds = 0xffff;
    LedDriver_Create(&virtualleds);
    LONGS_EQUAL(0, virtualleds);
}

TEST(LedDriver, TurnOnLedOne)
{
    LedDriver_TurnOn(1);
    LONGS_EQUAL(1, virtualleds);
}

TEST(LedDriver, TurnOffLedOne) {
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    LONGS_EQUAL(0, virtualleds);
}

TEST(LedDriver, TurnOnMultipleLeds) {
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    LONGS_EQUAL(0x180, virtualleds);
}

TEST(LedDriver, TurnOffMultipleLeds) {
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    LedDriver_TurnOn(16);
    LedDriver_TurnOff(9);
    LedDriver_TurnOff(16);
    LONGS_EQUAL(0x80, virtualleds);
}


TEST(LedDriver, TurnOnInvalidLeds) {
    LedDriver_TurnOn(0);
    LedDriver_TurnOn(17);
    LedDriver_TurnOn(-1);
    LONGS_EQUAL(0, virtualleds);
}
