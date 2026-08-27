\# 02: Analog Telemetry



\## Overview

This module explores Analog-to-Digital Conversion (ADC). It reads continuous variable voltage from a physical rotary dial and broadcasts the raw telemetry data back to the Serial Monitor.



\## Hardware Required

* Arduino Mega 2560
* 10k Ohm Rotary Potentiometer
* Breadboard and Jumper wires



\## The Code Logic

1. \*\*Setup:\*\* Initializes the Serial communication channel at a 9600 baud rate.
2. \*\*Execution Loop:\*\*

   * Read the voltage on Analog Pin 'A0'.
   * Translates the voltage into an integer value between '0' (0V) and '1023'(5V).
   * Transmits the string '"Knob Position: "' followed by the live data to the Serial Monitor.
   * Freezes for 100 milliseconds (running the loop at exactly 10Hz) for stable reading.



\## Media

!\[System Test](Hardware_for_Analog_Telemetry,jpeg)

\[Click here to watch the working of the hardware](Working_for_Analog_Telemetry.mp4)

\[Click here to watch the Serial Monitor Readings](Serial_Monitor_Reading.mp4)

