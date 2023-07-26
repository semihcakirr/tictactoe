#include <stdio.h>
#include <stdlib.h>
// Declaring the board.
char board[3][3];

// Function to display the tic-tac-toe board
void display_board()
{
    printf("\n");
    // Looping through each row and column of the board and printing its contents.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if there is a winner.
char check_winner(char winner)
{
    // Setting the default value of the winner as NULL character.
    winner = '\0';

    // Check each row to see if all three spots have the same player marker. (X or O)
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
        {
            winner = board[i][0];
        }
    }

    // Check each column to see if all three spots have the same player marker (X or O)
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '-')
        {
            winner = board[0][j];
        }
    }

    // Check the two diagonals to see if all three spots have the same player marker (X or O)
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
    {
        winner = board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
    {
        winner = board[0][2];
    }
    // Return the winner's marker (if any)
    return winner;
}

// Function to get a player's move
void get_move(char player, int *row, int *col)
{
    printf("Player %c (X/O), enter your move (row col): ", player);
    scanf("%d %d", row, col);
}

// Function to check players move's validity.
int validate_move(int row, int col)
{
    if (row < 0 || row >= 3 || col < 0 || col >= 3)
    {
        printf("Invalid move. Please enter row and column values between 0 and %d.\n", 2);
        return 0;
    }
    if (board[row][col] != '-')
    {
        printf("Invalid move. That spot is already taken.\n");
        return 0;
    }
    return 1;
}

// Function to update the board with a player's move.
void update_board(char player, int row, int col)
{
    board[row][col] = player;
}

// Function to reset the board
void reset_board()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '-';
        }
    }
}

int main()
{
    char player = 'X';
    int row, col;
    int winner_found = 0;
    int play_again = 0;
    char winner;
    // Loop to play multiple games.
    do
    {
        reset_board();
        // Loop for a single game.
        do
        {
            // Display the board.
            display_board();
            // Get the player's move.
            get_move(player, &row, &col);
            // Check the move.
            while (!validate_move(row, col))
            {
                get_move(player, &row, &col);
            }
            // Update the board with the player's move.
            update_board(player, row, col);
            // Check if there is a winner.
            winner = check_winner(winner);
            if (winner != '\0')
            {
                display_board();
                printf("Player %c wins!\n", winner);
                winner_found = 1;
                break;
            }
            // Check if it's a draw.
            if (board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-' &&
                board[1][0] != '-' && board[1][1] != '-' && board[1][2] != '-' &&
                board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-')
            {
                display_board();
                printf("It's a draw!\n");
                break;
            }
            // Switch players.
            player = player == 'X' ? 'O' : 'X';
        } while (!winner_found);

        // Reset the flag for a new game.
        winner_found = 0;
        // Ask if the players want to play again.
        printf("Do you want to play again? (1 for yes, 0 for no): ");
        scanf("%d", &play_again);
    } while (play_again);

    return 0;
}