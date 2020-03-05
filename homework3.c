#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    unsigned int buttonHistory = MAX_VALUE;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // YOU MUST WRITE timer0expired IN myTimer.c
        if (timer0Expired()) {
            count0++;
        }

        // YOU MUST WRITE timer1expired IN myTimer.c
        if (timer1Expired()) {
            buttonHistory = (buttonHistory << 1) | checkStatus_BoosterpackS1();
        }

        // YOU MUST WRITE THIS FUNCTION BELOW.
        if (fsmBoosterpackButtonS1(buttonHistory)) {
            count1++;
        }
    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{
    switch(count % 8) {
    case 0: // Nothing
        turnOff_LaunchpadLED2Blue();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();
        break;
    case 1: // Red
        turnOff_LaunchpadLED2Blue();
        turnOff_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Red();
        break;
    case 2: // Green
        turnOff_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();
        break;
    case 3: // Red & Green
        turnOff_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Red();
        break;
    case 4: // Blue
        turnOn_LaunchpadLED2Blue();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();
        break;
    case 5: // Red & Blue
        turnOn_LaunchpadLED2Blue();
        turnOff_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Red();
        break;
    case 6: // Green & Blue
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();
        break;
    case 7: // Red & Green & Blue
        turnOn_LaunchpadLED2Blue();
        turnOn_LaunchpadLED2Green();
        turnOn_LaunchpadLED2Red();
        break;
    default:
        turnOff_LaunchpadLED2Blue();
        turnOff_LaunchpadLED2Green();
        turnOff_LaunchpadLED2Red();
    }
}

// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{
    switch(count % 8) {
    case 0: // Nothing
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        break;
    case 1: // Red
        turnOn_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        break;
    case 2: // Green
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        break;
    case 3: // Red & Green
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        break;
    case 4: // Blue
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
        break;
    case 5: // Red & Blue
        turnOn_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
        break;
    case 6: // Green & Blue
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
        break;
    case 7: // Red & Green & Blue
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
        break;
    default:
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
    }
}

// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{
    static bool pressed = false;

    if (!pressed & buttonhistory == 0) {
        pressed = true;
        return true;
    } else if (pressed && buttonhistory == MAX_VALUE) {
        pressed = false;
        return false;
    }
    return false;
}


