#include "matriz.h"

int main() {
    // Teste da função leMatriz
    FILE *file = fopen("entrada.txt", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    Matriz A = leMatriz(file);
    fclose(file);

    // Teste da função imprimeMatriz
    printf("Matriz A:\n");
    imprimeMatriz(A);

    // Teste da função somaMatrizes
    Matriz B = leMatriz(file); // Carregar outra matriz para a soma
    Matriz C = somaMatrizes(A, B);
    printf("Matriz B:\n");
    imprimeMatriz(B);
    printf("\n");
    printf("Soma de A e B:\n");
    imprimeMatriz(C);
    printf("\n");

    // Teste da função multiplicaMatrizes
    Matriz D = leMatriz(file);
    Matriz E = multiplicaMatrizes(A, D);
    printf("Matriz D:\n");
    imprimeMatriz(D);
    printf("\n");
    printf("Multiplicação de A e D:\n");
    imprimeMatriz(E);

     // Libere a memória alocada para as matrizes
    liberaMatriz(&A);
    liberaMatriz(&B);
    liberaMatriz(&C);
    liberaMatriz(&D);
    liberaMatriz(&E);

    return 0;
}