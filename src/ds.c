#ifndef DS_C
#define DS_C 1245
#include<common.h>
#include<ds.h>
#include<stdlib.h>
#include<string.h>
// just for testing
#include<stdio.h>
void initStack(struct __Stack__ *stack,int sizeOfOneElement)
{
if(stack==NULL || sizeOfOneElement<=0) return;
if(stack->node!=NULL)
{
stack->node=NULL;
stack->size=0;
stack->initFlag=true;
stack->sizeOfOneElement=sizeOfOneElement;
}
}
void pushOnStack(struct __Stack__ *stack,const void *data,OperationDetail *error)
{
StackNode *node;
if(error) error->succ=false;
if(stack==NULL)
{
if(error) error->code=3;
return;
}
if(data==NULL)
{
if(error) error->code=4;
return;
}
if(stack->initFlag!=true)
{
if(error) error->code=5;
return;
}
node=(StackNode *)malloc(sizeof(StackNode));
if(node==NULL)
{
if(error) error->code=2;
return;
}
node->ptr=(void *)malloc(sizeof(stack->sizeOfOneElement));
if(node->ptr==NULL)
{
if(error) error->code=2;
free(node);
return;
}
memcpy(node->ptr,(const void *)data,stack->sizeOfOneElement);
node->next=stack->node;
stack->node=node;
stack->size++;
if(error)
{
error->code=0;
error->succ=true;
}
}
void popFromStack(struct __Stack__ *stack,void *data,OperationDetail *error)
{
StackNode *j;
if(error) error->succ=false;
if(stack==NULL)
{
if(error) error->code=3;
return;
}
if(data==NULL)
{
if(error) error->code=4;
return;
}
if(stack->initFlag!=1 || stack->node==NULL)
{
if(error) error->code=5;
return;
}
memcpy(data,(const void *)stack->node->ptr,stack->sizeOfOneElement);
free(stack->node->ptr);
j=stack->node;
stack->node=stack->node->next;
free(j);
stack->size--;
if(error)
{
error->code=0;
error->succ=true;
}
}
int isStackEmpty(struct __Stack__ *stack)
{
if(stack==NULL) return 0;
return stack->node==NULL;
}
void clearStack(struct __Stack__ *stack)
{
StackNode *j;
if(stack==NULL || stack->initFlag!=true || stack->node==NULL) return;
while(stack->node!=NULL)
{
free(stack->node->ptr);
j=stack->node;
stack->node=stack->node->next;
free(j);
}
stack->size=0;
}
void initQueue(struct __Queue__ *queue,int sizeOfOneElement)
{
if(queue==NULL || sizeOfOneElement<=0) return;
queue->sizeOfOneElement=sizeOfOneElement;
if(queue->front!=NULL)
{
/*
Now I realised Why C++ have constructor feature this is one of the key
reason major bug in this queue and stack
assume user first call init method for queue or stack
so in queue attributes after initialized that look like:
front=NULL;
rear=NULL;
s‪ize=0;
initFlag=true that is 1 (one)
sizeofOneElement = what user wants
ok cool
Now user add some data in queue and again calling init function.
now our attribute front is not equal NULL so if block code is executed
then I assign again NULL so memory leak issue is present
now you might be thinking intiFlag attribute so lets workout
let say you give condition
if(intiFlag!=0) clearQueue or clearStack now thinking it might be help 
when user re-calling initQueue or stack but what about the first time
lets see user create Queue type structure and queue attribute value may
be
front=garbage
rear=garbage
size=garbage
sizeofOneElement=garbage
now user call function initQueue.
if block of code is executed because front is not equal to NULL
then initFlag also have garbage then you call clear stack check out
the code of clearQueue now see you free(UNKOWN MEMORY) so yes it idea
also fails
*/
queue->front=NULL;
queue->rear=NULL;
queue->size=0;
queue->initFlag=true;
queue->sizeOfOneElement=sizeOfOneElement;
}
}
void addToQueue(struct __Queue__ *queue,const void *data,OperationDetail *error)
{
QueueNode *node;
if(error) error->succ=false;
if(queue==NULL)
{
if(error) error->code=3;
return;
}
if(data==NULL)
{
if(error) error->code=4;
return;
}
if(queue->initFlag!=true)
{
if(error) error->code=5;
return;
}
node=(QueueNode *)malloc(sizeof(QueueNode));
if(node==NULL)
{
if(error) error->code=2;
return;
}
node->ptr=(void *)malloc(sizeof(queue->sizeOfOneElement));
if(node->ptr==NULL)
{
if(error) error->code=2;
free(node);
return;
}
memcpy(node->ptr,(const void *)data,queue->sizeOfOneElement);
if(queue->rear==NULL && queue->front==NULL)
{
queue->rear=node;
queue->front=node;
node->next=NULL;
queue->size++;
if(error)
{
error->code=0;
error->succ=true;
}
return;
}
queue->rear->next=node;
node->next=NULL;
queue->rear=node;
queue->size++;
if(error)
{
error->code=0;
error->succ=true;
}
}
void removeFromQueue(struct __Queue__ *queue,void *data,OperationDetail *error)
{
QueueNode *j;
if(error) error->succ=false;
if(queue==NULL)
{
if(error) error->code=3;
return;
}
if(data==NULL)
{
if(error) error->code=4;
return;
}
if(queue->initFlag!=1)
{
if(error) error->code=5;
return;
}
memcpy(data,(const void *)queue->front->ptr,queue->sizeOfOneElement);
free(queue->front->ptr);
j=queue->front;
queue->front=queue->front->next;
if(queue->front==NULL)
{
queue->rear=NULL;
queue->front=NULL;
}
free(j);
queue->size--;
if(error)
{
error->code=0;
error->succ=true;
}
}
int isQueueEmpty(struct __Queue__ *queue)
{
if(queue==NULL) return 0;
return queue->front==NULL;
}
void clearQueue(struct __Queue__ *queue)
{
QueueNode *j;
if(queue==NULL || queue->front!=NULL) return;
while(!isQueueEmpty(queue))
{
free(queue->front->ptr);
j=queue->front;
queue->front=queue->front->next;
free(j);
}
queue->size=0;
queue->front=NULL;
queue->rear=NULL;
}

