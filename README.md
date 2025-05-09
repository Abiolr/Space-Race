
# 🚀 Atari ST Arcade Game – Spaceship vs. Asteroids

> A low-level, real-time 2D arcade game built in C for the Atari ST platform, demonstrating proficiency in hardware-level graphics rendering, sound synthesis using PSG, and double-buffered animation with custom game logic.

---

## 📌 Project Overview

This project is a fully interactive arcade-style game where the player pilots a spaceship through waves of horizontally moving asteroids. Designed for the Atari ST hardware, the game is implemented from the ground up in C, showcasing an understanding of system-level programming, graphics manipulation, and sound control.

It simulates a complete game loop: splash screen, player input, real-time rendering, collision detection, background music, and sound effects — all without using any game engines or external libraries.

---

## 🎮 Features

- **Spaceship navigation**: Move the spaceship up/down with real-time control.
- **Asteroid waves**: 33+ animated asteroids with varying positions and direction.
- **Collision detection**: Instant feedback and life reduction when crashing into asteroids.
- **Score & lives tracking**: HUD displays score and remaining lives as bitmap digits/hearts.
- **Double buffering**: Smooth rendering without flicker using front and back buffers.
- **Dynamic splash screen**: Rendered welcome screen using bitmap graphics.
- **Sound system**: PSG-driven background music and crash sound effects.

---

## 🧰 Tech Stack

| Category        | Technology        | Description                                                       |
|----------------|-------------------|-------------------------------------------------------------------|
| Platform        | Atari ST          | Real-mode computing with hardware memory-mapped I/O               |
| Language        | C                 | System-level logic, buffers, data manipulation                    |
| Graphics        | Raster Blitting   | Custom bitmap plotting (8-, 16-, 32-bit) to video memory          |
| Audio           | PSG (YM2149)      | Programmable Sound Generator via direct register manipulation     |
| Rendering       | Double Buffering  | Flicker-free screen updates by swapping front and back buffers    |

> Why it matters: This project builds core systems from scratch — graphics, sound, game loop — with no libraries. It's a real test of foundational programming ability.

---

## 🚀 Getting Started

### Prerequisites

You’ll need:
- An Atari ST emulator (e.g., [Hatari](https://hatari.tuxfamily.org/)) or actual Atari ST hardware
- A C compiler compatible with the Atari ST (e.g., Devpac, VBCC, or cross-compilation toolchains)

### File Structure

```bash
├── GAME.C           # Main game loop & system control
├── MODEL.C          # Game objects: spaceship, asteroids
├── EVENTS.C         # Input handling & collision logic
├── RENDER.C         # Sprite rendering to the screen
├── RASTER.C         # Bitmap plotting primitives
├── MUSIC.C          # Background music engine
├── EFFECTS.C        # Sound effects (e.g., crash)
├── PSG.C            # PSG sound driver (YM2149 chip)
├── BITMAP.H         # Sprite data (spaceship, asteroid, heart, digits)
├── RAST_ASM.H       # Video memory control (inline ASM interface)
```

### Compilation & Usage

1. Compile all `.C` files with your ST-compatible C compiler.
2. Link into a `.PRG` or `.TOS` file.
3. Load the executable on your Atari ST or through an emulator like Hatari.
4. **Controls:**
   - `W`: Move spaceship up
   - `S`: Move spaceship down
   - `ESC`: Exit game

---

## 📷 Demo Screenshots

> _(Replace with actual emulator screenshots if available)_

```
+-------------------+
|  SPACESHIP vs.    |
|     ASTEROIDS     |
|  SCORE:   ♥ ♥ ♥    |
+-------------------+
```

---

## ⚠️ Known Limitations

- Only vertical movement is allowed for the player.
- No level progression — difficulty remains static.
- PSG sound timing may vary across different emulator configurations.

---

## 🔭 Future Enhancements

- Add horizontally moving player or bullet shooting mechanics.
- Integrate a high score leaderboard using NVRAM or save files.
- Optimize for variable frame rates across Atari models.

---

## 👥 Authors

- **Patrick Dang**
- **Abiola Raji**

> Developed as part of COMP 2659: Computer Architecture & Systems Programming – Fall 2024

---

## 📝 License

This project is distributed under the MIT License. See `LICENSE` file for details if included.

---

## 🧠 Why This Project Stands Out

This game highlights:
- **Low-level programming skills** (memory, buffers, hardware registers)
- **Clean architecture** (modular C files for rendering, input, sound)
- **System design thinking** under constraints — no dynamic memory, no libraries

If you're a recruiter reviewing student portfolios, this demonstrates readiness for roles that require strong fundamentals in graphics, systems programming, or embedded software engineering.
