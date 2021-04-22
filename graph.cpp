/**
 * Author:Daniel Arciniega
 * This program will hold the methods to
 * ./dijikstra <graph> <direction> this is how to run the program
 */

#include "graph.h"
#include "heap.h"
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int dijkstra(int n, pNODE* A, pVERTEX* V, int source, int destination, int f)
{
    pNODE node;

    pELEMENT element;
    int u, v, i;
    float w;
    int pos;

    float oldKey;

    for(i = 1; i <= n; i++)
    {

        V[i]->color = 0;
        V[i]->pi = 0;

    }


    V[source]->color = 1;   //grey color
    V[source]->d = 0;    //distance to itself


    HEAP* heap = heap->initialize(n);

    element = (ELEMENT*) malloc(sizeof(ELEMENT));
    element->vertex = source;
    element->key = V[source]->d;

    heap->insert(heap, V, element);

    if(f ==1)
    {
        printf("Insert vertex %d, key=%12.4f\n", element->vertex, element->key);
    }
    
       while(heap->size != 0)
    {
        element = heap->extractMin(heap, V);

        if(f == 1)
        {
            printf("Delete vertex %d, key=%12.4f\n", element->vertex, element->key);
        }

        u = element->vertex;

        V[u]->color = 2;

        if(u == destination)
        {
            break; //source found
        }

        free(element);

        node = A[u];

        while(node != NULL)
        {
            v = node->v;
            w = node->w;

            if(V[v]->color == 0)
            {
                V[v]->color = 1;
                V[v]->pi = u;
                V[v]->d = V[u]->d + w;


                element = (ELEMENT*) malloc(sizeof(ELEMENT));
                element->vertex = v;
                element->key = V[v]->d;

                heap->insert(heap, V, element);

                if(f == 1)
                {
                    printf("Insert vertex %d, key=%12.4f\n", v, V[v]->d);

                }

            }
            else if(V[v]->d > V[u]->d + w)
            {
                if(f == 1)
                {

                    printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", v, V[v]->d, V[u]->d+w);
                }

                oldKey = V[v]->d;
                V[v]->d = V[u]->d + w;
                V[v]->pi = u;

                heap->xueDecreaseKey(heap, V, V[v]->pos, V[v]->d);
            }//end else if

            node = node -> next;

        }//while(node!)
    }//end while(!HEAP)
    return 1;
}
void printPath(int n, int source, pVERTEX* V, int destination, int s, int t)
{
    int u, v;
    int arr[n+1];

    //initalize variables
    PATH *pPath;
    PATH *pNODE;

    //using a stack to and pushing its values
    pNODE = (PATH *) malloc(sizeof(PATH));
    pNODE->vertex = t;
    pNODE->next = NULL;
    pPath = pNODE;
    v = pNODE->vertex;

    arr[0] = t;
    int count = 1;
    while(V[v]->pi)
    {
        u = V[v]->pi;
        pNODE = (PATH *) malloc(sizeof(PATH));

        //save path
        pNODE->vertex = u;
        pNODE->next = pPath;

        v = pNODE->vertex;

        arr[count] = v;
        count++;
    }
    
    int arr2[count];
  if(V[t]->color == 0)
    {
        if(destination < 1 || destination > n || t == destination)
        {
            printf("No %d-%d path exists.\n", s,t);
            return;
        }
        else
        {
            printf("No %d-%d path has been computed.\n", s, t);
            return;
        }
    }
    else if(V[t]->color == 1)
    {
        printf("Path not known to be shortest: <%d, %d", s,t);
    }
    else if(V[t]->color == 2)
    {
       
    }
    

    pNODE = pPath;
    pPath = pPath->next;
    free(pNODE);
	cout << "test" <<endl;
    while (pNODE)
    {
        pNODE = pPath;
        printf(" , %d", pNODE->vertex);
        pNODE = pNODE->next;
    }
    cout << "test2" << endl;
    printf(">\n");
    printf("The path weight is: %12.4f\n", V[t]->d);


}

