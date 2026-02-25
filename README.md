# DSA mini project on: Snake Game (C++ & Raylib)

A simple 2d Snake Game built using C++ and Raylib.  
Control the snake, eat food to grow, and avoid collisions with walls and yourself.

---

## Technologies Used

- Language: C++
- Graphics Library: Raylib
- Audio: Raylib Audio Module
- Compiler: g++

---

## Features

- Grid-based snake movement
- Random food generation
- Score tracking
- Sound effects
- Collision detection (wall)

---

## DSA Concepts Used

- Deque (std::deque) to store and manage the snake body  
- push_front() and pop_back() operations (O(1) insertion and deletion)  
- Linear Search for self-collision detection  
- Boundary Checking (collision with walls)  
- Random Position Generation for food spawning  
- 2D Grid-Based Movement using coordinate system  
- Vector Addition for updating snake position  
- Game Loop Algorithm (Input → Update → Render cycle)

---

## Game Logic Flow

1. Game starts.
2. Snake moves every 0.2 seconds.
3. If snake eats food:
   - Score increases
   - Snake grows
   - Sound plays
4. If snake hits wall or itself:
   - Game resets
   - Score becomes 0
     
---

## Future Improvements

- Add Start Screen
- Add Game Over Screen
- Add High Score System
- Add Difficulty Levels
- Add Pause Feature
- Add Background Music
  
---
## Game demo

![Snake game demo](demo.gif)

---
## Conclusion

This project demonstrates:

- Use of Deque data structure
- Basic DSA concepts
- Object-Oriented Programming
- Real-time game development using Raylib
- Collision detection logic
- Audio integration

A beginner-friendly graphics and DSA mini project. 

## project by:
kunal panjiyar.
