#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/* PORTC4 (number 40), J1[5]/D4/SW3 */
#define BOARD_SW3_GPIO                                                     GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_SW3_PORT                                                     PORTC   /*!< PORT device name: PORTC */
#define BOARD_SW3_GPIO_PIN                                                    4U   /*!< PORTC pin index: 4 */
#define BOARD_SW3_PIN_NAME                                                  PTC4   /*!< Pin name */
#define BOARD_SW3_LABEL                                           "J1[5]/D4/SW3"   /*!< Label */
#define BOARD_SW3_NAME                                                     "SW3"   /*!< Identifier name */
#define BOARD_SW3_DIRECTION                              kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTC5 (number 41), J3[1]/SW4 */
#define BOARD_SW4_GPIO                                                     GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_SW4_PORT                                                     PORTC   /*!< PORT device name: PORTC */
#define BOARD_SW4_GPIO_PIN                                                    5U   /*!< PORTC pin index: 5 */
#define BOARD_SW4_PIN_NAME                                                  PTC5   /*!< Pin name */
#define BOARD_SW4_LABEL                                              "J3[1]/SW4"   /*!< Label */
#define BOARD_SW4_NAME                                                     "SW4"   /*!< Identifier name */
#define BOARD_SW4_DIRECTION                              kPIN_MUX_DirectionInput   /*!< Direction */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitButtons(void);

/* PORTA19 (number 7), J2[3]/D10/RGB_GREEN */
#define BOARD_LED_GREEN_GPIO                                               GPIOA   /*!< GPIO device name: GPIOA */
#define BOARD_LED_GREEN_PORT                                               PORTA   /*!< PORT device name: PORTA */
#define BOARD_LED_GREEN_GPIO_PIN                                             19U   /*!< PORTA pin index: 19 */
#define BOARD_LED_GREEN_PIN_NAME                                           PTA19   /*!< Pin name */
#define BOARD_LED_GREEN_LABEL                              "J2[3]/D10/RGB_GREEN"   /*!< Label */
#define BOARD_LED_GREEN_NAME                                         "LED_GREEN"   /*!< Identifier name */
#define BOARD_LED_GREEN_DIRECTION                       kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTA18 (number 6), J2[6]/D13/RGB_BLUE */
#define BOARD_LED_BLUE_GPIO                                                GPIOA   /*!< GPIO device name: GPIOA */
#define BOARD_LED_BLUE_PORT                                                PORTA   /*!< PORT device name: PORTA */
#define BOARD_LED_BLUE_GPIO_PIN                                              18U   /*!< PORTA pin index: 18 */
#define BOARD_LED_BLUE_PIN_NAME                                            PTA18   /*!< Pin name */
#define BOARD_LED_BLUE_LABEL                                "J2[6]/D13/RGB_BLUE"   /*!< Label */
#define BOARD_LED_BLUE_NAME                                           "LED_BLUE"   /*!< Identifier name */
#define BOARD_LED_BLUE_DIRECTION                        kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTC1 (number 37), J2[2]/U9[11]/D9/RGB_RED/INT1_COMBO */
#define BOARD_LED_RED_GPIO                                                 GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_LED_RED_PORT                                                 PORTC   /*!< PORT device name: PORTC */
#define BOARD_LED_RED_GPIO_PIN                                                1U   /*!< PORTC pin index: 1 */
#define BOARD_LED_RED_PIN_NAME                                              PTC1   /*!< Pin name */
#define BOARD_LED_RED_LABEL                 "J2[2]/U9[11]/D9/RGB_RED/INT1_COMBO"   /*!< Label */
#define BOARD_LED_RED_NAME                                             "LED_RED"   /*!< Identifier name */
#define BOARD_LED_RED_DIRECTION                         kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTB0 (number 16), LED3 */
#define BOARD_LED_COMM_GPIO                                                GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_LED_COMM_PORT                                                PORTB   /*!< PORT device name: PORTB */
#define BOARD_LED_COMM_GPIO_PIN                                               0U   /*!< PORTB pin index: 0 */
#define BOARD_LED_COMM_PIN_NAME                                             PTB0   /*!< Pin name */
#define BOARD_LED_COMM_LABEL                                              "LED3"   /*!< Label */
#define BOARD_LED_COMM_NAME                                           "LED_COMM"   /*!< Identifier name */
#define BOARD_LED_COMM_DIRECTION                        kPIN_MUX_DirectionOutput   /*!< Direction */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDs(void);

