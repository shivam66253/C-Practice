#include <stdio.h>

// Function prototypes
void printBoard(char board[3][3]);
int checkWin(char board[3][3]);
int isFull(char board[3][3]);

int main() {
    char board[3][3] = { {'1','2','3'},
                         {'4','5','6'},
                         {'7','8','9'} };
    int choice, row, col;
    char turn = 'X';
    int win = 0;

    printf("🎮 Welcome to Tic Tac Toe!\n");
    printf("Player 1: X\nPlayer 2: O\n\n");

    while (1) {
        printBoard(board);
        printf("Player %c, enter your move (1-9): ", turn);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("❌ Invalid move! Try again.\n");
            continue;
        }

        // Convert choice to board coordinates
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if the cell is already taken
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("⚠️ Cell already taken! Try again.\n");
            continue;
        }

        board[row][col] = turn;

        // Check for win
        win = checkWin(board);
        if (win) {
            printBoard(board);
            printf("🎉 Player %c wins!\n", turn);
            break;
        }

        // Check for draw
        if (isFull(board)) {
            printBoard(board);
            printf("🤝 It's a draw!\n");
            break;
        }

        // Switch turns
        turn = (turn == 'X') ? 'O' : 'X';
    }

    return 0;
}

// Function to print the board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
            printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// Function to check win conditions
int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return 1;
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return 1;

    return 0;
}

// Function to check if the board is full
int isFull(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}
