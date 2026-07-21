#include <stdio.h>


void fun(int* ptr , int size){
    for(int i =0; i<size ; i++){
        printf("%d\n" , ptr[i]); //the same as // printf("%d\n" , *(ptr + i));
        
    }

}
void main(void){
    // int x = 5 ;
    // int y = 3;
    // int *ptr2 = &y;
    //pointer increase depend on ptr kind 
    // we can not summesion two adress 
   // printf("%p" ,ptr2 );
     int arr[]= {2 ,4 ,5,6};
     int size = sizeof(arr)/sizeof(arr[0]);
     fun(arr ,size); //it could writen as fun(&arr[0])
    

}