/* PORTC7 (number 43), J1[2]/D1/UART0_TX_TGTMCU */
#define BOARD_DEBUG_UART_TX_PERIPHERAL                                   LPUART0   /*!< Device name: LPUART0 */
#define BOARD_DEBUG_UART_TX_SIGNAL                                            TX   /*!< LPUART0 signal: TX */
#define BOARD_DEBUG_UART_TX_PIN_NAME                                    UART0_TX   /*!< Pin name */
#define BOARD_DEBUG_UART_TX_LABEL                     "J1[2]/D1/UART0_TX_TGTMCU"   /*!< Label */
#define BOARD_DEBUG_UART_TX_NAME                                 "DEBUG_UART_TX"   /*!< Identifier name */
#define BOARD_DEBUG_UART_TX_DIRECTION                   kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTC6 (number 42), J1[1]/D0/UART0_RX_TGTMCU */
#define BOARD_DEBUG_UART_RX_PERIPHERAL                                   LPUART0   /*!< Device name: LPUART0 */
#define BOARD_DEBUG_UART_RX_SIGNAL                                            RX   /*!< LPUART0 signal: RX */
#define BOARD_DEBUG_UART_RX_PIN_NAME                                    UART0_RX   /*!< Pin name */
#define BOARD_DEBUG_UART_RX_LABEL                     "J1[1]/D0/UART0_RX_TGTMCU"   /*!< Label */
#define BOARD_DEBUG_UART_RX_NAME                                 "DEBUG_UART_RX"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UART(void);

/* XTAL (number 31), Y1[1]/XTAL_32M */
#define BOARD_XTAL_PERIPHERAL                                              RADIO   /*!< Device name: RADIO */
#define BOARD_XTAL_SIGNAL                                                   XTAL   /*!< RADIO signal: XTAL */
#define BOARD_XTAL_PIN_NAME                                                 XTAL   /*!< Pin name */
#define BOARD_XTAL_LABEL                                        "Y1[1]/XTAL_32M"   /*!< Label */
#define BOARD_XTAL_NAME                                                   "XTAL"   /*!< Identifier name */

/* EXTAL (number 30), Y1[3]/EXTAL_32M */
#define BOARD_EXTAL_PERIPHERAL                                             RADIO   /*!< Device name: RADIO */
#define BOARD_EXTAL_SIGNAL                                                 EXTAL   /*!< RADIO signal: EXTAL */
#define BOARD_EXTAL_PIN_NAME                                               EXTAL   /*!< Pin name */
#define BOARD_EXTAL_LABEL                                      "Y1[3]/EXTAL_32M"   /*!< Label */
#define BOARD_EXTAL_NAME                                                 "EXTAL"   /*!< Identifier name */

/* PORTB17 (number 22), Y2[1]/XTAL_32K */
#define BOARD_XTAL32K_PERIPHERAL                                             RTC   /*!< Device name: RTC */
#define BOARD_XTAL32K_SIGNAL                                             XTAL32K   /*!< RTC signal: XTAL32K */
#define BOARD_XTAL32K_PIN_NAME                                           XTAL32K   /*!< Pin name */
#define BOARD_XTAL32K_LABEL                                     "Y2[1]/XTAL_32K"   /*!< Label */
#define BOARD_XTAL32K_NAME                                             "XTAL32K"   /*!< Identifier name */

/* PORTB16 (number 21), Y2[2]/EXTAL_32K */
#define BOARD_EXTAL32K_PERIPHERAL                                            RTC   /*!< Device name: RTC */
#define BOARD_EXTAL32K_SIGNAL                                           EXTAL32K   /*!< RTC signal: EXTAL32K */
#define BOARD_EXTAL32K_PIN_NAME                                         EXTAL32K   /*!< Pin name */
#define BOARD_EXTAL32K_LABEL                                   "Y2[2]/EXTAL_32K"   /*!< Label */
#define BOARD_EXTAL32K_NAME                                           "EXTAL32K"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitOSC(void);

/* PORTC3 (number 39), J2[9]/U9[6]/D14/I2C1_SDA */
#define BOARD_ACCEL_SDA_PERIPHERAL                                          I2C1   /*!< Device name: I2C1 */
#define BOARD_ACCEL_SDA_SIGNAL                                               SDA   /*!< I2C1 signal: SDA */
#define BOARD_ACCEL_SDA_PIN_NAME                                        I2C1_SDA   /*!< Pin name */
#define BOARD_ACCEL_SDA_LABEL                         "J2[9]/U9[6]/D14/I2C1_SDA"   /*!< Label */
#define BOARD_ACCEL_SDA_NAME                                         "ACCEL_SDA"   /*!< Identifier name */

