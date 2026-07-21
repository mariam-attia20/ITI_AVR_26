#include<stdio.h>

typedef union {
    char id ;
     short int sal ;
     int y;
}u;


void main(void){
    u u1;
    u1.sal = 10;
    u1.id= 3;
    u1.y = 4576;
    printf("%d\n" , u1.sal); //it will print the value of 4576 override.
    // printf("%zu\n" , sizeof(u));

}