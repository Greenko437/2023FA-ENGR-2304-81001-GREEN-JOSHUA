/*
2023FA-ENGR-2304-81001-GREEN-JOSHUA-P03
Description: A program to solve a system of equations using Cramer's rule and co-factors.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to get cofactor of A[p][q] in temp[][]. n is current dimension of A[][] 
void getCofactor(float A[3][3], float temp[3][3], int p, int q, int n) {
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = A[row][col];

                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Recursive function to find determinant of a matrix
float determinant(float A[3][3], int n) {
    float D = 0;
    if (n == 1)
        return A[0][0];

    float temp[3][3];
    int sign = 1;  // To store sign multiplier

    for (int f = 0; f < n; f++) {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);

        sign = -sign;
    }
    return D;
}

void cramerRule(float A[3][3], float B[3], int n) {
    float detA = determinant(A, n);

    if (detA == 0) {
        printf("System of equations has no unique solution.\n");
        return;
    }

    float temp[3][3];
    float X[3];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            temp[j][i] = B[j];
        
        if (i > 0)
            for (int j = 0; j < n; j++)
                temp[j][i-1] = A[j][i-1];

        X[i] = determinant(temp, n) / detA;
    }

    printf("Solution is:\n");
    for (int i = 0; i < n; i++)
        printf("%f\n", X[i]);
}

int main() {
    float A[3][3], B[3];

    printf("Enter the coefficients for the 3x3 matrix A:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter value for A[%d][%d]: ", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }

    printf("Enter the constants for the 3x1 matrix B:\n");
    for (int i = 0; i < 3; i++) {
        printf("Enter value for B[%d]: ", i+1);
        scanf("%f", &B[i]);
    }

    cramerRule(A, B, 3);

    return 0;
}