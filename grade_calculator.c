/*Nora Chau, 11/1/2025, Problem:
Grade calculator that takes a numerical score (0-100) as input and output the
corresponding letter grade:
- A: 90-100
- B: 80-89
- C: 70-79
- D: 60-69
- F: Below 60
Additionally, it can
- validate that input is between 0-100
- handle decimal inputs
- display '+' for scores in top 3% of the grade range
- display '-' for scores in bottom 3% of grade range*/

#include <stdio.h>

int main(){
    float score;
    printf("Enter your score: ");
    scanf("%f", &score);
    /* Program outputs F if user enters anything other than an integer or float, 
    which isn't exactly correct.
    I have no idea how to make the program tolerates this error.*/

    //Validate that input is between 0-100
    if (score < 0 || score > 100) {
        printf("Invalid score. Please enter a score between 0 and 100.\n");
        return 1;
    }

    //Print letter grade according to the score
    if (score >= 99.7) {
        printf("Grade: A+\n");
    } else if (score >= 90.3) {
        printf("Grade: A\n");
    } else if (score >= 90) {
        printf("Grade: A-\n");
    } else if (score >= 88.7) {
        printf("Grade: B+\n");
    } else if (score >= 80.3) {
        printf("Grade: B\n");
    } else if (score >= 80) {
        printf("Grade: B-\n");
    } else if (score >= 78.7) {
        printf("Grade: C+\n");
    } else if (score >= 70.3) {
        printf("Grade: C\n");
    } else if (score >= 70) {
        printf("Grade: C-\n");
    } else if (score >= 68.7) {
        printf("Grade: D+\n");
    } else if (score >= 60.3) {
        printf("Grade: D\n");
    } else if (score >= 60) {
        printf("Grade: D-\n");
    } else {
        printf("Grade: F\n");
    }
}

/*Sample cases, input, output:

Enter your score: 95.5
Grade: A

Enter your score: 88.9
Grade: B+
*/