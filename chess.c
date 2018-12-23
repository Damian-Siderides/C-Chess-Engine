#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "board.c"
#include "pieces.c"


void move(int turnNumber);

int gameOver();
int isCheck();
int isCheckMate();

int movePiece();
int isInBounds();
int isYourPiece();

void changeTurn();



int x = 0;
int y = 0;
int m = 0;
int n = 0;

char p = 0;

int turnNum = 0;
int turn = 0;


int blackKingCastle  = 1;
int blackQueenCastle = 1;

int whiteKingCastle  = 1;
int whiteQueenCastle = 1;



//change the thing

// (x,y)  -> (m,n)
//start -> end




//how to define a move

	/*
		Rules

		Computer rules, humans dont really consider
			- Cant capture your own piece
			- Cant move to where the piece was originially
			- Cant move through pieces
			-

		Bounds					DONE
		Your piece 				DONE
		Legal Move 				90% DONE

		Castling 				next
		Check 					later
		Checkmate 				later
		Promotion 				Half Done
		En Passant 				later

		AI - important cause i dont feel like playing chess anymore

			chess notation generator
			revert to previous board states - either store the board - naive
											- or store the moves and play them backwards - more efficient.
		


		FUTURE, extra goals probably wont implement.

			Network Games or Internet games
			Gui probably easy in javascript

		END FUTURE

	*/



int main() {

	initBoard();

	printf("White is lowercase\n");
	printf("Black is uppercase\n");

	// jump instruction may be better but
	// might produce the same assembly code.
	while (1) {
		move(turn);
	}

}

void move(int turnNumber) {
	
	printBoard();

	if (turn == 0) {
		printf("\nIt is White's turn to move\n(LOWERCASE)\n");
	} else {
		printf("\nIt is Black's turn to move\n(UPPERCASE)\n");
	}


	scanf(" %d", &x);				// here we are scanning in the arguments. In future is there a better way of input output?
	scanf(" %d", &y);
	scanf(" %d", &m);				// one simpler way is to use one number and one letter. We just need a way to convert the letter back into number format very quickly.
	scanf(" %d", &n);


	//implement any tricks here, so future interation with the BOARD are clean.

	x--;
	y--;
	m--;
	n--;

	// when we implement characters as coordinates, probably smarter to convert it to an int here.

	printf("You moved the piece %d from %d%d to %d%d\n\n\n\n\n", board[y][x], x, y, m, n);	

	
	//implement IFF - Identify Friend or Foe



	if (!isInBounds()) {
		return;
	}
	if (!movePiece()) {
		return;
	}	
	if (!whichPiece(board, x, y, m, n)) {
		return;
	}
	changeTurn();

	//you also cant make a move which will create CHECK. This will require going back to the previous board state.

	//insert check and checkmate somewhere here.


}



int movePiece() {

	if (turn == 0) {
		
		if ( islower(board[y][x]) && !islower(board[n][m]) ) {

			//isLower = white pieces
			//!isLower = black pieces and empty
			//
			//you can not capture your own piece
			return 1;
		}

		return 0;

	}

	if (turn == 1) {

		if ( isupper(board[y][x]) && !isupper(board[n][m]) ) {

			return 1;

		}

		return 0;

	}

	return 0;

}

int isInBounds() {
	if (x > 7 || x < 0 || y > 7 || y < 0 ||
	    m > 7 || m < 0 || n > 7 || n < 0) {

		printf("Coordinates out of bounds\n");								// we need to check that the inputs are within the bounds
		return 0;
	}

	if (x == m && y == n) {
		printf("You can't move your piece where it already was\n");
		return 0;
	}
	return 1;
}


int isYourPiece() {

	//this is kind of being checked above in another function. maybe just remove this function.

	// this is wrong, Fix
	//if ( (!islower(board[y - 1][x - 1])) == turn || isupper(board[y - 1][x - 1]) == turn) {						// and thatt you are moving the right piece					
	// 	return 1;
	// } 
	
	// 	printf("Yo you tried to move the wrong piece\n");
	// 	return 0;

	return 1;

}

void changeTurn() {

	board[n][m] = board[y][x];
	board[y][x] = ' ';

	//could use
	// turn ^= 1;

	if (turn == 0) {
			turn = 1;							// black turn == 1
	} else if (turn == 1) {
		turn = 0;								// white turn == 0
	}

	turnNum++;

}


int gameOver() {return 0;}
int isCheck() {return 0;}
int isCheckMate() {return 0;}

