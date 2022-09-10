#include<stdio.h>
#include<ds.h>
int main()
{
OperationDetail error;
int num,n,i;
SinglyLinkedList *sll;
SinglyLinkedListIterator iter;
sll=createSinglyLinkedList(sizeof(int),&error);
if(error.succ==false)
{
printf("Unable to create sll,Code: %d\n",error.code);
return 0;
}
for(i=1;i<=20;i++)
{
addToSinglyLinkedList(sll,&i,&error);
if(error.succ==false)
{
printf("Unable to add into sll, code: %d\n",error.code);
destroySinglyLinkedList(sll);
return 0;
}
}
iter=getSinglyLinkedListIterator(sll,&error);
if(error.succ==true)
{
while(hasNextInSinglyLinkedList(&iter))
{
getNextElementFromSinglyLinkedList(&iter,&num,&error);
if(error.succ==true) printf("%d-->",num);
}
}
destroySinglyLinkedList(sll);
return 0;
}