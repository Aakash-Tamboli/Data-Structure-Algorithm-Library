#	DOCUMENTATION

## Overview
here you get to know about `library` of GENERIC data structures and alogrithms, which is built in `c` programming language.

## Why The Generic Data Structure and algorithms In C ?
we have `STL in C++`, `Collection classes in Java` but when we talk about `C` so there is no such facilites to handle some huge data and In this project I Implemeted data stuctures and some sorting algorithms for data.

***
* [Comparator Function](#comparator-function)
* [Error](#error)
  * [Error-Codes](#error-codes)
* [Compile Code](#how-to-compile-code)
  * [Error-Codes](#error-codes)

* [Generic Bubble Sort](#generic-bubble-sort)  
   * [Use of Bubble Sort on `int` type](#use-of-bubble-sort-on-int-type)
   * [Use of Bubble Sort on `struct student` type](#use-of-bubble-sort-on-struct-student-type)
                          
   
## Comparator function
The Comparator function are written by user of this libaray.
### Guidlines for Comparator Function-
** 1. return type always `int` type .

2. Parameter Should always `(void *,void *)`.

3. if left pointer points to data is EQAUL to right pointer points data then
return 0.

4. if left pointer pointer data is greater then return +ve.

5. if left pointer pointer data is lesser them return -ve. **

### Example
                                           int INTComparator(void *left,void *right);

## Error

The struct type ErrorCode have two properties,

                                              typedef struct __$__errorCode
                                              {
                                              int code,succ;
                                              }ErrorCode;

1. succ:-
      it aknowlegde your operation is successfull or not.

2. code:-
      it aknowlegde why your operation failed see error codes.

    ### Error-Codes
          Error-Codes   | description of Code
          ------------- | --------------------
                0       | Operation Successfull Executed
                1       | Problem in LowerBound,UpperBound Or may be you are passing same values
                2       | Unable To Allocate Memory For Internal Use
                3       | Problem in your Data_ Structure Address may be you passed NULL
                4       | Problem in data address which you want to store in Data_Structure or retrieve from Data_Structure may be you
                        | passed NULL;
                        | void pushOnStack(&yourStack,NULL,&YourstructtypeErrorCode)
                        | popFromStack(&yourStack,NULL,&YourstructtypeErrorCode)
                5       | Please Initialized Your Data_Structure First
                        |  Note:If you are trying to pass value of sizeofOneElement is 0(zero) in 
                        |       initData_Structure(&yourData_Structure,0);
                        |       Then Your Data_Structure will not initialized because it make no sense.
                6       | Problem in Your Comparator predicate may be you passed NULL
                7       | Your Size of One Element is 0 or may be negative.
                8       | Your Collection is Not int data_type.this Algo only for int data_type
    	

## How to compile code
1. When you compile code inside data-Structure-Algorithm-Library/testCases/
``` c
gcc filename.c -o filename.exe -I ..\include -L ..\lib -l dsAlgo
```
Note: If your machine is linux then
``` c
gcc filename.c -o filename.out -I ..\include -L ..\lib -l dsAlgo
```


## Generic Bubble Sort
### Description of Bubble Sort :
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst case time complexity is quite high. [More info](https://www.geeksforgeeks.org/bubble-sort/)



### [BubbleSort (Only For array-Collection)]


The Bubble Sort Algorithm Takes 6 Arguments

1. Base Address of Collection

2. Value of lowerBound

3. Value of upperbound

4. Size of 1 Element

5. Pass address of struct errorCode type structure

6. Address of the comparator function {boolian predicate}

 
### Use of bubble Sort on `int` type:
 
 
 
```c
#include<stdio.h>
#include<stdlib.h>
#include<algo.h>
int INTComparator(void *left,void *right)
{
int *i,*j;
i=(int *)left;
j=(int *)right;
return (*i)-(*j);
}
int main()
{
ErrorCode error;
int *x,req;
int i;
printf("enter the requiremnt: ");
scanf("%d",&req);
if(req<=0)
{
printf("Invaild request\n");
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("insuffient space in memory\n");
return 0;
}
for(i=0;i<req;i++)
{
printf("Enter an Number: ");
scanf("%d",&x[i]);
}
bubbleSort(x,0,req-1,sizeof(int),&error,INTComparator);
if(error.succ==false)
{
printf("I unable to Sort Your collection,Check Error Code\n");
printf("Error code is: %d\n",error.code);
free(x);
return 0;
}
else
{
for(i=0;i<req;i++) printf("%d\n",x[i]);
free(x);
}
return 0;
}
```
                   

### Use Of bubble sort on `struct student` type:
```c
#include<stdio.h>
#include<stdlib.h>
#include<algo.h>

typedef struct student
{
int roll;
char name[32];
}Student;

int studentComparator(void *left,void *right) // (boolian predicate)
{
Student *s1,*s2;
s1=(Student *)left;
s2=(Student *)right;
return s1->roll-s2->roll;
}
int main()
{
ErrorCode error;
Student *s,*j;
int req;
int i;
int sizeOfOneElement;
printf("enter the requiremnt: ");
scanf("%d",&req);
if(req<=0)
{
printf("Invaild request\n");
return 0;
}
s=(Student *)malloc(sizeof(Student)*req);
j=s;
if(s==NULL)
{
printf("insuffient space in memory\n");
return 0;
}
for(i=0;i<req;i++)
{
printf("Enter the Roll Number: ");
scanf("%d",&j->roll);
printf("Enter the name: ");
scanf("%s",&j->name);
j++;
}
sizeOfOneElement=sizeof(Student);
bubbleSort(s,0,req-1,sizeOfOneElement,&error,studentComparator);
if(error.succ==false)
{
printf("I unable to Sort Your collection,Check Error Code\n");
printf("Error code is: %d\n",error.code);
free(s);
return 0;
}
else
{
for(i=0;i<req;i++) printf("Name: %s,RollNumber: %d\n",s[i].name,s[i].roll);
free(s);
}
return 0;
}
```

