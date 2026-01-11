/** @mainpage
 *
 *  This is the main app for flashing on the peripheral devices module of the
 *  CARL Air Brake computer. The source code documentation is aimed at
 *  developers interested in contributing to or modifying the software.
 */

#include "Configuration.h"
#include "Brake.h"
#include "Interface.h"

static void interfaceCallback (int16_t command) {
    Brake.sendCommand(command);
}

void setup (void) {
    Brake.begin(BRAKE_OUTPUT);
    Interface.begin(
        INTERFACE_ADDRESS, INTERFACE_LOWER_LIMIT, INTERFACE_UPPER_LIMIT,
        interfaceCallback
    );
}

void loop (void) {}
