/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1 - P1.1
    GPIO_setAsInputPinWithPullUpResistor(LAUNCHPAD_S1_PORT, LAUNCHPAD_S1_PIN);

    // Launchpad S2- P1.4
    GPIO_setAsInputPinWithPullUpResistor(LAUNCHPAD_S2_PORT, LAUNCHPAD_S2_PIN);

    // Boosterpack S1- P5.1
    GPIO_setAsInputPinWithPullUpResistor(BOOSTERPACK_S1_PORT, BOOSTERPACK_S1_PIN);

    // Boosterpack S2- P3.5
    GPIO_setAsInputPinWithPullUpResistor(BOOSTERPACK_S2_PORT, BOOSTERPACK_S2_PIN);

    // Launchpad LED1 - P1.0
    GPIO_setAsOutputPin(LAUNCHPAD_LED1_PORT, LAUNCHPAD_LED1_PIN);

    // Launchpad LED2 Red - P2.0
    GPIO_setAsOutputPin(LAUNCHPAD_LED2_RED_PORT, LAUNCHPAD_LED2_RED_PIN);

    // Launchpad LED2 Green - P2.1
    GPIO_setAsOutputPin(LAUNCHPAD_LED2_GREEN_PORT, LAUNCHPAD_LED2_GREEN_PIN);

    // Launchpad LED2 Blue - P2.2
    GPIO_setAsOutputPin(LAUNCHPAD_LED2_BLUE_PORT, LAUNCHPAD_LED2_BLUE_PIN);

    // Boosterpack LED Red - P2.6
    GPIO_setAsOutputPin(BOOSTERPACK_LED_RED_PORT, BOOSTERPACK_LED_RED_PIN);

    // Boosterpack LED Green - P2.4
    GPIO_setAsOutputPin(BOOSTERPACK_LED_GREEN_PORT, BOOSTERPACK_LED_GREEN_PIN);

    // Boosterpack LED Blue - P5.6
    GPIO_setAsOutputPin(BOOSTERPACK_LED_BLUE_PORT, BOOSTERPACK_LED_BLUE_PIN);

    // Turn off all LEDs at the start.
    turnOff_LaunchpadLED1();
    turnOff_LaunchpadLED2Red();
    turnOff_LaunchpadLED2Green();
    turnOff_LaunchpadLED2Blue();
    turnOff_BoosterpackLEDRed();
    turnOff_BoosterpackLEDGreen();
    turnOff_BoosterpackLEDBlue();

}

unsigned char checkStatus_LaunchpadS1()
{
    return GPIO_getInputPinValue(LAUNCHPAD_S1_PORT, LAUNCHPAD_S1_PIN);
}

unsigned char checkStatus_LaunchpadS2()
{
    return GPIO_getInputPinValue(LAUNCHPAD_S2_PORT, LAUNCHPAD_S2_PIN);
}

unsigned char checkStatus_BoosterpackS1()
{
    return GPIO_getInputPinValue(BOOSTERPACK_S1_PORT, BOOSTERPACK_S1_PIN);
}

unsigned char checkStatus_BoosterpackS2()
{
    return GPIO_getInputPinValue(BOOSTERPACK_S2_PORT, BOOSTERPACK_S2_PIN);
}

void turnOn_LaunchpadLED1()
{
    GPIO_setOutputHighOnPin(LAUNCHPAD_LED1_PORT, LAUNCHPAD_LED1_PIN);
}

void turnOff_LaunchpadLED1()
{
    GPIO_setOutputLowOnPin(LAUNCHPAD_LED1_PORT, LAUNCHPAD_LED1_PIN);
}

void turnOn_LaunchpadLED2Red()
{
    GPIO_setOutputHighOnPin(LAUNCHPAD_LED2_RED_PORT, LAUNCHPAD_LED2_RED_PIN);
}

void turnOff_LaunchpadLED2Red()
{
    GPIO_setOutputLowOnPin(LAUNCHPAD_LED2_RED_PORT, LAUNCHPAD_LED2_RED_PIN);
}

void turnOn_LaunchpadLED2Green()
{
    GPIO_setOutputHighOnPin(LAUNCHPAD_LED2_GREEN_PORT, LAUNCHPAD_LED2_GREEN_PIN);
}

void turnOff_LaunchpadLED2Green()
{
    GPIO_setOutputLowOnPin(LAUNCHPAD_LED2_GREEN_PORT, LAUNCHPAD_LED2_GREEN_PIN);
}

void turnOn_LaunchpadLED2Blue()
{
    GPIO_setOutputHighOnPin(LAUNCHPAD_LED2_BLUE_PORT, LAUNCHPAD_LED2_BLUE_PIN);
}

void turnOff_LaunchpadLED2Blue()
{
    GPIO_setOutputLowOnPin(LAUNCHPAD_LED2_BLUE_PORT, LAUNCHPAD_LED2_BLUE_PIN);
}

void turnOn_BoosterpackLEDRed()
{
    GPIO_setOutputHighOnPin(BOOSTERPACK_LED_RED_PORT, BOOSTERPACK_LED_RED_PIN);
}

void turnOff_BoosterpackLEDRed()
{
    GPIO_setOutputLowOnPin(BOOSTERPACK_LED_RED_PORT, BOOSTERPACK_LED_RED_PIN);
}

void turnOn_BoosterpackLEDGreen()
{
    GPIO_setOutputHighOnPin(BOOSTERPACK_LED_GREEN_PORT, BOOSTERPACK_LED_GREEN_PIN);
}

void turnOff_BoosterpackLEDGreen()
{
    GPIO_setOutputLowOnPin(BOOSTERPACK_LED_GREEN_PORT, BOOSTERPACK_LED_GREEN_PIN);
}

void turnOn_BoosterpackLEDBlue()
{
    GPIO_setOutputHighOnPin(BOOSTERPACK_LED_BLUE_PORT, BOOSTERPACK_LED_BLUE_PIN);
}

void turnOff_BoosterpackLEDBlue()
{
    GPIO_setOutputLowOnPin(BOOSTERPACK_LED_BLUE_PORT, BOOSTERPACK_LED_BLUE_PIN);
}
