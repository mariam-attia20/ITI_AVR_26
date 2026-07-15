#include <stdio.h>
void main (void){
//bubble sort 
    int arr[] = {4 ,2 ,7 ,9} ;
    int temp = 0 ;
    int n = sizeof(arr) /sizeof(arr[0]);

     for(int j=0 ; j< n-1 ; j++){
        for(int i = 0 ; i < n-1-j ; i++){ //n-1-j this part just for optemize the operation time as it donot make the compiler to check the sorted elements aready  
            if (arr[i]>arr[i-1]){
                //swapping 
               temp = arr[i];
               arr[i] = arr[i+1] ;
               arr[i+1]= temp ;
            
            
        }
     }
    }















}