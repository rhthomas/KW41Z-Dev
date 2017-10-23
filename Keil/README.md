# ARM-Cortex Development using Keil IDE

## Flashing

To flash the device:

1. Connect the device.
2. Go to Flash > Configure Flash Tools... > Debug > Use: *J_LINK / J-TRACE Cortex*.

    ![Flash Config](flash-config.png)

3. Then to find the device select Settings and the JLINK connection will discover the device. This handles all the addressing issues allowing you to program the device.

    ![j-link](./j-link.png)

4. Hit ok on all windows until you have returned to your code.
5. Build for target.
6. Load (Agree to any T&C's that might pop up).

## Compile Markdown
`pandoc --from markdown --to html --standalone Keil.md --output index.html`
