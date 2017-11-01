# KW41Z-Dev

The idea of this lab exercise is to get experience and realise the pros and cons of different development environments. To demonstrate this, a simple RTOS program will be written, flashed and debugged for the FRDM-KW41Z on three different development environments:

1. ARM Keil
2. NXP MCUXpresso
3. GNU FOSS Toolchain and Makefiles

The directory structure for this repository is as follows:

```
KW41Z-Dev/
├── GNU/
│   └── README.md
├── Keil/
│   └── README.md
├── MCUXpresso/
│   └── README.md
└── README.md
```

---

## Simple RTOS Program

The RTOS program that will be written for the processor will simply toggle two different LEDs with different periods. A red on at 500ms, and a green one at 330ms.

Below is segments of the FreeRTOS functionality **ONLY**, i.e. no development platform specific functions or includes.

### Main Function

The job of the main function is to create the two LED tasks and begin the OS scheduler.

```c
int main(void)
{
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
```

### LED Tasks

The LED tasks are very basic. They consist of a while loop that forever turns on an LED, waits a period of time, then turns off the LED before again waiting. This is not at all efficient code however it is meant to only be a simple example.

```c
void LEDTaskN(void *pvPs)
{
    while (42) {
        // Turn LED on.
        vTaskDelay( tDelay_ms(500) );
        // Turn LED off.
        vTaskDelay( tDelay_ms(500) );
    }
}
```

### Converting RTOS *Ticks* to Seconds

For the `vTaskDelay` function, we cannot simply pass a millisecond wait time, we need to convert this to RTOS processor *ticks* which is done using a small converter function.

```c
portTickType tDelay_ms(const float ms)
{
    return (portTickType)(ms / portTICK_PERIOD_MS);
}
```

---

## Comparison Between Development Platforms

### ARM Keil

#### Pros
+ Easy to use debugging interface.
+ Able to batch build for multiple targets.
+ Well designed and easy to use package manager.

#### Cons
- 32kB code limit.
- Very expensive full version of the software.
- Pulls in files from a variety of locations. Not sure what you're including.

### MCUXpresso

#### Pros
+ Cross-platform IDE.
+ Free.
+ IDEs allow more time writing code rather than wasting time figuring out the toolchains.
+ Easy debugging interface.
+ Familiarity to those who have used Eclipse tools in the past.

#### Cons
- Based on Eclipse so is a fairly heavy editor for embedded platforms.
    - Most of Eclipse isn't even used!

### GNU Toolchains

#### Pros
+ Free.
+ You know exactly what files are being compiled into your project.
    + More control over code size.
    + More control over security.
        + Not pulling in random libraries you didn't write.
+ Lightweight IDEs.
    + Just need a text editor and a terminal.
    + Use whatever text editor you like.
        + Atom
        + Vi/Vim
        + Nano
        + Notepad++

#### Cons
- Makefiles can be very complicated/convoluted.
    - Spend more time debugging makefiles rather than actual code.
- More complicated methods of making linker scripts.
- More time spent setting up the toolchains rather than actually writing functional code for the target.
- GDB in the command line has a steep learning curve.
