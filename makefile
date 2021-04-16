CC=gcc
STD=c17

dice: dice.c
	$(CC) -std=$(STD) dice.c -o rolldice
