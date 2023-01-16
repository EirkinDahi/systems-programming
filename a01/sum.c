#include <stdio.h>

int main () {
    int num1, num2, sum;
    //hello
    printf("Input the first integer: ");
    scanf("%d", &num1);

    printf("Input the second integer: ");
    scanf("%d", &num2);

    //calculations 
    sum = num1 + num2;

    printf("Sum of the above two integers = %d", sum);

    return 0;
}