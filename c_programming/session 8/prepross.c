#include <stdio.h>
//abslute path 
// #include "C:\Users\LOQ\Desktop\ITI\ITI_AVR\c_programming\session 8\test.h"
// //relative path 
// #include "..\new\test.h"
// #define square(x)  x*x 
// #define fun(x , y)  square(x+y) //x+y*x+y
#define x 8
// #undef x //cancelled the define for x 
int main(){
    //preprosecor does not aunderstand c it just replace things by anther .
    //extention helps the systenm to know which pp i will open the file by it .
    // printf(" hello word\n") ;
    // printf("x from test.h : %d" , x);
    int y = 0;
    #if x== 5
       y = 4;
    #elif x== 8
       y = 7 ;
      // #warning " ohhh" //not  stop compiling 

    //    #error "error" //stop compiling
    #endif

    printf("y value is : %d" , y);
   
    return 0 ;
}