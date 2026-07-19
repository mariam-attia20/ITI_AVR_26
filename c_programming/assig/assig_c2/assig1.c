#include<stdio.h>


void main(void){

    int num1 , num2 ,num3;

    printf("enter three numbers plz : ");
    scanf("%d %d %d " , &num1 , &num2 , &num3);

    if(num1 > num2 && num1> num3){
        printf("num1 is the biggest %d" , num1);
    }else if ( num2 > num3 ){
        printf("num2 is the biggest %d" , num2);
    }else {
        printf ("num3 is the biggest: %d" , num3);
    }
}
