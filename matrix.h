#ifndef MATRIX_HEADER
#define MATRIX_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "list.h"

double **readMatrix(char *fileName, int n);
void printMatrix(double **matrix, int n);
int near(list *ls, int n, double **m);

#endif