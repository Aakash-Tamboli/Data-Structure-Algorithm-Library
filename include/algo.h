#ifndef ALGO_H
#define ALGO_H 123
#include<common.h>
void bubbleSort(void *,int ,int,int,OperationDetail *,int (*)(void *,void *));
void bubbleSortRecursive(void *,int ,int,int,OperationDetail *,int (*)(void *,void *));
void BSR(void *,int ,int ,int ,void *,int (*)(void *,void *));
void onePassOfBubbleSort(void *,int ,int ,int ,void *,int (*)(void *,void *));
void linearSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void linearSortRecursive(void *,int ,int ,int ,OperationDetail *,int (*)(void *,void *));
void LSR(void *,int ,int ,int ,void *,int (*)(void *,void *));
void onePassOfLinearSort(void *,int ,int ,int ,int ,void *,int (*)(void *,void *));
void selectionSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void selectionSortRecursive(void *,int ,int ,int ,OperationDetail *,int (*)(void *,void *));
void sSR(void *,int ,int ,int ,void *,int (*)(void *,void *));
void onePassOfSelectionSort(void *,int ,int ,int ,int ,int *,int (*)(void *,void *));
void insertionSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void insertionSortRecursive(void *,int ,int ,int ,OperationDetail *,int (*)(void *,void *));
void ISR(void *,int ,int ,int ,int ,void *,int (*)(void *,void *));
void onePassOfInsertionSort(void *,int *,int ,int ,void *,int (*)(void *,void *));
void quickSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void quickSortRecursive(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void QSR(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void mergeSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void mergeSortRecursive(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void MSR(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void heapSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void toConvertIntoHeap(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void toConvertIntoHeapUsingRecursive(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void convertingIntoHeapUsingRecursive(void *,int,int,int,void *,int (*)(void *,void *));
void anotherRecursiveCallForConvertingHeap(void *,int,int,int, void *,int (*) (void *,void *));

void heapSortRecursive(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void swappingAndHeapifyLogic(void *,int,int,int,void *,int (*) (void *,void *));
void heapifyLogic(void *,int,int,int,void *,int (*) (void *,void *));

void radixSort(void *,int,int,int,OperationDetail *,int);
void shellSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void countSort(void *,int,int,int,OperationDetail *,int (*)(void *,void *));
void findingTheHeavestElement(void *,int,int,int,OperationDetail *,void *,int (*p2f) (void *,void *));
void findingTheLightestElement(void *,int,int,int,OperationDetail *,void *,int (*p2f) (void *,void *));
#endif