#include<stdio.h>

typedef struct {
    char id ;
    int sal ;
}employee;


void main(void){
    employee ahmed = {33 , 4500};
    employee* ptr = &ahmed;
    // printf("%d\n", (*ptr).id);
     printf("%d\n", ptr -> id); //  same to printf("%d\n", (*ptr).id);
    (*ptr).id = 5 ;
    printf("%d\n" , (*ptr).id);

}