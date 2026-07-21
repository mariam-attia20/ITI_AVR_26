#include <stdio.h>
enum week{
    fri = 5 , 
    sat = 7,
    sun //assigned as 8 
}; //cmpiler increas the next elemenator by one as a defult if you donot assigned

enum states{
    faild,
    passed
};


//enum with struct 
typedef struct
{
   char id ;
   enum states std_state ;
} std;
 
void main(void){
    enum week week_one;
    // week_one= fri;
    // printf("%d\n" , week_one);
    // week_one = sat;
    // printf("%d\n" , week_one);
    // week_one = sun ;
    // printf("%d\n" , week_one);
    std s1 = {1, passed};
    std s2 = {1, 5};
    printf("%d\n" , s2.std_state); //will print 5 
    printf("%d\n" , s1.std_state); //will print 1
    printf("%zn\n" , sizeof(enum states));

} 