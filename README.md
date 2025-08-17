# 🎮 Dodge 'Em Game

## 📖 Introduction

Take a nostalgic journey back to the golden era of gaming with **Dodge 'Em**, the classic game developed by Carla Meninsky in 1980. Experience the thrill of maneuvering a brown car through a maze of blue opponent cars while collecting rewards and avoiding collisions. Simple yet addictive, *Dodge 'Em* has stood the test of time.

---

## 🏎️ Game Overview

Dodge 'Em is set in a racing arena where players control a **brown car**, aiming to:

* Collect rewards 🎁
* Avoid head-on collisions with **blue opponent cars** 🚙

The game unfolds on a single screen with concentric roadways, adding twists and turns for an extra challenge.


---

## 🆚 Player vs Opponent

* **Player’s Car** → Moves **anti-clockwise**
* **Opponent Cars** → Move **clockwise**
* **Lives** → Lost upon collision
* **Goal** → Collect rectangular gift-boxes to earn reward points

---

## 🚦 Driving Rules

* Each roadway has **four turns**
* Player starts from the **middle of the topmost roadway**
* **Controls:**

  * Arrow keys → Movement
  * Spacebar → Double speed ⚡
* Opponent cars turn strategically based on distance from the player

---

## 📈 Game Levels

Dodge 'Em features progressive difficulty:

1. **Level 1** → Opponent cars take only **top and bottom turns**
2. **Level 2** → Opponent cars can take **any turn**
3. **Level 3** → Opponent cars move at **increased speed**
4. **Level 4** → **Two opponent cars** chase the player

🎉 Completing Level 4 → Displays *"You won!"*

---

## 🏆 High Scores

* Scores stored in **`highscores.txt`**
* **Top 10 scores** displayed
* New high scores overwrite the lowest score in the list

---

## 📋 Menu Options

* Start a new game
* View high scores
* Help
* Exit

During gameplay, press **`P`** to pause and access:

* Continue
* Start new game
* High scores
* Help
* Exit

---

## 🎮 Gameplay Mechanics

Core mechanics include:

* **Skillful navigation** & strategic dodging
* **Collision Detection** → Losing lives upon collision
* **Scoring System** → Collecting items for points
* **Level Progression** → Each level increases speed and challenge
* **Speed Control** → Adjust car speed for strategy

---

## ⚙️ Setting Up the Game

This project is written in **C++** with simple functions:

* **Board Initialization** → Sets up racetrack
* **Player Car Movement** → Controlled with `_kbhit()` & `_getch()`
* **Opponent Cars** → Predefined but dynamic movement
* **Scoring System** → Collect rewards to advance

### Personal Features

* Dynamic road changes for opponents
* Random starting positions
* ASCII art for cars & roads

---

## 🏁 Conclusion

**Dodge 'Em** is a tribute to classic arcade fun—fast, simple, and endlessly engaging. Its timeless design still entertains gamers today.

✨ Get ready to **dodge, maneuver, and win!** 🚗💨
