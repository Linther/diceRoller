CC=gcc
STD=c17

dice: dice.c
	$(CC) -std=$(STD) dice.c rollDieN.c -o rolldice -I.
