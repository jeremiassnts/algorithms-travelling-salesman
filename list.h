#ifndef LIST_HEADER
#define LIST_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _elem{
    int value;
    struct _elem *prox;
} elem;

typedef struct _list{
    elem *inicio;
    elem *fim;
    int size;
} list;

void add(list *ls, int value);
list *newList();
void printList(list *ls);
bool some(list *ls, int value);
double sumCost(list *ls, double **m, bool cycle);
void createCycle(list *ls, int n);
void turn(int i, int j, list *ls);
elem *getByIndex(int i, list *ls);

#endif