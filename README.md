# Audio-Based Multi-Switch Input System (Arduino to STM32 Bare-Metal)

## Overview

This project implements a multi-switch input decoding system that converts combinations of digital inputs into:

* Alphabets (A–Z)
* Numbers (0–9)
* Symbols and predefined words

The system also provides audio feedback by playing corresponding `.wav` files.

The project was developed in two stages:

1. Arduino-based implementation for rapid prototyping
2. STM32 bare-metal implementation using Embedded C and direct register access

This demonstrates the transition from high-level development to low-level firmware engineering.

---

## Key Features

* Multi-input system (6 switches and 1 mode selector)
* Dual operation modes:

  * Alphabet and symbol mode
  * Number mode
* Audio feedback for each decoded input
* UART-based debugging (STM32 version)
* Real-time input decoding

---

## Working Principle

Each switch represents a binary input. A combination of switch states forms a unique pattern. This pattern is decoded into a character or word, and the corresponding audio file is triggered.

Mode selection:

* LOW: Alphabet and symbol mode
* HIGH: Number mode

---

## System Architecture

```text
[Switch Inputs]
      ↓
[Bit Combination]
      ↓
[Decoder Logic]
      ↓
[Character Output]
      ↓
[Audio Playback]
```

---

## Arduino Implementation

### Technologies Used

* Arduino Uno (or compatible)
* SPI library
* SD library
* TMRpcm library

### Features

* Rapid prototyping using high-level APIs
* Audio playback via SD card
* Serial output for debugging
* Simple GPIO handling using `digitalRead()`

### Limitations

* Large conditional (if-else) structure
* Platform-specific libraries
* Blocking delays
* Limited control over hardware behavior

---

## STM32 Implementation (Bare-Metal)

### Target Platform

* STM32 Nucleo-F446RE

### Technologies Used

* Embedded C
* Direct register programming (no HAL)
* Peripheral registers:

  * GPIO (MODER, IDR, PUPDR)
  * RCC
  * USART

### Features

* Register-level GPIO configuration and input reading
* Custom UART driver for debugging
* Fully portable embedded C code
* Hardware-level control and understanding

### Improvements Over Arduino Version

* No abstraction layers
* Higher performance and efficiency
* Industry-relevant coding approach
* Clear separation between hardware control and application logic

---

## Current Limitations

* Large conditional decoding logic (not scalable)
* Polling-based input handling
* Audio playback not implemented in STM32 version (placeholder only)

---

## Future Enhancements

* Replace conditional logic with bitmask-based lookup table
* Implement SD card support using SPI and FATFS
* Add WAV file decoding and playback using DAC or I2S with DMA
* Introduce interrupt-based input handling (EXTI)
* Add debounce logic for switches
* Integrate RTOS (e.g., FreeRTOS)

---

## Skills Demonstrated

* Embedded C programming
* Register-level hardware control
* GPIO interfacing
* UART communication
* Firmware architecture design
* Transition from Arduino to bare-metal systems

---

## Applications

* Assistive input systems (e.g., Braille-like interfaces)
* Custom chorded keyboards
* Embedded human-machine interfaces
* Educational embedded systems projects

---

## Project Structure

```text
/project
 ├── arduino/
 │    ├── main.ino
 │    └── audio files (.wav)
 │
 ├── stm32/
 │    ├── main.c
 │    ├── startup.s
 │    └── linker.ld
```

---


## Summary

This project demonstrates a complete development progression:

* Initial prototyping using Arduino
* Migration to a bare-metal STM32 implementation

It reflects a practical understanding of embedded systems development from abstraction to hardware-level control.
