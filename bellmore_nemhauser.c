#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "utils/matrix.c"
#include "utils/list.c"

int main()
{
    //nome do arquivo & quantidade de linhas/colunas
    char *fileName = (char *)malloc(sizeof(char) * 1000);
    int n;
    scanf("%s %d", fileName, &n);

    double **matrix = readMatrix(fileName, n);
    list *Hls = newList();
    //insere primeiro vertice
    add(Hls, 1);
    //itera até visitar todos vértices
    while (Hls->size < n)
    {
        int w = near(Hls, n, matrix);
        add(Hls, w);
    }
    //fecha o ciclo com o vértice inicial
    add(Hls, 1);

    printList(Hls);
    double cost = sumCost(Hls, matrix);
    printf("\ncusto minimo -> %lf", cost);

    free(matrix);
    free(Hls);
    free(fileName);
    return 0;
}