/*Nora Chau, 11/2/2025, Problem:
A program that
- finds all prime numbers between 1 and user's input number
- uses the Sieve of Eratosthenes algorithm
- displays the primes in a 10-per-row table
- calculates and displays the total count of primes found
- measures and displays the execution time*/

#include <stdio.h>
#include <time.h>

int main() {
    int max, start, end, count = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &max);

    /*If user enters a non-number or a number less than 1, the program does nothing.
    This takes care of that and somehow the non-number issue too, for some reason. */
    if (max < 1) {
        printf("Invalid input. Please enter a positive integer greater than 0.\n");
        return 1;
    }
    
    printf("Prime numbers between 1 and %d are:\n", max);

    start = clock();

    int isPrime[max+1]; // allocate placeholders for all num 0-max

    // first mark all numbers as prime
    for (int position = 2; position <= max; position++)
        isPrime[position] = 1;

    // 0 and 1 aren't primes.
    isPrime[0] = 0;
    isPrime[1] = 0; 

    // "Cross out" non-prime numbers using Sieve of Eratosthenes starting from 2
    // Only goes up to sqrt(max) because after that, factor pairs repeat
    for (int num = 2; num * num <= max; num++) {
        if (isPrime[num]) {

            /* Cross out every multiply of Prime starting from Prime^2 
            (Prime x less-than-Prime is already marked 0 when checking
            less-than-Prime)*/
            for (int multiply = num * num; multiply <= max; multiply += num)
                isPrime[multiply] = 0;
        }
    }

    // print all primes by all the 1 marks in isPrime array
    for (int i = 2; i <= max; i++) {
        if (isPrime[i]){
            if (count % 10 == 0 && count != 0)
                printf("\n");
            count++;
            printf("%d ", i);
        }
    }


    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Convert processing time to seconds
    printf("\nTotal prime numbers found: %d\n", count);
    printf("Execution time: %f seconds\n", time_taken);

    return 0;
}

/* Sample case, input, output:

Enter a positive integer: 113
Prime numbers between 1 and 113 are:
2 3 5 7 11 13 17 19 23 29 
31 37 41 43 47 53 59 61 67 71 
73 79 83 89 97 101 103 107 109 113 
Total prime numbers found: 30
Execution time: 0.000012 seconds

Enter a positive integer: abc
Invalid input. Please enter a positive integer greater than 0.
*/