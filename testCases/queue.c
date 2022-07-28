#include<stdio.h>
#include<ds.h>
int main()
{
int i;
char m,data;
OperationDetail err;
Queue q;
initQueue(&q,sizeof(char));
m='P';
addToQueue(&q,(const void *)&m,&err);
m='R';
addToQueue(&q,(const void *)&m,&err);
m='A';
addToQueue(&q,(const void *)&m,&err);
m='I';
addToQueue(&q,(const void *)&m,&err);
m='S';
addToQueue(&q,(const void *)&m,&err);
m='E';
addToQueue(&q,(const void *)&m,&err);
m=' ';
addToQueue(&q,(const void *)&m,&err);
m='G';
addToQueue(&q,(const void *)&m,&err);
m='O';
addToQueue(&q,(const void *)&m,&err);
m='D';
addToQueue(&q,(const void *)&m,&err);
// just for checking clearQueue(&q);
printf("(");
while(!isQueueEmpty(&q))
{
removeFromQueue(&q,(void *)&data,&err);
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
printf(")");
printf(":  comes from Queue\n");
if(isQueueEmpty(&q)) printf("Yes Your Queue Data Structure is Empty\n");
else printf("Queue Still have elements\n");
return 0;
}