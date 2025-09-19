# Simple LCD Screen Game — AVR ATmega32

A fun and interactive old-school game played on a 16x2 LCD where players block a moving ball by pressing buttons. The game uses custom patterns drawn in the CGRAM of the LCD.

---

## 🎮 Game Description

- ⚽ By default, both players miss the ball — but pressing the button lets them try to block it!
- ✅ Each successful block is detected and the score is updated accordingly.
- ✅ Points are added to the player's score for every successful block.
- 💡 When a goal is scored:
  - A yellow LED lights up.
  - The winner sees a happy emoji on the LCD.
  - The loser sees a sad emoji 😄😢.

---

## 🛠 Technologies & Tools Used

- **Microcontroller:** ATmega32 (AVR)
- **Display:** 16x2 LCD
- **Programming Language:** C (AVR-GCC)
- **Simulation:** Proteus
- **Drivers Developed:**
  - HAL layer for LCD
  - MCAL layer for Digital Input/Output (DIO)

---

## 🔗 Watch Demo Video

[![Watch the Demo](https://media-exp1.licdn.com/dms/image/C4E22AQF42dBcaV8sUw/feedshare-shrink_800/0/1689372514833?e=2147483647&v=beta&t=96qogOPHVd7XDY65dA4IooYT1jS5SMIL8rFT2psFvqI)](https://www.linkedin.com/posts/ahmed-ellmallah-86883b341_embeddedsystems-avr-cprogramming-activity-7351372546497269760-F-P7)

_Click the image above to watch the LinkedIn video demo._

---

## 📚 Key Concepts Practiced

- Writing custom characters using LCD CGRAM.
- Button debouncing and input handling.
- Score calculation and display management.
- Hardware interaction using HAL and MCAL drivers.
- Embedded C programming and simulation using Proteus.

---

⭐ If you enjoy this project, please give it a ⭐!

---

_Last updated: September 2025_
