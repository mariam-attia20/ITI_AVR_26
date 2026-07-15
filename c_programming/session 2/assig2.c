#include <stdio.h>
void main(void){

    int num1 ,num2 , opperation , result;

    printf("plz enter two numbers : ");
    scanf("%d %d" , &num1 , &num2);

    printf("enter number 1 for addition , number 2 for subtraction ,number 3 for mult. , number 4 for division");
    scanf(" %d" , &opperation);

    switch(opperation){
        case 1:
        result = num1 + num2 ;
        break;
        case 2 :
        result = num1 - num2 ;
        break;
        case 3 :
        result = num1 * num2 ;
        break;
        case 4:
        result = num1 / num2 ;
        break;
        
    }
}