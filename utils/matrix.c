#include "matrix.h"
#include <float.h>

double **readMatrix(char *fileName, int n)
{
    double **matrix = (double **)malloc(sizeof(double) * n * n);

    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("\nfile reading error");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        matrix[i] = (double *)malloc(sizeof(double) * n);
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%lf", &matrix[i][j]);
        }
    }

    fclose(file);
    return matrix;
}

int near(list *ls, int n, double **m)
{
    //pega último vértice inserido no ciclo
    int last_v = ls->fim->value - 1;
    //vertice que será retornado
    int w = 0;
    //mínimo valor encontrado
    double min = DBL_MAX;
    for (int i = 0; i < n; i++)
    {
        if (i != last_v && m[last_v][i] < min && !some(ls, i + 1))
        {
            min = m[last_v][i];
            w = i + 1;
        }
    }

    return w;
}

void printMatrix(double **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
        {
            printf(" %lf |", matrix[i][j]);
        }
        printf("\n");
    }
}