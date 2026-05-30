# 🧠 Math Quiz Game (C++ Console Application)

A simple interactive console-based quiz game written in C++.  
The game generates random math questions based on selected difficulty and operation type, and evaluates the player's performance.

---

## 📌 Features

- Choose number of questions (1–10)
- Select difficulty level:
  - Easy (1–10)
  - Medium (11–100)
  - Hard (101–1000)
  - Mixed
- Select operation type:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
  - Mixed operations
- Random question generation
- Instant feedback (correct / wrong answers)
- Final result summary (Pass / Fail)
- Option to replay the game
- Console color feedback:
  - Green = correct answer
  - Red = wrong answer

---

## 🧩 How It Works

1. The user selects:
   - Number of questions
   - Difficulty level
   - Operation type
2. The program generates random math questions
3. User answers each question
4. The system checks answers and tracks:
   - Correct answers
   - Wrong answers
5. At the end, a final result screen is displayed showing:
   - Score
   - Pass/Fail status

---

## 🛠️ Technologies Used

- C++
- iostream (input/output)
- cstdlib (random numbers)
- ctime (seeding randomness)
- Windows console commands (color + clear screen)

---

## ▶️ How to Run

### Compile (G++ example):
```bash
g++ main.cpp -o quiz
