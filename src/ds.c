#ifndef DS_C
#define DS_C 1245
#include<common.h>
#include<ds.h>
#include<stdlib.h>
#include<string.h>
void initStack(struct __Stack__ *stack,int sizeOfOneElement)
{
if(stack==NULL || sizeOfOneElement<=0) return;
if(stack->initFlag!=true)
{
stack->node=NULL;
stack->size=0;
stack->initFlag=true;
stack->sizeOfOneElement=sizeOfOneElement;
return;
}
if(stack->node!=NULL) clearStack(stack);
stack->node=NULL;
stack->size=0;
stack->sizeOfOneElement=sizeOfOneElement;
}
void pushOnStack(struct __Stack__ *stack,const void *data,ErrorCode *error)
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
void popFromStack(struct __Stack__ *stack,void *data,ErrorCode *error)
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
if(queue->initFlag!=true)
{
queue->front=NULL;
queue->rear=NULL;
queue->size=0;
queue->initFlag=true;
queue->sizeOfOneElement=sizeOfOneElement;
}
if(queue->front!=NULL) clearQueue(queue);
queue->sizeOfOneElement=sizeOfOneElement;
}
void addToQueue(struct __Queue__ *queue,const void *data,ErrorCode *error)
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
void removeFromQueue(struct __Queue__ *queue,void *data,ErrorCode *error)
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
if(queue==NULL) return;
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
#endif