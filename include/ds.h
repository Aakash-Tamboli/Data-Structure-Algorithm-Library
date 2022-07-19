#ifndef DS_H
#define DS_H 1234
#include<common.h>
// structure definations of stack and stackNode
typedef struct __stackNode__
{
void *ptr;
struct __stackNode__ *next;
}StackNode;
typedef struct __Stack__
{
StackNode *node;
int size;
int initFlag;
int sizeOfOneElement;
}Stack;

// stack related functionality

void initStack(struct __Stack__ *stack,int sizeofOneElement);
void pushOnStack(struct __Stack__ *,const void *,ErrorCode *);
void popFromStack(struct __Stack__ *,void *,ErrorCode *);
int isStackEmpty(struct __Stack__ *);
void clearStack(struct __Stack__ *);

// structure definations of queue and queueNode

typedef struct __Queue_Node__
{
void *ptr;
struct __Queue_Node__ *next;
}QueueNode;
typedef struct __Queue__
{
QueueNode *front;
QueueNode *rear;
int size;
int initFlag;
int sizeOfOneElement;
}Queue;
// queue related functionality

void initQueue(struct __Queue__ *queue,int sizeofOneElement);
void addToQueue(struct __Queue__ *,const void *,ErrorCode *);
void removeFromQueue(struct __Queue__ *,void *,ErrorCode *);
int isQueueEmpty(struct __Queue__ *);
void clearQueue(struct __Queue__ *);

#endif