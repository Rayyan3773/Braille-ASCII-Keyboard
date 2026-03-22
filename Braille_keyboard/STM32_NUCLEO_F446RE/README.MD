#  Audio Input Decoder (STM32 Bare-Metal)

##  Overview

This project is a **bare-metal embedded C implementation** of a multi-switch input decoding system on STM32.

It reads GPIO inputs directly via registers and maps them to:

* Alphabets
* Numbers
* Symbols

Designed to demonstrate **low-level firmware development skills** without HAL or Arduino abstraction.

---

##  Key Highlights

* Pure **register-level programming**
* No HAL / No Arduino libraries
* GPIO input handling via `IDR`
* Modular design (input → decode → action)
* UART debug output
* Audio playback interface (placeholder for driver integration)

---

##  System Design

### Input Layer

* 6 digital inputs + 1 mode switch
* Read using:

```c
GPIOA->IDR
```

### Processing Layer

* Input combinations decoded using logic conditions
* Mode selection:

  * LOW → Alphabet mode
  * HIGH → Number mode

### Output Layer

* UART print (debug)
* Audio playback function (stub)

---

##  Architecture

```
[GPIO Inputs]
      ↓
[Bit Pattern Decode]
      ↓
[Character Mapping]
      ↓
[UART Output + Audio Trigger]
```

---

##  Hardware Requirements

* STM32 (e.g., STM32F103C8T6)
* Push Buttons (6 + 1 slide switch)
* UART interface (for debug)
* SD card + DAC/I2S (for future audio support)

---

##  Project Structure

```
/stm32_project
 ├── main.c
 ├── startup.s
 ├── linker.ld
 ├── system_stm32.c
```

---

##  How to Run

1. Configure clock and GPIO manually
2. Flash using ST-Link / OpenOCD
3. Monitor UART output
4. Trigger inputs via switches

---

##  Current Limitations

* Audio playback not implemented (stub only)
* Polling-based input
* Large conditional logic (not optimized)

---

##  Future Enhancements

* Implement:

  * SPI driver for SD card
  * FATFS integration
  * WAV decoding
  * I2S/DAC + DMA audio output
* Replace logic with lookup table
* Add EXTI interrupts
* RTOS integration (FreeRTOS)

---

##  Why This Project Matters

This project demonstrates:

* Embedded C proficiency
* Register-level hardware control
* Firmware design thinking
* Transition from Arduino → industry-grade embedded systems

---

##  Learning Outcomes

* GPIO register manipulation
* Embedded system architecture
* Input decoding techniques
* Hardware abstraction removal

---

##  Author

Embedded Systems / Firmware Developer
