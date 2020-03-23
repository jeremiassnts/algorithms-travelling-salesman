#include "list.h"

void add(list *ls, int value)
{
    elem *e = (elem *)malloc(sizeof(int));
    e->value = value;
    e->prox = NULL;

    if (ls->size == 0)
    {
        ls->inicio = e;
        ls->fim = e;
    }
    else
    {
        ls->fim->prox = e;
        ls->fim = e;
    }
    ls->size = ls->size + 1;
}

list *newList()
{
    list *ls = (list *)malloc(sizeof(int));
    ls->inicio = NULL;
    ls->fim = NULL;
    ls->size = 0;
    return ls;
}

void printList(list *ls)
{
    elem *e = ls->inicio;
    printf("\n -");
    while (e != NULL)
    {
        printf(" %d -", e->value);
        e = e->prox;
    }
}

bool some(list *ls, int value)
{
    elem *e = ls->inicio;
    while (e != NULL)
    {
        if (e->value == value)
        {
            return true;
        }
        e = e->prox;
    }
    return false;
}

double sumCost(list *ls, double **m, bool cycle)
{
    elem *e = ls->inicio;
    double cost = 0.0;
    while (e != NULL)
    {
        elem *prox = e->prox;
        if (prox != NULL)
        {
            cost += m[e->value - 1][prox->value - 1];
        }
        e = prox;
    }
    if (cycle)
    {
        cost += m[ls->fim->value - 1][ls->inicio->value - 1];
    }
    return cost;
}

void createCycle(list *ls, int n)
{
    for (int i = 0; i < n; i++)
    {
        add(ls, i + 1);
    }
}

void turn(int i, int j, list *ls)
{
    elem *e_i = getByIndex(i, ls);
    elem *e_j = getByIndex(j, ls);
    int aux = e_i->value;

    e_i->value = e_j->value;
    e_j->value = aux;
}

elem *getByIndex(int i, list *ls)
{
    if (i >= ls->size)
    {
        return NULL;
    }

    elem *e = ls->inicio;
    for (int j = 0; j < ls->size; j++)
    {
        if (j == i)
        {
            return e;
        }
        e = e->prox;
    }
    return NULL;
}

list *copy(list *ls)
{
    elem *e = ls->inicio;
    list *new = newList();
    while (e != NULL)
    {
        add(new, e->value);
        e = e->prox;
    }
    return new;
}