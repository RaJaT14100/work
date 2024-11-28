#include <stdio.h>
#include <math.h>

void decimalToBinary(int n) {
    int binary[32], i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }
    printf("Binary representation: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int binaryToDecimal(int n) {
    int decimal = 0, i = 0;
    while (n > 0) {
        decimal += (n % 10) * pow(2, i);
        n = n / 10;
        i++;
    }
    return decimal;
}

int main() {
    int choice, number;
    printf("Choose an option:\n1. Decimal to Binary\n2. Binary to Decimal\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter a decimal number: ");
        scanf("%d", &number);
        decimalToBinary(number);
    } else if (choice == 2) {
        printf("Enter a binary number: ");
        scanf("%d", &number);
        printf("Decimal representation: %d\n", binaryToDecimal(number));
    } else {
        printf("Invalid choice!\n");
    }
    
    return 0;
}
