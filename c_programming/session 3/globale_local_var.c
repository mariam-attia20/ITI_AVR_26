#include <stdio.h>
int fact(int x);

void main (void){


//recursion example 
   int n = fact(5);
   printf("%d" , n);


}
int fact(int x){
    if((x == 1)|| (x == 0))
      return 1 ;
    return(x * fact(x-1));
}