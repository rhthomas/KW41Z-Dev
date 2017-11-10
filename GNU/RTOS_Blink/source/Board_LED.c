#include "Board_LED.h"

#define NUM_LEDS  (4) // Number of available LEDs.
                           /*   rgb_red,   rgb_blue,  rgb_green,        red */
const uint32_t led_pin[]  = {         1,         18,         19,          0};
const uint32_t led_port[] = {PORTC_BASE, PORTA_BASE, PORTA_BASE, PORTB_BASE};
const uint32_t led_gpio[] = {GPIOC_BASE, GPIOA_BASE, GPIOA_BASE, GPIOB_BASE};

void LED_Initialize(void)
{
	uint8_t i;

	SIM->SCGC5 |= (
		(1U << SIM_SCGC5_PORTA_SHIFT) |
		(1U << SIM_SCGC5_PORTB_SHIFT) |
		(1U << SIM_SCGC5_PORTC_SHIFT)
	);

	// Port initialisation.
	for (i = 0; i < NUM_LEDS; i++) {
		((PORT_Type *)led_port[i])->PCR[led_pin[i]] = (1U << 8);
		((PORT_Type *)led_port[i])->ISFR           &= (1U << led_pin[i]);
	}

	// GPIO Initialisation.
	for (i = 0; i < NUM_LEDS; i++) {
	    ((GPIO_Type *)led_gpio[i])->PDOR |=  (1U << led_pin[i]);
	    ((GPIO_Type *)led_gpio[i])->PDDR |=  (1U << led_pin[i]);
	}
}

void LED_On(uint8_t num)
{
	if (num < NUM_LEDS) {
	    ((GPIO_Type *)led_gpio[num])->PCOR  =  (1U << led_pin[num]);
	}
}

void LED_Off(uint8_t num)
{
	if (num < NUM_LEDS) {
	    ((GPIO_Type *)led_gpio[num])->PSOR  =  (1U << led_pin[num]);
	}
}
