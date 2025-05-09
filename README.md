
# 🚀 Space Race – Atari ST Arcade Game

> A low-level, real-time 2D arcade game built in C for the Atari ST platform, demonstrating hardware-level programming with sprite rendering, audio effects, and double-buffered animation. Navigate a spaceship through asteroid fields and survive as long as possible!

---

## 📌 Project Overview

**Space Race** is a top-down arcade game where the player pilots a spaceship vertically through a looping asteroid field. Inspired by classic arcade mechanics, the goal is to reach the top of the screen without colliding with obstacles to score points. The game features:

- Real-time sprite movement and collisions
- Three-life system with score tracking
- PSG-controlled sound effects and background music
- Clean rendering using double buffering
- A planned split-screen 2-player competitive mode

---

## 🎮 Features

- **1-Player Mode**
  - Navigate vertically using `W` (up) and `S` (down)
  - 33 asteroids move horizontally from both screen edges
  - Score a point upon reaching the top, resetting your position
  - Colliding with an asteroid costs a life and triggers a 2-second cooldown
  - Game ends when all 3 lives are lost

- **HUD & Feedback**
  - Score displayed using bitmap digits (max 999)
  - Lives shown as hearts in the top-right
  - Game Over screen with final score
  - Crash sound and ominous background track

- **Bonus (Planned) Features**
  - 2-Player split-screen competitive mode
  - Spaceship propulsion animation
  - Low-life warning banner

---

## 🧰 Tech Stack

| Category        | Technology        | Description                                                       |
|----------------|-------------------|-------------------------------------------------------------------|
| Platform        | Atari ST          | Real-mode computing with memory-mapped I/O                        |
| Language        | C                 | System-level game logic and memory control                        |
| Graphics        | Raster            | Manual bitmap rendering with double buffering                     |
| Audio           | PSG (YM2149)      | Direct register manipulation for music and effects                |

---

## Controls

```bash
  - W: Move Up
  - S: Move Down
  - ENTER: Start Game (on splash)
  - ESC: Exit Game
```

---

## 🕹️ Game Mechanics

- **Spaceship**: 32x32 pixels, moves 10px per tick along the Y-axis
- **Asteroids**: 8x8 pixels, move horizontally at 2px/tick, loop after exiting screen
- **Scoring**: 1 point per top-edge reach, resets position after each point
- **Lives**: Lose 1 life per collision, max 3, ends game on 0
- **Cooldown**: 2-second pause after crash (spaceship disabled)

---

## 📷 Demo

<img width="1103" alt="Screenshot 2025-05-08 at 7 55 44 PM" src="https://github.com/user-attachments/assets/88b98bf3-d7c6-4798-aa53-a4589805adc0" />

---

## ⚠️ Known Limitations

- No horizontal movement or projectile support
- No save system (score resets on power-off)
- 2-player mode and animations not implemented

---

## 👥 Authors

- **Abiola Raji**
- **Patrick Dang**

Project submitted for **COMP 2659 – Computing Machinery II (Fall 2024)**  

---

## 🧠 Why This Project Matters

Space Race showcases the core competencies of a systems-oriented developer:

- Understanding of embedded audio and video memory
- Strong debugging across direct memory manipulation
- Design of a full game loop and real-time event system from scratch

Ideal for showcasing foundational skills in embedded systems, game dev, and low-level graphics/audio programming.

---
