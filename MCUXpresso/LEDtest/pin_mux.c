/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v3.0
processor: MKW41Z512xxx4
package_id: MKW41Z512VHT4
mcu_data: ksdk2_0
processor_version: 2.0.1
board: FRDM-KW41Z
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

/*FUNCTION**********************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 *END**************************************************************************/
void BOARD_InitBootPins(void) {
    BOARD_InitPins();
}

#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN6_IDX                         6u   /*!< Pin number for pin 6 in a port */
#define PIN7_IDX                         7u   /*!< Pin number for pin 7 in a port */
#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */
#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port */
#define SOPT5_LPUART0RXSRC_LPUART_RX  0x00u   /*!< LPUART0 Receive Data Source Select: LPUART_RX pin */
#define SOPT5_LPUART0TXSRC_LPUART_TX  0x00u   /*!< LPUART0 Transmit Data Source Select: LPUART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '6', peripheral: GPIOA, signal: 'GPIO, 18', pin_signal: TSI0_CH12/PTA18/LLWU_P6/SPI1_SCK/TPM2_CH0, identifier: ''}
  - {pin_num: '7', peripheral: GPIOA, signal: 'GPIO, 19', pin_signal: TSI0_CH13/ADC0_SE5/PTA19/LLWU_P7/SPI1_PCS0/TPM2_CH1, identifier: ''}
  - {pin_num: '37', peripheral: GPIOC, signal: 'GPIO, 1', pin_signal: PTC1/ANT_B/I2C0_SDA/UART0_RTS_b/TPM0_CH2/BLE_RF_ACTIVE}
  - {pin_num: '43', peripheral: LPUART0, signal: TX, pin_signal: TSI0_CH3/PTC7/LLWU_P15/SPI0_PCS2/I2C1_SDA/UART0_TX/TPM2_CH1/BSM_DATA, identifier: ''}
  - {pin_num: '42', peripheral: LPUART0, signal: RX, pin_signal: TSI0_CH2/PTC6/LLWU_P14/XTAL_OUT_EN/I2C1_SCL/UART0_RX/TPM2_CH0/BSM_FRAME, identifier: ''}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN18_IDX, kPORT_MuxAsGpio);         /* PORTA18 (pin 6) is configured as PTA18 */
  PORT_SetPinMux(PORTA, PIN19_IDX, kPORT_MuxAsGpio);         /* PORTA19 (pin 7) is configured as PTA19 */
  PORT_SetPinMux(PORTC, PIN1_IDX, kPORT_MuxAsGpio);          /* PORTC1 (pin 37) is configured as PTC1 */
  PORT_SetPinMux(PORTC, PIN6_IDX, kPORT_MuxAlt4);            /* PORTC6 (pin 42) is configured as UART0_RX */
  PORT_SetPinMux(PORTC, PIN7_IDX, kPORT_MuxAlt4);            /* PORTC7 (pin 43) is configured as UART0_TX */
  SIM->SOPT5 = ((SIM->SOPT5 &
    (~(SIM_SOPT5_LPUART0TXSRC_MASK | SIM_SOPT5_LPUART0RXSRC_MASK))) /* Mask bits to zero which are setting */
      | SIM_SOPT5_LPUART0TXSRC(SOPT5_LPUART0TXSRC_LPUART_TX) /* LPUART0 Transmit Data Source Select: LPUART0_TX pin */
      | SIM_SOPT5_LPUART0RXSRC(SOPT5_LPUART0RXSRC_LPUART_RX) /* LPUART0 Receive Data Source Select: LPUART_RX pin */
    );
}


#define PIN4_IDX                         4u   /*!< Pin number for pin 4 in a port */
#define PIN5_IDX                         5u   /*!< Pin number for pin 5 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitButtons:
- options: {prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '40', peripheral: GPIOC, signal: 'GPIO, 4', pin_signal: TSI0_CH0/PTC4/LLWU_P12/ANT_A/EXTRG_IN/UART0_CTS_b/TPM1_CH0/BSM_DATA, direction: INPUT, slew_rate: slow,
    pull_select: up, pull_enable: enable}
  - {pin_num: '41', peripheral: GPIOC, signal: 'GPIO, 5', pin_signal: TSI0_CH1/PTC5/LLWU_P13/RF_NOT_ALLOWED/LPTMR0_ALT2/UART0_RTS_b/TPM1_CH1/BSM_CLK, direction: INPUT,
    slew_rate: slow, pull_select: up, pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitButtons
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitButtons(void) {
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  const port_pin_config_t portc4_pin40_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTC4 */
  };
  PORT_SetPinConfig(PORTC, PIN4_IDX, &portc4_pin40_config);  /* PORTC4 (pin 40) is configured as PTC4 */
  const port_pin_config_t portc5_pin41_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTC5 */
  };
  PORT_SetPinConfig(PORTC, PIN5_IDX, &portc5_pin41_config);  /* PORTC5 (pin 41) is configured as PTC5 */
}


