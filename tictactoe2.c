#include <gtk/gtk.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3 // Size of the Tic Tac Toe grid

// Global variables
char board[SIZE][SIZE];         // Logical board state
int currentPlayer = 1;          // Player 1 starts (1 = X, 2 = O)
GtkWidget *buttons[SIZE][SIZE]; // Buttons for the grid

// Function prototypes
void resetBoard();
void buttonClicked(GtkWidget *widget, gpointer data);
bool checkWin(char mark);
bool checkDraw();
void updateButtonLabel(GtkWidget *button, char mark);
void showMessage(const char *message);

// Main function
int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *grid;

    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tic Tac Toe");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a grid to hold buttons
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Initialize the board and create buttons
    resetBoard();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            buttons[i][j] = gtk_button_new_with_label(" ");
            gtk_widget_set_size_request(buttons[i][j], 100, 100);
            g_signal_connect(buttons[i][j], "clicked", G_CALLBACK(buttonClicked), GINT_TO_POINTER(i * SIZE + j));
            gtk_grid_attach(GTK_GRID(grid), buttons[i][j], j, i, 1, 1);
        }
    }

    // Show all widgets in the window
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}

// Reset the board to its initial state
void resetBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Handle button click events
void buttonClicked(GtkWidget *widget, gpointer data)
{
    int position = GPOINTER_TO_INT(data);
    int row = position / SIZE;
    int col = position % SIZE;

    if (board[row][col] != ' ')
    {
        showMessage("Invalid move! Tile already taken.");
        return;
    }

    char mark = (currentPlayer == 1) ? 'X' : 'O';
    board[row][col] = mark;
    updateButtonLabel(widget, mark);

    if (checkWin(mark))
    {
        char message[50];
        sprintf(message, "Player %d (%c) wins!", currentPlayer, mark);
        showMessage(message);
        resetBoard();
        return;
    }

    if (checkDraw())
    {
        showMessage("It's a draw!");
        resetBoard();
        return;
    }

    currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch player
}

// Check if the current player has won
bool checkWin(char mark)
{
    // Check rows and columns
    for (int i = 0; i < SIZE; i++)
    {
        if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) || // Row check
            (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark))
        { // Column check
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) || // Main diagonal
        (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark))
    { // Anti-diagonal
        return true;
    }

    return false;
}

// Check if the game is a draw
bool checkDraw()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

// Update the label of a button to reflect the player's move
void updateButtonLabel(GtkWidget *button, char mark)
{
    char label[2];
    sprintf(label, "%c", mark);
    gtk_button_set_label(GTK_BUTTON(button), label);
}

// Show a message in a dialog box and reset the game after dismissal
void showMessage(const char *message)
{
    GtkWidget *dialog;

    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_MODAL,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_OK,
                                    "%s", message);

    gtk_dialog_run(GTK_DIALOG(dialog));

    gtk_widget_destroy(dialog);

    // Reset the game after showing the message
}
