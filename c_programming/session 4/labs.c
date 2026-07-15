#include<stdio.h>

void math(int x , int y , int* sum , int* sub);
void compare(int x , int y , int *max  );
void square_print(int dim );
void main(void){
    int num1 , num2,max ;
    // printf("enter num1  :");
    // scanf("%d " , &num1 );
    // printf("enter num2  :");
    // scanf("%d " , &num2 ); 
   // math( num1 , num2 , &sum , &sub);
   //compare(num1 ,num2 , &max);
    square_print( 4 );
   
   //printf("maximum is : %d" , max);
   // printf("sum result : %d , sub result : %d \n", sum , sub);

    

}
void math(int x , int y , int* sum , int* sub){
    *sum = x + y ;
    *sub = x - y ;
}
void compare(int x , int y , int *max  ){
    if(x > y){
        *max =x ;
    }else{
        *max = y ; 
    }
}
void square_print(int dim ){
    for(int i =0 ; i < dim ; i++ ){
        for (int j = 0 ; j < dim ; j++){
            int col = dim;
            printf("*");

        }
        printf("\n");
    }
    printf("\n");
}

void many_repet(){
    
}