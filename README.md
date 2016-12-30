# WIFI-84
*Wi-Fi Interface Furnishing Internet for TI-84*


## Overview

This project aims to provide direct Internet access to TI-84 calculators
using an inexpensive ESP8266 module as a wireless modem.
It will support calculators with I/O ports, i.e. those up to the TI-84+CSE.

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

USB communication would be preferable to maintain forward compatibility
with the TI-84+CE, which lacks the I/O port.
However, since the CE's USB controller is completely different IP
than the older 84s, the driver would have to be mostly rewritten anyway.
I/O is the simplest option.

Having an external battery pack would be suboptimal,
so USB power makes the most sense.
The USB port can only supply up to 100mA,
which is less than the ESP8266's maximum draw,
but the transmit power can be lowered in software to decrease current usage.
An efficienct buck converter, such as TR05S3V3, can minimize power loss.
In addition, to save the calculator's batteries,
the ESP8266 can use deep sleep mode whenever possible.

Current consensus: USB power + I/O communication


### Driver

The ESP8266 itself would likely run its standard AT firmware
or an equivalent for the sake of simplicity.
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

Another possibility using the I/O port would be to write custom ESP8266 firmware
using the [ArTICL](https://github.com/KermMartian/ArTICL) library
to communicate with the calculator directly over the TI link protocol.
This enables larger buffer space due to the ESP8266's more plentiful resources.
It decreases the software complexity on the calculator to the point that
even TI-Basic programs could use the modem.

Current consensus: custom ESP8266 firmware


### API

This portion is fairly flexible.
All it really needs to do is send AT commands over either the USB or I/O port
and pass the result back to the caller.
If using custom firmware, it needs to follow the equivalent protocol
that is implemented.

The easiest way would be to support CBL variable transfer with ArTICL.
Then any program or app could use a defined API for
communicating with the ESP8266 using strings or other variables.
However, this is rather inflexible.

Another way would be to provide a header file that can be included
with each program needing a Wi-Fi connection.
It would likely bear resemblance to the Arduino ESP8266 WiFi API.
This has the disadvantage of tight coupling and inflexibility.
It would only be necessary in the case of a specialized serial driver.

A better possibility would be to provide a dedicated app, similar to usb8x,
but apparently the signing key has not yet been released for the TI-84+CE.

Current consensus: CBL