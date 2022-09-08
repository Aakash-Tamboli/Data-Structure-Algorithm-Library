#include<stdio.h>
#include<ds.h>
#include<stdlib.h>
#include<algo.h>
int main()
{
OperationDetail err;
int i;
int x[10]={1,2,3,4,5,6,7,8,9,10};
printf("Before apply sorting algo\n");
for(i=0;i<=9;i++) printf("%d\n",x[i]);
addressCalculationSort(x,0,9,sizeof(int),&err,DEC);
if(err.succ==false)
{
printf("Something wrong, code: %d\n",err.code);
}
printf("After apply sorting algo\n");
for(i=0;i<=9;i++) printf("%d\n",x[i]);
return 0;
}