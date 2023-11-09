# Game Of Life

An implementation of John Conway's Game of Life in C++ using SDL2 for rendering.

## Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [Usage](#usage)
4. [Dependencies](#dependencies)
5. [Future Development](#future-development)
6. [SDL2 Installation](#sdl2-installation)
    - [Windows](#windows)
    - [macOS](#macos)
    - [Linux (Ubuntu/Debian)](#linux-ubuntudebian)
    - [Other Linux Distributions](#other-linux-distributions)
8. [License](#license)

## Overview

The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine.  

The game works on the following simple rules :- 
- Any live cell with two or three live neighbours survives.
- Any dead cell with three live neighbours becomes a live cell- .
- All other live cells die in the next generation. Similarly-ll other dead cells stay dead.
 
## Features

- Random generation of initial patterns.
- Visualization of each generation using SDL2.
- Customizable screen dimensions (SCREEN_HEIGHT and SCREEN_WIDTH constants in the code).

## Usage

1. Clone the repository:
```bash
git clone https://github.com/your-username/GameOfLife.git
```
2. Compile the code using your preferred C++ compiler.
```bash
g++ -std=c++20 <your-file-name>.cpp -o <your-output-file> -lSDL2  
```
3. Run the executable.
```bash
./<your-output-file>
```

## Dependencies
SDL2: Simple DirectMedia Layer is a cross-platform development library designed to provide low-level access to audio, keyboard, mouse, and display.

## Future Development
- Optimize code for better cache utilization.
- Implement a terminal version of the Game of Life.

## SDL2-Installation

To install SDL2, you'll need to follow platform-specific instructions, as the installation process can vary depending on your operating system. Here are instructions for common platforms:

### Windows

1. **Download SDL2 Development Libraries:**
   - Go to the SDL2 download page: [https://www.libsdl.org/download-2.0.php](https://www.libsdl.org/download-2.0.php).
   - Under "Development Libraries," download the "Visual C++" version (e.g., `SDL2-devel-2.x.x-VC.zip`).
   - Extract the contents of the downloaded ZIP file to a location on your computer.

2. **Set Up Visual Studio (If Using Visual Studio):**
   - If you're using Visual Studio, create a new C++ project.
   - Go to "Project Properties" > "Configuration Properties" > "VC++ Directories."
   - Add the path to the `include` directory inside the extracted SDL2 folder to "Include Directories."
   - Add the path to the `lib` directory inside the extracted SDL2 folder to "Library Directories."

3. **Link SDL2 Library:**
   - Under "Configuration Properties" > "VC++ Directories," add `SDL2.lib` and `SDL2main.lib` to "Additional Dependencies" under "Linker" > "Input."

4. **Copy SDL2.dll:**
   - From the extracted SDL2 folder, copy `SDL2.dll` to your project's executable directory (where your `.exe` file is located).

### macOS

1. **Using Homebrew (Recommended):**
   - Open Terminal.
   - Install Homebrew if you haven't already: [https://brew.sh/](https://brew.sh/)
   - Run the following command to install SDL2:

     ```bash
     brew install sdl2
     ```

2. **Using MacPorts (Alternative):**
   - Open Terminal.
   - Install MacPorts if you haven't already: [https://www.macports.org/install.php](https://www.macports.org/install.php)
   - Run the following command to install SDL2:

     ```bash
     sudo port install libsdl2
     ```

### Linux (Ubuntu/Debian)

1. **Using APT:**
   - Open Terminal.
   - Update your package list:

     ```bash
     sudo apt-get update
     ```

   - Install SDL2 development libraries:

     ```bash
     sudo apt-get install libsdl2-dev
     ```

2. **Using Snap (Alternative):**
   - Open Terminal.
   - Install SDL2 via Snap:

     ```bash
     sudo snap install sdl2
     ```

### Other Linux Distributions

You can typically install SDL2 via your distribution's package manager. Use the appropriate package manager and search for the SDL2 development libraries.

After installing SDL2, you can compile and run your SDL2-based C++ programs by including the appropriate SDL2 headers and linking against the SDL2 library during compilation.

## License

This project is licensed under the MIT License.
