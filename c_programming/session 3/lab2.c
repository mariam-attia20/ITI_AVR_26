#include <stdio.h>

// check palindrome number 
void palindrome (int );

 void main (void){
    int num ;
    printf(" enter number");
    scanf("%d", &num);
    palindrome(num);

 }

 void palindrome( int num ){
    
    int original = num;
    int reversed = 0;
    int remainder;

    // Reverse the digits of the number
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
     if (original == reversed) {
        printf(" is a palindrome number.\n");
    } else {
        printf(" is NOT a palindrome number.\n");
    }

    // Compare original number with its reversed counterpart

}
