# Arduino Mouse Jiggler

A specialized hardware utility designed to simulate mouse movement to prevent system idle states and screen locks.

## Overview
This project transforms a standard Arduino Uno R3 into a plug-and-play USB Human Interface Device (HID). By flashing the onboard ATmega16U2 chip with custom mouse firmware, the Arduino can send raw HID reports to a host computer, effectively mimicking a physical mouse. This is useful for preventing corporate screen locks during long tasks or simulating activity in environments where software-based jigglers are restricted.

## Technology Stack
* [cite_start]**Hardware:** Arduino Uno R3 (with ATmega16U2 chip). [cite: 59, 154]
* **Firmware:** `Arduino-mouse-0.1.hex` (16U2 firmware).
* **Software:** Arduino IDE 1.8.19, Atmel FLIP (Flexible In-system Programmer).

## System Requirements
* **Operating System:** Windows (for FLIP support).
* **Hardware:** Arduino Uno R3 and a USB 2.0 Cable.
* **Software:** Atmel FLIP tool installed.

## Installation & Setup

### 1. Flash the ATmega328P (The Logic)
1.  Open the Arduino IDE 1.8.19.
2.  [cite_start]Open `Jiggler_Advanced_Square.ino` (formerly `sketch_may02b.ino`). [cite: 15-26]
3.  Connect your Uno via USB.
4.  Go to **Tools > Board > Arduino Uno** and select your COM port.
5.  Click **Upload**.

### 2. Enter DFU Mode
1.  Locate the 6-pin ICSP header near the USB port.
2.  Briefly short the two pins closest to the USB reset button with a jumper or wire.
3.  The device should now appear in Device Manager under **libusb-win32 devices** or **Atmel USB Devices** as "ATmega16U2".

### 3. Flash the ATmega16U2 (The HID Interface)
1.  Open the **FLIP** software.
2.  Click the **Device** icon and select **ATmega16U2**.
3.  Click the **USB Cable** icon and select **Open**.
4.  Go to **File > Load HEX File** and select `Arduino-mouse-0.1.hex`.
5.  Under **Operations Flow**, ensure Erase, Program, and Verify are checked, then click **Run**.
6.  Unplug and replug the Arduino. It will now be recognized as a HID Mouse.

## Key Learning Objectives
* [cite_start]Understanding the dual-processor architecture of the Arduino Uno (16U2 vs 328P). [cite: 59, 74, 154]
* [cite_start]Learning to communicate with the OS via low-level 4-byte HID packets. [cite: 16-17, 20]
* Mastering Device Firmware Update (DFU) procedures.

## Real-World Applications
* **Productivity:** Preventing computer sleep during large file transfers or data processing.
* **Security Testing:** Testing if a system's idle-timeout policies can be bypassed by hardware peripherals.

## Documentation & Resources
* [Atmel FLIP Tool Download](https://www.microchip.com/en-us/development-tool/FLIP)
* [Arduino Uno HID Transformation Guide](https://anhnguyen.me/2014/01/turn-arduino-uno-r3-into-a-mouse/)
