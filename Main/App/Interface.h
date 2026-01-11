/** @file Interface.h */

#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <Arduino.h>
#include <Wire.h>

/** @brief  Host interface.
 *
 *  This class provides an API to configure the I2C interface to the host. The
 *  host can then send brake control commands over I2C. Every time a command is
 *  received in this way, a callback is triggered. This callback can be used to
 *  drive the brake actuator.
 *
 *  The following configuration parameters are necessary for initializing
 *  objects of this class.
 *  - `address` `(uint8_t)`:                I2C address to respond to.
 *  - `lowerLimit` `(int16_t)`:             Brake command for full retraction.
 *  - `upperLimit` `(int16_t)`:             Brake command for full deployment.
 *  - `callback` `(void (*) (int16_t))`:    Callback to trigger.
 *
 *  An object of this class must be initialized by calling Interface_t::begin().
 *  This configures the above parameters for that object. Subsequently, the
 *  configured callback will automatically trigger whenever the host sends a
 *  brake control command.
 */

class Interface_t {
    public:
        /** @brief  Initialize object.
         *
         *  Initializes the object by configuring its parameters.
         *
         *  @param  address     I2C address to respond to.
         *  @param  lowerLimit  Brake command for full retraction.
         *  @param  upperLimit  Brake command for full deployment.
         *  @param  callback    Callback to trigger.
         */
        void begin (
            uint8_t address, int16_t lowerLimit, int16_t upperLimit,
            void (* callback) (int16_t)
        );
};

extern Interface_t Interface;   //!< Object to expose API.

#endif