/* PORTC2 (number 38), J2[10]/U9[4]/D15/I2C1_SCL */
#define BOARD_ACCEL_SCL_PERIPHERAL                                          I2C1   /*!< Device name: I2C1 */
#define BOARD_ACCEL_SCL_SIGNAL                                               CLK   /*!< I2C1 signal: CLK */
#define BOARD_ACCEL_SCL_PIN_NAME                                        I2C1_SCL   /*!< Pin name */
#define BOARD_ACCEL_SCL_LABEL                        "J2[10]/U9[4]/D15/I2C1_SCL"   /*!< Label */
#define BOARD_ACCEL_SCL_NAME                                         "ACCEL_SCL"   /*!< Identifier name */

/* PORTC1 (number 37), J2[2]/U9[11]/D9/RGB_RED/INT1_COMBO */
#define BOARD_ACCEL_INT1_GPIO                                              GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_ACCEL_INT1_PORT                                              PORTC   /*!< PORT device name: PORTC */
#define BOARD_ACCEL_INT1_GPIO_PIN                                             1U   /*!< PORTC pin index: 1 */
#define BOARD_ACCEL_INT1_PIN_NAME                                           PTC1   /*!< Pin name */
#define BOARD_ACCEL_INT1_LABEL              "J2[2]/U9[11]/D9/RGB_RED/INT1_COMBO"   /*!< Label */
#define BOARD_ACCEL_INT1_NAME                                       "ACCEL_INT1"   /*!< Identifier name */
#define BOARD_ACCEL_INT1_DIRECTION                       kPIN_MUX_DirectionInput   /*!< Direction */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitACCEL(void);

/* PORTC17 (number 46), J1[6]/U4[1]/D5 */
#define BOARD_FLASH_SI_PERIPHERAL                                           SPI0   /*!< Device name: SPI0 */
#define BOARD_FLASH_SI_SIGNAL                                               SOUT   /*!< SPI0 signal: SOUT */
#define BOARD_FLASH_SI_PIN_NAME                                        SPI0_SOUT   /*!< Pin name */
#define BOARD_FLASH_SI_LABEL                                    "J1[6]/U4[1]/D5"   /*!< Label */
#define BOARD_FLASH_SI_NAME                                           "FLASH_SI"   /*!< Identifier name */

/* PORTC18 (number 47), J1[7]/U4[8]/D6 */
#define BOARD_FLASH_SO_PERIPHERAL                                           SPI0   /*!< Device name: SPI0 */
#define BOARD_FLASH_SO_SIGNAL                                                SIN   /*!< SPI0 signal: SIN */
#define BOARD_FLASH_SO_PIN_NAME                                         SPI0_SIN   /*!< Pin name */
#define BOARD_FLASH_SO_LABEL                                    "J1[7]/U4[8]/D6"   /*!< Label */
#define BOARD_FLASH_SO_NAME                                           "FLASH_SO"   /*!< Identifier name */

/* PORTC16 (number 45), J1[4]/U4[2]/D3/SW5 */
#define BOARD_FLASH_SCK_PERIPHERAL                                          SPI0   /*!< Device name: SPI0 */
#define BOARD_FLASH_SCK_SIGNAL                                               SCK   /*!< SPI0 signal: SCK */
#define BOARD_FLASH_SCK_PIN_NAME                                        SPI0_SCK   /*!< Pin name */
#define BOARD_FLASH_SCK_LABEL                               "J1[4]/U4[2]/D3/SW5"   /*!< Label */
#define BOARD_FLASH_SCK_NAME                                         "FLASH_SCK"   /*!< Identifier name */
#define BOARD_FLASH_SCK_DIRECTION                       kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTC19 (number 48), J1[3]/U4[4]/D2/SW2 */
#define BOARD_FLASH_CS_PERIPHERAL                                           SPI0   /*!< Device name: SPI0 */
#define BOARD_FLASH_CS_SIGNAL                                            PCS0_SS   /*!< SPI0 signal: PCS0_SS */
#define BOARD_FLASH_CS_PIN_NAME                                        SPI0_PCS0   /*!< Pin name */
#define BOARD_FLASH_CS_LABEL                                "J1[3]/U4[4]/D2/SW2"   /*!< Label */
#define BOARD_FLASH_CS_NAME                                           "FLASH_CS"   /*!< Identifier name */
#define BOARD_FLASH_CS_DIRECTION                        kPIN_MUX_DirectionOutput   /*!< Direction */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitFLASH(void);

