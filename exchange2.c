#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "matrix.c"
#include "list.c"

int main()
{
    //nome do arquivo & quantidade de linhas/colunas
    char *fileName = (char *)malloc(sizeof(char) * 1000);
    int n;
    scanf("%s %d", fileName, &n);

    double **matrix = readMatrix(fileName, n);
    list *H = newList();
    //cria ciclo em ordem numerica
    createCycle(H, n);
    double Z = sumCost(H, matrix, true);
    double Z_aux = Z;
    int A = -1;
    int B = -1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            turn(i, j, H);
            Z = sumCost(H, matrix, true);
            if (Z < Z_aux)
            {
                Z_aux = Z;
                A = i;
                B = j;
            }
            turn(i, j, H);
        }
    }

    if (A != -1)
    {
        turn(A, B, H);
        Z = Z_aux;
    }

    //Adiciona primeiro vertice para fechar o ciclo
    add(H, H->inicio->value);
    Z = sumCost(H, matrix, false);

    printList(H);
    printf("\ncusto minimo -> %lf\n", Z);

    free(matrix);
    free(H);
    free(fileName);

    return 0;
}