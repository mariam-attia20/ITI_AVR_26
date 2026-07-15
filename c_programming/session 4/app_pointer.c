#include<stdio.h>

void modify(int *x);
void swaping (int *x , int *y);

void main(void){
    int z = 5;
    int b = 10 ;
    // char*ptr1 = &z ; //pointer can point on data does not have the same type as it but the number could cut or change 
    int *ptr2= NULL; //prefer to put null 

    // modify(&z);//pass address for function
    // swaping(&z ,&b);
    //the two pointers have the same size the value depends on your laptop  
    
   // printf("z : %d , b :%d " , z , b);
  // printf("%d , %d" , sizeof(ptr1) , sizeof(ptr2));


}

void modify(int *x){ 
    *x = 10 ; //derefrance 
}
void swaping (int *x , int *y){
      *x =*x ^*y;
      *y= *y ^*x ;
      *x=  *x ^*y ;
}