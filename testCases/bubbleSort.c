#include<stdio.h>
#include<stdlib.h>
#include<algo.h>

typedef struct student
{
int roll;
char name[32];
}Student;

int studentComparator(void *left,void *right) // (boolian predicate)
{
Student *s1,*s2;
s1=(Student *)left;
s2=(Student *)right;
return s1->roll-s2->roll;
}
int main()
{
ErrorCode error;
Student *s,*j;
int req;
int i;
int sizeOfOneElement;
printf("enter the requiremnt: ");
scanf("%d",&req);
if(req<=0)
{
printf("Invaild request\n");
return 0;
}
s=(Student *)malloc(sizeof(Student)*req);
j=s;
if(s==NULL)
{
printf("insuffient space in memory\n");
return 0;
}
for(i=0;i<req;i++)
{
printf("Enter the Roll Number: ");
scanf("%d",&j->roll);
printf("Enter the name: ");
scanf("%s",&j->name);
j++;
}
sizeOfOneElement=sizeof(Student);
bubbleSort(s,3,4,sizeOfOneElement,&error,studentComparator);
if(error.succ==false)
{
printf("I unable to Sort Your collection,Check Error Code\n");
printf("Error code is: %d\n",error.code);
free(s);
return 0;
}
else
{
for(i=0;i<req;i++) printf("Name: %s,RollNumber: %d\n",s[i].name,s[i].roll);
free(s);
}
return 0;
}