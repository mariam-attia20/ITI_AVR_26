#include <stdio.h>
#include <stdlib.h>


typedef struct Node_t{
    int data;
    struct Node_t* next ; //point on the next struct so his kind is the same as struct 

}node;
node *head = NULL; //pointer to the  first element 

void addfirst(int value){
    node *ptr = (node*)malloc(sizeof(node)) ;
     if(ptr == NULL){
        printf("failed to allocate\n");
        return 1 ;
    }else{
        ptr -> data = value;
        
    }
}
void main (void){

}