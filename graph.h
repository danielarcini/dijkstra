#ifndef Graph_H
#define Graph_H
#define N 10
#define INF 1000000

class VERTEX
{
public:

    //Variables
    int color; //color of vertex in {0,1,2} 0 = white, 1 = grey, 2 = black
    int pi; //predecssor of vertex in {1,2, ..., n} 0 == nil
    float d; //name current distance from source vertex
    int pos; //index in the heap array MAKE SURE TO UPDATE IN HEAP OPERATIONS

    float key; //holds the distance from the source vertex

    int vertex;

};

typedef VERTEX *pVERTEX;

//This the adjacency list of vertex u, and will be called A[u] 
class NODE
{
public:
    int u;

    int v; //end vertex v
    float w; //weight of edge (u,v)

    NODE *next; //pointer to the next node
};

//pointer class to node
typedef NODE *pNODE;

class PATH
{
public:
    int vertex;
    PATH *next;
};

//methods
int dijkstra(int n, pNODE *A, pVERTEX* V, int source, int destination, int f);
void printPath(int n, int source, pVERTEX* V, int destination, int s, int t);



#endif



