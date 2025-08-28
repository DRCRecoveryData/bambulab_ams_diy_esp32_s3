#pragma once

#include "main.h"

// UART PORT = specifies which UART in the chip (controller) is used.
// TXD_PIN/RXD_PIN = specifies which physical GPIOs are connected externally.
// Without this combination, it won't work:
// Only UART_PORT → the ESP32 won't know which pins to send/receive on.
// Only TXD_PIN/RXD_PIN → you haven't selected a hardware UART.
// Bambulab connection
//#define BAMBU_UART_BAUD   1250000
#define BAMBU_UART_BAUD 1228800 // Another value, because the ESP32 can't maintain exactly 1250000
// The UART in the ESP32 has coarser dividers, meaning it can't achieve every baud rate precisely.
// At "odd" rates like 1,250,000, the error on the ESP32 is several percent – enough to break CRC as bits flip.
// 👉 The next best baud rate that the ESP32 can achieve exactly is 1,228,800 Bd.
// This is closer to 1.25 M than what it actually generates at 1250000.

#define UART_PORT   UART_NUM_1 // USB --> UART_NUM_0, TX2/RX2 --> UART_NUM_1
// Choose appropriate pins on the ESP32-S3
#define TXD_PIN     GPIO_NUM_19 // TX Pin 19
#define RXD_PIN     GPIO_NUM_18 // RX Pin 18
// RS485 PIN
#define DE_PIN      GPIO_NUM_5 // PIN 5

// Test with 8 LEDs
#define LED_NUM 2

// PWM Pins for Motion Control
#define PWM0_PIN_LED GPIO_NUM_25
#define PWM1_PIN_LED GPIO_NUM_26
#define PWM2_PIN_LED GPIO_NUM_27
#define PWM3_PIN_LED GPIO_NUM_14

// Mainboard PIN
#define PWM6_PIN_LED GPIO_NUM_13

// Example GPIO assignment for 4 AS5600 I2C devices
// AS5600
// The AS5600 is a magnetic rotary angle sensor (Hall sensor).
// It measures the rotational angle of a magnet with 12-bit precision (0–4095), making it very accurate.
// Typical use: motors, encoders, position detection.
#define AS5600_0_SCL GPIO_NUM_8
#define AS5600_1_SCL GPIO_NUM_10
#define AS5600_2_SCL GPIO_NUM_12
#define AS5600_3_SCL GPIO_NUM_14

#define AS5600_0_SDA GPIO_NUM_9
#define AS5600_1_SDA GPIO_NUM_11
#define AS5600_2_SDA GPIO_NUM_13
#define AS5600_3_SDA GPIO_NUM_15

// PWM Channels (ESP32 supports max 16 channels, 0-15)
// Probably 8 motors? DC motors
#define PWM_CH0 0
#define PWM_CH1 1
#define PWM_CH2 2
#define PWM_CH3 3

// PWM frequency and resolution
#define PWM_FREQ 20000           // 20 kHz, suitable for motor control
#define PWM_RES  10              // 10-bit resolution (0-1023)

// Define pins for PWM channels
#define PWM_CH0_PIN GPIO_NUM_6
#define PWM_CH1_PIN GPIO_NUM_7
#define PWM_CH2_PIN GPIO_NUM_8
#define PWM_CH3_PIN GPIO_NUM_9
#define PWM_CH4_PIN GPIO_NUM_10  // instead of 18 (use GPIO2 carefully, boot pin)
#define PWM_CH5_PIN GPIO_NUM_11
#define PWM_CH6_PIN GPIO_NUM_12
#define PWM_CH7_PIN GPIO_NUM_13

// ADC Pins for ESP32 (ADC1), filtered voltages
// Initializes 8 ADC channels of the ESP32 with 12-bit resolution and ~3.3 V measurement range.
// Reads all 8 channels 256 times on demand (ADC_DMA_get_value()).
// Averages the values (noise filter).
// Returns the filtered values in volts.

// Currently disabled in void MC_PULL_ONLINE_read (only simulated, always optimal value)
#define ADC1_CH0_PIN GPIO_NUM_1
#define ADC1_CH1_PIN GPIO_NUM_2
#define ADC1_CH2_PIN GPIO_NUM_3
#define ADC1_CH3_PIN GPIO_NUM_4
#define ADC1_CH4_PIN GPIO_NUM_5
#define ADC1_CH5_PIN GPIO_NUM_6
#define ADC1_CH6_PIN GPIO_NUM_7
#define ADC1_CH7_PIN GPIO_NUM_8

#define Debug_log_on
#define Debug_log_baudrate 115200

// OTA Task
#define OTA_TASK_DELAY_MS 100  // Delay for OTA task in milliseconds

// Global variables (declaration only!)
extern uint8_t BambuBus_AMS_num;
extern uint8_t AMS_humidity_wet;