#include <stdio.h>
#include <stdlib.h>

int main() {
     int  n, i, j, temp;
     int* arr ;
    
    // // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int*) malloc(n *sizeof(int));
     if(arr == NULL){
        printf("failed to allocate\n");
        return 1 ;
    }
    
    // Input array elements
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", arr+i);
    }

    // Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[i] > arr[i+1]) {
                temp = arr[i];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        };
    }

    // Print sorted array
    printf("\nSorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
     free(arr);
    // // Print minimum and maximum values
    // printf("\nMinimum Value = %d", ptr);
    // printf("\nMaximum Value = %d\n", ptr);
    
    return 0;
}