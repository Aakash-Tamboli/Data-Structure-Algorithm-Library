#include<stdio.h>
#include<stdlib.h>
#include<algo.h>
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
fflush(stdin);
}
printf("Sorting Using Linear Sort\n");
radixSort(x,0,req-1,sizeof(int),&err);
if(err.succ==true) printf("Your collection is successfully\n");
else printf("unable to sort your collection check on error code %d\n",err.code);
for(i=0;i<req;i++) printf("Element: %d\n",x[i]);
free(x);
return 0;
}