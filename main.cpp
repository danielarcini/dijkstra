/**
 * Daniel Arciniega
 * This pieces all of the files together using user given inputs.
 * 
 */
#include "util.h"
#include "heap.h"
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string> 
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    //initalizing values
    FILE *ifile;

    //structures
    pNODE *A;
    pNODE node;
    pVERTEX *V;
        
    //for nextWord
    char word[256];
    char word2[256];

    //for reading text, vertices, edges
    int n, m, directed_graph, i;
    //for source nodes and destination nodes
    int s, s_new, t, t_new, source, source_new, destination, destination_new;
    //for reading source node and next nodes and flags
    int u, v, edge_id, flag, flag_new;
    float w;

    //for util
    int v_scanf, v_fscanf;
    int r_value;


    /* get direction from commandline */
    if(argc != 3)
    {
        printf("Command Format: %s <graph_file> <direction>\n", argv[0]);
        exit(1);
    }

    // <direction> == directed
    //directed_graph == 1 otherwise 0
    if(0 == strcmp(argv[2], "directed\0"))
    {
        directed_graph = 1;
    }

    /* ifile Reading */
    //opens network file to be read 
    ifile = fopen(argv[1], "r");
    if(ifile == NULL)
    {
        cout << "iFile not initalized" << endl;
    }


    v_fscanf = fscanf(ifile, "%d%d", &n, &m);
    if(v_fscanf < 2)
    {
        printf("ErrorGLX2: fscan returns %d.\n", v_fscanf);
    }

    A = (pNODE *) calloc(n+1, sizeof(pNODE));
    if(!A)
    {
        printf("Error: calloc failure.\n");
        exit(1);
    }

}


