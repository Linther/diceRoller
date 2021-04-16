/**
 * 	dice.c
 *    Command line:  (todo)
 *   
 *   	 	./a.out -d<die size> -c<die count> +<bonus>
 *          	or
 *       	./a.out
 *       		This just rolls a single d20
 *
 *       	Ideally you can ask for multiple combos. eg
 *       		./a.out d20 c5 +1 d6 c2 +3
 *       		This should roll 5 d20s and 2 d6s
 *
 *       	Output should look like:
 *       	5	d20:	50	(+1) = 51
 *       	2	d6:		3	(+3) = 6
 *
 *       	Total = 57
 *
 *       flags:
 *       	-a   (todo)
 *       		Roll with advantage (rolls 2 and prints higher count)
 *
 *          -d   (todo)
 *          	Roll with disadvantage (rolls 2 and prints lower count)
 *
 *          -v   (todo)
 *          	Verbose mode, print individual rolls instead of sums.
 *
 *
 *
 *
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>

int rollDieN(int dieSize, int verboseMode){
	struct timespec ts;
	int timeNano;
	int randNumber;

	//update timespec struct with current time
	clock_gettime(0, &ts);

	// Get current nanoseconds from posix 
    timeNano = ts.tv_nsec;
	
	// Seed rand
	srand(timeNano * 1000000);
	
	randNumber = rand() % dieSize + 1;

	return(randNumber);
}


void main(int argc, char** argv){

	int c;
	int diceRoll;
	int dieSize;
	int dieCount;
 	int verboseMode;
	
    dieSize = 20;
	dieCount = 1;

	while ((c = getopt (argc, argv, "d:c:v:")) != -1){
		switch(c){
			case 'd':
				dieSize = atoi(optarg);
				break;
			case 'c':
				dieCount = atoi(optarg);
				break;
			case 'v':
				verboseMode = 1;
				break;
			default:
				printf("char: [%c]", c);
		}
	}

	for (int i = 0; i < dieCount; i++){
		diceRoll = rollDieN(dieSize, 0);
		printf("Roll: %d\n", diceRoll); 
	}
}
