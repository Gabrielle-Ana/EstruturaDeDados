#include <stdio.h>

int main() {
    FILE *entrada, *saida;
    char nome[100], telefone[20], curso[100];
    float nota1, nota2, media;

    entrada = fopen("DadosEntrada.cvs", "r");
    saida = fopen("SituacaoFinal.cvs", "w");

    while (fscanf(entrada, "%[^,],%[^,],%[^,],%f,%f\n", nome, telefone, curso, &nota1, &nota2) == 5) {
        media = (nota1 + nota2) / 2;
        fprintf(saida, "%s, %.2f, %s\n", nome, media, media >= 7.0 ? "APROVADO" : "REPROVADO");
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
