# Minimax-Based Tic Tac Toe Game in C++

## Project Description

This project is a command-line Tic Tac Toe game implemented in C++. It features two game modes:

- **Single Player vs AI**: The AI uses the Minimax algorithm to never lose.
- **Multiplayer**: Two human players compete against each other.

The game provides clear instructions, a dynamically updated board, and announces the winner or if it results in a tie.

## Table of Contents

1. [Features of the Game](#features-of-the-game)
2. [Minimax Algorithm Description](#minimax-algorithm-description)
3. [Minimax in Tic Tac Toe](#minimax-in-tic-tac-toe)
4. [Rules of Tic Tac Toe](#rules-of-tic-tac-toe)
5. [Project Setup](#project-setup)

## 1. Features of the Game

- **Game Modes**:
  - Single Player vs. AI (AI never loses due to the Minimax Algorithm).
  - Multiplayer mode for two human players.
- **User-Friendly Interface**: The game uses a clear 3x3 grid with numbered slots for easy input.

- **Optimal AI**: In single-player mode, the AI always makes the best possible move using the Minimax Algorithm.

- **Dynamic Board**: After every move, the board is re-rendered to show the current state.

- **Game Result**: The game announces the winner or declares a tie if there are no valid moves left.

## 2. Minimax Algorithm Description

The **Minimax Algorithm** is a recursive algorithm used in two-player games like Tic Tac Toe. It explores all possible moves and counter-moves to determine the best possible decision for the AI.

### Key Points:

- **Maximizer (AI)** tries to get the highest score (best possible outcome).
- **Minimizer (Player)** tries to reduce the score (worst possible outcome for the AI).

The algorithm evaluates every possible board state and chooses the optimal move based on whether it maximizes or minimizes the score. This ensures the AI never loses.

## 3. Minimax in Tic Tac Toe

In Tic Tac Toe, the AI uses the Minimax algorithm to simulate all possible moves for both itself and the player. The AI then chooses the move that maximizes its chance of winning (or minimizing the opponent's chances).

- **Best Move**: At every turn, the AI evaluates the available moves and picks the one with the highest score. If no move is winning, it chooses a move that will force a draw.

![Tic-Tac-Toe Game Tree](/minimax-tic-tac-toe.jpg)

## 4. Rules of Tic Tac Toe

1. The game is played on a 3x3 grid.
2. Players take turns placing their markers ('X' or 'O') on an empty spot.
3. A player wins by placing three of their markers in a row, column, or diagonal.
4. If all 9 spots are filled without a winner, the game ends in a draw.

## 5. Project Setup

### Requirements

- A C++ compiler.
- C++11 or later for vector and other standard features.

### Steps

1. Clone or download the source code from the repository.
2. Compile the project using your preferred C++ compiler:
   ```bash
   g++ tic_tac_toe.cpp -o tic_tac_toe
   ```
3. Run the executable

```bash
    ./tic_tac_toe
```

4. Play the Game
   - Select the game mode:
     - Option 1: Single Player (You vs AI)
     - Option 2: Multiplayer (Player vs Player)
   - Follow the on-screen prompts to place your marker on the board.

## Enjoy the game!

---
