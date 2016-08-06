#include <stdio.h>

/*******
My name is LEON ALEXANDRE
This is a program that translates an alphabetic phone number into numeric form.
********/

int main()
{
char ch;


printf("Enter phone number please:\n \n ");

while ((ch = getchar())!='\n')  //loop scans the whole buffer
{

if( ch >='0' && ch<='9') // series of tests. Invalid cases not included.
	printf("%c",ch);
if( ch >='A' && ch<='C')
	printf("2");
if( ch >='D' && ch<='F')
	printf("3");
if( ch >='G' && ch<='I')
	printf("4");
if( ch >='J' && ch<='L')
	printf("5");
if( ch >='M' && ch<='O')
	printf("6");
if( ch >='P' && ch<='S')
	printf("7");
if( ch >='T' && ch<='V')
	printf("8");
if( ch >='W' && ch<='Z')
	printf("9");
}
printf("\n");
system("pause");
return 0;
}