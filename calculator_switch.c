/*Nora Chau, 11/1/2025, Problem:
Calculator that:
- accepts two numbers and an operator (+, -, *, /, ^)
- uses a switch statement to perform the operation
- handles division by zero
- handles ^ operation using loops
- supports both integer and floating-point
- includes a menu system that allows multiple calculations until the user decides to exit          
*/


#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    while(1){
        printf("Enter an operator (+, -, *, /, ^). Enter 0 to exit: ");
        scanf(" %c", &operator);

        // Exit when user enters '0'
        if (operator == '0') {
            printf("Exiting the calculator. Goodbye!\n");
            return 0;
        }

        /* Program encounters an error if operator other than 0, +, -, *, /, ^, is entered. 
        Warn user and restarts*/
        if (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '^') {
            printf("Invalid operator. Please try again.\n");
            continue;
        }

        /*Program encounters an error if user enters anything other than an integer or float.
        I have no idea how to make the program tolerates this error.*/
        printf("Enter 1st number: ");
        scanf("%lf", &num1);
        printf("Enter 2nd number: ");
        scanf("%lf", &num2);

        // Calculations
        switch (operator) {
            case '+':
                result = num1 + num2;
                printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
                continue;

            case '-':
                result = num1 - num2;
                printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
                continue;

            case '*':
                result = num1 * num2;
                printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
                continue;

            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("Division by zero is not allowed.\n");
                }
                continue;

            // Multiply num1 by itself num2 times, as is done in raising to a power
            case '^':
                result = 1;
                for (int i = 0; i < (int)num2; i++) {
                    result *= num1;
                }
                printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
                continue;    
        }
    }
}

/*Sample case, input, output:

Enter an operator (+, -, *, /, ^). Enter 0 to exit: +
Enter 1st number: 5
Enter 2nd number: 3
5.00 + 3.00 = 8.00
Enter an operator (+, -, *, /, ^). Enter 0 to exit: ^
Enter 1st number: 2
Enter 2nd number: 3
2.00 ^ 3.00 = 8.00
Enter an operator (+, -, *, /, ^). Enter 0 to exit: 0
Exiting the calculator. Goodbye!
*/