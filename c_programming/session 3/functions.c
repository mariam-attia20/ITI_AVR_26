#include<stdio.h>
//function decleration 
//void print_hello(void);
void facturial(void);
void sign(int  );
void main(void){
    //for function facturial with arg
   // int m ;
    // printf("enter you number ");
    // scanf("%d" , &m);


     /*function address
     we will take it later in pointers 
     print_hello;*/

    //function call 
    // print_hello(); 
    // sign( -5 );   
    facturial();
    
}


// void print_hello(void){
//     printf("hello\n");
// }
void sign(int x ){

    if (x >0){
        printf("number is positive");

    }else{
        printf("number is negative");
    }

}

int facturial_with_arg(int num){
    int factorial=1;


    for (int i = 1 ; i < num+1 ; i++){
        // factorial = (num) * (num -i);
        factorial= factorial* (i);

        // printf("%d \n" , factorial);
    }
    printf("%d\n" , factorial);
}

void facturial(void){
    int num ,factorial=1;

    printf("enter you number ");
    scanf("%d" , &num);

    for (int i = 1 ; i < num+1 ; i++){
        // factorial = (num) * (num -i);
        factorial= factorial* (i);

        // printf("%d \n" , factorial);
    }
    printf("%d\n" , factorial);
}