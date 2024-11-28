#include <stdio.h>

void swapUsingTempVariable(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapUsingArithmetic(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swapUsingXOR(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void swapUsingPointer(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    
    swapUsingTempVariable(&a, &b);
    printf("After swap using temp variable: a = %d, b = %d\n", a, b);
    
    swapUsingArithmetic(&a, &b);
    printf("After swap using arithmetic: a = %d, b = %d\n", a, b);
    
    swapUsingXOR(&a, &b);
    printf("After swap using XOR: a = %d, b = %d\n", a, b);
    
    int *pa = &a, *pb = &b;
    swapUsingPointer(&pa, &pb);
    printf("After swap using pointer: a = %d, b = %d\n", a, b);
    
    return 0;
}
