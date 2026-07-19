#include <stdio.h>

int npr(int n , int r);
int facturial(int n );


void main(void){


   int n ,r ,result_npr ;

   printf("plz enter n and r");
   scanf("%d %d" , &n , &r );
   result_npr = npr(n , r) ;
   printf("nPr : %d , nCr:%d " , result_npr   );
   



    
}


int npr(int n , int r){
    //nPr = n! / (n − r)!
    int npr = facturial(n) / facturial(n - r) ;
    return npr ;
    
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
