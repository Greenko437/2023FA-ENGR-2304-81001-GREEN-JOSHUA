// 2023FA-ENGR-2304-81001-GREEN-JOSHUA-P06

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototype declarations
void analyzeData(const char *filename);
void searchData(const char *filename);
double calculateMean(int sum, int count);
double calculateStdDev(int data[], int count, double mean);

int main() {
    int choice;
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    do {
        printf("\nMenu:\n");
        printf("1. Analyze Data\n");
        printf("2. Search Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                analyzeData(filename);
                break;
            case 2:
                searchData(filename);
                break;
            case 3:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != 3);

    return 0;
}

void analyzeData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }

    int data[1000];
    int i = 0, sum = 0;
    char temp[10];

    while (fscanf(file, "%s", temp) != EOF) {
        data[i] = atoi(temp);
        sum += data[i];
        i++;
    }

    fclose(file);

    double mean = calculateMean(sum, i);
    double stdDev = calculateStdDev(data, i, mean);

    printf("\nReport:\n");
    printf("Total numbers: %d\n", i);
    printf("Sum: %d\n", sum);
    printf("Mean: %f\n", mean);
    printf("Standard Deviation: %f\n", stdDev);
}

void searchData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }

    int number;
    printf("Enter number to search: ");
    scanf("%d", &number);

    int temp;
    while (fscanf(file, "%d", &temp) != EOF) {
        if (temp == number) {
            printf("Number %d found in the file.\n", number);
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Number %d not found in the file.\n", number);
}

double calculateMean(int sum, int count) {
    return (double)sum / count;
}

double calculateStdDev(int data[], int count, double mean) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += pow(data[i] - mean, 2);
    }
    return sqrt(sum / count);
}
