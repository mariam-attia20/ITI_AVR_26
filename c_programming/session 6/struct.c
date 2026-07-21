#include <stdio.h>


// struct mystruct {
//     int x ;
//     float y ;
// };
typedef struct{
    char id ;
    char grades[100];
}class;
struct data
{
    int salary ;
    int bonus ;
    int deduction ;
};
//how to use typedef with  struct 
typedef struct data New_name ;
//or 
// typedef struct data
// {
//     int salary ;
//     int bonus ;
//     int deduction ;
// } New_name;
typedef struct {
    int id;
    int sal ;
}Employee;


void main (void){
    //array of structs
    Employee iti[10]={
        {0 , 1000},
        {1 , 2000},
        {2 , 4000}
    };
    iti[0].id=10;

    New_name d ; //use typedef for struct
    //struct of array
    class A = {1 , {20 , 30 , 90, 70}};
    printf("%d\n" , A.grades[2]) ;
    A.grades[2] = 100 ;
    printf("%D\n ", A.grades[2]);
    // struct mystruct A;
    // A.x = 10 ;
    // A.y = 12.5;
    // printf("%d\n" , A.x);
    // printf("%f" , A.y);
   // struct data AMR ;
    //you can call the struct object in two ways
    // struct data Ahmed = { 5000, 700, 66};
    // AMR.bonus =300;
    // AMR.salary= 8000;
    // AMR.deduction =200 ;
    // printf("plz enter ahmed data: ");
    // scanf("%d  %d %d" , &(Ahmed.salary) , &(Ahmed.bonus) ,&(Ahmed.deduction));

    //printf("plz enter ahmed data: ");
    // scanf("%d  %d %d" , &(AMR.bonus) , &(AMR.deduction),&(AMR.salary));
   // printf("salary : " , Ahmed.salary+ AMR.salary);
    

}

