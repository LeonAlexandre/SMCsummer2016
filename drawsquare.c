#include <stdio.h>

/*******
My name is LEON ALEXANDRE

This program prompts the user to type a number and draws a square of length entered
********/

int main()
{
int i,j,k,l; //muh counters

printf("Enter length of square:");
scanf("%d",&i);

for(j=0;j<i;j++)
{	printf("*");
}	
for(k=0;k<(i-2);k++)
{
printf("\n*"); 
	for(l=0;l<(i-2);l++) // printf the blanks
		{printf(" ");}
printf("*");
}
printf("\n");
for(j=0;j<i;j++)
{	printf("*");
}	

printf("\n");




system("pause");
return 0;
}