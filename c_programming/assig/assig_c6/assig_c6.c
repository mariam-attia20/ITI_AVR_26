#include <stdio.h>
 void main(void){
   int x = 10, y = 20, z = 30;
    int* p = &x;
    int* q = &y;
    int* r = &z;

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    
    printf("*p = %d\n", *p);
    printf("*q = %d\n", *q);
    printf("*r = %d\n", *r);

    r = p;
    p = q;
    q = r;
    printf("\nAfter Swapping:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);

    printf("*p = %d\n", *p);
    printf("*q = %d\n", *q);
    printf("*r = %d\n", *r);

 }