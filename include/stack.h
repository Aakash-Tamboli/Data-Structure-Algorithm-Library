#ifndef __STACK__
#define __STACK__
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
int sizeOfOneElement;
}Stack;

// stack related functionality
Stack * createStack(int,OperationDetail *);
void pushOnStack(struct __Stack__ *,const void *,OperationDetail *);
void popFromStack(struct __Stack__ *,void *,OperationDetail *);
int isStackEmpty(struct __Stack__ *);
void clearStack(struct __Stack__ *);
void destroyStack(struct __Stack__ *);
void elementAtTopOfStack(struct __Stack__ *,void *,OperationDetail *);

#endif
