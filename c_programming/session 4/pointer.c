#include <stdio.h>
void main(void){
    int x=5  ;
    int y = 10;
    int* ptr1 =&x ;
    int *ptr2 = &y ;
    printf("ptr1 :%d\n ",*ptr1); //derefrance operator (show me data on the address which ptr cary)
    printf("ptr2 :%d\n ",*ptr2);
    ptr1 = ptr2;
    printf("ptr1 now is : %d\n" , *ptr1);
    *ptr1 = 200 ;
    printf("ptr1 now is : %d\n" , *ptr1); 
//how to get variable address
    printf(" address is :%p\n" , ptr1);
    //to get pointer address 
    printf(" address is :%p\n" , &ptr1);
}