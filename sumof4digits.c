#include <stdio.h>
/*********************
   My name is Leon_Alexandre ID: 1558682
   
   Write a function that takes an integer as its parameters and returns sum of digits
   This version works for 4 digit numbers, but I have included a version that 
   counts the number of digits then add them, but it only works for 
   up to ten digit integers in my folder.
   
**********************/

int sumOfFour( int C);

int main()
{
	int C;
	
	printf("enter the number you want dissected:");
	scanf("%d",&C);
	
	printf("The sum of its digits is %d\n",sumOfFour(C));

	system("Pause");
return 0;	
}

int sumOfFour( int C)
{
	int w,x,y,z;
	
	w = C / 1000;
	C = C % 1000;
	x = C / 100;
	C = C % 100;
	y = C / 10;
	z = C % 10;
	

	
	return (w+x+y+z);
	
}