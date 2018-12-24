#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int whichPiece(char board[8][8], int x, int y, int m, int n);
int pawn(char board[8][8], int x, int y, int m, int n);
int knight(char board[8][8], int x, int y, int m, int n);
int bishop(char board[8][8], int x, int y, int m, int n);
int rook(char board[8][8], int x, int y, int m, int n);
int queen(char board[8][8], int x, int y, int m, int n);
int king(char board[8][8], int x, int y, int m, int n);

int whichPiece(char board[8][8], int x, int y, int m, int n) {
	printf("Actually checking which piece\n");
	switch (tolower(board[y][x])) {
		case 'p': {
					printf("Checking Pawn legal move\n");
					return pawn(board, x, y, m, n);
					break;
		}
		case 'n': {
					printf("Checking Knight legal move\n");
					return knight(board, x, y, m, n);
					break;
		}
		case 'b': {
					printf("Checking Bishop legal move\n");
					return bishop(board, x, y, m, n);
					break;
		}
		case 'r': {
					printf("Checking Rook legal move\n");
					return rook(board, x, y, m, n);
					break;
		}
		case 'q': {
					printf("Checking Queen legal move\n");
					//return queen(board, x, y, m, n);
					return rook(board, x, y, m, n) || bishop(board, x, y, m, n);
					break;
		}
		case 'k': {
					printf("Checking King legal move\n");
					return king(board, x, y, m, n);
					break;
		}
	}
	printf("You've reposted in the wrong neighborhood\n");
	return 0;
}


int pawn(char board[8][8], int x, int y, int m, int n) {
	

	//2 movements, initial, en passante, capturing



	//Initial 			DONE
	//capturing 		DONE
	//normal movement 	DONE

	//Promotion 		Somewhat DONE

	//en pasante 		have a headache
	// going to somehow make the program aware
	// that on the previous move an en passant-able move was made by the opponent.
	// probably need a variable.

	//cab we simplify this to only have one if statement instaed of two?

	if (islower(board[y][x])) {

			//move forward 1
		if (y == n + 1 && x == m && board[n][m] == ' ') {
			return 1;
		}
			//move forwards 2 on first move
		if (y == 6 && n == 4 && x == m && board[n][m] == ' ') {
			return 1;
		}

			//capturing
		if ( (isupper(board[m][n])) && (y == n - 1) && ( (m == x + 1) || (m == x - 1) ) ) {
			return 1;
		}


			//promotion
		if (n == 1) {
			//pawn is promoted
			char piece = 'q';

			printf("Please promote your piece\nSelect from q, r, b, n");
				
			scanf("%c", &piece);
				// check here that the piece is valid.
			//fix this in future
			board[y][x] = piece;

			//pawn is now the promoted piece

		}
		
	}

	if (isupper(board[y][x])) {

			//move forward 1
		if (y == n - 1 && x == m && board[n][m] == ' ') {
			return 1;
		}
			//move forwards 2 on first move
		if (y == 1 && n == 3 && x == m && board[n][m] == ' ') {
			return 1;
		}

		//capturing
		if ( (islower(board[m][n])) && (y == n + 1) && ( (m == x + 1) || (m == x - 1) ) ) {
			return 1;
		}


			//promotion
		if (n == 6) {
			//pawn is promoted
			char piece = 'q';

			printf("Please promote your piece\nSelect from q, r, b, n");
				
			scanf("%c", &piece);
				// check here that the piece is valid.

			board[y][x] = piece;

			//pawn is now the promoted piece

		}
		
	}
	return 0;
}


int knight(char board[8][8], int x, int y, int m, int n) {

	//complete

	if (	
			(n == y + 2 && m == x + 1) ||
			(n == y + 2 && m == x - 1) ||
			(n == y + 1 && m == x + 2) ||
			(n == y + 1 && m == x - 2) ||
			(n == y - 1 && m == x + 2) ||
			(n == y - 1 && m == x - 2) ||
			(n == y - 2 && m == x + 1) ||
			(n == y - 2 && m == x - 1)
		) { 
		
		printf("Legal Knight Move.\n"); 
		return 1;
	}
	printf("Illegal Knight Move\n");
	return 0;
}
int bishop(char board[8][8], int x, int y, int m, int n) {

	//figure out direction either NE NW SE SW

	//make sure it travels on a diagonal

	
	//then it moved on the y axis

	int distance = n - y;
	int distance2 = m - x;

	int limit = abs(distance); //limit still remains the x axis displacement
	int limit2 = abs(distance2);
	
		
	if (limit != limit2) {
		return 0;
	}

	int mult = 0;
	int mult2 = 0;

	if (distance > 0) {
		mult = 1;
	} else {
		mult = -1;
	}

	if ( distance2 > 0) {
		mult2 = 1;
	} else {
		mult2 = -1;
	}

	for (int i = 0; i < limit; i++) {

		if (board[y + (mult * i)][x + (mult2 * i)] != ' ') {
			return 0;
		}
	}
	return 1;
}

int rook(char board[8][8], int x, int y, int m, int n) {


	//figure out direction either N S E or W

	// need to fix everything because of collisions.

	if (x == m || y == n) {
		//do nothing.
	} else {
		return 0;
	}

	if (x == m) {

		//then it moved on the y axis
		int limit = abs(n - y);
		int distance = n - y;

		int mult = 0;

		if (distance > 0) {
			mult = 1;
		} else {
			mult = -1;
		}

		for (int i = 0; i < limit; i++) {

			if (board[y + (mult * i)][x] != ' ') {
				return 0;
			}
		}
	}

	if (y == n) {

		//then it moved on the y axis
		int limit = abs(m - x);
		int distance = m - x;

		int mult = 0;

		if (distance > 0) {
			mult = 1;
		} else {
			mult = -1;
		}

		for (int i = 0; i < limit; i++) {

			if (board[y][x + (mult * i)] != ' ') {
				return 0;
			}
		}
	}

	return 0;
}

int queen(char board[8][8], int x, int y, int m, int n) {
	return 0;
}

int king(char board[8][8], int x, int y, int m, int n) {
		

		printf("\n");

		//Done

		//what if you used the distance instead?

	if (

		(n == y + 1 && m == x + 1 ) ||
		(n == y + 1 && m == x) ||
		(n == y + 1 && m == x - 1) ||
		
		(n == y && m == x + 1) ||
		(n == y && m == x - 1) ||
		
		(n == y - 1 && m == x + 1) ||
		(n == y - 1 && m == x) ||
		(n == y - 1 && m == x - 1)

		) {
			printf("Legal King Move\n"); 
	}

	return 0;
// implement 4 kinds of castling

	//perhaps implement castling here
	//have to look up rules, think king cant castle through a square that will be in check

	//figure out if black or white king, etc.

	//king castling and pawn depend upon wether they are black or white

	//}
}





/*





pawn		    Movement
				Initial Movement
				Capturing
				En Passante
				Promotion

Knight 			COMPLETE
Bishop 			half
rook 			half
queen 			Just needs rook and bishop
King 			Require Castling



future


Check
CheckMate


Current Tasks:


Pawn, bishop, rook



*/