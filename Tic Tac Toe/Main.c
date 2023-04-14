#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define board
char board[3][3];

// function declarations
void initBoard();
void printBoard();
void getInput();
void computerMove();
int checkWin(char mark);
int startGame();

// game loop here.
int main() {
	printf("Welcome to Tic-Tac-Toe!\nPress Y, then ENTER to play, or press ENTER to Quit. ");
	char input = ' ';
	scanf_s("%c", &input);
	printf("Entered %c", input);
	while (input == 'y') {
		startGame();
	}

	return 0;
}

int startGame() {
	srand(time(NULL)); // set random seed
	initBoard();
	int i = 0;
	char mark = 'O';
	do {
		printBoard();
		mark = (mark == 'X') ? 'O' : 'X';

		switch (mark) {
		case 'X':
			getInput();
			break;
		case 'O':
			computerMove();
			break;
		}

		i = checkWin(mark);

	} while (i == 0);

	printBoard();

	if (i == 1) {
		switch (mark) {
		case 'X':
			printf("\nYou won!");
			break;
		case 'O':
			printf("\nYou lose!");
			break;
		}
	}
	else {
		printf("\nThe game is a draw.");
	}
}

// initialize board cells as empty
void initBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

// print the contents of the board to the console
void printBoard() {
	printf("\n-------------\n");
	for (int i = 0; i < 3; i++) {
		printf("| ");
		for (int j = 0; j < 3; j++) {
			printf("%c | ", board[i][j]);
		}
		printf("\n-------------\n");
	}
}

// get user input, validates it, then modifies the board
void getInput() {
	int row, col;
	while (1) {
		printf("\nEnter a row (1-3): ");
		scanf_s("%d", &row);
		printf("\nEnter a column (1-3): ");
		scanf_s("%d", &col);
		if (row < 1 || row > 3 || col < 1 || col > 3) {
			printf("\nInvalid input. Row and column must be between 1 and 3.\n");
			continue;
		}
		if (board[row - 1][col - 1] != ' ') {
			printf("\nThat space is already taken!\n");
			continue;
		}
		break;
	}
	board[row - 1][col - 1] = 'X';
}

// computer randomly chooses a coordinate
void computerMove() {
	printf("\nComputer's turn:\n");
	int row, col;
	while (1) {
		row = (rand() % 3);
		col = (rand() % 3);

		if (board[row][col] != ' ') {
			continue;
		}
		break;
	}
	board[row][col] = 'O';
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				return;
			}
		}
	}
	printf("The game is a draw!");
}

// win condition checking
int checkWin(char mark) {
	int i;
	// Check for a winning row
	for (i = 0; i < 3; i++) {
		if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) {
			return 1;
		}
	}
	// Check for a winning column
	for (i = 0; i < 3; i++) {
		if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) {
			return 1;
		}
	}
	// Check for a winning diagonal
	if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
		return 1;
	}
	if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
		return 1;
	}
	return 0;  // No winner yet
}