/* ADC0_DM0 (number 25), J4[1]/THER_B */
#define BOARD_ADC0_DM_THER_PERIPHERAL                                       ADC0   /*!< Device name: ADC0 */
#define BOARD_ADC0_DM_THER_SIGNAL                                             DM   /*!< ADC0 signal: DM */
#define BOARD_ADC0_DM_THER_CHANNEL                                             0   /*!< ADC0 DM channel: 0 */
#define BOARD_ADC0_DM_THER_PIN_NAME                                     ADC0_DM0   /*!< Pin name */
#define BOARD_ADC0_DM_THER_LABEL                                  "J4[1]/THER_B"   /*!< Label */
#define BOARD_ADC0_DM_THER_NAME                                   "ADC0_DM_THER"   /*!< Identifier name */

/* ADC0_DP0 (number 24), J4[6]/J35[2]/V_BATT/THER_A/THERMISTOR */
#define BOARD_ADC0_DP_THER_PERIPHERAL                                       ADC0   /*!< Device name: ADC0 */
#define BOARD_ADC0_DP_THER_SIGNAL                                             DP   /*!< ADC0 signal: DP */
#define BOARD_ADC0_DP_THER_CHANNEL                                             0   /*!< ADC0 DP channel: 0 */
#define BOARD_ADC0_DP_THER_PIN_NAME                                     ADC0_DP0   /*!< Pin name */
#define BOARD_ADC0_DP_THER_LABEL         "J4[6]/J35[2]/V_BATT/THER_A/THERMISTOR"   /*!< Label */
#define BOARD_ADC0_DP_THER_NAME                                   "ADC0_DP_THER"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitThermistor(void);

/* ADC0_DP0 (number 24), J4[6]/J35[2]/V_BATT/THER_A/THERMISTOR */
#define BOARD_ADC0_BATT_MON_PERIPHERAL                                      ADC0   /*!< Device name: ADC0 */
#define BOARD_ADC0_BATT_MON_SIGNAL                                            SE   /*!< ADC0 signal: SE */
#define BOARD_ADC0_BATT_MON_CHANNEL                                            0   /*!< ADC0 SE channel: 0 */
#define BOARD_ADC0_BATT_MON_PIN_NAME                                    ADC0_DP0   /*!< Pin name */
#define BOARD_ADC0_BATT_MON_LABEL        "J4[6]/J35[2]/V_BATT/THER_A/THERMISTOR"   /*!< Label */
#define BOARD_ADC0_BATT_MON_NAME                                 "ADC0_BATT_MON"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitBatteryMonitor(void);

/* PORTB1 (number 17), J4[5]/IR_SIG */
#define BOARD_IR_TX_PERIPHERAL                                               CMT   /*!< Device name: CMT */
#define BOARD_IR_TX_SIGNAL                                                   IRO   /*!< CMT signal: IRO */
#define BOARD_IR_TX_PIN_NAME                                             CMT_IRO   /*!< Pin name */
#define BOARD_IR_TX_LABEL                                         "J4[5]/IR_SIG"   /*!< Label */
#define BOARD_IR_TX_NAME                                                 "IR_TX"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitInfraLed(void);

/* PORTC16 (number 45), J1[4]/U4[2]/D3/SW5 */
#define BOARD_TSI_ELECTRODE_1_PERIPHERAL                                    TSI0   /*!< Device name: TSI0 */
#define BOARD_TSI_ELECTRODE_1_SIGNAL                                          CH   /*!< TSI0 signal: CH */
#define BOARD_TSI_ELECTRODE_1_CHANNEL                                          4   /*!< TSI0 channel: 4 */
#define BOARD_TSI_ELECTRODE_1_PIN_NAME                                  TSI0_CH4   /*!< Pin name */
#define BOARD_TSI_ELECTRODE_1_LABEL                         "J1[4]/U4[2]/D3/SW5"   /*!< Label */
#define BOARD_TSI_ELECTRODE_1_NAME                             "TSI_ELECTRODE_1"   /*!< Identifier name */

/* PORTC19 (number 48), J1[3]/U4[4]/D2/SW2 */
#define BOARD_TSI_ELECTRODE_2_PERIPHERAL                                    TSI0   /*!< Device name: TSI0 */
#define BOARD_TSI_ELECTRODE_2_SIGNAL                                          CH   /*!< TSI0 signal: CH */
#define BOARD_TSI_ELECTRODE_2_CHANNEL                                          7   /*!< TSI0 channel: 7 */
#define BOARD_TSI_ELECTRODE_2_PIN_NAME                                  TSI0_CH7   /*!< Pin name */
#define BOARD_TSI_ELECTRODE_2_LABEL                         "J1[3]/U4[4]/D2/SW2"   /*!< Label */
#define BOARD_TSI_ELECTRODE_2_NAME                             "TSI_ELECTRODE_2"   /*!< Identifier name */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitTouch(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
