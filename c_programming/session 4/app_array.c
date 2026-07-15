#include <stdio.h>


void main (void){
//  int arr[6] = {10 , 7, 5 ,12 ,100 ,55} ;
//  for (int i = 0 ; i <5 ; i ++){
//     if( arr[i]== 13){
//         printf(" the number 5 's id : %d" , i );
//         break;
//     }
//  }
    // another solution
    // char target = 5 ;
    // int flag = 0;
    // char arr[] = { 8 ,5 ,9 ,4,2} ; // the output will be 5 as char is 1 byte and we have 5 elements
   // int arr[] = {8 ,5 ,9 ,4 ,2}; //the output will be  20 as int is 4 byte and we have  5 elelments  
//    // char n = sizeof(arr)/sizeof(arr[0]); //divided into first index size as all elements have the same size so you solve different size issu
//     printf ("%d \n" , n);
//     for (char i = 0 ; i <n ; i ++){
//         if(target == arr[i]){
//             flag == 1;
//             break ;
//   };
//   if (flag ==1){
//     printf("exist");
//   }else{
//       printf("not exist");
//   }
//binary search 
    char arr[] = {20, 30, 40, 50, 60, 70, 80};

    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    int mid;
    int target;
    int flag = 0;

    printf("Enter target: ");
    scanf("%d", &target);

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            printf("Index is: %d\n", mid);
            flag = 1;
            break;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    if (!flag)
        printf("Not exist\n");

    return 0;
}

        
