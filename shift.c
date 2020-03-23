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
    double _Z = Z;
    list *_H = copy(H);

    for (int i = 0; i < n; i++)
    {
        list *H_aux = copy(H);
        double Z_aux = Z;
        int A = 0;
        for (int j = 0; j < n - 1; j++)
        {
            turn(j, j + 1, H);
            double Z = sumCost(H, matrix, true);
            if (Z < Z_aux)
            {
                Z_aux = Z;
                A = j;
            }
        }
        if (A != 0 && _Z > Z_aux)
        {
            for (int j = 0; j < A; j++)
            {
                turn(j, j + 1, H_aux);
            }
            _H = copy(H_aux);
            _Z = Z_aux;
        }
    }

    //Adiciona primeiro vertice para fechar o ciclo
    add(_H, _H->inicio->value);
    _Z = sumCost(_H, matrix, false);

    printList(_H);
    printf("\ncusto minimo -> %lf\n", _Z);

    free(matrix);
    free(H);
    free(_H);
    free(fileName);

    return 0;
}