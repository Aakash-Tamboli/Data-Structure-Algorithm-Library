#ifndef ALGO_H
#define ALGO_H 123
#include<common.h>
void bubbleSort(void *,int ,int,int,OperationDetail *,int (*)(void *,void *));
void bubbleSortRecursive(void *,int ,int,int,OperationDetail *,int (*)(void *,void *));
void BSR(void *,int ,int ,int ,void *,int (*)(void *,void *));
void onePassOfBubbleSort(void *,int *,int *,int *,void *,int (*)(void *,void *));
void linearSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void selectionSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void insertionSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void quickSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void mergeSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void heapSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void toMaxHeap(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void radixSort(void *,int,int,int,OperationDetail *,int);
void shellSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void countSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void findingTheHeavestElement(void *,int,int,int,OperationDetail *,void *,int (*p2f) (void *,void *));
void findingTheLightestElement(void *,int,int,int,OperationDetail *,void *,int (*p2f) (void *,void *));
#endif