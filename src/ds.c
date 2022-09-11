#ifndef DS_C
#define DS_C 1245
#include<common.h>
#include<ds.h>
#include<stdlib.h>
#include<string.h>
// just for testing
#include<stdio.h>
Stack * createStack(int sizeOfOneElement,OperationDetail *error)
{
Stack *stack;
if(error) error->succ=false;
if(sizeOfOneElement<=0)
{
if(error) error->code=7;
return NULL;
}
stack=(Stack *)malloc(sizeof(Stack));
if(stack==NULL)
{
if(error) error->code=2;
return NULL;
}
stack->node=NULL;
stack->size=0;
stack->sizeOfOneElement=sizeOfOneElement;
if(error)
{
error->succ=true;
error->code=0;
}
return stack;
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
if(stack->node==NULL)
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
if(stack==NULL || stack->node==NULL) return;
while(stack->node!=NULL)
{
free(stack->node->ptr);
j=stack->node;
stack->node=stack->node->next;
free(j);
}
stack->size=0;
}

void destroyStack(struct __Stack__ *stack)
{
if(stack==NULL) return;
clearStack(stack);
free(stack);
}

void elementAtTopOfStack(struct __Stack__ *stack,void *ptr,OperationDetail *error)
{
if(error) error->succ=false;
if(isStackEmpty(stack))
{
ptr=NULL;
if(error)
{
error->succ=true;
error->code=0;
}
return;
}
memcpy(ptr,(const void *)stack->node->ptr,stack->sizeOfOneElement);
} // function ends


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
// implementation of singlyLinkedList
SinglyLinkedList * createSinglyLinkedList(int sizeOfOneElement,OperationDetail *error)
{
SinglyLinkedList *singlyLinkedList;
if(error) error->succ=false;
singlyLinkedList=(SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
if(singlyLinkedList==NULL)
{
if(error) error->code=2;
return NULL;
}
singlyLinkedList->start=NULL;
singlyLinkedList->end=NULL;
singlyLinkedList->size=0;
singlyLinkedList->sizeOfOneElement=sizeOfOneElement;
if(error)
{
error->succ=true;
error->code=0;
}
return singlyLinkedList;
} // function ends

void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
if(singlyLinkedList==NULL) return;
clearSinglyLinkedList(singlyLinkedList);
free(singlyLinkedList);
}

void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
SinglyLinkedListNode *node;
if(singlyLinkedList==NULL) return;
node=singlyLinkedList->start;
while(singlyLinkedList->start!=NULL)
{
node=singlyLinkedList->start;
singlyLinkedList->start=singlyLinkedList->start->next;
free(node->ptr);
free(node);
}
singlyLinkedList->end=NULL;
singlyLinkedList->size=0;
} // function ends

int getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
if(singlyLinkedList==NULL) return 0;
return singlyLinkedList->size;
} // function ends

void addToSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,OperationDetail *error)
{
SinglyLinkedListNode *node;
if(error) error->succ=false;
if(singlyLinkedList==NULL)
{
if(error) error->code=3;
return;
}
node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL)
{
if(error) error->code=2;
return;
}
node->ptr=(void *)malloc(singlyLinkedList->sizeOfOneElement);
if(node->ptr==NULL)
{
if(error) error->code=2;
free(node);
return;
}
memcpy(node->ptr,(const void *)ptr,singlyLinkedList->sizeOfOneElement);
node->next=NULL;
if(singlyLinkedList->start==NULL)
{
singlyLinkedList->start=node;
singlyLinkedList->end=node;
}
else
{
singlyLinkedList->end->next=node;
singlyLinkedList->end=node;
}
singlyLinkedList->size++;;
if(error)
{
error->succ=true;
error->code=0;
}
} // function ends

void insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,void *ptr,OperationDetail *error)
{
SinglyLinkedListNode *node,*p1,*p2;
int x;
if(error) error->succ=false;
if(singlyLinkedList==NULL)
{
if(error) error->code=3;
return;
}
if(index<0 || index>singlyLinkedList->size)
{
if(error) error->code=9;
return;
}
if(index==singlyLinkedList->size)
{
addToSinglyLinkedList(singlyLinkedList,ptr,error);
return;
}
node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL)
{
if(error) error->code=2;
return;
}
node->ptr=(void *)malloc(singlyLinkedList->sizeOfOneElement);
if(node->ptr==NULL)
{
if(error) error->code=2;
free(node);
return;
}
memcpy(node->ptr,(const void *)ptr,singlyLinkedList->sizeOfOneElement);
node->next=NULL;
if(index==0)
{
node->next=singlyLinkedList->start;
singlyLinkedList->start=node;
singlyLinkedList->size++;
if(error)
{
error->succ=true;
error->code=0;
}
return;
}
p1=singlyLinkedList->start;
x=0;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
node->next=p1;
p2->next=node;
singlyLinkedList->size++;
if(error)
{
error->succ=true;
error->code=0;
}
} // function ends

void removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,int index,OperationDetail *error)
{
SinglyLinkedListNode *p1,*p2;
int x;
if(error) error->succ=false;
if(singlyLinkedList==NULL)
{
if(error) error->code=3;
return;
}
if(index<0 || index>=singlyLinkedList->size)
{
if(error) error->code=9;
return;
}
p1=singlyLinkedList->start;
x=0;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
memcpy(ptr,(const void *)p1->ptr,singlyLinkedList->sizeOfOneElement);
if(singlyLinkedList->start==p1 && singlyLinkedList->end==p1)
{
singlyLinkedList->start=NULL;
singlyLinkedList->end=NULL;
}
else if(singlyLinkedList->start==p1)
{
singlyLinkedList->start=singlyLinkedList->start->next;
}else if(singlyLinkedList->end==p1)
{
singlyLinkedList->end=p2;
singlyLinkedList->end->next=NULL;
}else
{
p2->next=p1->next;
}
free(p1->ptr);
free(p1);
singlyLinkedList->size--;
if(error)
{
error->succ=true;
error->code=0;
}
} // function ends

void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList,SinglyLinkedList *sourceSinglyLinkedList,OperationDetail *error)
{
SinglyLinkedListNode *s,*e,*t,*node;
bool done;
if(error) error->succ=false;
if(targetSinglyLinkedList==NULL)
{
if(error) error->code=3;
return;
}
if(sourceSinglyLinkedList->sizeOfOneElement!=targetSinglyLinkedList->sizeOfOneElement)
{
if(error) error->code=10;
return;
}
if(sourceSinglyLinkedList==NULL || sourceSinglyLinkedList->size==0)
{
if(error)
{
error->succ=true;
error->code=0;
}
return;
}
s=NULL;
e=NULL;
done=true;
t=sourceSinglyLinkedList->start;
while(t!=NULL)
{
node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=(void *)malloc(sourceSinglyLinkedList->sizeOfOneElement);
if(node->ptr==NULL)
{
free(node);
done=false;
break;
}
memcpy(node->ptr,(const void *)t->ptr,sourceSinglyLinkedList->sizeOfOneElement);
node->next=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
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
if(error) error->code=2;
return;
}
if(targetSinglyLinkedList->start==NULL)
{
targetSinglyLinkedList->start=s;
targetSinglyLinkedList->end=e;
targetSinglyLinkedList->size=sourceSinglyLinkedList->size;
targetSinglyLinkedList->sizeOfOneElement=sourceSinglyLinkedList->sizeOfOneElement;
}
else
{
targetSinglyLinkedList->end->next=s;
targetSinglyLinkedList->end=e;
targetSinglyLinkedList->size+=sourceSinglyLinkedList->size;
}
if(error)
{
error->succ=true;
error->code=0;
}
} // function ends

void getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,int index,OperationDetail *error)
{
SinglyLinkedListNode *node;
int x;
if(error) error->succ=false;
if(singlyLinkedList==NULL)
{
if(error) error->code=3;
return;
}
if(index<0 || index>=singlyLinkedList->size)
{
if(error) error->code=9;
return;
}
node=singlyLinkedList->start;
x=0;
while(x<index)
{
node=node->next;
x++;
}
memcpy(ptr,(const void *)node->ptr,singlyLinkedList->sizeOfOneElement);
if(error)
{
error->succ=true;
error->code=0;
}
} // function ends

SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList,OperationDetail *error)
{
SinglyLinkedListIterator singlyLinkedListIterator;
singlyLinkedListIterator.node=NULL;
if(error) error->succ=false;
if(singlyLinkedList==NULL)
{
if(error) error->code=3;
return singlyLinkedListIterator;
}
if(singlyLinkedList->start==NULL) 
{
if(error)
{
error->succ=true;
error->code=0;
}
return singlyLinkedListIterator;
}
if(error)
{
error->succ=true;
error->code=0;
}
singlyLinkedListIterator.node=singlyLinkedList->start;
singlyLinkedListIterator.sizeOfOneElement=singlyLinkedList->sizeOfOneElement;
return singlyLinkedListIterator;  
} // function ends

bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator)
{
if(singlyLinkedListIterator==NULL) return false;
if(singlyLinkedListIterator->node==NULL) return false;
return true;
} // function ends

void getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator,void *ptr,OperationDetail *error)
{
if(error) error->succ=false;
if(singlyLinkedListIterator==NULL || singlyLinkedListIterator->node==NULL)
{
if(error) error->code=3;
return;
}
memcpy(ptr,(const void *)singlyLinkedListIterator->node->ptr,singlyLinkedListIterator->sizeOfOneElement);
singlyLinkedListIterator->node=singlyLinkedListIterator->node->next;
if(error)
{
error->code=0;
error->succ=true;
}
} // function ends

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
return doublyLinkedList;
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

void getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,int index,OperationDetail *error)
{
DoublyLinkedListNode *node;
int x;
if(error) error->succ=false;
if(doublyLinkedList==NULL)
{
if(error) error->code=3;
return;
}
if(index<0 || index>=doublyLinkedList->size)
{
if(error) error->code=9;
return;
}
node=doublyLinkedList->start;
x=0;
while(x<index)
{
node=node->next;
x++;
}
memcpy(ptr,(const void *)node->ptr,doublyLinkedList->sizeOfOneElement);
if(error)
{
error->succ=true;
error->code=0;
}
}
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,OperationDetail *error)
{
DoublyLinkedListIterator doublyLinkedListIterator;
doublyLinkedListIterator.node=NULL;
if(error) error->succ=false;
if(doublyLinkedList==NULL)
{
if(error) error->code=3;
return doublyLinkedListIterator;
}
if(doublyLinkedList->start==NULL) 
{
if(error)
{
error->succ=true;
error->code=0;
}
return doublyLinkedListIterator;
}
if(error) error->succ=true;
doublyLinkedListIterator.node=doublyLinkedList->start;
doublyLinkedListIterator.sizeOfOneElement=doublyLinkedList->sizeOfOneElement;
return doublyLinkedListIterator;  
}
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator)
{
if(doublyLinkedListIterator==NULL) return false;
if(doublyLinkedListIterator->node==NULL) return false;
return true;
}
void getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,void *ptr,OperationDetail *error)
{
if(error) error->succ=false;
if(doublyLinkedListIterator==NULL || doublyLinkedListIterator->node==NULL)
{
if(error) error->code=3;
return;
}
memcpy(ptr,(const void *)doublyLinkedListIterator->node->ptr,doublyLinkedListIterator->sizeOfOneElement);
doublyLinkedListIterator->node=doublyLinkedListIterator->node->next;
if(error)
{
error->succ=true;
error->code=0;
}
}

DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,OperationDetail *error)
{
DoublyLinkedListReverseIterator doublyLinkedListReverseIterator;
doublyLinkedListReverseIterator.node=NULL;
if(error) error->succ=false;
if(doublyLinkedList==NULL)
{
if(error) error->code=3;
return doublyLinkedListReverseIterator;
}
if(doublyLinkedList->start==NULL) 
{
if(error)
{
error->succ=true;
error->code=0;
}
return doublyLinkedListReverseIterator;
}
if(error) error->succ=true;
doublyLinkedListReverseIterator.node=doublyLinkedList->end;
doublyLinkedListReverseIterator.sizeOfOneElement=doublyLinkedList->sizeOfOneElement;
return doublyLinkedListReverseIterator;  
}
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator)
{
if(doublyLinkedListReverseIterator==NULL) return false;
if(doublyLinkedListReverseIterator->node==NULL) return false;
return true;
}
void getPreviousElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,void *ptr,OperationDetail *error)
{
if(error) error->succ=false;
if(doublyLinkedListReverseIterator==NULL || doublyLinkedListReverseIterator->node==NULL)
{
if(error) error->code=3;
return;
}
memcpy(ptr,(const void *)doublyLinkedListReverseIterator->node->ptr,doublyLinkedListReverseIterator->sizeOfOneElement);
doublyLinkedListReverseIterator->node=doublyLinkedListReverseIterator->node->previous;
if(error)
{
error->succ=true;
error->code=0;
}
}

#endif