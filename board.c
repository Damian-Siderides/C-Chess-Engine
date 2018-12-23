#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char board[8][8];

void printBoard();
void initBoard();

void initBoard() {
	for (int i = 0; i < 8; i++) {
		board[1][i] = 'P';
		board[6][i] = 'p';
	}
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = ' ';
		}
	}

	board[0][0] = 'R';
	board[0][7] = 'R';

	board[7][0] = 'r';
	board[7][7] = 'r';

	board[0][1] = 'N';
	board[0][6] = 'N';

	board[7][1] = 'n';
	board[7][6] = 'n';

	board[0][2] = 'B';
	board[0][5] = 'B';

	board[7][2] = 'b';
	board[7][5] = 'b';

	board[0][3] = 'Q';
	board[0][4] = 'K';

	board[7][3] = 'q';
	board[7][4] = 'k';
}

void printBoard() {
	printf("\n\n");
	printf("  ");
	
	for (int i = 0 ; i < 8; i++) {
		printf("_");
		printf(" ");
	}
	
	printf("\n");
	
	for (int i = 0; i < 8; i++) {
		printf("%d", i + 1);
		
		for (int j = 0; j < 8; j++) {
			printf("|");
			printf("%c", board[i][j]);

		}
		
		printf("|");
		printf("\n  ");

		for (int k = 0 ; k < 8; k++) {
			printf("-");
			printf(" ");
		}
	
	printf("\n");
	
	}
	
	printf("  ");
	
	for (char c = 'A'; c < 'I'; c++) {
		printf("%c", c);
		printf(" ");
	}
	
	printf("\n\n");	

}