// calcula_area_poligono.c
#include <stdio.h>
#include "ponto.h"

int main() {
    FILE *file = fopen("vertices.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    Ponto pontos[n];
    for (int i = 0; i < n; i++) {
        float x, y;
        fscanf(file, "%f %f", &x, &y);
        pontos[i] = criarPonto(x, y);
    }

    fclose(file);

    float area = calcularArea(pontos, n);
    printf("A área do polígono é %.2f\n", area);

    return 0;
}
