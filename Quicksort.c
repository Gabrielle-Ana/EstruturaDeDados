#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Declaração do vetor
char *arr[20] = {
    "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga",
    "abacate", "kiwi", "cereja", "morango", "pêssego", "goiaba", "melancia",
    "framboesa", "amora", "caqui", "figo", "papaya"
};

int swaps = 0;
int comparisons = 0;

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

int partition(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    printf("Número de trocas: %d\n", swaps);
    printf("Número de comparações: %d\n", comparisons);

    // Mediana do conjunto de dados
    if (n % 2 == 0) {
        printf("Mediana: %s e %s\n", arr[(n-1)/2], arr[n/2]);
    } else {
        printf("Mediana: %s\n", arr[n/2]);
    }

    // Gerar arquivo texto de saída
    FILE *outputFile = fopen("saida.txt", "w");
    if (outputFile) {
        for (int i = 0; i < n; i++) {
            fprintf(outputFile, "%s\n", arr[i]);
        }
        fclose(outputFile);
    } else {
        printf("Erro ao criar o arquivo de saída!\n");
    }

    return 0;
}
