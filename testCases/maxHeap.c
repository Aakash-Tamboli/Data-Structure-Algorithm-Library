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
printf("Enter your requirement: ");
scanf("%d",&req);
if(req<=0) return 0;
x=(int *)malloc(sizeof(int)*req);
if(x==NULL) return 0;
for(i=0;i<req;i++)
{
printf("Enter a Number: ");
scanf("%d",&x[i]);
}
printf("Convert Into Max Heap\n");
toMaxHeap(x,4,9,sizeof(int),&err,INTComparator);
if(err.succ==true) printf("Your collection is successfully converted\n");
else printf("unable to convert your collection check on error code %d\n",err.code);
for(i=0;i<req;i++) printf("Element: %d\n",x[i]);
free(x);
return 0;
}