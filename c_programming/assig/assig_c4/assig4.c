#include <stdio.h>

int facturial(int n );
int ncr(int n , int r);
int npr(int n , int r);

void main(void){
    int n ,r ,result_ncr;
    printf("plz enter n and r");
   scanf("%d %d" , &n , &r );
    result_ncr = ncr(n ,r );
}
int facturial(int n ){
    int factorial=1;
    for (int i = 1 ; i < n+1 ; i++){
        // factorial = (num) * (num -i);
        factorial= factorial* (i);

        // printf("%d \n" , factorial);
    }
    return factorial ;
}
int ncr(int n , int r){
    int ncr = npr(n , r)/facturial(r) ;
    return ncr ;
}
int npr(int n , int r){
    //nPr = n! / (n − r)!
    int npr = facturial(n) / facturial(n - r) ;
    return npr ;
    
}