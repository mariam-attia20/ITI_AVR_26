#include <stdio.h>
#include "STD_TYPES.h"
// void toggeleled(void);
void PrintName(const char *ptr) ;
void main(void){
    // char x;
     int y= 20;
     int x = 10 ;
    // float z;
    // double d ;
    // printf("size of char : %d\n" , sizeof(x));
    // printf("size of int : %d\n," , sizeof(y));
    // printf("size of float : %d\n" , sizeof(z));
    // printf("size of double : %d\n" , sizeof(d));
   // toggeleled();
//    int *ptr1 = &x ;
//    printf("befor ");
//    *ptr1 = 30 ;
//    ptr1 = &y ;
//    *ptr1 = 40 ; 
//    printf(" x = %d\n" , x);
//    printf("y =  %d\n" , y);
char name[] = "memma" ;
PrintName(name);
    
}
//  unsigned -> u
//  signed -> s
//  char -> 8bit
//  typedef unsigned char u8;
//  typedef signed char s8;
//  typedef signed int u32;
//  typedef unsigned int u32;
//  typedef float f32;
//  typedef double f64;
// void toggeleled(void){
//     //to make the compiler know that the old value was saved and will take the decision depend on this value;
//     static int led_state ;
//     for(int i =0 ; i< 6 ; i++)
//     if(led_state== 1){
//         printf("led on\n");
//         led_state = 0;
//     }else{
//         printf("led off\n");
//         led_state = 1;
//     }
// }
void PrintName(const char *ptr){
    while(*ptr != '\0'){
        printf("%c" , *ptr);
        ptr++;
    }

}