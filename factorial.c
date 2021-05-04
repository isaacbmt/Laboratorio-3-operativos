#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

double factorial(double num, double res) {
	if (num == 1) {
		return res;
	}
	else {
		return factorial(num - 1, res * num);
	}
}

int main(int argc, char *argv[]) {
	struct timespec begin, end;
    	clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
	double fact = factorial((double) strtol(argv[1], (char **) NULL ,10), 1);
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	double total = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 + (end.tv_sec  - begin.tv_sec); 
	sleep(2);
	printf("Resultado: %lf \nTiempo: %.15f\n", fact, total);
	return 0;
}

