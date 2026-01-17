# CARL Air Brake Peripheral Devices Software

This repository contains the software for the peripheral devices module of the
[CARL Air Brake][cab-repo] computer. The CARL Air Brake computer automatically
controls a rocket air brake in flight, so that the vehicle attains an apogee at
the desired altitude. Its peripheral devices module (see
[CARL Air Brake Peripheral Devices Hardware][cab-pdev-hw-repo]) contains the
necessary sensors and the brake actuator.

## Description

A detailed description of the peripheral devices module can be found in
[CARL Air Brake Peripheral Devices Hardware][cab-pdev-hw-repo]. As described
there, the software in this repository must be flashed onto the peripheral
devices module for it to receive control commands from the Raspberry Pi and
drive the brake actuator.

## Prerequisites

The [Arduino IDE][ard-ide] is required for building and flashing the software.
Additionally, the following hardware is also needed.

- The power supply module (for description, see
  [CARL Air Brake Power Supply Hardware][cab-psup-hw-repo]).
- The battery (for requirements, see
  [CARL Air Brake Power Supply Hardware][cab-psup-hw-repo]).
- The brake servo actuator (for requirements, see
  [CARL Air Brake Peripheral Devices Hardware][cab-pdev-hw-repo]).
- An Arduino Uno.
- Six male to female jumper wires.
- A standard sized USB type B cable.
- A micro USB type B cable.

## Flashing

To properly configure, build, and flash the software for the peripheral devices
module, carry out the following six steps.

### Configure Arduino IDE

Apply the following settings in the Arduino IDE. The same settings will be used
in all subsequent steps in the process.

- Set the target platform to *Arduino Uno* by clicking on *Tools > Board >
  Arduino AVR Boards > Arduino Uno*.
- Set the programmer to *Arduino as ISP* by clicking on *Tools > Programmer >
  Arduino as ISP*. This setting is not necessary if the peripheral devices
  module already has the Arduino bootloader installed. If unsure, assume that
  the bootloader is not installed.

### Program Arduino Uno as ISP

Program the Arduino Uno to act as an ISP. This step is not necessary if the
peripheral devices module already has the Arduino bootloader installed. If
unsure, assume that the bootloader is not installed.

- Open the *ArduinoISP* sketch by clicking on *File > Examples > ArduinoISP >
  ArduinoISP*.
- Connect the Arduino Uno to your computer with a USB cable. Do not connect any
  other circuitry to the Arduino Uno.
- Select the serial port connected to the Arduino Uno in *Tools > Port*.
- Upload the sketch.
- Disconnect the Arduino Uno from the computer.

### Install bootloader on peripheral devices module

Using the Arduino Uno as an ISP, install the Arduino bootloader on the
peripheral devices module. This step is not necessary if the peripheral devices
module already has the Arduino bootloader installed. If unsure, assume that the
bootloader is not installed.

- Connect the ICSP port of the peripheral devices module to the Arduino Uno by
  making the following connections with jumper wires.
  | **Arduino Uno** | **Peripheral devices module** |
  | --------------- | ----------------------------- |
  | 5V              | VCC                           |
  | GND             | GND                           |
  | 10              | RST                           |
  | 11              | MOSI                          |
  | 12              | MISO                          |
  | 13              | SCK                           |
- Connect the Arduino Uno to your computer with a USB cable.
- Select the serial port connected to the Arduino Uno in *Tools > Port*.
- Install the Arduino bootloader by clicking on *Tools > Burn bootloader*.
- Disconnect all devices from each other.

### Flash tuning app on peripheral devices module

Flash the tuning app (contained in the [Tuning/App][tune-app-dir] directory) on
the peripheral devices module.

- Connect the peripheral devices module to your computer with a USB cable.
- Open the [Tuning/App/App.ino][tune-app-file] sketch in the Arduino IDE.
- Select the serial port connected to the peripheral devices module in *Tools >
  Port*.
- Upload the sketch.
- Leave the peripheral devices module connected to the computer.

### Configure actuator positions

Using the tuning app, configure the brake actuator positions for the main app
(contained in the [Main/App][main-app-dir] directory). As described in
[CARL Air Brake Peripheral Devices Hardware][cab-pdev-hw-repo], the peripheral
devices module can receive control commands from the Raspberry Pi and drive the
brake actuator. After flashing the main app (next step), the peripheral devices
module will respond to commands received from the Raspberry Pi.

- Connect the power supply module to the peripheral devices module by stacking
  it under the peripheral devices module.
- Connect the brake servo actuator to the peripheral devices module.
- Connect the battery to the power supply module and switch the power supply
  module on.
- Open the serial monitor in the Arduino IDE and set the baud rate to 115200 and
  the line ending to *New Line*.
- Manually adjust the brake actuator by typing in the desired angular position
  in degrees into the serial input. The angles must lie between 0 and 180
  degrees. In this way, adjust the brake actuator until the brake is fully
  retracted, and then until it is fully deployed, and note the corresponding
  angular positions.
- Disconnect the power supply module and the brake servo actuator from the
  peripheral devices module. However, leave the peripheral devices module
  connected to the computer over USB.
- Open the [Main/App/Configuration.h][main-app-conf-file] file and replace the
  default values of the `INTERFACE_LOWER_LIMIT` and `INTERFACE_UPPER_LIMIT`
  constants with the values you noted.

### Flash main app on peripheral devices module

Flash the main app on the peripheral devices module.

- Open the [Main/App/App.ino][main-app-file] sketch in the Arduino IDE.
- Select the serial port connected to the peripheral devices module in *Tools >
  Port*.
- Upload the sketch.
- Disconnect the peripheral devices module from the computer.

## Documentation

The documentation for the source code can be generated with [Doxygen][dox].
Installation instructions can be found on the [Download][dox-dl] page. For each
app, run the following command from the respective app directory
([Tuning][tune-dir] for the tuning app, and [Main][main-dir] for the main app)
to generate the documentation for that app.

```
doxygen
```

This will create a directory named *Doc* and place the HTML documentation in it.

[tune-dir]:           ./Tuning
[tune-app-dir]:       ./Tuning/App
[tune-app-file]:      ./Tuning/App/App.ino
[main-dir]:           ./Main
[main-app-dir]:       ./Main/App
[main-app-file]:      ./Main/App/App.ino
[main-app-conf-file]: ./Main/App/Configuration.h

[cab-repo]:           https://github.com/Kenneth-Goveas/CARL-Air-Brake
[cab-psup-hw-repo]:   https://github.com/Kenneth-Goveas/CARL-Air-Brake-Power-Supply-Hardware
[cab-pdev-hw-repo]:   https://github.com/Kenneth-Goveas/CARL-Air-Brake-Peripheral-Devices-Hardware

[ard-ide]:            https://www.arduino.cc/en/software

[dox]:                https://www.doxygen.nl
[dox-dl]:             https://www.doxygen.nl/download.html
