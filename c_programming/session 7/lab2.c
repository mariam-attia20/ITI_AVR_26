#include <stdio.h>

typedef struct
{
    int hours ;
    int min ;
    int sec ;
}time;
void tdiff(time t1 , time t2 , time* diff ){
    diff->hours = t1.hours - t2.hours ;
    diff->min   = t1.min -t2.min;
    diff ->sec = t1.sec - t2.sec;
}


void main(void){
    time start , end , diff ;
    printf("enter start time : \n");
    scanf("%d %d %d" ,&start.hours , &start.min , &start.sec );

    printf("enter end time : \n");
    scanf("%d %d %d" ,&end.hours , &end.min , &end.sec );
    
    tdiff(start , end ,&diff);
    printf("%d : %d :%d" , diff.hours , diff.min , diff.sec);

}