// implementation of Doubly Linked List
DoublyLinkedList * createDoublyLinkedList(int sizeOfOneElement,OperationDetail *error)
{
DoublyLinkedList *doublyLinkedList;
if(error) error->succ=false;
doublyLinkedList=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
if(doublyLinkedList==NULL)
{
if(error) error->code=2;
return NULL;
}
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
doublyLinkedList->sizeOfOneElement=sizeOfOneElement;
if(error)
{
error->succ=true;
error->code=0;
}
}
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL) return 0;
return doublyLinkedList->size;
}

void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
DoublyLinkedListNode *node;
if(doublyLinkedList==NULL) return;
node=doublyLinkedList->start;
while(doublyLinkedList->start!=NULL)
{
node=doublyLinkedList->start;
doublyLinkedList->start=doublyLinkedList->start->next;
free(node->ptr);
free(node);
}
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
}

void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL) return;
clearDoublyLinkedList(doublyLinkedList);
free(doublyLinkedList);
}

void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,const void *ptr,OperationDetail *error)
{
DoublyLinkedListNode *node;
if(error) error->succ=false;
if(doublyLinkedList==NULL) return;
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)
{
if(error) error->code=2;
return;
}
node->ptr=(void *)malloc(doublyLinkedList->sizeOfOneElement);
if(node->ptr==NULL)
{
free(node);
if(error) error->code=2;
return;
}
memcpy(node->ptr,(const void *)ptr,doublyLinkedList->sizeOfOneElement);
node->next=NULL;
node->previous=NULL;
if(doublyLinkedList->start==NULL)
{
doublyLinkedList->start=node;
doublyLinkedList->end=node;
}
else
{
doublyLinkedList->end->next=node;
node->previous=doublyLinkedList->end;
doublyLinkedList->end=node;
}
doublyLinkedList->size++;;
if(error)
{
error->succ=true;
error->code=0;
}
}

