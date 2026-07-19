#include <stdio.h>

int main()
{
    int answer;
    int correct = 56;   // Example: 7 × 8

    printf("Alarm System \n");

    do
    {
        printf("Enter the result of 7 * 8 = ");
        scanf("%d", &answer);

        if (answer != correct)
        {
            printf("Wrong answer! Try again.\n");
        }

    } while (answer != correct);

    printf("Correct! Alarm stopped.\n");

    return 0;
}