#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */

#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */

#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */

#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLEDs:
- options: {prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '7', peripheral: GPIOA, signal: 'GPIO, 19', pin_signal: TSI0_CH13/ADC0_SE5/PTA19/LLWU_P7/SPI1_PCS0/TPM2_CH1, direction: OUTPUT, slew_rate: slow, pull_select: down,
    pull_enable: disable}
  - {pin_num: '6', peripheral: GPIOA, signal: 'GPIO, 18', pin_signal: TSI0_CH12/PTA18/LLWU_P6/SPI1_SCK/TPM2_CH0, direction: OUTPUT, slew_rate: slow, pull_select: down,
    pull_enable: disable}
  - {pin_num: '37', peripheral: GPIOC, signal: 'GPIO, 1', pin_signal: PTC1/ANT_B/I2C0_SDA/UART0_RTS_b/TPM0_CH2/BLE_RF_ACTIVE, identifier: LED_RED, direction: OUTPUT,
    slew_rate: slow, drive_strength: low, pull_select: down, pull_enable: disable}
  - {pin_num: '16', peripheral: GPIOB, signal: 'GPIO, 0', pin_signal: PTB0/LLWU_P8/XTAL_OUT_EN/I2C0_SCL/CMP0_OUT/TPM0_CH1/CLKOUT, identifier: LED_COMM, direction: OUTPUT,
    slew_rate: slow, drive_strength: low, pull_select: down, pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitLEDs
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitLEDs(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  const port_pin_config_t porta18_pin6_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTA18 */
  };
  PORT_SetPinConfig(PORTA, PIN18_IDX, &porta18_pin6_config); /* PORTA18 (pin 6) is configured as PTA18 */
  const port_pin_config_t porta19_pin7_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTA19 */
  };
  PORT_SetPinConfig(PORTA, PIN19_IDX, &porta19_pin7_config); /* PORTA19 (pin 7) is configured as PTA19 */
  const port_pin_config_t portb0_pin16_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB0 */
  };
  PORT_SetPinConfig(PORTB, PIN0_IDX, &portb0_pin16_config);  /* PORTB0 (pin 16) is configured as PTB0 */
  const port_pin_config_t portc1_pin37_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTC1 */
  };
  PORT_SetPinConfig(PORTC, PIN1_IDX, &portc1_pin37_config);  /* PORTC1 (pin 37) is configured as PTC1 */
}



#define PIN6_IDX                         6u   /*!< Pin number for pin 6 in a port */

#define PIN7_IDX                         7u   /*!< Pin number for pin 7 in a port */
#define SOPT5_LPUART0ODE_DISABLED     0x00u   /*!< LPUART0 Open Drain Enable: Open drain is disabled on LPUART0. */

#define SOPT5_LPUART0RXSRC_LPUART_RX  0x00u   /*!< LPUART0 Receive Data Source Select: LPUART_RX pin */

