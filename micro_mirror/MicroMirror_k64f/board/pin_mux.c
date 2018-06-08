/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v4.0
processor: MK64FN1M0xxx12
package_id: MK64FN1M0VLL12
mcu_data: ksdk2_0
processor_version: 3.0.1
board: FRDM-K64F
pin_labels:
- {pin_num: '71', pin_signal: ADC0_SE15/PTC1/LLWU_P6/SPI0_PCS3/UART1_RTS_b/FTM0_CH0/FB_AD13/I2S0_TXD0, label: 'J1[5]', identifier: FTM0_CH0}
- {pin_num: '76', pin_signal: PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/FTM0_CH3/FB_AD11/CMP1_OUT, label: 'J2[4]', identifier: FTM0_CH3}
- {pin_num: '94', pin_signal: ADC0_SE5b/PTD1/SPI0_SCK/UART2_CTS_b/FTM3_CH1/FB_CS0_b, label: 'J2[12]', identifier: PTD1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '62', peripheral: UART0, signal: RX, pin_signal: PTB16/SPI1_SOUT/UART0_RX/FTM_CLKIN0/FB_AD17/EWM_IN}
  - {pin_num: '63', peripheral: UART0, signal: TX, pin_signal: PTB17/SPI1_SIN/UART0_TX/FTM_CLKIN1/FB_AD16/EWM_OUT_b, direction: OUTPUT}
  - {pin_num: '33', peripheral: GPIOE, signal: 'GPIO, 26', pin_signal: PTE26/ENET_1588_CLKIN/UART4_CTS_b/RTC_CLKOUT/USB_CLKIN, direction: OUTPUT, drive_strength: high}
  - {pin_num: '67', peripheral: GPIOB, signal: 'GPIO, 21', pin_signal: PTB21/SPI2_SCK/FB_AD30/CMP1_OUT, direction: OUTPUT, drive_strength: high}
  - {pin_num: '68', peripheral: GPIOB, signal: 'GPIO, 22', pin_signal: PTB22/SPI2_SOUT/FB_AD29/CMP2_OUT, direction: OUTPUT, drive_strength: high}
  - {pin_num: '94', peripheral: GPIOD, signal: 'GPIO, 1', pin_signal: ADC0_SE5b/PTD1/SPI0_SCK/UART2_CTS_b/FTM3_CH1/FB_CS0_b, direction: INPUT, pull_select: up, pull_enable: enable,
    passive_filter: enable, digital_filter: enable}
  - {pin_num: '38', peripheral: GPIOA, signal: 'GPIO, 4', pin_signal: PTA4/LLWU_P3/FTM0_CH1/NMI_b/EZP_CS_b, direction: INPUT, passive_filter: enable}
  - {pin_num: '55', peripheral: GPIOB, signal: 'GPIO, 2', pin_signal: ADC0_SE12/PTB2/I2C0_SCL/UART0_RTS_b/ENET0_1588_TMR0/FTM0_FLT3, direction: INPUT, pull_select: up,
    pull_enable: enable}
  - {pin_num: '76', peripheral: FTM0, signal: 'CH, 3', pin_signal: PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/FTM0_CH3/FB_AD11/CMP1_OUT, direction: OUTPUT, slew_rate: slow,
    drive_strength: high, pull_select: up, pull_enable: enable}
  - {pin_num: '27', peripheral: DAC0, signal: OUT, pin_signal: DAC0_OUT/CMP1_IN3/ADC0_SE23}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    /* PORTA4 (pin 38) is configured as PTA4 */
    PORT_SetPinMux(BOARD_INITPINS_SW3_PORT, BOARD_INITPINS_SW3_PIN, kPORT_MuxAsGpio);

    PORTA->PCR[4] = ((PORTA->PCR[4] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PFE_MASK | PORT_PCR_ISF_MASK)))

                     /* Passive Filter Enable: Passive input filter is enabled on the corresponding pin, if the
                      * pin is configured as a digital input.                     /* Refer to the device data sheet for filter characteristics. */
                     | PORT_PCR_PFE(kPORT_PassiveFilterEnable));

    /* PORTB16 (pin 62) is configured as UART0_RX */
    PORT_SetPinMux(BOARD_INITPINS_DEBUG_UART_RX_PORT, BOARD_INITPINS_DEBUG_UART_RX_PIN, kPORT_MuxAlt3);

    /* PORTB17 (pin 63) is configured as UART0_TX */
    PORT_SetPinMux(BOARD_INITPINS_DEBUG_UART_TX_PORT, BOARD_INITPINS_DEBUG_UART_TX_PIN, kPORT_MuxAlt3);

    /* PORTB2 (pin 55) is configured as PTB2 */
    PORT_SetPinMux(BOARD_INITPINS_ADC0_SE12_PORT, BOARD_INITPINS_ADC0_SE12_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[2] = ((PORTB->PCR[2] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp));

    /* PORTB21 (pin 67) is configured as PTB21 */
    PORT_SetPinMux(BOARD_INITPINS_LED_BLUE_PORT, BOARD_INITPINS_LED_BLUE_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[21] = ((PORTB->PCR[21] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))

                      /* Drive Strength Enable: High drive strength is configured on the corresponding pin, if pin
                       * is configured as a digital output. */
                      | PORT_PCR_DSE(kPORT_HighDriveStrength));

    /* PORTB22 (pin 68) is configured as PTB22 */
    PORT_SetPinMux(BOARD_INITPINS_LED_RED_PORT, BOARD_INITPINS_LED_RED_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[22] = ((PORTB->PCR[22] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))

                      /* Drive Strength Enable: High drive strength is configured on the corresponding pin, if pin
                       * is configured as a digital output. */
                      | PORT_PCR_DSE(kPORT_HighDriveStrength));

    /* PORTC4 (pin 76) is configured as FTM0_CH3 */
    PORT_SetPinMux(BOARD_INITPINS_FTM0_CH3_PORT, BOARD_INITPINS_FTM0_CH3_PIN, kPORT_MuxAlt4);

    PORTC->PCR[4] =
        ((PORTC->PCR[4] &
          /* Mask bits to zero which are setting */
          (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))

         /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE
          * field is set. */
         | (uint32_t)(kPORT_PullUp)

         /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is configured as a
          * digital output. */
         | PORT_PCR_SRE(kPORT_SlowSlewRate)

         /* Drive Strength Enable: High drive strength is configured on the corresponding pin, if pin is
          * configured as a digital output. */
         | PORT_PCR_DSE(kPORT_HighDriveStrength));
    /* Configure digital filter */
    PORT_EnablePinsDigitalFilter(
        /* Digital filter is configured on port D */
        PORTD,
        /* Digital filter is configured for PORTD0 */
        PORT_DFER_DFE_1_MASK,
        /* Enable digital filter */
        true);

    /* PORTD1 (pin 94) is configured as PTD1 */
    PORT_SetPinMux(BOARD_INITPINS_PTD1_PORT, BOARD_INITPINS_PTD1_PIN, kPORT_MuxAsGpio);

    PORTD->PCR[1] = ((PORTD->PCR[1] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_PFE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | (uint32_t)(kPORT_PullUp)

                     /* Passive Filter Enable: Passive input filter is enabled on the corresponding pin, if the
                      * pin is configured as a digital input.                     /* Refer to the device data sheet for filter characteristics. */
                     | PORT_PCR_PFE(kPORT_PassiveFilterEnable));

    /* PORTE26 (pin 33) is configured as PTE26 */
    PORT_SetPinMux(BOARD_INITPINS_LED_GREEN_PORT, BOARD_INITPINS_LED_GREEN_PIN, kPORT_MuxAsGpio);

    PORTE->PCR[26] = ((PORTE->PCR[26] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))

                      /* Drive Strength Enable: High drive strength is configured on the corresponding pin, if pin
                       * is configured as a digital output. */
                      | PORT_PCR_DSE(kPORT_HighDriveStrength));

    SIM->SOPT5 = ((SIM->SOPT5 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT5_UART0TXSRC_MASK)))

                  /* UART 0 transmit data source select: UART0_TX pin. */
                  | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
