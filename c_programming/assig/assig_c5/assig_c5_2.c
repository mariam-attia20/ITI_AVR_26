#include <stdio.h>

int main() {
    int arr[100], size, i;
    int evenSum = 0, oddSum = 0;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Input array elements
    printf("Enter %d numbers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Check odd/even and calculate sums
    printf("\nElement Type:\n");
    for (i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d is Even\n", arr[i]);
            evenSum += arr[i];
        } else {
            printf("%d is Odd\n", arr[i]);
            oddSum += arr[i];
        }
    }

    // Print results
    printf("\nSum of Even Numbers = %d\n", evenSum);
    printf("Sum of Odd Numbers = %d\n", oddSum);

    return 0;
}