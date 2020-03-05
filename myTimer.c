/*
 * myTimer.c
 *
 *  Created on: 05 March 2020
 *      Author: Youness Bella
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myTimer.h"

// Aliases for the Timers and the preScaler arguments are defined in myTimer.h
void initTimer(unsigned int timer, unsigned int preScaler, unsigned int count)
{
    // For the specified timer and pre-scale value, put the timer in 32-bit periodic mode.
    Timer32_initModule(timer, preScaler, TIMER32_32BIT, TIMER32_PERIODIC_MODE);

    // For the specified timer, pass the count value.
    Timer32_setCount(timer, count);


    // For the specified timer, configure the timer to repeat once it elapses.
    Timer32_startTimer(timer, REPEAT);
}

// You have been given a such a function in the lecture slides.
bool timer0Expired(void)
{
    static uint32_t previousSnap = 0;
    uint32_t currentSnap = Timer32_getValue(TIMER0);
    bool returnValue = (currentSnap > previousSnap);
    previousSnap = currentSnap;
    return returnValue;
}

// This is essentially a copy of the previous function, using a different timer.
// Since we only have two timers, later in the course we will create software timers that use a common time base.
bool timer1Expired(void)
{
    static uint32_t previousSnap = 0;
    uint32_t currentSnap = Timer32_getValue(TIMER1);
    bool returnValue = (currentSnap > previousSnap);
    previousSnap = currentSnap;
    return returnValue;
}
