/*
 * myGPIO.h
 *
 *  Created on: 05 March 2020
 *      Author: Youness Bella
 *
 */

#ifndef MYGPIO_H_
#define MYGPIO_H_

// This function initializes the peripherals used in the program.
void initGPIO();
// This function returns the value of Launchpad S1.
unsigned char checkStatus_LaunchpadS1();
// This function returns the value of Launchpad S2.
unsigned char checkStatus_LaunchpadS2();
// This function returns the value of Boosterpack S1.
unsigned char checkStatus_BoosterpackS1();
// This function returns the value of Boosterpack S2.
unsigned char checkStatus_BoosterpackS2();
// This function turns on Launchpad LED1.
void turnOn_LaunchpadLED1();
// This function turns off Launchpad LED1.
void turnOff_LaunchpadLED1();
// This function turns on Launchpad Red LED2.
void turnOn_LaunchpadLED2Red();
// This function turns off Launchpad Red LED2.
void turnOff_LaunchpadLED2Red();
// This function turns on Launchpad Blue LED2.
void turnOn_LaunchpadLED2Blue();
// This function turns off Launchpad Blue LED2.
void turnOff_LaunchpadLED2Blue();
// This function turns on Launchpad Green LED2.
void turnOn_LaunchpadLED2Green();
// This function turns off Launchpad Green LED2.
void turnOff_LaunchpadLED2Green();
// This function turns on Boosterpack Red LED.
void turnOn_BoosterpackLEDRed();
// This function turns off Boosterpack Red LED.
void turnOff_BoosterpackLEDRed();
// This function turns on Boosterpack Green LED.
void turnOn_BoosterpackLEDGreen();
// This function turns off Boosterpack Green LED.
void turnOff_BoosterpackLEDGreen();
// This function turns on Boosterpack Blue LED.
void turnOn_BoosterpackLEDBlue();
// This function turns off Boosterpack Blue LED.
void turnOff_BoosterpackLEDBlue();

#define LAUNCHPAD_S1_PORT   1
#define LAUNCHPAD_S1_PIN    BIT1

#define LAUNCHPAD_S2_PORT   1
#define LAUNCHPAD_S2_PIN    BIT4

#define BOOSTERPACK_S1_PORT 5
#define BOOSTERPACK_S1_PIN  BIT1

#define BOOSTERPACK_S2_PORT 3
#define BOOSTERPACK_S2_PIN  BIT5

// Launchpad LED1 - P1.0
#define LAUNCHPAD_LED1_PORT 1
#define LAUNCHPAD_LED1_PIN  BIT0

// Launchpad LED2 Red - P2.0
#define LAUNCHPAD_LED2_RED_PORT 2
#define LAUNCHPAD_LED2_RED_PIN  BIT0

// Launchpad LED2 Green - P2.1
#define LAUNCHPAD_LED2_GREEN_PORT   2
#define LAUNCHPAD_LED2_GREEN_PIN    BIT1

// Launchpad LED2 Blue - P2.2
#define LAUNCHPAD_LED2_BLUE_PORT    2
#define LAUNCHPAD_LED2_BLUE_PIN     BIT2

// Boosterpack LED Red - P2.6
#define BOOSTERPACK_LED_RED_PORT    2
#define BOOSTERPACK_LED_RED_PIN     BIT6

// Boosterpack LED Green - P2.4
#define BOOSTERPACK_LED_GREEN_PORT  2
#define BOOSTERPACK_LED_GREEN_PIN   BIT4

// Boosterpack LED Blue - P5.6
#define BOOSTERPACK_LED_BLUE_PORT   5
#define BOOSTERPACK_LED_BLUE_PIN    BIT6

#endif /* MYGPIO_H_ */
