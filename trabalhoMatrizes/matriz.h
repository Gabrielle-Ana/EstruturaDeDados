#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>

// Estrutura para representar um nó da lista
typedef struct Node {
    int row;
    int col;
    double value;
    struct Node *nextRow;
    struct Node *nextCol;
} Node;

// Estrutura para representar a matriz esparsa
typedef struct {
    int rows;
    int cols;
    Node *head;
} Matriz;

Matriz initMatriz(int rows, int cols);
void insere(Matriz *A, int row, int col, double value);
void imprimeMatriz(Matriz A);
Matriz leMatriz(FILE *file);
Matriz somaMatrizes(Matriz A, Matriz B);
Matriz multiplicaMatrizes(Matriz A, Matriz B);

void liberaMatriz(Matriz *A);

#endif