#include <stdio.h>
void main(void){
    //======bitwise lab======== 
    // char x = 10 ;
    // //set bit 0
    // x = x |(1<<0);
    // printf("%d\n", x);
    // //clear bit 1 
    // x = x & ~(1<<1);
    // printf("%d\n", x);

    // //toogle bit 3 
    // x = x ^ (1<<3) ;
    // printf("%d\n", x);
    // // get bit 2 
    // x =  1 & (x>>2);
    // printf("%d\n", x);
//=====ternally operater =====
    int x ,y ,z ,max, max2 ;
    printf("enter you numbers :");
    scanf("%d %d %d", &x, &y, &z);
    // (x > y ) ? (max = x) : (max = y) ;
    // (max > z) ? (max2 = max) : (max2 = z) ;
    // printf("maximum value is %d " , max2) ;
    //another way 
    max = ((x>y) && (x > z)) ? x :(y > z)? y : z ;
    printf("maximum value is %d " , max) ;
    







}