#define SOPT5_LPUART0TXSRC_LPUART_TX  0x00u   /*!< LPUART0 Transmit Data Source Select: LPUART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UART:
- options: {prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '43', peripheral: LPUART0, signal: TX, pin_signal: TSI0_CH3/PTC7/LLWU_P15/SPI0_PCS2/I2C1_SDA/UART0_TX/TPM2_CH1/BSM_DATA, direction: OUTPUT, slew_rate: fast,
    open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable}
  - {pin_num: '42', peripheral: LPUART0, signal: RX, pin_signal: TSI0_CH2/PTC6/LLWU_P14/XTAL_OUT_EN/I2C1_SCL/UART0_RX/TPM2_CH0/BSM_FRAME, slew_rate: fast, drive_strength: low,
    pull_select: down, pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UART
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitDEBUG_UART(void) {
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  const port_pin_config_t portc6_pin42_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt4,                                           /* Pin is configured as UART0_RX */
  };
  PORT_SetPinConfig(PORTC, PIN6_IDX, &portc6_pin42_config);  /* PORTC6 (pin 42) is configured as UART0_RX */
  const port_pin_config_t portc7_pin43_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt4,                                           /* Pin is configured as UART0_TX */
  };
  PORT_SetPinConfig(PORTC, PIN7_IDX, &portc7_pin43_config);  /* PORTC7 (pin 43) is configured as UART0_TX */
  SIM->SOPT5 = ((SIM->SOPT5 &
    (~(SIM_SOPT5_LPUART0TXSRC_MASK | SIM_SOPT5_LPUART0RXSRC_MASK | SIM_SOPT5_LPUART0ODE_MASK))) /* Mask bits to zero which are setting */
      | SIM_SOPT5_LPUART0TXSRC(SOPT5_LPUART0TXSRC_LPUART_TX) /* LPUART0 Transmit Data Source Select: LPUART0_TX pin */
      | SIM_SOPT5_LPUART0RXSRC(SOPT5_LPUART0RXSRC_LPUART_RX) /* LPUART0 Receive Data Source Select: LPUART_RX pin */
      | SIM_SOPT5_LPUART0ODE(SOPT5_LPUART0ODE_DISABLED)      /* LPUART0 Open Drain Enable: Open drain is disabled on LPUART0. */
    );
}


#define PIN16_IDX                       16u   /*!< Pin number for pin 16 in a port */
#define PIN17_IDX                       17u   /*!< Pin number for pin 17 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitOSC:
- options: {prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '31', peripheral: RADIO, signal: XTAL, pin_signal: XTAL}
  - {pin_num: '30', peripheral: RADIO, signal: EXTAL, pin_signal: EXTAL}
  - {pin_num: '22', peripheral: RTC, signal: XTAL32K, pin_signal: XTAL32K/PTB17/I2C1_SDA/TPM2_CH1/BSM_CLK, slew_rate: no_init, pull_select: no_init, pull_enable: no_init}
  - {pin_num: '21', peripheral: RTC, signal: EXTAL32K, pin_signal: EXTAL32K/PTB16/I2C1_SCL/TPM2_CH0, slew_rate: no_init, pull_select: no_init, pull_enable: no_init}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitOSC
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitOSC(void) {
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTB, PIN16_IDX, kPORT_PinDisabledOrAnalog); /* PORTB16 (pin 21) is configured as EXTAL32K */
  PORT_SetPinMux(PORTB, PIN17_IDX, kPORT_PinDisabledOrAnalog); /* PORTB17 (pin 22) is configured as XTAL32K */
}



#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitACCEL:
- options: {prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '39', peripheral: I2C1, signal: SDA, pin_signal: TSI0_CH15/PTC3/LLWU_P11/RX_SWITCH/I2C1_SDA/UART0_TX/TPM0_CH1/DTM_TX, slew_rate: slow, drive_strength: low,
    pull_select: down, pull_enable: disable}
  - {pin_num: '38', peripheral: I2C1, signal: CLK, pin_signal: TSI0_CH14/PTC2/LLWU_P10/TX_SWITCH/I2C1_SCL/UART0_RX/CMT_IRO/DTM_RX, slew_rate: slow, drive_strength: low,
    pull_select: down, pull_enable: disable}
  - {pin_num: '37', peripheral: GPIOC, signal: 'GPIO, 1', pin_signal: PTC1/ANT_B/I2C0_SDA/UART0_RTS_b/TPM0_CH2/BLE_RF_ACTIVE, identifier: ACCEL_INT1, direction: INPUT,
    slew_rate: fast, drive_strength: low, pull_select: up, pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitACCEL
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitACCEL(void) {
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  const port_pin_config_t portc1_pin37_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTC1 */
  };
  PORT_SetPinConfig(PORTC, PIN1_IDX, &portc1_pin37_config);  /* PORTC1 (pin 37) is configured as PTC1 */
  const port_pin_config_t portc2_pin38_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt3,                                           /* Pin is configured as I2C1_SCL */
  };
  PORT_SetPinConfig(PORTC, PIN2_IDX, &portc2_pin38_config);  /* PORTC2 (pin 38) is configured as I2C1_SCL */
  const port_pin_config_t portc3_pin39_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt3,                                           /* Pin is configured as I2C1_SDA */
  };
  PORT_SetPinConfig(PORTC, PIN3_IDX, &portc3_pin39_config);  /* PORTC3 (pin 39) is configured as I2C1_SDA */
}



