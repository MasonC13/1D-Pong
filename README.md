# 1D Pong Game – Embedded Systems Final Project

A simple one-dimensional pong game implementation using an ATmega328p microcontroller.

***

## 🎮 Overview

This project implements a **1D Pong game** on an **ATmega328p microcontroller**, using:

- **10 LEDs** to represent the ball's position
- **1 button** to "hit" the ball back when it reaches the edge
- **1 potentiometer** to control ball speed
- **1 buzzer** for game feedback sounds
- **Sleep mode** to save power when idle

***

## ⚙️ How It Works

- LEDs simulate a ball "bouncing" left and right
- Player presses the button to reflect the ball when it reaches the end
- The potentiometer adjusts game speed
- Successful and failed button presses trigger different buzzer sounds
- The system enters sleep mode if idle for too long

***

## 🔌 Hardware Connections

- **LEDs**: PD0–PD7, PB0–PB1
- **Button**: PC0
- **Potentiometer**: PC1 (ADC)
- **Buzzer**: PB3

***

## 💻 Build & Flash Instructions

1. Run `make` to compile
2. Flash to the microcontroller with AVRDUDE:

```
avrdude -c <programmer> -p m328p -U flash:w:pong.hex:i
```

***

## 📁 File Structure

- `main.c`: Main game logic
- `led.c/h`: LED control
- `input.c/h`: Button and ADC handling
- `buzzer.c/h`: Buzzer tone generation
- `sleep.c/h`: Power-down sleep mode
- `timer.c/h`: Timer-based LED and button handling
- `Makefile`: Build script

***

