#include "matriz.h"
#include <stdlib.h>

Matriz initMatriz(int rows, int cols) {
    Matriz A;
    A.rows = rows;
    A.cols = cols;
    A.head = NULL;
    return A;
}

void insere(Matriz *A, int row, int col, double value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->nextRow = NULL;
    newNode->nextCol = NULL;

    // Inserir na linha
    if (A->head == NULL || row < A->head->row) {
        newNode->nextRow = A->head;
        A->head = newNode;
    } else {
        Node *current = A->head;
        while (current->nextRow != NULL && current->nextRow->row < row) {
            current = current->nextRow;
        }
        newNode->nextRow = current->nextRow;
        current->nextRow = newNode;
    }

    // Inserir na coluna
    if (A->head == NULL || col < A->head->col) {
        newNode->nextCol = A->head;
        A->head = newNode;
    } else {
        Node *current = A->head;
        while (current->nextCol != NULL && current->nextCol->col < col) {
            current = current->nextCol;
        }
        newNode->nextCol = current->nextCol;
        current->nextCol = newNode;
    }
}

void imprimeMatriz(Matriz A) {
    Node *currentRow = A.head;

    for (int i = 1; i <= A.rows; i++) {
        Node *currentCol = currentRow;

        for (int j = 1; j <= A.cols; j++) {
            if (currentCol != NULL && currentCol->col == j) {
                printf("%g ", currentCol->value);
                currentCol = currentCol->nextCol;
            } else {
                printf("0 ");
            }
        }
        printf("\n");

        if (currentRow != NULL && currentRow->row == i) {
            currentRow = currentRow->nextRow;
        }
    }
}

Matriz leMatriz(FILE *file) {
    int rows, cols;
    fscanf(file, "%d, %d", &rows, &cols);
    Matriz A = initMatriz(rows, cols);

    int row, col;
    double value;
    while (fscanf(file, "%d, %d, %lf", &row, &col, &value) == 3) {
        insere(&A, row, col, value);
    }

    return A;
}

Matriz somaMatrizes(Matriz A, Matriz B) {
    Matriz C = initMatriz(A.rows, A.cols);

    Node *nodeA = A.head;
    Node *nodeB = B.head;

    while (nodeA != NULL || nodeB != NULL) {
        if (nodeA == NULL) {
            insere(&C, nodeB->row, nodeB->col, nodeB->value);
            nodeB = nodeB->nextRow;
        } else if (nodeB == NULL) {
            insere(&C, nodeA->row, nodeA->col, nodeA->value);
            nodeA = nodeA->nextRow;
        } else {
            if (nodeA->row < nodeB->row || (nodeA->row == nodeB->row && nodeA->col < nodeB->col)) {
                insere(&C, nodeA->row, nodeA->col, nodeA->value);
                nodeA = nodeA->nextRow;
            } else if (nodeB->row < nodeA->row || (nodeB->row == nodeA->row && nodeB->col < nodeA->col)) {
                insere(&C, nodeB->row, nodeB->col, nodeB->value);
                nodeB = nodeB->nextRow;
            } else {
                // As células estão na mesma posição
                double sum = nodeA->value + nodeB->value;
                if (sum != 0.0) {
                    insere(&C, nodeA->row, nodeA->col, sum);
                }
                nodeA = nodeA->nextRow;
                nodeB = nodeB->nextRow;
            }
        }
    }

    return C;
}

Matriz multiplicaMatrizes(Matriz A, Matriz B) {
    Matriz C = initMatriz(A.rows, B.cols);

    for (int i = 1; i <= A.rows; i++) {
        for (int j = 1; j <= B.cols; j++) {
            double sum = 0.0;

            Node *nodeA = A.head;
            Node *nodeB = B.head;

            while (nodeA != NULL && nodeB != NULL) {
                if (nodeA->col < nodeB->row) {
                    nodeA = nodeA->nextCol;
                } else if (nodeA->col > nodeB->row) {
                    nodeB = nodeB->nextRow;
                } else {
                    sum += nodeA->value * nodeB->value;
                    nodeA = nodeA->nextCol;
                    nodeB = nodeB->nextRow;
                }
            }

            if (sum != 0.0) {
                insere(&C, i, j, sum);
            }
        }
    }

    return C;
}

void liberaMatriz(Matriz *A) {
    Node *currentRow = A->head;
    Node *nextRow;

    while (currentRow != NULL) {
        Node *currentCol = currentRow;
        Node *nextCol;

        while (currentCol != NULL) {
            nextCol = currentCol->nextCol;
            free(currentCol);
            currentCol = nextCol;
        }

        nextRow = currentRow->nextRow;
        free(currentRow);
        currentRow = nextRow;
    }

    A->head = NULL;
}
