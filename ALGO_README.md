## Introduction
Hey,I am Aakash, the Creator of this Library. It is Collection Some Sorting Algos.

## Alogrithms (ONLY ARRAY TYPE COLLECTION)
  For all algos Recursive approach available:
          BubbleSort , linearSort , selectionSort , insertionSort , quickSort , mergeSort , heapSort , shellSort and pancakeSort.It takes 6 Arguments
          
  a) Base Address of Collection
  
  b) value of lowerBound
  
  c) value of upperbound
  
  d) size of 1 Element
  
  e) pass address of struct OperationDetail type structure
  
  f) address of the comparator function {boolian predicate} (The Comparator function are written by user of this libaray)
  
  

## This alogs only works on int_datatype: 
   radixSort,countSort,addressCalculationSorts
   It takes 6 Arguments
   
   a) Base Address of Collection
   
   b) value of lowerBound
   
   c) value of upperbound
   
   d) size of 1 Element
   
   e) pass address of struct errorCode type structure
   
   f) pass ACC or DEC, ACC number means	you want to sort in ACCENDING ORDER, DEC means you want to sort in DECCENDING ORDER
   

NOTE:
  Individual illustation are present in Algo.txt located in Documentation/Algo.txt

## Algorithm functions name are:
```c
bubbleSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
bubbleSortRecursive(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
linearSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
linearSortRecursive(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
selectionSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
selectionSortRecursive(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
insertionSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
insertionSortRecursive(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
quickSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
quickSortRecursive(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
mergeSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
mergeSortRecursive(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
heapSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
heapSortRecursive(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
shellSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
shellSortRecursive(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
pancakeSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
pancakeSortRecursive(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
radixSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
pancakeSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
addressCalculationSort(base_address,lower_bound,upper_bound,size_of_one_element_of_your_collection,address_of_structure_type_OperatonDetail,comparator);
```



### Guidlines for Comparator Function-

** 1. return type always `int` type .

2. Parameter Should always `(void *,void *)`.

3. if left pointer points to data is EQAUL to right pointer points data then
return 0.

4. if left pointer points data is greater then return +ve.

5. if left pointer points data is lesser then return -ve. **

### Example
                                           int INTComparator(void *left,void *right);

