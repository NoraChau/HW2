/* Nora Chau, 11/2/2025, Problem:
Implemenet 3 different approaches to generate Fibonacci numbers:
- For loop
- While loop
- Do-while loop
The program should:
- Generate the first 10 Fibonacci numbers
- Find the sum of even Fibonacci numbers below a given limit
- Determine if a given number is in the Fibonacci sequence
- Display the golden ratio approximation using consecutive Fibonacci numbers
*/



#include <stdio.h>

// Function to print the first 10 Fibonacci numbers
void generate_10() {
    int before, now, fib[10];
    before = fib[0] = 0;
    now = fib[1] = 1;
    // Initialize first two Fibonacci numbers

    /* Set array items to Fibonacci numbers using a for loop 
    so I can apply the Fibonacci logic itself */
    for(int index=2; index<10; index++) { // Index 2-9 => num 3-10
        fib[index] = now + before;
        before = now;
        now = fib[index];
    }

    printf("The first 10 Fibonacci numbers are:\n");
    for(int i=0; i<10; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}


// Function to print the sum of even Fibonacci numbers below a given limit
void fib_even_sum(int limit) {
    int before = 0, now = 1, sum = 0, next;

    // Using a while loop to generate Fibonacci numbers and sum the even ones as we go
    while (next < limit) {
        next = now + before;
        before = now;
        now = next;

        if (next % 2 == 0) 
            sum += next;  
    } 

    printf("Sum of even Fibonacci numbers below %d is %d\n", limit, sum);
}


// Function to print whether a given number is in the Fibonacci sequence
void is_fib(int number) {
    int before = 0, now = 1, next = 0;

    if (number == 0 || number == 1) {
        printf("%d is in the Fibonacci sequence.\n", number);
    }

    else {
    // Using a do-while loop to generate the last Fibonacci number until we reach or exceed the number
    // Then compare whether that last number is the given number
        do {
            next = now + before;
            before = now;
            now = next;
        } while (next < number);

        if (next == number) {
            printf("%d is in the Fibonacci sequence.\n", number);
        } else {
            printf("%d is not in the Fibonacci sequence.\n", number);
        }
    }
}


// Function to print the golden ratio approximation using consecutive Fibonacci numbers
void golden_ratio_approximation(int n) {
    int before, now, next;
    double ratio = 0.0;
    int fib[n];

    before = fib[0] = 0;
    now = fib[1] = 1;

    // Using a for loop to generate Fibonacci numbers up to the nth number
    for (int index=2; index<n; index++) {
        fib[index] = now + before;
        before = now;
        now = fib[index];
    }

    ratio = (double)fib[n-1] / (double)fib[n-2];
    printf("Golden ratio approximation using the %dth Fibonacci number is: %.6f/%.6f=%.6f\n", n, (double)fib[n-1], (double)fib[n-2], ratio);
}



int main() {
    int choice, limit, number, n;

    printf("Menu:\n");
    printf("1. Generate the first 10 Fibonacci numbers\n");
    printf("2. Find the sum of even Fibonacci numbers below this limit\n");
    printf("3. Is this number within the Fibonacci sequence?\n");    
    printf("4. Display the golden ratio approximation using nth Fibonacci number\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    if (choice == 1) {
        generate_10();
    } 
    
    else if (choice == 2) {
        printf("Enter the limit: ");
        scanf("%d", &limit);

        /* The function's limit automatically becomes 29221(?) 
        when called using an invalid input. This fixes that. */
        if (limit <= 0) {
            printf("Invalid. Limit must be a positive integer.\n");
            return 1;
        }
        else
            fib_even_sum(limit);
    } 
    
    else if (choice == 3) {
        printf("Enter the number: ");
        scanf("%d", &number);

        // Add layer of validation here based on error detected in choice 2
        if (limit <= 0) {
            printf("Invalid. Limit must be a positive integer.\n");
            return 1;
        }
        else
            is_fib(number);
    } 
    
    else if (choice == 4) {
        printf("This operation will take your nth Fibonacci number and the Fibonacci number before it to approximate the golden ratio.\n");
        printf("Enter n (n > 2): ");
        scanf("%d", &n);

        // Add layer of validation here based on error detected in choice 2
        // Cannot be 2 or lower because 1st Fibonacci number is 0, 2nd is 1 => either have no number prior or is division by 0
        if (n <= 2) {
            printf("Invalid. n must be bigger than 2.\n");
            return 1;
        }
        else
            golden_ratio_approximation(n);
    } 
    
    else {
        printf("Invalid choice.\n");
    }
    
    return 0;
}

/* Sample case, input, output:

Menu:
1. Generate the first 10 Fibonacci numbers
2. Find the sum of even Fibonacci numbers below this limit
3. Is this number within the Fibonacci sequence?
4. Display the golden ratio approximation using nth Fibonacci number
Enter your choice (1-4): 2
Enter the limit: 40
Sum of even Fibonacci numbers below 40 is 44

Menu:
1. Generate the first 10 Fibonacci numbers
2. Find the sum of even Fibonacci numbers below this limit
3. Is this number within the Fibonacci sequence?
4. Display the golden ratio approximation using nth Fibonacci number
Enter your choice (1-4): 4
This operation will take your nth Fibonacci number and the Fibonacci number before it to approximate the golden ratio.
Enter n (n > 2): 10
Golden ratio approximation using the 10th Fibonacci number is: 34.000000/21.000000=1.619048

Menu:
1. Generate the first 10 Fibonacci numbers
2. Find the sum of even Fibonacci numbers below this limit
3. Is this number within the Fibonacci sequence?
4. Display the golden ratio approximation using nth Fibonacci number
Enter your choice (1-4): 3
Enter the number: 100
100 is not in the Fibonacci sequence.

*/