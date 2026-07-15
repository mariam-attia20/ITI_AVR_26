#include <stdio.h>

void main(void) {
	//---swaping between two values ------
	//int x = 10;
	//int y = 50 ;
	//int z ;
	//z = x ;
	//x = y ;
	//y = z ;
	//=====or=====
	//x = x ^ y ;
	//y = x ^ y ;
	//x = x ^ y ;
	//printf(" x : %d , y : %d" , x , y);
	float first ,sec, tird, four , five ;
	printf(" Enter marks of five subjects:");
	scanf(" %f %f %f %f %f ", &first ,&sec ,&tird , &four ,&five);
	float total = first+sec +tird +four+five ;
	float average = (total)/5 ;
	float percentage = average ;
	printf(" %0.1f\n %0.1f\n %0.1f\n ", total ,average ,percentage);
	 
	
    
}