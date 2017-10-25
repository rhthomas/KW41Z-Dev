#ifndef BOARD_LED_H_
#define BOARD_LED_H_

#include "MKW41Z4.h"
#include "Board_LED.h"

extern void LED_Initialize (void);
extern void LED_On         (uint8_t num);
extern void LED_Off        (uint8_t num);

#endif /* BOARD_LED_H_ */
