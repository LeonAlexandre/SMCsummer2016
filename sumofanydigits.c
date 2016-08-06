#include <stdio.h>
#include <math.h>

/*************************

My name is Alexandre Leon  ID: 1558682

This is an attempt to generalize the assignment to any number of digits for the input.
I included <math.h> tp have access to pow function.
I got a satisfactory result which I try to document as accurately as I could.
It only works for numbers up to nine digits.


*****************************/

int digitSum(int C);


int main()
{
int C;
printf("This program sums up the digits of an integer\n Please enter a number:");
scanf("%d",&C);


printf("\nThe sum of all digits is %d \n", digitSum(C));

 system("pause");
 return 0;
}

int digitSum(int C)
{
	int T,D,i,j;
	double rem;
	
	
	
	
	rem = 2;  // Dummy value for variables until they are used.
	j = 1;
	T=0; // Total counter.
	
	while( rem > 0) // This loop counts the number of digits (only for integers)
{
		rem = C - pow(10.0,j);
		j++;
}
	j = j -1;

	printf("\nYour number has %d digits",j); 
			// I get a good result for number with less than 10 digits, but higher returned wrong result(might need long int)
			// It didn't work for numbers whose first digits are a series of zeroes 0 (irellevant when adding the value)



	for(i = j; i >= 0; i--)
{
	int Power;
	Power = pow(10, i);
	
	D = C / Power;
	C = C % Power;
	T = T + D;
}
return T;
	
	
}


