#include <stdio.h>
#include <stdbool.h>

int main() {
    FILE *source, *destination;
    char ch;
    bool insideTag = false;

    // Abra o arquivo HTML de origem
    source = fopen("input.html", "r");
    if (source == NULL) {
        printf("Erro ao abrir o arquivo 'input.html'.\n");
        return 1;
    }

    // Crie ou abra o arquivo de destino para gravação
    destination = fopen("output.txt", "w");
    if (destination == NULL) {
        printf("Erro ao criar ou abrir o arquivo 'output.txt'.\n");
        fclose(source);
        return 1;
    }

    // Processa o arquivo, caractere por caractere
    while ((ch = fgetc(source)) != EOF) {
        if (ch == '<') {
            insideTag = true;
            continue;
        } else if (ch == '>') {
            insideTag = false;
            continue;
        }
        if (!insideTag) {
            fputc(ch, destination);
        }
    }

    // Fecha os arquivos
    fclose(source);
    fclose(destination);

    printf("As tags HTML foram removidas com sucesso! Verifique 'output.txt'.\n");
    return 0;
}
