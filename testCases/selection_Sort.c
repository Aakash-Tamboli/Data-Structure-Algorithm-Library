#include<stdio.h>
#include<algo.h>
#include<stdlib.h>
int INTComparator(void *left,void *right)
{
int *i,*j;
i=(int *)left;
j=(int *)right;
return (*i)-(*j);
}
int main()
{
OperationDetail err;
int *x,req,i;
printf("Enter your requirement: ");
scanf("%d",&req);
if(req<=0) return 0;
x=(int *)malloc(sizeof(int)*req);
if(x==NULL) return 0;
for(i=0;i<req;i++)
{
printf("Enter the Number: ");
scanf("%d",&x[i]);
}
selectionSort(x,0,req-1,sizeof(int),&err,INTComparator);
if(err.succ==false) printf("Something Wrong\n");
for(i=0;i<req;i++) printf("%d\n",x[i]);
free(x);
return 0;
}