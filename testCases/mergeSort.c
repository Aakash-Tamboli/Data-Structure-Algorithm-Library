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
ErrorCode err;
int *x,req,i;
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
mergeSort(x,0,req-1,sizeof(int),&err,INTComparator);
if(err.succ) printf("your collection is Sorted\n");
else printf("something wrong check error code\n");
for(i=0;i<req;i++) printf("%d\n",x[i]);
free(x);
return 0;
}