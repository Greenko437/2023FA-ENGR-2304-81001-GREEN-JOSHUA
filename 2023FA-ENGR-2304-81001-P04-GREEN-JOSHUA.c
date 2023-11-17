// 2023FA-ENGR-2304-81001-GREEN-JOSHUA-P04
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


#define MAX_VOLTAGE 10
#define MAX_RESISTANCE 20
#define TOLERANCE 1e-3

// Function to generate a random integer between min and max
int generateRandomValue(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to calculate the total current and individual branch currents
void calculateCurrents(int Vs, int R1, int R2, int R3, double *It, double *I1, double *I2, double *I3) {
    // Calculate total resistance in parallel
    double Rt = 1 / (1 / (double)R1 + 1 / (double)R2 + 1 / (double)R3);

    // Calculate total current
    *It = Vs / Rt;

    // Calculate individual branch currents
    *I1 = Vs / R1;
    *I2 = Vs / R2;
    *I3 = Vs / R3;
}

// Function to check the user's answers with calculated values
int checkAnswer(double userValue, double actualValue) {
    return fabs(userValue - actualValue) <= TOLERANCE;
}

// Main function
int main() {
    int Vs, R1, R2, R3;
    double It, I1, I2, I3;
    double userIt, userI1, userI2, userI3;
    char option;

    srand(time(NULL)); // Seed random number generator

    do {
        // Step 1: Generate random values
        Vs = generateRandomValue(1, MAX_VOLTAGE - 1);
        R1 = generateRandomValue(1, MAX_RESISTANCE - 1);
        R2 = generateRandomValue(1, MAX_RESISTANCE - 1);
        R3 = generateRandomValue(1, MAX_RESISTANCE - 1);

        // Calculate the solution
        calculateCurrents(Vs, R1, R2, R3, &It, &I1, &I2, &I3);

        // Step 2: Present the random values
        printf("Random values generated:\nVs = %dV, R1 = %dohms, R2 = %dohms, R3 = %dohms\n", Vs, R1, R2, R3);

        // Step 3: Query for the answers
        printf("Enter your calculated total current It: ");
        scanf("%lf", &userIt);
        printf("Enter your calculated current I1: ");
        scanf("%lf", &userI1);
        printf("Enter your calculated current I2: ");
        scanf("%lf", &userI2);
        printf("Enter your calculated current I3: ");
        scanf("%lf", &userI3);

        // Step 4: Compare the values
        if(checkAnswer(userIt, It)) {
            printf("Correct It!\n");
        } else {
            printf("Incorrect It! Correct value: %.3f\n", It);
        }
        if(checkAnswer(userI1, I1)) {
            printf("Correct I1!\n");
        } else {
            printf("Incorrect I1! Correct value: %.3f\n", I1);
        }
        if(checkAnswer(userI2, I2)) {
            printf("Correct I2!\n");
        } else {
            printf("Incorrect I2! Correct value: %.3f\n", I2);
        }
        if(checkAnswer(userI3, I3)) {
            printf("Correct I3!\n");
        } else {
            printf("Incorrect I3! Correct value: %.3f\n", I3);
        }

        // Ask user if they want to exit or restart
        printf("Do you want to exit the program? (y/n): ");
        scanf(" %c", &option); // space before %c is to consume any leftover '\n' in the input buffer

    } while(option != 'y' && option != 'Y');

    return 0;
}