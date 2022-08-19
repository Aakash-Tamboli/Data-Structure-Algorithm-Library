#include<stdio.h>
#include<stdlib.h>
#include<algo.h>

typedef struct student
{
int roll;
char name[32];
}Student;


int INTComparator(void *left,void *right)
{
int *i,*j;
i=(int *)left;
j=(int *)right;
return (*i)-(*j);
}

int studentComparator(void *left,void *right) // (boolian predicate)
{
Student *s1,*s2;
s1=(Student *)left;
s2=(Student *)right;
return s1->roll-s2->roll;
}
int testCases(void (*functionWhoToBeTested) (void *,int ,int ,int ,OperationDetail *,int (*predicate) (void *,void *)))
{
OperationDetail error;
int lb1,ub1,flag,lb2,ub2;
int allTestCasesResult[2]={0,0};
int x[10],req,i;
int ans[10];
ans[0]=1;
ans[1]=2;
ans[2]=3;
ans[3]=4;
ans[4]=5;
ans[5]=6;
ans[6]=7;
ans[7]=8;
ans[8]=9;
ans[9]=10;

x[0]=10;
x[1]=9;
x[2]=8;
x[3]=7;
x[4]=6;
x[5]=5;
x[6]=4;
x[7]=3;
x[8]=2;
x[9]=1;


lb1=0;
ub1=9;

functionWhoToBeTested(x,lb1,ub1,sizeof(int),&error,INTComparator);
if(error.succ==true)
{
printf("1st testCase Pass\n");
allTestCasesResult[0]=1;
for(i=0;i<=9;i++)
{
if(x[i]!=ans[i])
{
printf("Problem in testCases :%d\n",1);
allTestCasesResult[0]=0;
break;
}
} // for ends
}
else
{
printf("1st testCase fails\n");
}
// 1st testcases ends
// 2nd testCase starts
x[0]=1;
x[1]=2;
x[2]=3;
x[3]=4;
x[4]=5;
x[5]=10;
x[6]=9;
x[7]=8;
x[8]=7;
x[9]=6;
lb2=5;
ub2=9;

functionWhoToBeTested(x,lb2,ub2,sizeof(int),&error,INTComparator);
if(error.succ==true)
{
printf("2nd testCase Passed\n");
allTestCasesResult[1]=1;
for(i=5;i<=9;i++)
{
if(x[i]!=ans[i])
{
printf("Problem in testCases :%d\n",2);
allTestCasesResult[1]=0;
break;
}
} // for ends
}
else
{
printf("2nd testCase passed\n");
}
// checking testCases
flag=1;
for(i=0;i<=1;i++)
{
if(allTestCasesResult[i]==0)
{
printf("Test Number %d is failed\n",i+1);
flag=0;
}
}
if(flag==0) return 0;
else return 1;
}
int main()
{
int result;
result=testCases(bubbleSort);
if(result) printf("All testcases passed\n");
return 0;
}