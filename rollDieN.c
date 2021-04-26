#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>

int rollDieN(int dieSize, int verboseMode){
	struct timespec ts;
	int timeNano;
	int randNumber;

	clock_gettime(0, &ts);

	timeNano = ts.tv_nsec;

	srand(timeNano * 1000000000);

	randNumber = rand() % dieSize + 1;

	return(randNumber);
}
