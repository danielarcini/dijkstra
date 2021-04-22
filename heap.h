/** 
 * Author: Daniel Arciniega
 * Header the methods and variablesr file
*/


#ifndef Heap_h
#define Heap_h
#include <stdio.h>
#include "graph.h"

typedef VERTEX ELEMENT;
typedef VERTEX *pELEMENT;


typedef ELEMENT *eELEMENT;

class HEAP
{
public:
    int capacity;
    int size;
    pELEMENT* H;      //With <type> ELEMENT

    HEAP()
    {

    }
    HEAP(int n);

    HEAP* initialize(int n);

    //methods
    int xueDecreaseKey(HEAP *a, pVERTEX* V, int pos, float newKey);
    void MovingUp (HEAP *a, pVERTEX* V,int pos);
    int insert(HEAP* a, pVERTEX* V, pELEMENT obj);
    pELEMENT extractMin(HEAP* heap, pVERTEX* V);
    void minHeap(HEAP* heap, pVERTEX* V, int i);
};
#endif