void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,const void *ptr,OperationDetail *error)
{
DoublyLinkedListNode *node,*p1;
int x;
if(error) error->succ=false;
if(doublyLinkedList==NULL)
{
if(error) error->code=3;
return;
}
if(index<0 || index>doublyLinkedList->size)
{
if(error) error->code=9;
return;
}
if(index==doublyLinkedList->size)
{
addToDoublyLinkedList(doublyLinkedList,ptr,error);
return;
}
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)
{
if(error) error->code=2;
return;
}
node->ptr=(void *)malloc(doublyLinkedList->sizeOfOneElement);
if(node->ptr==NULL)
{
free(node);
if(error) error->code=2;
return;
}
memcpy(node->ptr,(const void *)ptr,doublyLinkedList->sizeOfOneElement);
node->next=NULL;
node->previous=NULL;
if(index==0)
{
node->next=doublyLinkedList->start;
doublyLinkedList->start->previous=node;
doublyLinkedList->start=node;
doublyLinkedList->size++;
if(error)
{
error->succ=true;
error->code=0;
}
return;
}
p1=doublyLinkedList->start;
x=0;
while(x<index)
{
p1=p1->next;
x++;
}
node->next=p1;
node->previous=p1->previous;
p1->previous->next=node;
p1->previous=node;
doublyLinkedList->size++;
if(error)
{
error->succ=true;
error->code=0;
}
}

void removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,int index,OperationDetail *error)
{
DoublyLinkedListNode *p1;
int x;
if(error) error->succ=false;
if(doublyLinkedList==NULL)
{
if(error) error->code=3;
return;
}
if(index<0 || index>doublyLinkedList->size)
{
if(error) error->code=9;
return;
}
p1=doublyLinkedList->start;
x=0;
while(x<index)
{
p1=p1->next;
x++;
}
memcpy(ptr,(const void *)p1->ptr,doublyLinkedList->sizeOfOneElement);
free(p1->ptr);
if(doublyLinkedList->start==p1 && doublyLinkedList->end==p1)
{
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
}
else if(doublyLinkedList->start==p1)
{
doublyLinkedList->start=doublyLinkedList->start->next;
doublyLinkedList->start->previous=NULL;
}else if(doublyLinkedList->end==p1)
{
doublyLinkedList->end=doublyLinkedList->end->previous;
doublyLinkedList->end->next=NULL;
}else
{
p1->previous->next=p1->next;
p1->next->previous=p1->previous;
}
free(p1);
doublyLinkedList->size--;
if(error) error->code=0;
} // function ends

void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList * sourceDoublyLinkedList,OperationDetail *error)
{
DoublyLinkedListNode *s,*e,*t,*node;
bool done;
if(error) error->succ=false;
if(targetDoublyLinkedList==NULL)
{
if(error) error->code=3;
return;
}
if(sourceDoublyLinkedList==NULL || sourceDoublyLinkedList->size==0)
{
if(error) error->code=3;
return;
}
if(sourceDoublyLinkedList->sizeOfOneElement!=targetDoublyLinkedList->sizeOfOneElement)
{
if(error) error->code=10;
return;
}
s=NULL;
e=NULL;
done=true;
t=sourceDoublyLinkedList->start;
while(t!=NULL)
{
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=(void *)malloc(sourceDoublyLinkedList->sizeOfOneElement);
if(node->ptr==NULL)
{
free(node);
done=false;
break;
}
memcpy(node->ptr,(const void *)t->ptr,sourceDoublyLinkedList->sizeOfOneElement);
node->next=NULL;
node->previous=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
node->previous=e;
e=node;
}
t=t->next;
}

if(done==false)
{
while(s!=NULL)
{
node=s;
s=s->next;
free(node->ptr);
free(node);
}
return;
}
if(targetDoublyLinkedList->start==NULL)
{
targetDoublyLinkedList->start=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size=sourceDoublyLinkedList->size;
targetDoublyLinkedList->sizeOfOneElement=sourceDoublyLinkedList->sizeOfOneElement;
}
else
{
targetDoublyLinkedList->end->next=s;
s->previous=targetDoublyLinkedList->end;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size+=sourceDoublyLinkedList->size;
}
if(error) error->succ=true;
}

#endif