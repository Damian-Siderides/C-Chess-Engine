#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Board.c"


void move(int turnNumber);
void printBoard();
void initBoard();


int gameOver();
int isCheck();
int isCheckMate();

int isInBounds();
void isYourPiece();

void changeTurn();


int whichPiece();

int pawn();
int knight();
int bishop();
int rook();
int queen();
int king();




int x = 0;
int y = 0;
int m = 0;
int n = 0;

int turnNum = 0;
int turn = 0;



//change the thing

// x,y  -> m,n
//start -> end




//how to define a move

	/*
		Rules

		en passant, stalemate, check, checkmate, castling

		1. Is move out of bounds?  Done 
		2. Is it your piece to move? Done
		3.5 Is there a piece in the way
		3. Promotion

		4. Is move legal for the piece
		

		bounds					DONE
		Your piece 				DONE
		Legal Move 				1/2 DONE
		Nothing Blocking 		Impossible



		Castling 				Easy
		Check 					Impossible
		Checkmate 				Impossible
		Promotion 				Easy
		En Passant 				Easy - Very hard




		THE FUTURE
		
		5. AI


		5.5 Network Games

		6. Gui


	*/



int main() {


	initBoard();


	printf("White is lowercase\n");
	printf("Black is uppercase\n");

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



	printf("You moved the piece %d from %d%d to %d%d\n\n\n\n\n", board[y - 1][x - 1],x,y,m,n);	

	
	


	if (!isInBounds()) {
		return;
	}
	if (!isYourPiece()) {
		return;
	}
	if (!whichPiece()) {
		return;
	}
	changeTurn();

	//insert check and checkmate somewhere here.


}



int gameOver() {



}

int isCheck(){}
int isCheckMate(){}




int isInBounds(){
	if (x > 'h' || x < 'a' || y > 8 || y < 1 ||
	    m > 'h' || m < 'a' || n > 8 || n < 1) {

		printf("Coordinates out of bounds\n");								// we need to check that the inputs are within the bounds
		return 0;
	} 

	if (x == m && y == n) {
		printf("You can't move your piece where it already was\n");
		return 0;
	}
	return 1;
}


int isYourPiece(){
	if (!islower(board[y - 1][x - 1]) == turn || isupper(board[y - 1][x - 1]) == turn) {						// and thatt you are moving the right piece					
		return 1;
	} 
	
		printf("Yo you tried to move the wrong piece\n");
		return 0;

}

void changeTurn() {

	board[n - 1][m - 1] = board[y - 1][x - 1];
	board[y - 1][x - 1] = ' ';

	if (turn == 0) {
			turn = 1;								// black turn == 1
		} else if (turn == 1) {
			turn = 0;								// white turn == 0
		}

	turnNum++;

}




int whichPiece() {
	
	switch (board[n - 1][m - 1]) {
		case 'p': {
					return pawn();
					break;
		}
		case 'n': {
					return knight();
					break;
		}
		case 'b': {
					return bishop();
					break;
		}
		case 'r': {
					return rook();
					break;
		}
		case 'q': {
					return queen();
					break;
		}
		case 'k': {
					return king();
					break;
		}
	}
}


int pawn() {
	

	//2 movements, initial, en passante, capturing


	//initial
	//capturing

	//promotion


	printf("Just shake that ass bitch\nand let us see what you got\n");

		if (n == y + 1 || n == y + 2 || n == y - 1 || n == y - 2) {
			printf("Just shake that ass bitch\nand let us see what you got\n");
		}


		if (isLower(board[x - 1][y - 1]) {

			if (n == 7) {

			}



		}
}



int knight() {

	

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
	return 0;
}
int bishop() {

	

	for (int i = 1; i < 8; i++) {
		
		if ((n == y + 1 * i) && ( m == x + 1 * i) || (n == y - 1 * i) && ( m == x - 1 * i) ||
			(n == y + 1 * i) && ( m == x - 1 * i) || (n == y - 1 * i) && ( m == x + 1 * i)) {

			printf("Legal Bishop Move.");

		}
	}


}

int rook() {


	// need to fix everything because of collisions.

	if (x == m || y == n) {
		printf("Legal Rook Move.\n");
		return 1;
	}
	return 0;
}

int queen() {

	
	if (n == y || m == x) {
		printf("test\n");
		return 1;
	}

	for (int i = 1; i < 8; i++) {
		


		if ((n == y + 1 * i) && ( m == x + 1 * i) || (n == y - 1 * i) && ( m == x - 1 * i) ||
			(n == y + 1 * i) && ( m == x - 1 * i) || (n == y - 1 * i) && ( m == x + 1 * i)) {

			printf("\n\nLegal Queen Move attempt.\n\n");

		}
	}

}
int king() {
		

		printf("\n");

		//Done

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


// implement 4 kinds of castling

	//perhaps implement castling here



	//}
}
