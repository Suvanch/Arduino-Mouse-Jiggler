# Arduino Mouse Jiggler

A hardware-based utility designed to simulate mouse movement to prevent system idle states, screen locks, and "Away" status on communication platforms.

## Overview
This project transforms a standard Arduino Uno R3 into a plug-and-play USB Human Interface Device (HID). By flashing the onboard ATmega16U2 chip with custom mouse firmware, the Arduino can send raw HID reports to a host computer, effectively mimicking a physical mouse. 

Unlike software-based jigglers, this hardware solution is driverless and works at the BIOS/OS level, making it nearly impossible for standard IT monitoring tools to detect as "faked" activity.

## Technology Stack
* **Hardware:** Arduino Uno R3 (specifically the version with the ATmega16U2 chip).
* **Firmware:** `Arduino-mouse-0.1.hex` (16U2 firmware).
* **Software:** Arduino IDE 1.8.19 and Atmel FLIP (Flexible In-system Programmer).

## System Requirements
* **Operating System:** Windows (required to run the Atmel FLIP tool).
* **Hardware:** Arduino Uno R3 and a high-quality USB 2.0 Cable.
* **Software:** Atmel FLIP tool installed for firmware flashing.

## Installation & Setup

### 1. Flash the ATmega328P (The Logic)
1.  Open the Arduino IDE 1.8.19.
2.  Open the `Jiggler_Advanced_Square.ino` sketch.
3.  Connect your Uno via USB.
4.  Go to **Tools > Board > Arduino Uno** and select your COM port.
5.  Click **Upload**. This sets the movement logic (the clockwise square pattern).

### 2. Enter DFU Mode
1.  Locate the 6-pin ICSP header near the USB port.
2.  Briefly short the two pins closest to the USB reset button with a jumper or wire.
3.  The device should now appear in Device Manager under **libusb-win32 devices** as "ATmega16U2".

### 3. Flash the ATmega16U2 (The HID Interface)
1.  Open the **FLIP** software.
2.  Click the **Device** icon and select **ATmega16U2**.
3.  Click the **USB Cable** icon and select **Open**.
4.  Go to **File > Load HEX File** and select `Arduino-mouse-0.1.hex`.
5.  Under **Operations Flow**, ensure **Erase**, **Program**, and **Verify** are checked, then click **Run**.
6.  Unplug and replug the Arduino. It will now be recognized by your PC as a standard HID Mouse.

## Key Learning Objectives
* Understanding the dual-processor architecture of the Arduino Uno (16U2 vs 328P).
* Learning to communicate with the OS via low-level 4-byte HID packets.
* Mastering Device Firmware Update (DFU) procedures for AVR chips.

## Real-World Applications
* **System Maintenance:** Preventing computer sleep during long-running background tasks or file transfers.
* **Security Testing:** Auditing system idle-timeout policies and screen lock configurations.

## Documentation & Resources
* [Atmel FLIP Tool Download](https://www.microchip.com/en-us/development-tool/FLIP)
* [Reference Guide: Turning Arduino into a Mouse](https://anhnguyen.me/2014/01/turn-arduino-uno-r3-into-a-mouse/)
