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

    for(i = 1; i <=m; i++)
    {
        v_fscanf = fscanf(ifile, "%d%d%d%f", &edge_id, &u, &v, &w);
        if(v_fscanf < 4)
        {
            printf("Error: fscanf returns %d.\n", v_fscanf);
            exit(1);
        }
    
        //creates a pointerNode using size of NODE
        node = (pNODE) malloc(sizeof(NODE));
        if(!node)
        {
            printf("Error: malloc failure.\n");
            exit(1);
        }

        //sets the current [m] node with values
        node->u = u;
        node->v = v;
        node->w = w;
        node->next = A[u];

        //adjacency list does not need to be freed 
        //adds the [m] node to the 
        A[u] = node;

        //for undirected graphs
        if(!directed_graph)
        {
            //BGN: undirected 
            node = (pNODE) malloc(sizeof(NODE));
            if(!node)
            {
                printf("Error: malloc failure.\n");
                exit(1);
            }
            node->u = v;
            node->v = u;
            node->w = w;
            node->next = A[v];
            A[v] = node;
        }//end if Undirected Graphs

    }//end for loop

    //close the input file;
    fclose(ifile);

    //set default values for VERTEX variables
    source = 0;
    destination = 0;
    //creates V array
    V = (pVERTEX *) calloc(n+1, sizeof(pVERTEX));
    if(!V)
    {
        printf("Error: calloc failure.\n");
        exit(1);
    }

    for(i = 1; i <= n; i++)
    {
        V[i] = (VERTEX *) malloc(sizeof(VERTEX));
        if(!V[i])
        {
            printf("Error: malloc failure.\n");
            exit(1);
        }
        V[i]->vertex = i;
    }
    
    while(1)
    {   
        //first read in command 
        r_value = nextWord(word);

        //if there is no read value
        if(!r_value) 
        {
            printf("ErrorGLX: EOF\n");
            continue;
        }

        //stop command (FREE MEMORY HERE)
        if(0 == strcmp(word, "stop"))
        {
            printf("Query: %s\n", word);
            break;
        }//end stop

        //find command
        if(0 == strcmp(word, "find"))
        {
            v_scanf = scanf("%d%d%d", &source_new, &destination_new, &flag_new);
            if(v_scanf !=3)
            {
                continue;
            }
            else
            {
                printf("Query: %s %d %d %d\n", 
                    word, source_new, destination_new, flag_new);
                if(source_new < 1 || source_new > n || flag_new < 0 || flag_new > 1)
                {
                    printf("Error: invalid find query\n");
                }
                else
                {
                    source = source_new;
                    destination = destination_new;
                    flag = flag_new;

                    dijkstra(n, A, V, source, destination, flag);
                    continue;
                }
            }

        }//end find

        else if(0 == strcmp(word, "write"))
        {
            r_value = nextWord(word2);
            if(!r_value)
            {
                printf("ErrorGLX4: EOF\n");
                continue; 
            }
            if(0 == strcmp(word2, "path"))
            {
                v_scanf = scanf("%d%d", &s_new, &t_new);
                if(v_scanf !=2)
                {
                    printf("ErrorcwGLX5: wrong return value for scanf\n");
                    continue;
                }
                else
                {
                    printf("Query: %s %s %d %d\n", word, word2, s_new, t_new);
                    
                    if(source == 0 || !A)
                    {
                        printf("Error: no path computation done\n");
                    }

                    else if(s_new != source || t_new == s_new || t_new < 1 || t_new > n)
                    {
                        printf("Error: invalid source destination pair\n");
                    }

                    else
                    {
                        s = s_new; t = t_new;
                        printPath(n, source, V, destination, s, t);
                    }

                }
            }
        }//end of write
        else
        {
            printf("ErrorGLX: Bad Input\n");
            continue;
        }
    }//end of query loop
    


}


