# ARM-Cortex Development using Keil IDE

## Flashing

To flash the device:

1. Connect the device.
2. Go to Flash > Configure Flash Tools... > Debug > Use: *J-LINK / J-TRACE Cortex*.

    ![Flash Config](img/flash-config.png)

3. Then to find the device select Settings and the J-LINK connection will discover the device. This handles all the addressing issues allowing you to program the device.

    ![J-LINK](img/j-link.png)

4. Hit ok on all windows until you have returned to your code.
5. Build for target.
6. Load (Agree to any T&C's that might pop up).
7. *You may have to reset the board (press SW1) after flashing to run the code.*

## Installing Packages

Keil comes with a useful package installer to download the required tools on a per-board basis.

1. Open the package installer (![Package Installer Icon](img/pm-icon.png)) from inside Keil.
2. From here you can then install the necessary packages for your board. In the case of this module, we need the FreeRTOS port for the KW41Z from NXP.

    ![Package Installer](img/package-installer.png)

## Creating a New Project

Keil makes it easy to import these downloaded packages when making a new project.

1. Go to Project > New uVision Project...

    ![Choose your device](img/device-select.png)

2. Import the packages you want.

    ![RTE Manager](img/manage-rte.png)

3. You will notice that some of the boxes are yellow, this means the package you want to include requires other packages. In the case of the above screenshot, `FreeRTOS::RTOS:Core` also requires `FreeRTOS::RTOS:Heap` and `Keil::Device:Startup`.

    ![RTE Manager Complete](img/manage-rte-ok.png)

4. Now that all the packages are ok, we can finish creating the project, giving a structure as below.

    ![Project Structure](img/project.png)
