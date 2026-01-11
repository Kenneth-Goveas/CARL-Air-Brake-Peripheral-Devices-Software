/** @mainpage
 *
 *  This is the tuning app for flashing on the peripheral devices module of the
 *  CARL Air Brake computer. The source code documentation is aimed at
 *  developers interested in contributing to or modifying the software.
 */

#include "Configuration.h"
#include "Brake.h"
#include "Console.h"

void setup (void) {
    Brake.begin(BRAKE_OUTPUT);
    Console.begin(CONSOLE_BAUD);
}

void loop (void) {
    int16_t command = Console.getCommand();
    if (command >= 0) {
        Brake.sendCommand(command);
    }
}
