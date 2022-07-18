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

// struture defination for AVLTree and AVLTreeNode

typedef struct __$_avl_tree_node
{
void *ptr;
struct __$_avl_tree_node *left;
struct __$_avl_tree_node *right;
}AVLTreeNode;
typedef struct __$_avl_tree
{
struct __$_avl_tree_node *start;
int (*predicate)(void *,void *);
int size;
}AVLTree;

typedef struct __$_avl_tree_in_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreeInOrderIterator;

typedef struct __$_avl_tree_pre_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreePreOrderIterator;

typedef struct __$_avl_tree_post_order_iterator
{
AVLTreeNode *node;
Stack *stack;
}AVLTreePostOrderIterator;

// AVL Tree related functionality
AVLTree * createAVLTree(bool *,int (*)(void *,void *));

void destroyAVLTree(AVLTree *);

int getSizeOfAVLTree(AVLTree *);

void clearAVLTree(AVLTree *);

void addToAVLTree(AVLTree *,void *,bool *);

void insertIntoAVLTree(AVLTree *,void *,bool *);

void * removeFromAVLTree(AVLTree *,void *,bool *);

void * getFromAVLTree(AVLTree *,void *,bool *);

AVLTreeInOrderIterator getAVLTreeInOrderIterator(AVLTree *,bool *);

bool hasNextInOrderElementInAVLTree(AVLTreeInOrderIterator *); 

void * getNextInOrderElementFromAVLTree(AVLTreeInOrderIterator *,bool *);

AVLTreePreOrderIterator getAVLTreePreOrderIterator(AVLTree *,bool *);

bool hasNextPreOrderElementInAVLTree(AVLTreePreOrderIterator *); 

void * getNextPreOrderElementFromAVLTree(AVLTreePreOrderIterator *,bool *);

AVLTreePostOrderIterator getAVLTreePostOrderIterator(AVLTree *,bool *);

bool hasNextPostOrderElementInAVLTree(AVLTreePostOrderIterator *); 

void * getNextPostOrderElementFromAVLTree(AVLTreePostOrderIterator *,bool *);

int getHeightOfAVLTree(AVLTreeNode *root);

void balanceAVLTree(AVLTree *avlTree,Stack *stack);

#endif