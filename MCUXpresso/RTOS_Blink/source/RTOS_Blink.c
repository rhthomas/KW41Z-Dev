//---------------------------------------------//
//----- Header includes                   -----//
//---------------------------------------------//

#include "MKW41Z4.h"
#include "Board_LED.h"
#include "FreeRTOS.h"
#include "task.h"

//---------------------------------------------//
//----- Function prototypes               -----//
//---------------------------------------------//

void LEDTask1(void *pvPs);
void LEDTask2(void *pvPs);
TickType_t tDelay_ms(const float ms);

//---------------------------------------------//
//----- Main function                     -----//
//---------------------------------------------//

int main(void) {

	LED_Initialize();

    // Create red LED task.
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

    return 0;
}

//---------------------------------------------//
//----- RTOS tasks                        -----//
//---------------------------------------------//

/**
    \brief Task to toggle red LED every 500ms.
*/
void LEDTask1(void *pvPs)
{
    while (42) {
    	LED_On(3);
    	vTaskDelay( tDelay_ms(500) );
    	LED_Off(3);
    	vTaskDelay( tDelay_ms(500) );
    }
}

/**
    \brief Task to toggle blue LED every 330ms.
*/
void LEDTask2(void *pvPs)
{
    while (42) {
        LED_On(1);
        vTaskDelay( tDelay_ms(330) );
        LED_Off(1);
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
