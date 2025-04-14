#include <stdio.h>
#include <stdbool.h>

#define SIZE 3 // Size of the Tic Tac Toe grid

// Function prototypes
void displayBoard(char board[SIZE][SIZE]);
bool checkWin(char board[SIZE][SIZE], char mark);
bool checkDraw(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], int player);

int main()
{
    char board[SIZE][SIZE] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}}; // Initial board with numbered positions

    int currentPlayer = 1; // Player 1 starts
    char mark;             // Mark ('X' or 'O')

    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X | Player 2: O\n\n");

    while (true)
    {
        // Display the current state of the board
        displayBoard(board);

        // Assign mark based on the current player
        mark = (currentPlayer == 1) ? 'X' : 'O';

        // Allow the current player to make a move
        makeMove(board, currentPlayer);

        // Check if the current player has won
        if (checkWin(board, mark))
        {
            displayBoard(board);
            printf("Player %d (%c) wins!\n", currentPlayer, mark);
            break;
        }

        // Check if the game is a draw
        if (checkDraw(board))
        {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        // Switch to the next player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}

// Function to display the Tic Tac Toe board
void displayBoard(char board[SIZE][SIZE])
{
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1)
                printf("|"); // Print vertical separator
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("---|---|---\n"); // Print horizontal separator
    }
    printf("\n");
}

// Function to check if a player has won
bool checkWin(char board[SIZE][SIZE], char mark)
{
    // Check rows and columns
    for (int i = 0; i < SIZE; i++)
    {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) || // Row check
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark))   // Column check
            return true;
    }

    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) || // Main diagonal
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))   // Anti-diagonal
        return true;

    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O') // If any cell is unmarked, not a draw
                return false;
        }
    }
    return true;
}

// Function to handle a player's move
void makeMove(char board[SIZE][SIZE], int player)
{
    int position;
    char mark = (player == 1) ? 'X' : 'O';

    while (true)
    {
        printf("Player %d (%c), enter your move (1-9): ", player, mark);
        scanf("%d", &position);

        if (position < 1 || position > 9)
        {
            printf("Invalid position! Please choose a number between 1 and 9.\n");
            continue;
        }

        int row = (position - 1) / SIZE;
        int col = (position - 1) % SIZE;

        if (board[row][col] != 'X' && board[row][col] != 'O')
        { // Check if cell is empty
            board[row][col] = mark;
            break;
        }
        else
        {
            printf("Position already taken! Please choose another.\n");
        }
    }
}
