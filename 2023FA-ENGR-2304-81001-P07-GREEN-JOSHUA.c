// 2023FA-ENGR-2304-81001-GREEN-JOSHUA-P07
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define EMPTY '_'
#define PLAYER1 'X'
#define PLAYER2 'O'

char board[3][3];

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void displayBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool makeMove(char symbol, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
        board[row][col] = symbol;
        return true;
    }
    return false;
}

void playerMove(char playerSymbol) {
    int row, col;
    bool validMove = false;
    while (!validMove) {
        printf("Player %c, enter row and column (0-2): ", playerSymbol);
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input. Please enter numbers only.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        validMove = makeMove(playerSymbol, row, col);
        if (!validMove) {
            printf("Invalid move, try again.\n");
        }
    }
}

void aiMove(char aiSymbol) {
    srand(time(NULL)); // Seed for random number generation
    int row, col;
    bool validMove = false;
    while (!validMove) {
        row = rand() % 3;
        col = rand() % 3;
        validMove = makeMove(aiSymbol, row, col);
    }
}

int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return board[i][0] == PLAYER1 ? 1 : 2;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
            return board[0][i] == PLAYER1 ? 1 : 2;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0] == PLAYER1 ? 1 : 2;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return board[0][2] == PLAYER1 ? 1 : 2;

    return 0; // No winner
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == EMPTY)
                return false;
    return true; // It's a draw if we reach here
}

int getNumberOfPlayers() {
    int numPlayers;
    printf("Enter number of players (1 or 2): ");
    scanf("%d", &numPlayers);
    return numPlayers;
}

char getSymbolChoice() {
    char symbol;
    printf("Choose your symbol (X/O): ");
    scanf(" %c", &symbol); // The space before %c ignores any whitespace characters
    while (getchar() != '\n'); // Consume the newline character
    return (symbol == 'X' || symbol == 'x') ? PLAYER1 : PLAYER2;
}

void delay(int seconds) {
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main() {
    int numPlayers = getNumberOfPlayers();
    char playerSymbol = getSymbolChoice();
    char aiSymbol = (playerSymbol == PLAYER1) ? PLAYER2 : PLAYER1;

    srand(time(NULL));
    char currentPlayer = (rand() % 2) == 0 ? PLAYER1 : PLAYER2;
    bool gameEnded = false;

    initializeBoard();

    while (!gameEnded) {
        displayBoard();

        if (numPlayers == 1 && currentPlayer == aiSymbol) {
            delay(2); // AI move delay
            aiMove(aiSymbol);
        } else {
            playerMove(currentPlayer == PLAYER1 ? playerSymbol : aiSymbol);
        }

        int winStatus = checkWin();
        if (winStatus != 0 || isDraw()) {
            displayBoard();
            if (winStatus != 0) {
                printf("Player %c wins!\n", winStatus == 1 ? playerSymbol : aiSymbol);
            } else {
                printf("It's a draw!\n");
            }

            printf("Play again? (1 for yes, 0 for no): ");
            int playAgain;
            scanf("%d", &playAgain);
            if (playAgain) {
                initializeBoard();
                currentPlayer = (rand() % 2) == 0 ? PLAYER1 : PLAYER2;
                gameEnded = false;
            } else {
                gameEnded = true;
            }
        } else {
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
        }
    }

    return 0;
}
