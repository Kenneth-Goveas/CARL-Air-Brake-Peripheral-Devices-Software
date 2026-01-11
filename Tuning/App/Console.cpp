#include "Console.h"

Console_t Console;

void Console_t :: begin (uint32_t baud) {
    Serial.begin(baud);
    while (!Serial);
}

int16_t Console_t :: getCommand (void) {
    int count = 0;
    char * string = NULL;
    size_t length = 0;
    int16_t command = 0;

    do {
        while (!Serial.available());

        length++;
        string = (char *)realloc(string, length * sizeof(char));

        string[length - 1] = Serial.read();
        if (string[length - 1] == '\n') {
            string[length - 1] = '\0';
        }
    } while (string[length - 1] != '\0');

    count = sscanf(string, " %" SCNd16 " %n", &command, &length);
    if (count != 1 || length != strlen(string)) {
        free(string);
        return -1;
    } else if (command < 0 || command > 180) {
        free(string);
        return -1;
    }

    Serial.print("Servo command: ");
    Serial.println(command);

    free(string);

    return command;
}
