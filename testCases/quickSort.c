#include<stdio.h>
#include<stdlib.h>
#include<algo.h>
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
printf("Enter an Number :");
scanf("%d",&x[i]);
}
printf("Using Quick Sort\n");
quickSort(x,0,req-1,sizeof(int),&err,INTComparator);
if(err.succ) printf("Your collection is sorted\n");
else printf("Something wrong error code is: %d\n",err.code);
for(i=0;i<req;i++) printf("%d\n",x[i]);
return 0;
}
