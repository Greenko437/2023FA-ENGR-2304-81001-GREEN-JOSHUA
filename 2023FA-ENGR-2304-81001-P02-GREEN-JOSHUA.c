#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 2023FA-ENGR-2304-81001-GREEN-JOSHUA-P02 */

void decToBinary(int n);
void binToDec(char *binary);
void hexToBin(char *hex);
void binToHex(char *binary);

int main() {
    int choice;
    char number[65];
    
    do {
        printf("\nMenu:\n");
        printf("1. Decimal to Binary or Binary to Decimal\n");
        printf("2. Hexadecimal to Binary or Binary to Hexadecimal\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter a decimal number (between -127 and 127) or a binary number: ");
                scanf("%s", number);
                if (strchr(number, '2') || strchr(number, '3') || strchr(number, '4') || 
                    strchr(number, '5') || strchr(number, '6') || strchr(number, '7') || 
                    strchr(number, '8') || strchr(number, '9')) {
                    decToBinary(atoi(number));
                } else {
                    binToDec(number);
                }
                break;
            case 2:
                printf("Enter a hexadecimal number (starting with 0x) or a binary number: ");
                scanf("%s", number);
                if (strncmp(number, "0x", 2) == 0) {
                    hexToBin(number);
                } else {
                    binToHex(number);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 3);
    
    return 0;
}

void decToBinary(int n) {
    unsigned char binaryNum[8];
    int i;
    int isNegative = 0;
    
    if (n < 0) {
        isNegative = 1;
        n = abs(n);
    }
    
    for (i = 7; i >= 1; i--) {
        binaryNum[i] = n % 2;
        n = n / 2;
    }
    binaryNum[0] = isNegative;
    
    printf("The binary representation is: ");
    for (i = 0; i < 8; i++) {
        printf("%d", binaryNum[i]);
    }
    printf("\n");
}

void binToDec(char *binary) {
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);
    int i;
    int isNegative = binary[0] - '0';
    
    for (i = len - 1; i >= 1; i--) {
        decimal += (binary[i] - '0') * base;
        base = base * 2;
    }
    
    if (isNegative) {
        decimal = -decimal;
    }
    
    printf("The decimal representation is: %d\n", decimal);
}

void hexToBin(char *hex) {
    int i;
    printf("The binary representation is: ");
    for(i = 2; i < strlen(hex); i++) {
        switch(hex[i]) {
            case '0':
                printf("0000");
                break;
            case '1':
                printf("0001");
                break;
            case '2':
                printf("0010");
                break;
            case '3':
                printf("0011");
                break;
            case '4':
                printf("0100");
                break;
            case '5':
                printf("0101");
                break;
            case '6':
                printf("0110");
                break;
            case '7':
                printf("0111");
                break;
            case '8':
                printf("1000");
                break;
            case '9':
                printf("1001");
                break;
            case 'A':
            case 'a':
                printf("1010");
                break;
            case 'B':
            case 'b':
                printf("1011");
                break;
            case 'C':
            case 'c':
                printf("1100");
                break;
            case 'D':
            case 'd':
                printf("1101");
                break;
            case 'E':
            case 'e':
                printf("1110");
                break;
            case 'F':
            case 'f':
                printf("1111");
                break;
            default:
                printf("\nInvalid hexadecimal digit %c", hex[i]);
        }
    }
    printf("\n");
}

void binToHex(char *binary) {
    int len = strlen(binary);
    int dec = 0, base = 1, rem, i;
    char hex[17];
    int index = 0;
    
    for (i = len - 1; i >= 0; i--) {
        rem = binary[i] - '0';
        dec += rem * base;
        base = base * 2;
    }
    
    while (dec != 0) {
        rem = dec % 16;
        if (rem < 10) {
            hex[index++] = 48 + rem;
        } else {
            hex[index++] = 55 + rem;
        }
        dec = dec / 16;
    }
    
    printf("The hexadecimal representation is: 0x");
    for (i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");
}
