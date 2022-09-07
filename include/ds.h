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
void pushOnStack(struct __Stack__ *,const void *,OperationDetail *);
void popFromStack(struct __Stack__ *,void *,OperationDetail *);
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
void addToQueue(struct __Queue__ *,const void *,OperationDetail *);
void removeFromQueue(struct __Queue__ *,void *,OperationDetail *);
int isQueueEmpty(struct __Queue__ *);
void clearQueue(struct __Queue__ *);

// structure definations of DoublyLinkedList, DoublyLinkedListNode, DoublyLinkedListIterator and DoublyLinkedListReverseIterator.

typedef struct __$__DoublyLinkedListNode
{
void *ptr;
struct __$__DoublyLinkedListNode *next;
struct __$__DoublyLinkedListNode *previous;
}DoublyLinkedListNode;

typedef struct __$__DoublyLinkedList
{
DoublyLinkedListNode *start;
DoublyLinkedListNode *end;
int size;
int sizeOfOneElement;
}DoublyLinkedList;

typedef struct __$__DoublyLinkedListIterator
{
DoublyLinkedListNode *node;
}DoublyLinkedListIterator;

typedef struct __$__DoublyLinkedListReverseIterator
{
DoublyLinkedListNode *node;
}DoublyLinkedListReverseIterator;

// DoublyLinkedList related functionality
DoublyLinkedList * createDoublyLinkedList(int,OperationDetail *);
int getSizeOfDoublyLinkedList(DoublyLinkedList *);
void clearDoublyLinkedList(DoublyLinkedList *);
void destroyDoublyLinkedList(DoublyLinkedList *);
void addToDoublyLinkedList(DoublyLinkedList *,const void *,OperationDetail *);
void insertIntoDoublyLinkedList(DoublyLinkedList *,int,const void *,OperationDetail *);
void removeFromDoublyLinkedList(DoublyLinkedList *,void *,int,OperationDetail *);
void appendToDoublyLinkedList(DoublyLinkedList *,DoublyLinkedList *,OperationDetail *);
// above functions pending





void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);
DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success);
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator); 
void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success);
DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success);
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator); 
void * getPreviousElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool *success);




#endif