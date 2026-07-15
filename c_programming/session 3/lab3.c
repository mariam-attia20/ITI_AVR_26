#include <stdio.h>

void main(void){
    int arr[10];
    for (int i =0 ; i< 10 ;i ++){
        scanf("%d" ,&arr[i]);
    }
    for (int i =0 ; i< 10 ;i ++){
        printf("%d \n" , arr[10-i]);
    }
          
    
}