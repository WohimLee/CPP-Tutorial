#ifndef LIST_HPP
#define LIST_HPP

#define OK 1

#ifndef _MATH_H_
#define OVERFLOW  -2
#define UNDERFLOW -3
#define ERROR 0
#endif 

#ifndef NULL
#define NULL ((void*)0)
#endif

#define INIT_SIZE 10
#define INCRETMENT 10
typedef int Status;
typedef int ListElem_t;

typedef struct
{
    ListElem_t* elem;
    int size;
    int capacity;
}List;

Status init(List* L);
Status insert(List* L, int i, ListElem_t e);
void destroy(List* L);



#endif