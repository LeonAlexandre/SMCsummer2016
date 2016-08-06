#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/*********************
   My name is Leon Alexandre
   
   This program prompts the size of an array and generates an array of random integers up to two digits.
   The user can decide to shift the array left or right, and how many times consecultively he wants to.
   
**********************/
//prototypes
void arrayprint(int n, int* x);
void shiftit( char C, int i,int n, int* x);


int main()
{
//user choices.
int n; //number of elements in the array
char LoR;
int times;

int * yyz; //array of numbers
int i,j; //counters for loops.



srand(time(NULL));

printf("\n\nWelcome to Array Shifting!\n");
printf("\nEnter the number fo slots needed in the array:");
scanf("%d",&n);

//creating and filling the array
yyz = (int *) malloc(n*sizeof( int ));

for(i=0; i < n ; i++)  //fills array with  numbers up to two digits.
	yyz[i] = rand()%(100);
//Display the array for the user.
printf("Here are the elements of your array: ");
arrayprint(n,yyz);


	
//asks the user to input a character and a number.
fflush(stdin);
printf("\nWhich direction to shift (R/L): ");
scanf("%c",&LoR);
printf("How many times? : ");
scanf("%d",&times);

shiftit(LoR,times,n,yyz);
		
printf("Here is your new array:              ");
arrayprint(n,yyz);

printf("\n\n");
system("pause");
return 0;
}


void shiftit( char C, int i,int n, int* x)//syntax :user choice, times, number of elements, name of array.
{ 
int temp; //temporary location.
int j,k; //counters


//the Right case
if(C == 'R') 
{
	
	for(k = 0; k < i; k++) //
	{
	temp = x[n-1];
		for(j = (n-2); j >= 0; j--) //shifts the array 1 position left
			x[j+1] = x[j];

	x[0] = temp;
	}
	
}


//the Left case
else if(C == 'L') 
{
	for(k = 0; k < i; k++)
	{
		temp = x[0];
		
		for(j = 0; j < (n-1); j++)
			x[j] = x[j+1];
	
	
		x[n-1] = temp;
	}	
}

else
	printf("\nERROR\nPlease enter a valid character!!!!\n");

}

void arrayprint(int n, int* x) //syntax: number of elements, name of array.
{
int j;

for(j=0; j < n; j++)
	printf("%d ",x[j]);
}

