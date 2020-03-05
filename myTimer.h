/*
 * myTimer.h
 *
 *  Created on: 05 March 2020
 *      Author: Youness Bella
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

#ifndef MYTIMER_H_
#define MYTIMER_H_

void initTimer(unsigned int timer, unsigned int preScaler, unsigned int count);
bool timer0Expired(void);
bool timer1Expired(void);

// These are easy-to-use aliases for the arguments used by the timer configuration and use functions.
#define TIMER0              TIMER32_0_BASE
#define TIMER1              TIMER32_1_BASE
#define TIMER0_PRESCALER    TIMER32_PRESCALER_1
#define TIMER1_PRESCALER    TIMER32_PRESCALER_1
#define ONESHOT             true
#define REPEAT              false

// This is an initial value for use in the TimerExpired functions.
#define MAX_VALUE           0xFFFFFFFF

#define TIMER0_COUNT        3000000
#define TIMER1_COUNT        3000


#endif /* MYTIMER_H_ */
