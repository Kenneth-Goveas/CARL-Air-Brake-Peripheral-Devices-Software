/** @file Brake.h */

#ifndef __BRAKE_H__
#define __BRAKE_H__

#include <Arduino.h>
#include <Servo.h>

/** @brief  Brake control.
 *
 *  This class provides an API for brake control. The brake is controlled
 *  by sending commands to a servo actuator connected to an analog output pin.
 *  The commands specify the angular position of the servo actuator from 0 to
 *  180 degrees.
 *
 *  The following configuration parameters are necessary for initializing
 *  objects of this class.
 *  - `brake` `(uint8_t)`:  Analog output pin to control.
 *
 *  An object of this class must be initialized before use by calling
 *  Brake_t::begin(). This configures the above parameter for that object.
 *  Subsequently, Brake_t::sendCommand() can be called to send commands to the
 *  brake as described above.
 */

class Brake_t {
    private:
        Servo servo;
    public:
        /** @brief  Initialize object.
         *
         *  Initializes the object by configuring its parameters.
         *
         *  @note   This function must necessarily be called at least once
         *          before calling any other member functions.
         *
         *  @param  brake   Analog output pin to control.
         */
        void begin (uint8_t brake);
        /** @brief  Send command to brake.
         *
         *  Sends a command to control the brake.
         *
         *  @param  command Brake control command.
         */
        void sendCommand (int16_t command);
};

extern Brake_t Brake;   //!< Object to expose API.

#endif
