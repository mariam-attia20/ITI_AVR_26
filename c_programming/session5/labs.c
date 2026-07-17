#include <stdio.h>

void fun(int* ptr, int size) { 
    // Fix: Create an accumulator variable initialized to 0
    int total_sum = 0; 
    
    for(int i = 0; i < size; i++) { 
        // Add each element using pointer notation *(ptr + i) or array notation ptr[i]
        total_sum += *(ptr + i); 
    } 
    
    printf("The sum of all elements is: %d\n", total_sum);
} 

int main(void) { 
    // Fix: Specify a concrete size (e.g., 5) so the array has allocated memory
    int arr[5]; 
    int size = sizeof(arr) / sizeof(arr[0]); 

    for(int i = 0; i < size; i++) { 
        printf("plz enter value %d:\n", i + 1); 
        // Fix: Pass the address (&) of the element to scanf
        scanf("%d", &arr[i]); 
    } 

    // Passes the pointer of the array to the function
    fun(arr, size); 
    
    return 0;
}