#define PIN16_IDX                       16u   /*!< Pin number for pin 16 in a port */

#define PIN17_IDX                       17u   /*!< Pin number for pin 17 in a port */

#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */

#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitFLASH:
- options: {prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '46', peripheral: SPI0, signal: SOUT, pin_signal: TSI0_CH5/PTC17/LLWU_P1/SPI0_SOUT/I2C1_SCL/UART0_RX/BSM_FRAME/DTM_RX}
  - {pin_num: '47', peripheral: SPI0, signal: SIN, pin_signal: TSI0_CH6/PTC18/LLWU_P2/SPI0_SIN/I2C1_SDA/UART0_TX/BSM_DATA/DTM_TX}
  - {pin_num: '45', peripheral: SPI0, signal: SCK, pin_signal: TSI0_CH4/PTC16/LLWU_P0/SPI0_SCK/I2C0_SDA/UART0_RTS_b/TPM0_CH3, identifier: FLASH_SCK, direction: OUTPUT}
  - {pin_num: '48', peripheral: SPI0, signal: PCS0_SS, pin_signal: TSI0_CH7/PTC19/LLWU_P3/SPI0_PCS0/I2C0_SCL/UART0_CTS_b/BSM_CLK/BLE_RF_ACTIVE, identifier: FLASH_CS,
    direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitFLASH
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitFLASH(void) {
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTC, PIN16_IDX, kPORT_MuxAlt2);           /* PORTC16 (pin 45) is configured as SPI0_SCK */
  PORT_SetPinMux(PORTC, PIN17_IDX, kPORT_MuxAlt2);           /* PORTC17 (pin 46) is configured as SPI0_SOUT */
  PORT_SetPinMux(PORTC, PIN18_IDX, kPORT_MuxAlt2);           /* PORTC18 (pin 47) is configured as SPI0_SIN */
  PORT_SetPinMux(PORTC, PIN19_IDX, kPORT_MuxAlt2);           /* PORTC19 (pin 48) is configured as SPI0_PCS0 */
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitThermistor:
- options: {prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '25', peripheral: ADC0, signal: 'DM, 0', pin_signal: ADC0_DM0/CMP0_IN1}
  - {pin_num: '24', peripheral: ADC0, signal: 'DP, 0', pin_signal: ADC0_DP0/CMP0_IN0, identifier: ADC0_DP_THER}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitThermistor
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitThermistor(void) {
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitBatteryMonitor:
- options: {prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '24', peripheral: ADC0, signal: 'SE, 0', pin_signal: ADC0_DP0/CMP0_IN0, identifier: ADC0_BATT_MON}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitBatteryMonitor
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitBatteryMonitor(void) {
}



#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitInfraLed:
- options: {prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '17', peripheral: CMT, signal: IRO, pin_signal: ADC0_SE1/CMP0_IN5/PTB1/DTM_RX/I2C0_SDA/LPTMR0_ALT1/TPM0_CH2/CMT_IRO, slew_rate: fast, drive_strength: low,
    pull_select: down, pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitInfraLed
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitInfraLed(void) {
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */

  const port_pin_config_t portb1_pin17_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt7,                                           /* Pin is configured as CMT_IRO */
  };
  PORT_SetPinConfig(PORTB, PIN1_IDX, &portb1_pin17_config);  /* PORTB1 (pin 17) is configured as CMT_IRO */
}



#define PIN16_IDX                       16u   /*!< Pin number for pin 16 in a port */

#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitTouch:
- options: {prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '45', peripheral: TSI0, signal: 'CH, 4', pin_signal: TSI0_CH4/PTC16/LLWU_P0/SPI0_SCK/I2C0_SDA/UART0_RTS_b/TPM0_CH3, identifier: TSI_ELECTRODE_1}
  - {pin_num: '48', peripheral: TSI0, signal: 'CH, 7', pin_signal: TSI0_CH7/PTC19/LLWU_P3/SPI0_PCS0/I2C0_SCL/UART0_CTS_b/BSM_CLK/BLE_RF_ACTIVE, identifier: TSI_ELECTRODE_2}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitTouch
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitTouch(void) {
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTC, PIN16_IDX, kPORT_PinDisabledOrAnalog); /* PORTC16 (pin 45) is configured as TSI0_CH4 */
  PORT_SetPinMux(PORTC, PIN19_IDX, kPORT_PinDisabledOrAnalog); /* PORTC19 (pin 48) is configured as TSI0_CH7 */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
