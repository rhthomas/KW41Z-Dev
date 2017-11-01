# ARM-Cortex Development using ARM GCC Toolchains

The ARM toolchains can be downloaded from [here](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm).

---

## Compiling

Firstly the compilation commands were extracted from MCUXpresso by adding the `--verbose` flag to the makefile settings. Then when building, the commands were copied into a bash script.

Common flags were then grouped together in order to make the commands more easily readable. Any that were not necessary for compilation *(i.e. did not make the compiler return errors)* were then removed from the flags.

```bash
DEFINES="-DDEBUG -DCPU_MKW41Z512VHT4"

INCLUDES="-Isource -I. -ICMSIS -Ifreertos -Istartup -I/Applications/MCUXpressoIDE_10.0.2_411/ide/tools/features/include"

FLAGS="-O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0plus -mthumb"
```

The shortened `gcc` commands were then:

```bash
arm-none-eabi-gcc $DEFINES $INCLUDES $FLAGS -MMD -MP -MF"<file>.d" -MT"<file>.o" -MT"<file>.d" -o "<file>.o" "<file>.c"
```

The `-MMD`, `-MP`, `-MF` and `-MT` flags are all used for generating dependancies for makefiles, and may not be required in this bash script. **This has not yet been tested.**  

---

## Linking

Linking is currently failing since it cannot find the linker scripts required. `cannot open linker script file RTOS_Blink_Debug.ld: No such file or directory`. Nowhere in the MCUXpresso build commands does it make the linker files so I am unsure as to where they're coming from.

---

## Cleaning

Since this is a bash script and not a makefile we need to make our own clean command which removed the generated object and dependancy files.

```bash
find . -name '*.o' -or -name '*.d' | xargs rm
```

This command finds all `.o` and `.d` files in the directory and passes them to the `rm` command, which deletes them.

---

## Debugging
