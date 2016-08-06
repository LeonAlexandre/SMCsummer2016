#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/*********************
   My name is Leon Alexandre
   
**********************/

struct xrec
{
	char fN[11]; //first name (10 char)
	char lN[11]; //last name (10 char)
	char g; // gender (1 char: M/F)
	char ssn[12];	// social (11 char)
	int age; //age (1 number)
	int hs; //hours worked (1 nuber)
	double rT; //rate (1 number double)
	double sal; //salary (1 number)
	struct xrec * next; //Next employee in the list.
	
};
typedef struct xrec Employee;

Employee * addList( Employee * List, Employee temp);
int displayMenu(void);
void PrintList(Employee * List);
void computeSalary( Employee * list);
Employee * deleteFromList(Employee * list, char * t);
void genderSearch(Employee * list);
void overtime(Employee * list);



int main()
{
	FILE * infile;
	Employee temp;
	Employee x[20];
	Employee * first = NULL;
	char tssn[12];
	int com;
	
	infile = fopen("data.txt","r");
	if(infile==NULL)
	{
	  printf("File not found\n");
      exit(1);
	}
	while(fscanf(infile,"%10s %10s %c %11s %d %d %lf",temp.fN,
	temp.lN,&temp.g,temp.ssn,&temp.age,&temp.hs,&temp.rT)!=EOF)
	{
	temp.fN[10] ='\0'; temp.lN[10] ='\0'; temp.ssn[11] ='\0';
	first = addList(first,temp);
	}
	fclose(infile);
	
	computeSalary(first);
	
	do{
		
		com = displayMenu();
		switch(com)
		{   
			case 1 : PrintList(first); printf("\n");break;
			case 2 : 	printf("\n\n -----------Add an Employee -----\n");
						printf("\nenter Last name:");
						fflush(stdin);
						gets(temp.lN);
						printf("\nenter First name:");
						fflush(stdin);
						gets(temp.fN);
						printf("\nenter Gender (M/F):");
						fflush(stdin);
						temp.g = getchar();
						printf("\nenter Social Security Number:");
						fflush(stdin);
						gets(temp.ssn);
						printf("\nenter Age:");
						fflush(stdin);
						scanf("%d",&temp.age);
						printf("\nenter Hours:");
						fflush(stdin);
						scanf("%d",&temp.hs);
						printf("\nenter Rate:");
						fflush(stdin);
						scanf("%lf",&temp.rT);
	
						temp.fN[10] ='\0'; temp.lN[10] ='\0'; temp.ssn[11] ='\0';
						first = addList(first,temp);
					computeSalary(first);

			break;
			case 3 : printf("SSN>>");fflush(stdin);
                     gets(tssn); 
					 
					 first = deleteFromList(first,tssn);
					 break;
			case 4 : genderSearch(first);
					 break;
					 
					 
			case 5 :  overtime(first); break;
			
			case 6 : printf("\nNot implemented yet.\n\n");break;
			
			case 7 : printf("\nNot implement yet.\n\n"); break;
			
			case 8 : infile = fopen("data.txt", "w");
					while(first != NULL)
					{
						fprintf(infile,"%10s %10s %c %11s %d %d %lf\n",first->fN, first->lN,first->g,first->ssn,first->age,first->hs,first->rT);
						first = first->next;
						
					}

					fclose(infile);
					printf("File is updated\n");	break;	
			

		
		}
		
		
	}while(com !=8);
	
	
	
	
	
	return 0;
}

int displayMenu(void)
{
	int c;
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@@ 1.List all employees to the screen with their salary.      @@\n");
	printf("@@ 2.Add an employee to the payroll. @@\n");
	printf("@@ 3.Delete an employee from the payroll.           @@\n");
	printf("@@ 4.  List employees froma  certain gender       @@\n");
	printf("@@ 5.  List all employees with overtime.                  @@\n");
	printf("@@ 6.	Alphabetize the list of employees.                  @@\n");
	printf("@@ 7.	Who gets the highest salary?                 @@\n");
	printf("@@ 8.  Quit and Save.                 @@\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("enter choice>>>");
	scanf("%d",&c);
	return c;
}


Employee * addList( Employee * List, Employee temp)
{
	Employee * new;
	
	new = malloc(sizeof(Employee));
	(*new) = temp;
	new->next = List;
	return new;
}

void PrintList(Employee * List)
{
	printf("\n\n-----------Employee List----------\n");
	printf("Last      First      Gender  SSN         Age Hours  rate Salary\n");
	while(List != NULL)
	{
		printf("%-10s %-10s %c      %11s %d   %d  %6.2lf %6.2lf\n",List->lN, List->fN, List->g, List->ssn, List->age, List->hs, List->rT, List->sal);
		
		
		List = List->next;
	}
	
	
	
}


void computeSalary( Employee * list)
{
	double total;
	while( list != NULL)
	{
		if((list->hs) > 40)
		{
			total = (40*list->rT +(list->hs-40)*(1.5*list->rT));
		}
		else
			total = list->hs*list->rT;
	
	list->sal = total;
	list = list->next;
	}


}

Employee * deleteFromList(Employee * list, char * temp)
{
	Employee * curr, * prev;
	
	for(curr=list, prev = NULL;(curr!=NULL)&&(strcmp(curr->ssn,temp)!=0);
	prev =  curr,curr=curr->next)
	             ;
	if(prev==NULL)
    {
		list = curr->next;
		free(curr);
		printf("The first Employee was deleted\n");
		return list;
	}
    if(curr==NULL)
	{
		printf("Not in the list\n");
		
		
	}else
	{
		prev->next = curr->next;
		printf("The  Employee was deleted\n");
		free(curr);
		
		
		
	}
	return list;

}

void genderSearch(Employee * list)
{
	char choice;
	printf("\n\nWhich gender do you want to display?:");
	fflush(stdin);
	choice = getchar();
	while(list != NULL)
	{
		if(list->g == choice)
			printf("\n%-10s %-10s",list->lN, list->fN);
		list = list->next;
		
	}
	printf("\n\n");
}
void overtime(Employee * list)
{
	
	printf("\n\n-----------These are the Employees with Overtime-----------");

	while(list != NULL)
	{
		if(list->hs > 40)
			printf("\n%-10s %-10s",list->lN, list->fN);
		list = list->next;
		
	}
	printf("\n\n");
}





