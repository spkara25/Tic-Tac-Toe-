# Tic Tac Toe Game using GTK in C

This project is a simple implementation of the classic **Tic Tac Toe** game using the **GTK+3** library in the C programming language. It features a graphical 3x3 grid where two players can play alternately as 'X' and 'O'.

## 🧠 Features

- Graphical interface using GTK
- 3x3 Tic Tac Toe board
- Player vs Player gameplay
- Win and draw detection
- Interactive buttons with game messages

## 🛠 Requirements

To compile and run this project, you need:

- **GTK+3** development libraries installed  
  On Ubuntu/Debian-based systems:
  ```bash
  sudo apt-get install libgtk-3-dev
  ```

- A C compiler such as `gcc`

## 📦 Compilation

Use the following command to compile the program:

```bash
gcc tic_tac_toe.c -o tic_tac_toe `pkg-config --cflags --libs gtk+-3.0`
```

> Make sure to replace `tic_tac_toe.c` with your actual filename if different.

## ▶️ Running the Game

After compiling, run the executable:
    ./tic_tac_toe

A window will pop up with a 3x3 grid. Click a cell to make your move. The game will automatically detect wins or draws and display appropriate messages.

## 📋 Code Structure

- **main()**: Initializes the GTK app, creates the window and grid layout.
- **resetBoard()**: Initializes or clears the board.
- **buttonClicked()**: Handles user input and updates the game state.
- **checkWin()**: Checks if a player has won.
- **checkDraw()**: Checks if the game is a draw.
- **updateButtonLabel()**: Updates the button text with the player's move.
- **showMessage()**: Displays a popup message (e.g., win/draw).

## 🖥️ Screen Shots of the Implementation
<img width="299" alt="Screenshot 2025-04-14 at 10 34 04" src="https://github.com/user-attachments/assets/d1243560-16be-441e-b567-808bd39ef878" />

<img width="302" alt="Screenshot 2025-04-14 at 10 34 47" src="https://github.com/user-attachments/assets/ceff4506-5922-4b7b-a41d-e2ffd691f064" />

## 💡 Future Enhancements

- Add a restart button
- Implement AI for single-player mode
- Highlight winning line
- Keep score of rounds
---

## 🧑‍💻 Author

Shreeja Karajagi 

---
