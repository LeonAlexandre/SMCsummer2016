#include <stdio.h>

/*******
My name is LEON ALEXANDRE

This program reads a password and checks whether it is valid.

********/

int main()
{
char ch;
int i,j,k;//initializing the counters
i=0; // total characters
k=0; //digits
j=0; //invalid characters

printf("*******************************************************************\n\nWelcome to the incredible password creation. Here are a couple of rules. \n\tA password must have at least eight characters. \n\tA password consists of only letters and digits. \n\tA password must contain at least two digits.\n\n*******************************************************************\n");

printf("\n\nChoose a password:");
while((ch = getchar())!='\n')
{
	if( (ch >='A' && ch <='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
		{
		if(ch >='0' && ch <='9')
			k++;
		}
	
	else
		{
		printf("\nInvalid character used: %c",ch);
		j++;
		}
	i++;
}

if( i>=8 && k>=2 && j ==0)
	printf("\nPassword is valid. Have a nice day\n");
else
	printf("\nPassword is invalid!!! Calling FBI\n"); 



system("pause");
return 0;
}