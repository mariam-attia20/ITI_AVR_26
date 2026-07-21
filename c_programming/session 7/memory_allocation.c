#include<stdio.h>
#include <stdlib.h> //new library added to allocate memory 
void main(void){
    int x = 300;
    // char y = x ; 
    char y = (char) x ; //casting (deal with x as a char type)
    char *ptr = (char*) malloc(10 *sizeof(char)); //casting for function function return void* //it can work without casting but there is some compilers donot deal with
    if(ptr != NULL){
        printf("allocated successfuly");
    }else{
        printf("failed to allocate\n");
    }
    free(ptr); //free memory allocate
    //another way to allocate 
     int* ptr1= (int*)calloc(10 , sizeof(int));
     if(ptr1 != NULL){
        printf("allocated successfuly");
    }else{
        printf("failed to allocate\n");
    }
    free(ptr1);
    //reallocate for memory
    char * ptr2=(char*)realloc(ptr ,40*sizeof(char));

}