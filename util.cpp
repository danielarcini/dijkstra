/** 
 * Author: Daniel Arciniega
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "heap.h"
using namespace std;


int nextWord (char *word)
{
    char c;
    int i, r_value;

    //printf ("BGN nextWord\n");

    r_value = 0;
    c = getchar();

    //when reading a space, tab or enter, it keeps reading for char
    while(c == ' ' || c == '\t' || c == '\n')
    {
        c = getchar();
    }

    //checks to see if it is an alphabet letter
    while(!isalpha(c))
    {
        c = getchar();
        if(c == EOF)
        {
            return 0;
        }
    }

    //once it's inside of the word
    i = 0;

    return r_value;

    //printf("END nextWord\n");
    //r_value is 1 for success
    //r_value is 0 for fail

    
}

