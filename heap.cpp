/** 
 * Author: Daniel Arciniega
 * Function: This hold the heap class methods
 * from Heap.h to be used in the main
*/


#include "Heap.h"
#include "Graph.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

//construct heap
HEAP::HEAP(int n)
{
    capacity = n;
    size = 0; //correct I think
    //size = 12;	//wrong I think

    //element pointer array
    pVERTEX* arr = new pVERTEX[n + 1];  //dynamically allocated

    H = arr;


}

//initialize, return HEAP* ptr
HEAP*	HEAP::initialize(int n)
{
    HEAP* heap = new HEAP(n);   //will be dynamically allocated in the constuctor

    return heap;
}


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


//element into the heap pointed to by heap
int HEAP::insert(HEAP* heap, pVERTEX* V, pELEMENT obj)
{
    if(heap->size >= heap->capacity)
    {
        printf("Error in HeapInsert: Heap full...\n");
        return 1;
    }
    heap->size++;
    heap->H[heap->size] = obj;
    heap->H[heap->size]->pos = heap->size;

    MovingUp(heap, V, heap->size);
    return 1;

}

int	HEAP::xueDecreaseKey(HEAP* heap, pVERTEX* V, int pos, float newKey)
{

    if(pos < 1 || pos > heap->size || newKey >= heap->H[pos]->key)
    {

    }
        //else key = newKey
    else
    {

        heap->H[pos]->key = newKey;
        MovingUp(heap, V, pos);
    }
    return 1;
}

void HEAP::MovingUp (HEAP *heap, pVERTEX* V, int pos)
{

    int parent;
    pELEMENT temp;

    parent = pos/2;

    if(pos > 1 && heap->H[pos]->key < heap->H[parent]->key)
    {

        temp = heap->H[pos];
        heap->H[pos] = heap->H[parent];
        heap->H[parent] = temp;
        V[heap->H[pos]->vertex]->pos = pos;	//current vertex position is updated in vertex array
        V[heap->H[parent]->vertex]->pos = parent; //the parents position gets updated in the vertex array
        MovingUp(heap, V, parent);
    }

}

int hParent(int i)
{
    return i/2;
}
int hLeft(int i)
{
    return 2*i;
}
int hRight(int i)
{
    return ((2 * i) + 1);
}

void HEAP::minHeap(HEAP* heap, pVERTEX* V, int index)
{

    int left = hLeft(index);
    int right = hRight(index);

    if(left <= heap->size && heap->H[left]->key <= heap->H[index]->key)
    {
        smallest = left;
    }
    else
    {
        smallest = index;
    }
    if(right <= heap->size && heap->H[right]->key < heap->H[smallest]->key)
    {
        smallest = right;
    }
    if(smallest != index)
    {
        swap(heap->H[index], heap->H[smallest]);
        swap(V[heap->H[index]->vertex]->pos, V[heap->H[smallest]->vertex]->pos);
        swap(heap->H[smallest]->key, heap->H[index]->key);
        minHeap(heap, V, smallest);
    }
    //}
}

pELEMENT HEAP::extractMin(HEAP* heap, pVERTEX* V)
{
    pELEMENT min, last;

    if(heap->size <= 0)
    {
        return NULL;
    }
    min = heap->H[1];
    last = heap->H[heap->size--];
    heap->H[1] = last;
    V[heap->H[1]->vertex]->pos = 1;
    heap->minHeap(heap, V, min->vertex);
    V[min->vertex]->pos = 0;
    return min;
}

