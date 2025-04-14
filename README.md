**TIC TAC TOE GAME USING C PROGRAMMING LANGUAGE**

A simple graphical Tic Tac Toe game built using C and the GTK+3 library. This game allows two players to play Tic Tac Toe on a 3x3 grid with a user-friendly graphical interface.
Features
	•	Two-player mode.
	•	Interactive GUI with clickable buttons for each tile.
	•	Displays messages for:
	•	Player wins.
	•	Draws.
	•	Invalid moves (e.g., clicking on an already occupied tile).
	•	Automatically resets the board after a win or draw.
Prerequisites:
To run this program, ensure the following are installed on your system:
	1.	GTK+3 Development Libraries:
	•	Install via Homebrew (macOS):
 brew install gtk+3
  •	Install via apt (Linux):
sudo apt-get install libgtk-3-dev
	2.	C Compiler:
	•	GCC or Clang.
	3.	pkg-config:
	•	Install via Homebrew (macOS):
     brew install pkg-config
	•	Install via apt (Linux):
     sudo apt-get install pkg-config
**HOW TO COMPILE AND RUN**
*Step 1: Clone or Download the Code*
Clone this repository or download the `tictactoe.c` file to your local machine.
*Step 2: Compile the Code*
Use the following command to compile the code with `pkg-config` to link GTK+3 libraries:
  gcc $(pkg-config --cflags gtk+-3.0) -o tictactoe tictactoe.c $(pkg-config --libs gtk+-3.0)
*Step 3: Run the Program*
Run the compiled executable:
  ./tictactoe
How to Play
	1.	Launch the program by running `./tictactoe`.
	2.	A 3x3 grid will appear in a window.
	3.	Player 1 uses X, and Player 2 uses O.
	4.	Players take turns clicking on empty tiles to place their mark.
	5.	The game announces:
	•	A winner when one player gets three marks in a row, column, or diagonal.
	•	A draw when all tiles are filled without a winner.
	6.	After a win or draw, the board resets automatically.
Code Overview
Key Components
	•	GUI Setup:
	•	The game uses GTK widgets like `GtkWindow`, `GtkGrid`, and `GtkButton` to create the graphical interface.
	•	Game Logic:
	•	The game checks for wins and draws after each move using helper functions:
	•	`checkWin(char mark)`: Checks rows, columns, and diagonals for three consecutive marks.
	•	`checkDraw()`: Checks if all tiles are filled without a winner.
	•	Event Handling:
	•	Button clicks are handled by the `buttonClicked()` function, which updates the board state and checks for game outcomes.

 Dependencies
This program depends on the following libraries:
	•	GTK+3 (`gtk/gtk.h`)
	•	Standard C libraries (`stdio.h`, `stdlib.h`, `stdbool.h`, etc.)
Make sure these dependencies are installed before compiling.
Known Issues
	•	The board resets automatically after showing a win or draw message, which might not be ideal for some users who want to view the final state longer.
	•	The program does not support an AI opponent; it is strictly for two players.
Future Improvements
	•	Add support for single-player mode with an AI opponent.
	•	Allow users to configure grid size (e.g., 4x4 or 5x5 grids).
	•	Enhance UI design with custom themes or animations.
