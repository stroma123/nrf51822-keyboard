#ifndef _keyboard_conf_h_
#define _keyboard_conf_h_

#include <stdint.h>
#include "nrf_adc.h"
#include "config.h"

#ifdef KEYBOARD_4100

/** 电量测量引脚 */
#define KEYBOARD_ADC NRF_ADC_CONFIG_INPUT_2

/** 数字锁定灯IO口 */
#define LED_NUM 11
/** 大小写锁定灯IO口 */
#define LED_CAPS 12
/** 滚动锁定IO口 */
#define LED_SCLK 13

/** 行IO */
static const uint8_t row_pin_array[MATRIX_ROWS] = {21,22,23,24,25,26,27,29};
/** 列IO */
static const uint8_t column_pin_array[MATRIX_COLS] = {3,4,5,6,7,15,14,10,9,8,2,0,30,28};

/** Bootloader强制进入引脚 */
#define BOOTLOADER_BUTTON 16

#define UPDATE_IN_PROGRESS_LED      LED_NUM
#define ADVERTISING_LED_PIN_NO      LED_CAPS
#define CONNECTED_LED_PIN_NO        LED_SCLK
#define LED_POSITIVE

#endif

#ifdef KEYBOARD_60

#define LED_CAPS 18
#define LED_EXT1 16
#define LED_EXT2 14
#define LED_EXT3 12
#define LED_EXT4 10
#define LED_EXT5 8

#define UART_TXD 22
#define UART_RXD 21

static const uint8_t row_pin_array[MATRIX_ROWS] = {24,25,26,27,28};

#define BOOTLOADER_BUTTON 20
#define UPDATE_IN_PROGRESS_LED      LED_CAPS
#define ADVERTISING_LED_PIN_NO      LED_EXT1
#define CONNECTED_LED_PIN_NO        LED_EXT2
#define LED_POSITIVE

/**
 * @brief 此版本中有一个硬件设计错误，导致ADC电量测量无法使用。这里将其关闭。
 * 
 */
#ifdef KEYBOARD_REVA
    static const uint8_t column_pin_array[MATRIX_COLS] = {19,17,15,13,11,9,7,6,5,4,3,2,1,0};
#else
    #define KEYBOARD_ADC NRF_ADC_CONFIG_INPUT_2
    static const uint8_t column_pin_array[MATRIX_COLS] = {19,17,15,13,11,9,7,6,5,4,3,2,0,30};
#endif

#endif

#ifdef KEYBOARD_400

#define KEY1	16
#define KEY2	17

#define LED0	18
#define LED1	19
#define LED2	20
#define LED3	21
#define LED4	22

#define UART_TXD 9
#define UART_RXD 11
//#define UART_RXD 5
//#define UART_TXD 6

/** 电量测量引脚 */
#define KEYBOARD_ADC NRF_ADC_CONFIG_INPUT_2

/** 数字锁定灯IO口 */
#define LED_NUM	LED0
/** 大小写锁定灯IO口 */
#define LED_CAPS LED2
/** 滚动锁定IO口 */
#define LED_SCLK LED4

/** 行IO */
static const uint8_t row_pin_array[MATRIX_ROWS] = {23,24,25,26};
/** 列IO */
static const uint8_t column_pin_array[MATRIX_COLS] = {12,13,14,15};

/** Bootloader强制进入引脚 */
#define BOOTLOADER_BUTTON KEY1

#define UPDATE_IN_PROGRESS_LED      LED_NUM
#define ADVERTISING_LED_PIN_NO      LED_CAPS
#define CONNECTED_LED_PIN_NO        LED_SCLK
#define LED_POSITIVE

#endif

#ifdef LED_POSITIVE
    #define LED_SET(x) nrf_gpio_pin_set(x)
    #define LED_CLEAR(x) nrf_gpio_pin_clear(x)
    #define LED_WRITE(x,b) nrf_gpio_pin_write(x,b)
#else
    #define LED_SET(x) nrf_gpio_pin_clear(x)
    #define LED_CLEAR(x) nrf_gpio_pin_set(x)
    #define LED_WRITE(x,b) nrf_gpio_pin_write(x,!(b))
#endif


#endif
