# WIFI-84
*Wi-Fi Interface Furnishing Internet for TI-84*


## Overview

This project aims to provide direct Internet access to TI-84 calculators
using an inexpensive ESP8266 module as a wireless modem.
It will initially support the older monochrome calculators,
with the goal of eventually porting to the newer color ones.

## Architecture

The project will consist of three main parts:

1. A physical interface between the calculator and ESP8266
2. A driver for communicating between them
3. A high-level networking API exposed to calculator programs

Possible implementations for these are currently being considered.
Some of the ideas are in the following section.



## Architecture


### Physical interface

The main concerns here are power and communication.
For power, the primary options are either USB or an external battery.
For communication, the primary options are either USB or the 2.5mm I/O port.

USB communication is preferable to maintain forward compatibility
with the TI-84+CE, which lacks the I/O port.

In addition, having an external battery pack is suboptimal,
so USB power would make the most sense.
However, the ESP8266 can use more than 100mA of current (the USB port's limit),
so more research needs to be done on whether USB power is feasible.

Current consensus: USB power + communication


### Driver

The ESP8266 itself would likely run its standard AT firmware
for the sake of simplicity.
It should be able to do everything needed fairly easily.
The main difficulty is with sending commands from the calculator.

If using USB, communication would most likely occur over a PL2303
USB serial cable because a Linux driver for this chip is available
as a reference.
However, writing a USB driver is non-trivial, and hardware documentation
is sparse for the calculators' USB interfaces.
Using usb8x could help speed up development time,
but it is not available for the newer calculators.
There appears to be an ongoing community effort to understand
the TI-84+CE's USB port, however.

Alternatively, using the I/O port, there could be an ATtiny or similar IC
that interprets the TI link protocol and sends the equivalent serial commands
to the ESP8266.
As mentioned above, this would preclude calculators such as the TI-84+CE
that lack the I/O port,
and it would likely have issues with buffer space due to the communication
speed mismatch between the calculator and the ESP8266.

Current consensus: USB PL2303 driver


### API

This portion is fairly flexible.
All it really needs to do is send AT commands over either the USB or I/O port
and pass the result back to the caller.

The easiest way would be to provide a header file that can be included
with each program needing a Wi-Fi connection.
This has the disadvantage of tight coupling, inflexibility,
lack of centralized connection management, etc.

A better possibility would be to provide a dedicated app, similar to usb8x,
but apparently the signing key has not yet been released for the TI-84+CE.

The API itself will likely bear resemblance to the Arduino ESP8266
WiFi library.

Current consensus: TBD