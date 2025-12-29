# Arduino Mouse Jiggler & Activity Emulator

A hardware-based utility designed to simulate mouse movement, clicking, and keyboard activity to prevent system idle states, screen locks, and "Away" status on communication platforms.

## Overview
This project transforms a standard Arduino Uno R3 into a plug-and-play USB Human Interface Device (HID). By flashing the onboard ATmega16U2 chip with custom firmware, the Arduino can send raw HID reports to a host computer to mimic a physical mouse and keyboard. 

The "Chaotic Jiggler" mode performs a safe horizontal jitter while intermittently clicking and typing random characters to simulate active user engagement without disrupting the cursor's vertical position.

## Technology Stack
* [cite_start]**Hardware:** Arduino Uno R3 (Atmega16U2 version)[cite: 59].
* **Firmware:** `Arduino-mouse-0.1.hex` (Mouse only) or `HoodLoader2` (Composite Mouse/Keyboard).
* **Software:** Arduino IDE 1.8.19 and Atmel FLIP.

## System Requirements
* **Operating System:** Windows (for Atmel FLIP support).
* **Hardware:** Arduino Uno R3 and a USB 2.0 Cable.
* **Software:** Atmel FLIP tool installed.

## Installation & Setup

### 1. Flash the ATmega328P (The Logic)
1.  Open the Arduino IDE 1.8.19.
2.  Upload the `Chaotic_Jiggler.ino` sketch. This combines horizontal jitter, randomized left-clicks, and random character typing.
3.  Ensure you have selected **Tools > Board > Arduino Uno** and the correct COM port.

### 2. Enter DFU Mode
1.  Locate the 6-pin ICSP header near the USB port.
2.  Briefly short the two pins closest to the USB reset button.
3.  Verify the device appears as "ATmega16U2" in Device Manager.

### 3. Flash the ATmega16U2 (The HID Interface)
1.  Open **FLIP**, select **ATmega16U2**, and open the USB connection.
2.  [cite_start]**Note:** To support both typing and moving, you must use **HoodLoader2** or a composite HID firmware[cite: 39, 59].
3.  Load your `.hex` file, ensure **Erase**, **Program**, and **Verify** are selected, and click **Run**.
4.  Replug the device to begin emulation.

## Featured Logic: The Chaotic Jiggler
This version is designed for safety and activity persistence:
* [cite_start]**Horizontal Jitter:** The mouse moves 5 pixels right and 5 pixels left, returning to the exact starting point to prevent "drifting" onto unwanted buttons [cite: 5, 20-21].
* **Random Clicking:** Simulates a standard Left Click to maintain application focus.
* **Random Typing:** Generates 8-character strings of random alphanumeric text to bypass basic activity monitors.
* **Safe Boundaries:** Restricted to X-axis movement to ensure the device does not click on the Taskbar or Close buttons.

## Key Learning Objectives
* [cite_start]Implementation of composite HID devices (Mouse + Keyboard)[cite: 39, 217].
* Using `randomSeed()` with an unconnected analog pin to generate unpredictable behavior.
* Managing non-disruptive automated input to maintain system uptime.

## Documentation & Resources
* [Atmel FLIP Tool Download](https://www.microchip.com/en-us/development-tool/FLIP)
* [HoodLoader2 Installation Guide](https://github.com/NicoHood/HoodLoader2)
