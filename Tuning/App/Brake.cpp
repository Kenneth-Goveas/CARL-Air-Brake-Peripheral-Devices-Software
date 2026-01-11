#include "Brake.h"

Brake_t Brake;

void Brake_t :: begin (uint8_t brake) {
    servo.attach(brake);
}

void Brake_t :: sendCommand (int16_t command) {
    servo.write(command);
}
