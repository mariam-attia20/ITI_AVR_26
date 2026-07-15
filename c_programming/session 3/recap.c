# include <stdio.h>
void main(void){

    int num , factorial=1;

    printf("enter you number ");
    scanf("%d" , &num);

    for (int i = 1 ; i < num+1 ; i++){
        // factorial = (num) * (num -i);
        factorial= factorial* (i);

        // printf("%d \n" , factorial);
    }
    printf("%d\n" , factorial);



}