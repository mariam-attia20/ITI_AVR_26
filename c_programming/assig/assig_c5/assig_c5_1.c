#include <stdio.h>

int main() {
    int arr[100], size, i, j, temp;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Input array elements
    printf("Enter %d numbers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print sorted array
    printf("\nSorted Array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Print minimum and maximum values
    printf("\nMinimum Value = %d", arr[0]);
    printf("\nMaximum Value = %d\n", arr[size - 1]);

    return 0;
}