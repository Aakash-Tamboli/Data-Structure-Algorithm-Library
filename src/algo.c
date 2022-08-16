#ifndef ALGO_C
#define ALGO_C 123
#include<common.h>
#include<algo.h>
#include<stdlib.h>
#include<string.h>
#include<ds.h>
#include<stdio.h>
// common functions
int isInvalid(void *ptr,int *lb,int *ub,int *es,OperationDetail *error,int (*p2f) (void *,void *))
{
if(ptr==NULL)
{
error->code=3;
return 1;
}
if((*lb)<0 || (*ub)<(*lb) || *(lb)==*(ub))
{
error->code=1;
return 1;
}
if((*es)<=0)
{
error->code=7;
return 1;
}
if(p2f==NULL)
{
error->code=6;
return 1;
}
return 0;
}
void ifLowerBoundIsNotZero(void *ptr,int *lb,int *ub,int *es)
{
ptr=ptr+((*lb)*(*es));
*ub=(*ub)-(*lb);
*lb=0;
}
void findingTheHeavestElement(void *ptr,int lb,int ub,int es,OperationDetail *error,void *heavestElement,int (*p2f) (void *,void *))
{
int i;
if(error) error->succ=false;
if(error==NULL)
{
OperationDetail err;
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
if(lb!=0) ifLowerBoundIsNotZero(ptr,&lb,&ub,&es);
memcpy(heavestElement,(const void *)ptr,es);
for(i=0;i<=ub;i++)
{
if(p2f(heavestElement,ptr+(i*es))<0) memcpy(heavestElement,(const void *)ptr+(i*es),es);
}
if(error)
{
error->code=0;
error->succ=true;
}
}
void findingTheLightestElement(void *ptr,int lb,int ub,int es,OperationDetail *error,void *lightestElement,int (*p2f) (void *,void *))
{
int i;
if(error) error->succ=false;
if(error==NULL)
{
OperationDetail err;
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
if(lb!=0) ifLowerBoundIsNotZero(ptr,&lb,&ub,&es);
memcpy(lightestElement,(const void *)ptr,es);
for(i=0;i<=ub;i++)
{
if(p2f(lightestElement,ptr+(i*es))>0) memcpy(lightestElement,(const void *)ptr+(i*es),es);
}
if(error)
{
error->code=0;
error->succ=true;
}
}
// common function ends
void bubbleSort(void *ptr,int lb,int ub,int es,OperationDetail *error,int (*p2f)(void *,void *))
{
int m,e,f,weight;
void *a,*b,*c;
if(error) error->succ=false;
if(error==NULL)
{
OperationDetail err;
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
m=ub-1;
if(m<0) return;
c=(void *)malloc(sizeof(es));
if(c==NULL)
{
if(error) error->code=2;
return;
}
while(m>=lb)
{
e=lb;
f=lb+1;
while(e<=m)
{
a=ptr+(f*es);
b=ptr+(e*es);
weight=p2f(a,b);
if(weight<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
e++;
f++;
}
m--;
}
free(c);
if(error)
{
error->code=0;
error->succ=true;
}
}
void bubbleSortRecursive(void *ptr,int lb,int ub,int es,OperationDetail *error,int (*p2f)(void *,void *))
{
void *c;
if(error) error->succ=false;
if(error==NULL)
{
OperationDetail err;
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
c=(void *)malloc(sizeof(es));
if(c==NULL)
{
if(error) error->code=2;
return;
}
BSR(ptr,lb,ub,es,c,p2f);
free(c);
if(error)
{
error->succ=true;
error->code=0;
}
}
void BSR(void *ptr,int lb,int ub,int es,void *c,int (*p2f)(void *,void *))
{
// BSR stands for Bubble Sort Recursive
int ilb,iub;
ilb=lb;
iub=ub;
if(lb<ub)
{
onePassOfBubbleSort(ptr,&ilb,&iub,&es,c,p2f);
BSR(ptr,lb,ub-1,es,c,p2f);
}
}

void onePassOfBubbleSort(void *ptr,int *lb,int *ub,int *es,void *c,int (*p2f)(void *,void *))
{
if((*lb)<(*ub))
{
if(p2f((ptr+(((*lb)+1)*(*es))),(ptr+((*lb)*(*es))))<0)
{
memcpy(c,(const void *)ptr+((*lb)*(*es)),(*es));
memcpy(ptr+((*lb)*(*es)),(const void *)ptr+(((*lb)+1)*(*es)),(*es));
memcpy(ptr+(((*lb)+1)*(*es)),(const void *)c,(*es));
}
*lb=*lb+1;
onePassOfBubbleSort(ptr,lb,ub,es,c,p2f);
}
}							
void linearSort(void *ptr,int lb,int ub,int es,OperationDetail *error,int (*p2f)(void *,void *))
{
int e,f,weight,oep,iep;
void *a,*b,*c;
if(error) error->succ=false;
if(error==NULL)
{
OperationDetail err;
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
c=(void *)malloc(es);
if(c==NULL)
{
if(error) error->code=2;
return;
}
e=lb;
oep=ub-1;
iep=ub;
while(e<=oep)
{
f=e+1;
while(f<=iep)
{
a=ptr+(f*es);
b=ptr+(e*es);
weight=p2f(a,b);
if(weight<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
f++;
}
e++;
}
free(c);
if(error)
{
error->succ=true;
error->code=0;
}
}
void selectionSort(void *ptr,int lb,int ub,int es,OperationDetail *error,int (*p2f) (void *,void *))
{
int e,f,si,weight;
void *a,*b,*c;
if(error) error->succ=false;
if(error==NULL)
{
OperationDetail err;
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
c=(void *)malloc(es);
if(c==NULL)
{
if(error) error->code=2;
return;
}
e=lb;
while(e<=ub-1)
{
si=e;
f=e+1;
while(f<=ub)
{
a=ptr+(f*es);
b=ptr+(si*es);
weight=p2f(a,b);
if(weight<0)
{
si=f;
}
f++;
}
a=ptr+(e*es);
b=ptr+(si*es);
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
e++;
}
free(c);
if(error)
{
error->code=0;
error->succ=true;
}
}
void insertionSort(void *ptr,int lb,int ub,int es,OperationDetail *error,int (*p2f)(void *,void *))
{
int y,leastLb;
void *c;
if(error) error->succ=false;
if(error==NULL)
{
OperationDetail err;
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
c=(void *)malloc(es);
if(c==NULL)
{
error->code=2;
return;
}
leastLb=lb;
lb++;
while(lb<=ub)
{
memcpy(c,(const void *)ptr+(lb*es),es);
y=lb-1;
while(y>=leastLb && p2f(c,ptr+(y*es))<0)
{
memcpy(ptr+((y+1)*es),(const void *)(ptr+(y*es)),es);
y--;
}
memcpy(ptr+((y+1)*es),(const void *)c,es);
lb++;
}
free(c);
if(error)
{
error->code=0;
error->succ=true;
}
}
int findPartionPoint(void *ptr,int e,int f,int es,int (*p2f)(void *,void *),OperationDetail *err)
{
int lb=e;
int ub=f;
void *a,*b,*c;
if(err) err->succ=false;
c=(void *)malloc(es);
if(c==NULL)
{
if(err) err->code=2;
return 0;
}
while(e<f)
{
while(e<ub && p2f(ptr+(e*es),ptr+(lb*es))<=0) e++;
while(p2f(ptr+(f*es),ptr+(lb*es))>0) f--;
if(e<f)
{
a=ptr+(e*es);
b=ptr+(f*es);
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
else
{
a=ptr+(f*es);
b=ptr+(lb*es);
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
}
free(c);
if(err)
{
err->succ=true;
err->code=0;
}
return f;
}
void quickSort(void *ptr,int lb,int ub,int es,OperationDetail *error,int (*p2f)(void *,void *))
{
typedef struct indexes
{
int lb;
int ub;
}Indexes;
int a,b;
Indexes *indexes;
Stack *stack;
int succ;
int pp,ppSucc;
OperationDetail err;
if(error) error->succ=false;
if(error==NULL)
{
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
stack=(Stack *)malloc(sizeof(Stack));
if(stack==NULL)
{
if(error) error->code=2;
return;
}
initStack(stack,sizeof(Indexes));
indexes=(Indexes *)malloc(sizeof(Indexes));
if(indexes==NULL)
{
if(error) error->code=2;
free(stack);
return;
}
indexes->lb=lb;
indexes->ub=ub;
pushOnStack(stack,(const void *)indexes,&err);
if(!err.succ)
{
if(error) error->code=err.code;
free(stack);
free(indexes);
return;
}
while(!isStackEmpty(stack))
{
popFromStack(stack,(void *)indexes,&err);
a=indexes->lb;
b=indexes->ub;
free(indexes);
pp=findPartionPoint(ptr,a,b,es,p2f,&err);
if(!err.succ)
{
clearStack(stack);
free(stack);
if(error) error->code=err.code;
return;
}
if(pp+1<b)
{
indexes=(Indexes *)malloc(sizeof(Indexes));
if(indexes==NULL)
{
clearStack(stack);
free(stack);
if(error) error->code=2;
return;
}
indexes->lb=pp+1;
indexes->ub=b;
pushOnStack(stack,(const void *)indexes,&err);
if(!err.succ)
{
clearStack(stack);
free(stack);
free(indexes);
if(error) error->code=err.code;
return;
}
}
if(a<pp-1)
{
indexes=(Indexes *)malloc(sizeof(Indexes));
if(indexes==NULL)
{
clearStack(stack);
free(stack);
if(error) error->code=err.code;
return;
}
indexes->lb=a;
indexes->ub=pp-1;
pushOnStack(stack,(const void *)indexes,&err);
if(!err.succ)
{
clearStack(stack);
free(stack);
free(indexes);
if(error) error->code=err.code;
return;
}
}
}
clearStack(stack);
free(stack);
if(error)
{
error->code=0;
error->succ=true;
}
}
void merge(void *ptr,int low,int mid,int high,int es,int (*p2f) (void *,void *),int *succ)
{
if(succ) *succ=false;
int i1,i2,i3,lb1,lb2,lb3,ub1,ub2,ub3,size;
void *tmp;
size=(high-low)+1;
lb1=low;
ub1=mid;
lb2=mid+1;
ub2=high;
lb3=0;
ub3=size-1;
tmp=(void *)malloc(sizeof(es)*size);
if(tmp==NULL) return;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(p2f(ptr+(i1*es),ptr+(i2*es))<0)
{
memcpy(tmp+(i3*es),(const void *)ptr+(i1*es),es);
i1++;
}
else
{
memcpy(tmp+(i3*es),(const void *)ptr+(i2*es),es);
i2++;
}
i3++;
}
while(i1<=ub1)
{
memcpy(tmp+(i3*es),(const void *)ptr+(i1*es),es);
i1++;
i3++;
}
while(i2<=ub2)
{
memcpy(tmp+(i3*es),(const void *)ptr+(i2*es),es);
i3++;
i2++;
}
i3=lb3;
i1=lb1;
while(i3<=ub3)
{
memcpy(ptr+(i1*es),(const void *)tmp+(i3*es),es);
i3++;
i1++;
}
free(tmp);
if(succ) *succ=true;
}
void mergeSort(void *ptr,int lb,int ub,int es,OperationDetail *error,int (*p2f)(void *,void *))
{
typedef struct __indexes__
{
int lb;
int ub;
}Indexes;
int succ;
int a,b,mid,lb1,ub1,ub2;
Stack *stack1;
Stack *stack2;
Indexes *indexes;
OperationDetail err;
if(error) error->succ=false;
if(error==NULL)
{
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
stack1=(Stack *)malloc(sizeof(Stack));
if(stack1==NULL)
{
if(error) error->code=2;
return;
}
initStack(stack1,sizeof(Indexes));
stack2=(Stack *)malloc(sizeof(Stack));
if(stack2==NULL)
{
if(error) error->code=2;
free(stack1);
return;
}
initStack(stack2,sizeof(Indexes));
indexes=(Indexes *)malloc(sizeof(Indexes));
if(indexes==NULL)
{
if(error) error->code=2;
free(stack1);
free(stack2);
return;
}
indexes->lb=lb;
indexes->ub=ub;
pushOnStack(stack1,(const void *)indexes,&err);
if(!err.succ)
{
if(error) error->code=err.code;
free(indexes);
free(stack1);
free(stack2);
}
while(!isStackEmpty(stack1))
{
popFromStack(stack1,(void *)indexes,&err);
a=indexes->lb;
b=indexes->ub;
pushOnStack(stack2,(const void *)indexes,&err);
if(!err.succ)
{
if(error) error->code=err.code;
clearStack(stack1);
clearStack(stack2);
free(stack1);
free(stack2);
free(indexes);
return;
}
mid=(a+b)/2;
if(a<mid)
{
indexes=(Indexes *)malloc(sizeof(Indexes));
if(indexes==NULL)
{
if(error) error->code=2;
clearStack(stack1);
clearStack(stack2);
free(stack1);
free(stack2);
return;
}
indexes->lb=a;
indexes->ub=mid;
pushOnStack(stack1,(const void *)indexes,&err);
if(!err.succ)
{
if(error) error->code=err.code;
clearStack(stack1);
clearStack(stack2);
free(stack1);
free(stack2);
free(indexes);
return;
}
}
if(mid+1<b)
{
indexes=(Indexes *)malloc(sizeof(Indexes));
if(indexes==NULL)
{
if(error) error->code=2;
clearStack(stack1);
clearStack(stack2);
free(stack1);
free(stack2);
return;
}
indexes->lb=mid+1;
indexes->ub=b;
pushOnStack(stack1,(const void *)indexes,&err);
if(!err.succ)
{
if(error) error->code=err.code;
clearStack(stack1);
clearStack(stack2);
free(stack1);
free(stack2);
free(indexes);
return;
}
}
}
while(!isStackEmpty(stack2))
{
popFromStack(stack2,(void *)indexes,&err);
lb1=indexes->lb;
ub2=indexes->ub;
ub1=(lb1+ub2)/2;
merge(ptr,lb1,ub1,ub2,es,p2f,&succ);
if(succ==false)
{
clearStack(stack2);
free(stack1);
free(stack2);
free(indexes);
if(error)
{
error->code=2;
return;
}
}
}
clearStack(stack1); // just for the precaution
clearStack(stack2); // just for the precaution
free(stack1);
free(stack2);
free(indexes);
if(error)
{
error->code=0;
error->succ=true;
}
}
void toMaxHeap(void *ptr,int lb,int ub,int es,OperationDetail *error,int (*p2f)(void *,void *))
{
int y,ci,ri;
OperationDetail err;
void *c;
if(error) error->succ=false;
if(error==NULL)
{
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
c=(void *)malloc(es);
if(c==NULL)
{
if(error) error->code=2;
return;
}
if(lb!=0)
{
ptr=ptr+(lb*es);
ub=ub-lb;
lb=0;
}
y=lb+1;
while(y<=ub)
{
ci=y;
while(ci>lb)
{
ri=(ci-1)/2;
if(p2f(ptr+(ci*es),ptr+(ri*es))>0)
{
memcpy(c,(const void *)(ptr+(ci*es)),es);
memcpy((ptr+(ci*es)),(const void *)(ptr+(ri*es)),es);
memcpy((ptr+(ri*es)),(const void *)c,es);
ci=ri;
}
else
{
break;
}
}
y++;
}
if(error)
{
error->code=0;
error->succ=true;
}
free(c);
}
void heapSort(void *ptr,int lb,int ub,int es,OperationDetail *error,int (*p2f)(void *,void *))
{
int swi,y,lci,rci,ri;
OperationDetail err;
void *c;
if(error) error->succ=false;
if(error==NULL)
{
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
if(lb!=0)
{
ptr=ptr+(lb*es);
ub=ub-lb;
lb=0;
}
toMaxHeap(ptr,lb,ub,es,&err,p2f);
if(err.succ==true)
{
c=(void *)malloc(es);
if(c==NULL)
{
if(error) error->code=2;
return;
}
y=ub;
while(y>lb)
{
memcpy(c,(const void *)ptr+(y*es),es);
memcpy(ptr+(y*es),(const void *)ptr+(lb*es),es);
memcpy(ptr+(lb*es),(const void *)c,es);
y--;
ri=lb;
while(ri<y)
{
lci=(ri*2)+1;
if(lci>y) break;
rci=lci+1;
if(rci>y) swi=lci;
else
{
if(p2f(ptr+(lci*es),ptr+(rci*es))>0) swi=lci;
else swi=rci;
}
if(p2f(ptr+(swi*es),ptr+(ri*es))>0)
{
memcpy(c,(const void *)ptr+(swi*es),es);
memcpy(ptr+(swi*es),(const void *)ptr+(ri*es),es);
memcpy(ptr+(ri*es),(const void *)c,es);
ri=swi;
}
else
{
break;
}
}
}
free(c);
if(error)
{
error->succ=true;
error->code=0;
}
}
else
{
if(error) error->code=err.code;
}
}
// I use this dummy function for radix sort validation as predicate;
int dummy(void *left,void *right)
{
// do nothing 
}
void radixSort(void *x,int lb,int ub,int es,OperationDetail *error,int decision)
{
int i;
Queue negQueue[10],posQueue[10];
int largestDigit;
int biggestNumber,biggestNumberDigit;
int smallestNumber,smallestNumberDigit;
int y;
int qIndex;
int index;
int e,f;
int elem;
OperationDetail err;
if(error) error->succ=false;
if(error==NULL)
{
if(isInvalid(x,&lb,&ub,&es,&err,dummy)) return;
}
else{
if(isInvalid(x,&lb,&ub,&es,error,dummy)) return;
}
if(sizeof(int)!=es)
{
if(error) error->code=8;
return;
}
for(i=0;i<=9;i++)
{
initQueue(&negQueue[i],es);
initQueue(&posQueue[i],es);
}
memcpy(&biggestNumber,(const void *)x+(lb*es),es);
memcpy(&smallestNumber,(const void *)x+(lb*es),es);
for(y=lb+1;y<=ub;y++)
{
memcpy(&elem,(const void *)x+(y*es),es);
if(biggestNumber<elem) memcpy(&biggestNumber,(const void *)x+(y*es),es);
if(smallestNumber>elem) memcpy(&smallestNumber,(const void *)x+(y*es),es);
}
biggestNumberDigit=0;
while(biggestNumber>0)
{
biggestNumberDigit++;
biggestNumber=biggestNumber/10;
}
smallestNumberDigit=0;
while(smallestNumber<0)
{
smallestNumberDigit++;
smallestNumber=smallestNumber/10;
}
if(smallestNumberDigit>biggestNumberDigit) largestDigit=smallestNumberDigit;
else largestDigit=biggestNumberDigit;
e=1;
f=10;
while(largestDigit>0)
{
i=lb;
while(i<=ub)
{
memcpy(&elem,(const void *)x+(i*es),es);
qIndex=elem%f;
qIndex=qIndex/e;
if(qIndex<0)
{
qIndex=abs(qIndex);
addToQueue(&negQueue[qIndex],(void *)x+(i*es),&err);
if(err.succ==false)
{
for(i=0;i<=9;i++)
{
clearQueue(&negQueue[i]);
clearQueue(&posQueue[i]);
}
if(error) error->code=err.code;
return;
}
i++;
continue;
}
addToQueue(&posQueue[qIndex],(void *)x+(i*es),&err);
if(err.succ==false)
{
for(i=0;i<=9;i++)
{
clearQueue(&negQueue[i]);
clearQueue(&posQueue[i]);
}
if(error) error->code=err.code;
return;
}
i++;
}
if(decision>0)
{
// sorting in accending order
i=9;
index=lb;
while(i>=0)
{
while(!isQueueEmpty(&negQueue[i]))
{
removeFromQueue(&negQueue[i],(void *)x+(index*es),&err);
if(err.succ==false)
{
for(i=0;i<=9;i++)
{
clearQueue(&negQueue[i]);
clearQueue(&posQueue[i]);
}
if(error) error->code=err.code;
return;
}
index++;
}
i--;
}
i=0;
while(i<=9)
{
while(!isQueueEmpty(&posQueue[i]))
{
removeFromQueue(&posQueue[i],(void *)x+(index*es),&err);
if(err.succ==false)
{
for(i=0;i<=9;i++)
{
clearQueue(&negQueue[i]);
clearQueue(&posQueue[i]);
}
if(error) error->code=err.code;
return;
}
index++;
}
i++;
}
}
else
{
// case for decending order.
i=9;
index=lb;
while(i>=0)
{
while(!isQueueEmpty(&posQueue[i]))
{
removeFromQueue(&posQueue[i],(void *)x+(index*es),&err);
if(err.succ==false)
{
for(i=0;i<=9;i++)
{
clearQueue(&negQueue[i]);
clearQueue(&posQueue[i]);
}
if(error) error->code=err.code;
return;
}
index++;
}
i--;
}
i=0;
while(i<=9)
{
while(!isQueueEmpty(&negQueue[i]))
{
removeFromQueue(&negQueue[i],(void *)x+(index*es),&err);
if(err.succ==false)
{
for(i=0;i<=9;i++)
{
clearQueue(&negQueue[i]);
clearQueue(&posQueue[i]);
}
if(error) error->code=err.code;
return;
}
index++;
}
i++;
}
} // else block ends
largestDigit--;
e=e*10;
f=f*10;
}
for(i=0;i<=9;i++)
{
clearQueue(&negQueue[i]);
clearQueue(&posQueue[i]);
}
if(error)
{
error->succ=true;
error->code=0;
}
}
void shellSort(void *ptr,int lb,int ub,int es,OperationDetail *error,int (*p2f)(void *,void *))
{
int y,leastLb,diff;
void *c;
if(error) error->succ=false;
if(error==NULL)
{
OperationDetail err;
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
c=(void *)malloc(es);
if(c==NULL)
{
error->code=2;
return;
}
if(lb!=0)
{
ptr=ptr+(lb*es);
ub=ub-lb;
lb=0;
}
leastLb=lb;
diff=(ub-lb)+1;
diff=diff/2;
while(diff>0)
{
lb=diff;
while(lb<=ub)
{
memcpy(c,(const void *)ptr+(lb*es),es);
y=lb-diff;
while(y>=leastLb && p2f(c,ptr+(y*es))<0)
{
memcpy(ptr+((y+diff)*es),(const void *)(ptr+(y*es)),es);
y=y-diff;
}
memcpy(ptr+((y+diff)*es),(const void *)c,es);
lb=lb+diff;
}
diff=diff/2;
}
free(c);
if(error)
{
error->code=0;
error->succ=true;
}
}
/*
Count Sort is Pending Due to finding the largest Number Method..
void countSort(void *ptr,int lb,int ub,int es,OperationDetail *error,int (*p2f)(void *,void *))
{
void *heavestElement;
void *tmp;
if(error) error->succ=false;
if(error==NULL)
{
OperationDetail err;
if(isInvalid(ptr,&lb,&ub,&es,&err,p2f)) return;
}
else{
if(isInvalid(ptr,&lb,&ub,&es,error,p2f)) return;
}
heavestElement=(void *)malloc(es);
if(heavestElement==NULL)
{
error->code=2;
return;
}
ifLowerBoundIsNotZero(ptr,&lb,&ub);
findHeavestElement(ptr,&lb,&ub,heavestElement);


}
*/
#endif