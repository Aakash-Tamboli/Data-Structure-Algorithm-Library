#ifndef __STACK__IMPLEMENTATION__
#define __STACK__IMPLEMENTATION__
#include<common.h>
#include<string.h>
#include<stdlib.h>
#include<stack.h>

Stack *createStack(int sizeOfOneElement, OperationDetail *error)
{
    Stack *stack;
    if (error)
        error->succ = false;
    if (sizeOfOneElement <= 0)
    {
        if (error)
            error->code = 7;
        return NULL;
    }
    stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        if (error)
            error->code = 2;
        return NULL;
    }
    stack->node = NULL;
    stack->size = 0;
    stack->sizeOfOneElement = sizeOfOneElement;
    if (error)
    {
        error->succ = true;
        error->code = 0;
    }
    return stack;
}
void pushOnStack(struct __Stack__ *stack, const void *data, OperationDetail *error)
{
    StackNode *node;
    if (error)
        error->succ = false;
    if (stack == NULL)
    {
        if (error)
            error->code = 3;
        return;
    }
    if (data == NULL)
    {
        if (error)
            error->code = 4;
        return;
    }
    node = (StackNode *)malloc(sizeof(StackNode));
    if (node == NULL)
    {
        if (error)
            error->code = 2;
        return;
    }
    node->ptr = (void *)malloc(sizeof(stack->sizeOfOneElement));
    if (node->ptr == NULL)
    {
        if (error)
            error->code = 2;
        free(node);
        return;
    }
    memcpy(node->ptr, (const void *)data, stack->sizeOfOneElement);
    node->next = stack->node;
    stack->node = node;
    stack->size++;
    if (error)
    {
        error->code = 0;
        error->succ = true;
    }
}
void popFromStack(struct __Stack__ *stack, void *data, OperationDetail *error)
{
    StackNode *j;
    if (error)
        error->succ = false;
    if (stack == NULL)
    {
        if (error)
            error->code = 3;
        return;
    }
    if (data == NULL)
    {
        if (error)
            error->code = 4;
        return;
    }
    if (stack->node == NULL)
    {
        if (error)
            error->code = 5;
        return;
    }
    memcpy(data, (const void *)stack->node->ptr, stack->sizeOfOneElement);
    free(stack->node->ptr);
    j = stack->node;
    stack->node = stack->node->next;
    free(j);
    stack->size--;
    if (error)
    {
        error->code = 0;
        error->succ = true;
    }
}
int isStackEmpty(struct __Stack__ *stack)
{
    if (stack == NULL)
        return 0;
    return stack->node == NULL;
}
void clearStack(struct __Stack__ *stack)
{
    StackNode *j;
    if (stack == NULL || stack->node == NULL)
        return;
    while (stack->node != NULL)
    {
        free(stack->node->ptr);
        j = stack->node;
        stack->node = stack->node->next;
        free(j);
    }
    stack->size = 0;
}

void destroyStack(struct __Stack__ *stack)
{
    if (stack == NULL)
        return;
    clearStack(stack);
    free(stack);
}

void elementAtTopOfStack(struct __Stack__ *stack, void *ptr, OperationDetail *error)
{
    if (error)
        error->succ = false;
    if (isStackEmpty(stack))
    {
        ptr = NULL;
        if (error)
        {
            error->succ = true;
            error->code = 0;
        }
        return;
    }
    memcpy(ptr, (const void *)stack->node->ptr, stack->sizeOfOneElement);
} // function ends

#endif
