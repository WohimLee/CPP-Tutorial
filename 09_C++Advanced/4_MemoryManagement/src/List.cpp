#include "List.hpp"
#include <stdlib.h>
#include <stdio.h>



Status init(List* L)
{
    (*L).elem = (ListElem_t*)calloc(INIT_SIZE, sizeof(ListElem_t));
    if (!(*L).elem)
        exit(OVERFLOW);
    
    (*L).size = 0;
    (*L).capacity = INIT_SIZE;
    printf("Initialize Success!\n");

    return OK;
}

Status insert(List* L, int i, ListElem_t e)
{
    ListElem_t* newbase;
    ListElem_t *p, *q;

    if (i < 0 || i > (*L).size)
        return ERROR;

    if ((*L).size >= (*L).capacity)
    {
        newbase = (ListElem_t*)realloc((*L).elem, ((*L).capacity+INCRETMENT)*sizeof(ListElem_t));
        if (!newbase)
            exit (OVERFLOW);
        
        (*L).elem = newbase;
        (*L).capacity += INCRETMENT;
        printf("-------Realloc Memory--------\n");
    }

    q = &(*L).elem[i];

    for (p = &(*L).elem[(*L).size-1]; p >= q; --p)
        *(p+1) = *p;
    
    *q = e;
    printf("Insert %d\n", e);
    (*L).size++;

    return OK;
}

void destroy(List* L)
{
    free((*L).elem);

    (*L).elem = nullptr;
    (*L).size = 0;
    (*L).capacity = 0;
}

//  0 1  2  3 4 5 6
//  1 2 888 3 4 5 6


