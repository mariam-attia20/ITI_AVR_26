#include <stdio.h>
#include "STD_TYPES.h"
typedef struct 
{
    int salary ;
    int bonus ;
    int deduction ;
}employee;
void main(void){
    employee ahmed  , waleed , amr;
   
    printf("enter ahmed data :");
    scanf("%d %d %d" , &(ahmed.bonus) ,&(ahmed.deduction),&(ahmed.salary));
    printf("enter amr data :");
    scanf("%d %d %d" , &(amr.bonus) ,&(amr.deduction),&(amr.salary));
    printf("enter waleed data :");
    scanf("%d %d %d" , &(waleed.bonus) ,&(waleed.deduction),&(waleed.salary));
    int total = ((ahmed.bonus)-(ahmed.deduction)+(ahmed.salary));
    printf("total value  need" , total );
}