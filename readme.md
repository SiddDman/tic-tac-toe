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

## Features of the Game

- **Game Modes**:
  - Single Player vs. AI (AI never loses due to the Minimax Algorithm).
  - Multiplayer mode for two human players.
- **User-Friendly Interface**: The game uses a clear 3x3 grid with numbered slots for easy input.

- **Optimal AI**: In single-player mode, the AI always makes the best possible move using the Minimax Algorithm.

- **Dynamic Board**: After every move, the board is re-rendered to show the current state.

- **Game Result**: The game announces the winner or declares a tie if there are no valid moves left.

## Minimax Algorithm Description

The **Minimax Algorithm** is a recursive algorithm used in two-player games like Tic Tac Toe. It explores all possible moves and counter-moves to determine the best possible decision for the AI.

### Key Points:

- **Maximizer (AI)** tries to get the highest score (best possible outcome).
- **Minimizer (Player)** tries to reduce the score (worst possible outcome for the AI).

The algorithm evaluates every possible board state and chooses the optimal move based on whether it maximizes or minimizes the score. This ensures the AI never loses.

## Minimax in Tic Tac Toe

In Tic Tac Toe, the AI uses the Minimax algorithm to simulate all possible moves for both itself and the player. The AI then chooses the move that maximizes its chance of winning (or minimizing the opponent's chances).

- **Best Move**: At every turn, the AI evaluates the available moves and picks the one with the highest score. If no move is winning, it chooses a move that will force a draw.

### Example Scenario

Consider a Tic Tac Toe game where X (the AI) is trying to win:

- **Level 1 (AI's Move)**: X has three possible moves and is trying to find the one that maximizes its chance of winning.
  
- **Level 2 (Opponent's Move)**: 
    - The first move for X leads to an immediate win, so the value of this move is 100 points.
    - The second and third moves lead to more possibilities where it's O’s turn to play, trying to minimize the score.

- **Level 3 (Minimizing Opponent)**:
    - O is now trying to minimize the score. O chooses the move that either leads to a win for O or a draw.
    - The first move for O results in a win for O, which is valued at -100 points.
    - The second move for O results in a draw, valued at 0 points.
    - Thus, the parent nodes for these branches will have values of -100 and 0 respectively.

- **Back to Level 1**:
    - X now has to choose between the following options: 100 (a win), -100 (a loss), and 0 (a draw).
    - Since X is trying to maximize the score, it will choose the branch with 100 points, ensuring a win.

![Tic-Tac-Toe Game Tree](/minimax-tic-tac-toe.jpg)
### Depth Calculations in Minimax

The depth of the tree is determined by how far the game progresses. Each recursive call to Minimax evaluates a potential future board state.

- For Tic Tac Toe, a full game can have at most 9 moves, resulting in a depth of 9 in the decision tree. The AI evaluates all possible moves for X and O down to this depth, pruning paths that don't maximize its outcome.

- For a maximizing player (AI), it's preferable to win as quickly as possible. To achieve this, we subtract the depth from the score when the AI wins. This means that a faster win (lower depth) will yield a higher score.

  - Example:
    - If the AI wins in 2 moves, it receives a score of `10 - 2 = 8`.
    - If the AI wins in 4 moves, it receives a score of `10 - 4 = 6`.

- For a minimizing player (human), it's preferable to delay a loss as much as possible. To reflect this, we add the depth to the score when the player wins. A longer path to a loss (higher depth) will reduce the impact of the AI's loss.

  - Example:
    - If the human wins in 3 moves, the score for the AI is `-10 + 3 = -7`.
    - If the human wins in 5 moves, the score for the AI is `-10 + 5 = -5`.
      This depth-based adjustment ensures that the AI favors quicker victories and longer defenses, making it a more efficient and intelligent opponent.


## Rules of Tic Tac Toe

1. The game is played on a 3x3 grid.
2. Players take turns placing their markers ('X' or 'O') on an empty spot.
3. A player wins by placing three of their markers in a row, column, or diagonal.
4. If all 9 spots are filled without a winner, the game ends in a draw.

## Project Setup

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
