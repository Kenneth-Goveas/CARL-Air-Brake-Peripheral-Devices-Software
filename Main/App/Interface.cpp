#include "Interface.h"

Interface_t Interface;

static int16_t interfaceLowerLimit, interfaceUpperLimit;
static void (* interfaceCallback) (int16_t);

static void interfaceReceive (int count) {
    int16_t command;

    for (int i = 0; i < count; i++) {
        command = Wire.read();
    }
    command = map(command, 0, 255, interfaceLowerLimit, interfaceUpperLimit);

    interfaceCallback(command);
}

void Interface_t :: begin (
    uint8_t address, int16_t lowerLimit, int16_t upperLimit,
    void (* callback) (int16_t)
) {
    interfaceLowerLimit = lowerLimit;
    interfaceUpperLimit = upperLimit;
    interfaceCallback = callback;

    Wire.begin(address);
    Wire.onReceive(interfaceReceive);
}
