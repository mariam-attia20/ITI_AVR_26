#include <stdio.h>

void increament(void) ;
void printing_hello(void) ;

void main(void){
    
    // printf("%hhu\n" , y); //half half unsigned 
    printing_hello();

}
void increament(void){
    int counter = 0 ;
    counter++;
    printf("%d\n" , counter);
}
void printing_hello(void){
    printf("hello");
}