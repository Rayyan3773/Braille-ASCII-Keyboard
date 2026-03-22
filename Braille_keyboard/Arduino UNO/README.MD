#  Audio-Based Input System (Arduino)

##  Overview

This project implements a **multi-switch input decoding system** using an Arduino.
Based on combinations of switch inputs, the system identifies **alphabets, numbers, and symbols**, prints them via Serial, and plays corresponding **audio files from an SD card**.

It mimics a **Braille-like or chorded keyboard input system** with audio feedback.

---

##  Features

* Detects multiple switch combinations (6 inputs + 1 mode switch)
* Supports:

  * Alphabets (A–Z)
  * Numbers (0–9)
  * Symbols and common words
* Audio playback using SD card (`.wav` files)
* Serial output for debugging

---

##  Working Principle

* Each switch represents a binary input
* Combination of inputs → mapped to a character
* Slide switch selects mode:

  * LOW → Alphabet/Symbol mode
  * HIGH → Number mode
* Corresponding `.wav` file is played

---

##  Hardware Requirements

* Arduino Uno (or compatible)
* SD Card Module
* Speaker
* Push Buttons (6 + 1 slide switch)
* Resistors (for pull-down/up)

---

##  Libraries Used

* `SPI.h`
* `SD.h`
* `TMRpcm.h`

---

##  File Structure

```
/project
 ├── code.ino
 ├── A.wav
 ├── B.wav
 ├── ...
 ├── Z.wav
 ├── 0.wav - 9.wav
 ├── symbols (comma.wav, space.wav, etc.)
```

---

##  How to Run

1. Connect hardware as per pin configuration
2. Upload code using Arduino IDE
3. Insert SD card with `.wav` files
4. Open Serial Monitor (9600 baud)
5. Press switches to generate input

---

##  Limitations

* Large `if-else` structure (not scalable)
* Arduino-specific libraries (not portable)
* Blocking delay used
* No interrupt-based input handling

---

##  Future Improvements

* Replace `if-else` with lookup table
* Add debounce logic
* Use interrupts instead of polling
* Improve audio handling

---

##  Use Case

* Assistive input systems
* Educational tools
* Embedded system learning project

---

##  Author

Embedded Systems Enthusiast
