#include <stdio.h>

int main()
{
    int num1, num2, num3;

    printf("Please enter number 1: ");
    scanf("%d", &num1);

    printf("Please enter number 2: ");
    scanf("%d", &num2);

    printf("Please enter number 3: ");
    scanf("%d", &num3);

    printf("\nNumbers in reverse order:\n");
    printf("number 3: %d\n", num3);
    printf("number 2: %d\n", num2);
    printf("number 1: %d\n", num1);

    return 0;
}