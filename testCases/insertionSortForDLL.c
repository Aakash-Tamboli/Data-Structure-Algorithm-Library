#include<stdio.h>
#include<ds.h>
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
OperationDetail error;
DoublyLinkedList *dll;
DoublyLinkedListIterator iter0,iter1;
int num,n,i;
dll=createDoublyLinkedList(sizeof(int),&error);
if(error.succ==false)
{
printf("Code: %d\n",error.code);
return 0;
}
for(i=10;i>=1;i--) addToDoublyLinkedList(dll,&i,&error);
iter0=getDoublyLinkedListIterator(dll,&error);
if(error.succ==true)
{
while(hasNextInDoublyLinkedList(&iter0))
{
getNextElementFromDoublyLinkedList(&iter0,&num,&error);
printf("%d\n",num);
}
}
printf("Before applying Sorting algo\n");
insertionSortForDLL(dll,0,9,&error,INTComparator);
printf("After applying sorting algo\n");
iter1=getDoublyLinkedListIterator(dll,&error);
if(error.succ==true)
{
while(hasNextInDoublyLinkedList(&iter1))
{
getNextElementFromDoublyLinkedList(&iter1,&n,&error);
printf("%d\n",n);
}
}
destroyDoublyLinkedList(dll);
return 0;
}