/*Nora Chau, 11/3/2025, Problem:
Create a program that generate the following patterns based on user input:
Pattern A (Diamond):
                       *   
                      ***  
                     *****
                    *******
                     ***** 
                      ***  
                       *

Pattern B (Number Pyramid): 
                               1   
                              121  
                             12321 
                            1234321

*/

#include <stdio.h>

// Function to print a diamond pattern
int diamond(){
    printf("   *   \n");
    printf("  ***  \n");
    printf(" ***** \n");
    printf("*******\n");
    printf(" ***** \n");
    printf("  ***  \n");
    printf("   *   \n");

    return 0;
}

// Function to print a pyramid pattern
int pyramid() {
    printf("   1   \n");
    printf("  121  \n");
    printf(" 12321 \n");
    printf("1234321\n");

    return 0;
}

int main() {
    char pattern;

    printf("Enter the pattern you want (A/B): ");
    scanf("%c", &pattern);

    if (pattern == 'A' || pattern == 'a')
        diamond();
    else if (pattern == 'B' || pattern == 'b')
        pyramid();
    else
        printf("Invalid input. Please enter A or B.\n");

    return 0;
}

/* Sample case, input, output

Enter the pattern you want (A/B): A
   *   
  ***  
 *****
*******
 ***** 
  ***  
   *

Enter the pattern you want (A/B): B
   1   
  121  
 12321 
1234321
*/