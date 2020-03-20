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

double sumCost(list *ls, double **m)
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
    return cost;
}