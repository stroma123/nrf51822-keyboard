/**
 * @brief 蓝牙主机驱动
 * 
 * @file host_driver.c
 * @author Jim Jiang
 * @date 2018-05-13
 */
#include <stdint.h>
#include "keyboard_host_driver.h"

#include "ble_hid_service.h"
#include "custom_hook.h"
#include "uart_driver.h"

static uint8_t keyboard_leds(void);
static void send_keyboard(report_keyboard_t * report);
static void send_mouse(report_mouse_t * report);
static void send_system(uint16_t data);
static void send_consumer(uint16_t data);

host_driver_t driver = {
        keyboard_leds,
        send_keyboard,
        send_mouse,
        send_system,
        send_consumer
};

static uint8_t keyboard_leds()
{
    return led_val;
}
static void send_keyboard(report_keyboard_t * report)
{
    hids_keys_send(KEYBOARD_REPORT_SIZE, report->raw);
#ifdef UART_SUPPORT
    uart_send_packet(PACKET_KEYBOARD, report->raw, KEYBOARD_REPORT_SIZE);
#endif
    hook_send_keyboard(report);
}
static void send_mouse(report_mouse_t * report)
{
    // unsupport, and will not support in future.
}
static void send_system(uint16_t data)
{
    hids_system_key_send(2,(uint8_t *)&data);
#ifdef UART_SUPPORT
    uart_send_packet(PACKET_SYSTEM, (uint8_t *)&data, 2);
#endif
}
static void send_consumer(uint16_t data)
{
    hids_consumer_key_send(2,(uint8_t *)&data);
#ifdef UART_SUPPORT
    uart_send_packet(PACKET_COMSUMER, (uint8_t *)&data, 2);
#endif
}
