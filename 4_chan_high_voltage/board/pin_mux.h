/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
    kPIN_MUX_DirectionInput = 0U,        /* Input direction */
    kPIN_MUX_DirectionOutput = 1U,       /* Output direction */
    kPIN_MUX_DirectionInputOrOutput = 2U /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define SOPT5_UART0TXSRC_UART_TX 0x00u /*!<@brief UART 0 transmit data source select: UART0_TX pin */

/*! @name PORTB16 (number 62), U7[4]/UART0_RX
  @{ */
#define BOARD_INITPINS_DEBUG_UART_RX_PERIPHERAL UART0       /*!<@brief Device name: UART0 */
#define BOARD_INITPINS_DEBUG_UART_RX_SIGNAL RX              /*!<@brief UART0 signal: RX */
#define BOARD_INITPINS_DEBUG_UART_RX_PORT PORTB             /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN 16U                /*!<@brief PORTB pin index: 16 */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN_NAME UART0_RX      /*!<@brief Pin name */
#define BOARD_INITPINS_DEBUG_UART_RX_LABEL "U7[4]/UART0_RX" /*!<@brief Label */
#define BOARD_INITPINS_DEBUG_UART_RX_NAME "DEBUG_UART_RX"   /*!<@brief Identifier name */
                                                            /* @} */

/*! @name PORTB17 (number 63), U10[1]/UART0_TX
  @{ */
#define BOARD_INITPINS_DEBUG_UART_TX_PERIPHERAL UART0        /*!<@brief Device name: UART0 */
#define BOARD_INITPINS_DEBUG_UART_TX_SIGNAL TX               /*!<@brief UART0 signal: TX */
#define BOARD_INITPINS_DEBUG_UART_TX_PORT PORTB              /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN 17U                 /*!<@brief PORTB pin index: 17 */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN_NAME UART0_TX       /*!<@brief Pin name */
#define BOARD_INITPINS_DEBUG_UART_TX_LABEL "U10[1]/UART0_TX" /*!<@brief Label */
#define BOARD_INITPINS_DEBUG_UART_TX_NAME "DEBUG_UART_TX"    /*!<@brief Identifier name */
                                                             /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
