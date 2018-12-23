CC=gcc
CFLAGS=-Wall -Werror

make: chess.c board.c pieces.c
	$(CC) $(CFLAGS) chess.c -o chess.exe	




#$(CC) $(CFLAGS) chess.c board.c pieces.c -o chess.exe
