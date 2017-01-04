# WIFI-84
*Wi-Fi Interface Furnishing Internet for TI-84*


## Overview

This project aims to provide direct Internet access to TI-84 calculators
using an inexpensive ESP8266 module as a wireless modem.
It supports calculators with I/O ports, i.e. those up to the TI-84+CSE.


## Architecture

The project consists of four main parts:

1. A physical interface between the calculator and ESP8266
2. A driver for communicating between them
3. A high-level networking API exposed to calculator programs
4. A small collection of sample utilities using the API


### Physical interface

The adapter is powered from the calculator's USB port for convenience.
It could probably also be powered from e.g. a USB phone charger,
as long as the power supply is not noisy.
The USB's 5V gets converted to 3.3V using an efficient switching regulator
to save battery.

For communication, the adapter uses the I/O port for simplicity.
Ideally, it would use the USB port for forward compatibility and since
it already uses it for power;
however, writing a USB driver would be a lot of effort for very little gain,
considering that the TI-84+CE uses a completely different USB controller.

It would be nice to have the adapter plug directly into the calculator,
but I can't seem to find any 2.5mm male headphone connectors,
and the only USB mini-B male connector I found is vertical.
Instead, the adapter plugs in using cables,
but is laid out to make it easy to switch to a plug-oriented design later.
See the `hardware` folder for the schematic and circuit board.


### Driver

The ESP8266 runs firmware that directly communicates with the calculator
using the [ArTICL](https://github.com/KermMartian/ArTICL) library.
It acts as a CBL2 device to make communication easy with TI Basic programs.

The calculator does not need a driver since it uses the CBL2
Get( and Send( commands.


### API

The API exposed to the calculator is still in flux,
but it will provide similar capabilities to the ESP8266's default AT firmware.
The calculator will be able to send string variables containing API calls,
and then it will request another variable to get the result (if applicable).

The calculator will send token strings as commands
in order to save program space.
The ESP8266 will respond with token strings or real numbers,
depending on the call.


### Utilities

There will need to be a program to allow the user to connect to
nearby Wi-Fi networks.
It can be as simple as a menu of SSIDs.
By including such a program, applications won't need to
reinvent the wheel, and the connection can be managed centrally.

Also, a tool like wget/curl would be useful for testing.
It would probably have to include its own viewer to display the response
incrementally due to limited RAM.
For HTML, maybe it could have the option to display it with tags stripped
so that it looks sort of like a webpage.

In the future, it would be really cool to have the ESP8266 pre-render webpages
and have the calculator display them screen by screen.
A Slack client would also be neat.
