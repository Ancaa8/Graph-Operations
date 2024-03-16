/*ANDREI anca-Teodora - 313 CC*/

#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdlib.h>
#include <math.h>

typedef struct MinHeapNode
{
    int v;
    float d;
} MinHeapNode;


typedef struct MinHeap
{
    int size;
    int capacity;
    int *pos;
    MinHeapNode **elem;
} MinHeap;


MinHeapNode* newNode(int v, float d);
MinHeap* newQueue(int capacity);
int isEmpty(MinHeap* h);
MinHeapNode* removeMin(MinHeap* h);
void SiftUp(MinHeap* h, int idx);

#endif