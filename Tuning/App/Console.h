/** @file Console.h */

#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <Arduino.h>

/** @brief  Serial input console.
 *
 *  This class provides an API for receiving brake control commands from the
 *  serial input console.
 *
 *  The following configuration parameter is necessary for initializing objects
 *  of this class.
 *  - `baud` `(uint32_t)`: Serial input baud rate.
 *
 *  An object of this class must be initialized before use by calling
 *  Console_t::begin(). This configures the above parameter for that object.
 *  Subsequently, Console_t::getCommand() can be called to receive a brake
 *  control command.
 */

class Console_t {
    public:
        /** @brief  Initialize object.
         *
         *  Initializes the object by configuring its parameters.
         *
         *  @note   This function must necessarily be called at least once
         *          before calling any other member functions.
         *
         *  @param  baud    Serial input baud rate.
         */
        void begin (uint32_t baud);
        /** @brief  Receive command.
         *
         *  Receives a brake control command from the serial input console.
         *
         *  @return Non-negative brake control command, or `-1` on error.
         */
        int16_t getCommand (void);
};

extern Console_t Console;   //!< Object to expose API.

#endif
