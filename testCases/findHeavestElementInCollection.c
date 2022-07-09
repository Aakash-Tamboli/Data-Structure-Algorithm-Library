#include<stdio.h>
#include<common.h>
#include<algo.h>
#include<stdlib.h>
int comparator(void *left,void *right)
{
int *i,*j;
i=(int *)left;
j=(int *)right;
return (*i)-(*j);
}
int main()
{
ErrorCode err;
int *x,req,i;
int h;
printf("Enter your requirement: ");
scanf("%d",&req);
fflush(stdin);
if(req<=0) return 0;
x=(int *)malloc(sizeof(int)*req);
for(i=0;i<req;i++)
{
printf("Enter an Number: ");
scanf("%d",&x[i]);
fflush(stdin);
}
findingTheHeavestElement(x,0,req-1,sizeof(int),&err,&h,comparator);
if(err.succ) printf("%d is Heavest Element",h);
else printf("Something Wrong\n");
free(x);
return 0;
}