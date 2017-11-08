/*
 * Copyright (c) 2016, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    LEDtest.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKW41Z4.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "freertos.h"
#include "task.h"

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

/*
void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 800000; ++i)
    {
        __asm("NOP");
    }
}
*/

void LEDTask1(void *pvPs);
void LEDTask2(void *pvPs);
portTickType tDelay_ms(const float ms);

int main(void) {
    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput, 0,
    };

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
  	/* Init FSL debug console. */
	BOARD_InitDebugConsole();


	GPIO_PinInit(GPIOA, 19, &led_config);
	GPIO_PinInit(GPIOC, 1, &led_config);

	/*
	    while (1)
	    {
	        delay();
	        GPIO_TogglePinsOutput(GPIOA, 1u << 18);
	        delay();
	        GPIO_TogglePinsOutput(GPIOC, 1u << 1);
	    }
	 */
	 xTaskCreate(
	        LEDTask1, // Task function.
	        "LEDTask1", // Task name (for simulations).
	        configMINIMAL_STACK_SIZE, // Size of task stack.
	        (void *)NULL, // Parameter passed to task at startup.
	        (unsigned portBASE_TYPE)tskIDLE_PRIORITY+1, // Priority.
	        (xTaskHandle *)NULL // Pointer to reference of the task.
	    );

	    // Create green LED task.
	    xTaskCreate(
	        LEDTask2, // Task function.
	        "LEDTask2", // Task name (for simulations).
	        configMINIMAL_STACK_SIZE, // Size of task stack.
	        (void *)NULL, // Parameter passed to task at startup.
	        (unsigned portBASE_TYPE)tskIDLE_PRIORITY+1, // Priority.
	        (xTaskHandle *)NULL // Pointer to reference of the task.
	    );

	    // Start OS scheduler.
	    vTaskStartScheduler(); // No return!

}


void LEDTask1(void *pvPs)
{
    while (42) {
        GPIO_TogglePinsOutput(GPIOC, 1u << 1);
    	vTaskDelay( tDelay_ms(500) );
        GPIO_TogglePinsOutput(GPIOC, 1u << 1);
    	vTaskDelay( tDelay_ms(500) );
    }
}

/**
    \brief Task to toggle blue LED every 330ms.
*/
void LEDTask2(void *pvPs)
{
    while (42) {
        GPIO_TogglePinsOutput(GPIOA, 1u << 19);
        vTaskDelay( tDelay_ms(330) );
        GPIO_TogglePinsOutput(GPIOA, 1u << 19);
        vTaskDelay( tDelay_ms(330) );
    }
}

/**
    \brief Convert delay in milliseconds to RTOS ticks.
    \see vTaskDelay()
*/
portTickType tDelay_ms(const float ms)
{
    return (portTickType)(ms / portTICK_PERIOD_MS);
}

