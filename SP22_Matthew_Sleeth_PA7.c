/*
NAME : Matthew Sleeth
Course Number / Name : CS 4350 - 251 - Unix Systems Programming
Assignment Number : 7
Due Date : 4 / 28 / 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

static int x;
static int total;
static long threads = 12;
static long my_rank = 0;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


/* Calculates square roots */
double getRoot(int num) {

    double root = 1;
    int i = 0;

    while (1)
    {
        i = i + 1;
        root = (num / root + root) / 2;
        if (i == num + 1) { break; }
    }
    return root;
}


void* calculate(void* rank) {
	// x is the integer provided by the user
	my_rank++;
	// lock 
	pthread_mutex_lock(&lock);

	// calculation for thread : 1 
	if (my_rank == 1) {
		// calculates x divided by x
		int result1 = x / x;
		printf("Result of the 1st  thread = %d\n", result1);
		total += result1;
	}

	// calculation for thread : 2
	else if (my_rank == 2) {
		// calculates x plus x divided by x
		int result2 = (x + x) / x;
		printf("Result of the 2nd  thread = %d\n", result2);
		total += result2;
	}

	// calculation for thread : 3
	else if (my_rank == 3) {
		// calculates square root of x
		int result3 = (int)getRoot(x);
		printf("Result of the 3rd  thread = %d\n", result3);
		total += result3;
	}

	// calculation for thread : 4
	else if (my_rank == 4) {
		// calculates square root of x plus x divided by x
		int result4 = getRoot(x);
		result4 += (x / x);
		printf("Result of the 4th  thread = %d\n", result4);
		total += result4;
	}

	// calculation for thread : 5
	else if (my_rank == 5) {
		int factorial = 1;
		int i = 1;
		// sets result5 to the square root of x
		int result5 = (int)getRoot(x);
		// calculates factorial of results
		while (i <= result5) {
			factorial *= i;
			i++;
		}
		result5 = factorial - (x / x);
		printf("Result of the 5th  thread = %d\n", result5);
		total += result5;
	}

	// calculation for thread : 6  
	else if (my_rank == 6) {
		// calculates the subtraction of (x divided by the square root of x) from x
		double root = getRoot(x);
		int result6 = (x / root);
		result6 = x - result6;
		printf("Result of the 6th  thread = %d\n", result6);
		total += result6;
	}

	// calculation for thread : 7
	else if (my_rank == 7) {
		// calculates ((x divided by x) plux x) minus the square root of x
		int root = (int)getRoot(x);
		int result7 = ((x / x) + x) - root;
		printf("Result of the 7th  thread = %d\n", result7);
		total += result7;
	}

	// calculation for thread : 8
	else if (my_rank == 8) {
		// calculates x minus (x divided by x)
		int result8 = x - (x / x);
		printf("Result of the 8th  thread = %d\n", result8);
		total += result8;
	}

	// calculation for thread : 9
	else if (my_rank == 9) {
		// calculates x equals x
		int result9 = x;
		printf("Result of the 9th  thread = %d\n", result9);
		total += result9;
	}

	// calculation for thread : 10
	else if (my_rank == 10) {
		// calculates (x divided by x) plus x
		int result10 = (x / x) + x;
		printf("Result of the 10th thread = %d\n", result10);
		total += result10;
	}

	// calculation for thread : 11
	else if (my_rank == 11) {
		// calculates (x * x) plus (x + x), all divided by x
		int result11 = ((x * x) + (x + x)) / x;
		printf("Result of the 11th thread = %d\n", result11);
		total += result11;
	}

	// calculation for thread : 12
	else if (my_rank == 12) {
		// calculates (x divided by the square root of x) plus x
		double root = getRoot(x);
		int result12 = (x / root) + x;
		printf("Result of the 12th thread = %d\n", result12);
		total += result12;
	}
	// release lock
	pthread_mutex_unlock(&lock);
}


int main(void) {
	printf("\nWelcome to Matthew Sleeth's Thread App\n");
	printf("\nThis program will do the following: \n");
	printf("Accepts an integer number X from the user and then uses\n"); 
	printf("twelve synchronized threads in order to do some math\n");	
	printf("operations : \n");

	pthread_t tid1, tid2, tid3, tid4, tid5, tid6, tid7, tid8, tid9, tid10, tid11, tid12;
	int sum = 1 + 2 + +3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 + 12;
	total = 0;
	/* Gets a postive integer from the user */
	printf("\nEnter a positive integer : ");
	scanf("%d", &x);

	if (x > 0) {
		printf("\nSum of Numbers Between 1 and 12 = %d\n\n", sum);
		pthread_create(&tid1, NULL, calculate, NULL);
		usleep(0);
		pthread_create(&tid2, NULL, calculate, NULL);
		usleep(0);
		pthread_create(&tid3, NULL, calculate, NULL);
		usleep(0);
		pthread_create(&tid4, NULL, calculate, NULL);
		usleep(0);
		pthread_create(&tid5, NULL, calculate, NULL);
		usleep(0);
		pthread_create(&tid6, NULL, calculate, NULL);
		usleep(0);
		pthread_create(&tid7, NULL, calculate, NULL);
		usleep(0);
		pthread_create(&tid8, NULL, calculate, NULL);
		usleep(0);
		pthread_create(&tid9, NULL, calculate, NULL);
		usleep(0);
		pthread_create(&tid10, NULL, calculate, NULL);
		usleep(0);
		pthread_create(&tid11, NULL, calculate, NULL);
		usleep(0);
		pthread_create(&tid12, NULL, calculate, NULL);

		usleep(100);
		if (sum == total) {
			printf("\nTotal Result from All Threads = %d\n", total);
			printf("\nSum and Total are the same\n");
		}
		else {
			printf("\nTotal Result from All Threads = %d\n", total);
			printf("\nSum and Total are not the same\n");
		}
	}
	else {
		printf("\n*** Number must be greater than 0 ***\n", x);
	}

	printf("\n\nProgrammed by Matthew Sleeth\n");
	printf("4 - 28 - 2022\n");
	return 0;
}