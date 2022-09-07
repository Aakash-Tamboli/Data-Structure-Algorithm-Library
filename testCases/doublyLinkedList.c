#include<stdio.h>
#include<ds.h>
int main()
{
int num,n,i;
OperationDetail error;
DoublyLinkedList *dll;
DoublyLinkedListReverseIterator rdllIter;
dll=createDoublyLinkedList(sizeof(int),&error);
if(error.succ==true) printf("dll created\n");
num=1;
addToDoublyLinkedList(dll,(const void *)&num,&error);
if(error.succ==true) printf("%d is add To dll\n",num);
num=2;
addToDoublyLinkedList(dll,&num,&error);
if(error.succ==true) printf("%d is add To dll\n",num);
num=3;
addToDoublyLinkedList(dll,&num,&error);
if(error.succ==true) printf("%d is add To dll\n",num);
num=4;
addToDoublyLinkedList(dll,&num,&error);
if(error.succ==true) printf("%d is add To dll\n",num);
num=5;
addToDoublyLinkedList(dll,&num,&error);
if(error.succ==true) printf("%d is add To dll\n",num);
num=6;
addToDoublyLinkedList(dll,&num,&error);
if(error.succ==true) printf("%d is add To dll\n",num);
rdllIter=getDoublyLinkedListReverseIterator(dll,&error);
if(error.succ==true)
{
printf("List starts from:\n");
while(hasPreviousInDoublyLinkedList(&rdllIter))
{
getPreviousElementFromDoublyLinkedList(&rdllIter,(void *)&n,&error);
if(error.succ==true) printf("%d",n);
if(hasPreviousInDoublyLinkedList(&rdllIter)) printf("--->");
}

}
else
{
printf("Unable to create Iterator of dll\n");
}
destroyDoublyLinkedList(dll);
return 0;
}