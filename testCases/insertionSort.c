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
ErrorCode err;
int *x,req,i;
printf("Enter yout requirment: ");
scanf("%d",&req);
if(req<=0) return 0;
x=(int *)malloc(sizeof(int)*req);
for(i=0;i<req;i++)
{
printf("Enter an Number: ");
scanf("%d",&x[i]);
}
printf("using Insertion Sort\n");
insertionSort(x,4,req-1,sizeof(int),&err,INTComparator);
if(err.succ==false) printf("Something wrong check error code\n");
else printf("Your collection is sorted\n");
for(i=0;i<req;i++) printf("%d\n",x[i]);
free(x);
return 0;
}