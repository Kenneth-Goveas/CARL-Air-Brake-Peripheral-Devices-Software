/** @file Configuration.h */

#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <Arduino.h>

/// Brake_t configuration parameter `brake`
const uint8_t BRAKE_OUTPUT = 9;

/// Interface_t configuration parameter `address`
const uint8_t INTERFACE_ADDRESS = 0x10;

/// Interface_t configuration parameters `lowerLimit`
const int16_t INTERFACE_LOWER_LIMIT = 0;

/// Interface_t configuration parameter `upperLimit`
const int16_t INTERFACE_UPPER_LIMIT = 180;

#endif
