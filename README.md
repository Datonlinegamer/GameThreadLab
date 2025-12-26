# GameThreadLab

GameThreadLab

GameThreadLab is a C++ multithreading learning project focused on game development patterns.
It demonstrates how to separate a game thread from worker threads (AI) using standard C++ concurrency tools, following architecture patterns used in real game engines.

This project is intentionally minimal and engine agnostic, making it ideal for learning and experimentation.

<img width="1635" height="736" alt="image" src="https://github.com/user-attachments/assets/add4b2b3-44dc-4e76-9d06-7540c0b78544" />



🥅 Project Goals

Learn safe multithreading in C++

Model a game thread vs worker thread architecture

Avoid blocking the main game loop

Practice mutex discipline and thread lifetime management

Build foundations for future systems like job systems and async tasks

🧠 What This Project Simulates

Main Thread (Game Loop)

Reads AI decisions

Applies gameplay logic

Handles logging/output

Worker Thread (AI System)

Continuously computes enemy decisions

Writes results to shared data

Never performs rendering or logging

This mirrors how real engines (e.g. Unreal Engine) separate gameplay logic from background work.

🧩 Core Concepts Demonstrated

std::thread for worker execution

std::mutex for shared data protection

std::atomic<bool> for clean thread shutdown

Short, scoped locking (no long mutex holds)

Clear ownership between systems

🗂️ High-Level Structure

Enemy

Lightweight data structure (id, decision)

EnemyAI

Owns the enemy list

Runs the AI worker thread

Updates enemy decisions

main.cpp

Acts as the game loop

Reads AI results

Outputs game state

▶️ How It Works

The game creates several enemies

An AI worker thread starts running

The AI thread periodically updates enemy decisions

The main thread reads and uses those decisions each frame

The program shuts down cleanly by signaling the worker thread

All shared access is synchronized safely.

🛠️ Build Notes

Written in standard C++ (C++17+ recommended)

Uses only the C++ Standard Library

No engine or external dependencies

Tested with Visual Studio (Windows)

💡  Design Decisions

No logging from worker threads
Console I/O is slow and synchronized internally. In real engines, only the main thread handles logging.

Simple mutex-based synchronization
Chosen for clarity and correctness before introducing more advanced techniques.

📚 What I Learned

Through building GameThreadLab, I learned several core principles of multithreaded game development:

Thread roles must be clearly defined
The main (game) thread coordinates gameplay and presentation, while worker threads perform background computation only.

Never block the game loop
Expensive work like AI thinking must run off the main thread to keep frame timing stable.

Shared data must be protected intentionally
Using std::mutex with short, scoped locks prevents race conditions without stalling execution.

Thread lifetime management matters
Clean startup and shutdown using std::atomic<bool> avoids undefined behavior and dangling threads.

Worker threads should not handle logging or I/O
Console output is slow and internally synchronized; real engines centralize logging on the main thread.

Correctness comes before optimization
Building a simple, correct model first makes it easier to evolve toward job systems and lock-free designs.

These lessons mirror real-world engine patterns and form the foundation for advanced systems like job schedulers, async tasks, and parallel gameplay systems.

🚀 Possible Next Steps

This project is designed to grow. Potential extensions include:

Double-buffered AI results (remove mutex from game loop)

Job system / thread pool

Lock-free queues

Command buffers (AI → game thread)

Unreal-style async task architecture

🤷🏾‍♀️ Why This Exists

Multithreading bugs are some of the hardest to diagnose in game development.
GameThreadLab focuses on correct mental models first, before optimization or complexity.

If you understand this project, you understand the core of real-world game threading.

👩🏾‍💻 Author

Built as a hands on learning project for understanding C++ multithreading in a game development context.
