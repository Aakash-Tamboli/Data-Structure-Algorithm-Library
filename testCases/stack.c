#include<stdio.h>
#include<ds.h>
int main()
{
int i;
char m,data;
OperationDetail err;
Stack s;
initStack(&s,sizeof(char));
m='d';
pushOnStack(&s,(const void *)&m,&err);
m='r';
pushOnStack(&s,(const void *)&m,&err);
m='o';
pushOnStack(&s,(const void *)&m,&err);
m='L';
pushOnStack(&s,(const void *)&m,&err);
m=' ';
pushOnStack(&s,(const void *)&m,&err);
m='e';
pushOnStack(&s,(const void *)&m,&err);
m='h';
pushOnStack(&s,(const void *)&m,&err);
m='T';
pushOnStack(&s,(const void *)&m,&err);
m=' ';
pushOnStack(&s,(const void *)&m,&err);
m='e';
pushOnStack(&s,(const void *)&m,&err);
m='s';
pushOnStack(&s,(const void *)&m,&err);
m='i';
pushOnStack(&s,(const void *)&m,&err);
m='a';
pushOnStack(&s,(const void *)&m,&err);
m='r';
pushOnStack(&s,(const void *)&m,&err);
m='P';
pushOnStack(&s,(const void *)&m,&err);
while(!isStackEmpty(&s))
{
popFromStack(&s,(void *)&data,&err);
if(err.succ==false)
{
printf("Something Problem in your stack\n");
break;
}
else
{
printf("%c",data);
}
}
printf(":  comes from stack\n");
return 0;
}