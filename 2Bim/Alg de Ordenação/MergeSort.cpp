#include <stdio.h>

// Função para intercalar (merge) duas partes ordenadas
void merge(int vetor[], int inicio, int meio, int fim) {
    int i, j, k;

    int tamanhoEsq = meio - inicio + 1;
    int tamanhoDir = fim - meio;

    // Vetores auxiliares
    int esquerda[tamanhoEsq];
    int direita[tamanhoDir];

    // Copia os dados para os vetores auxiliares
    for (i = 0; i < tamanhoEsq; i++)
        esquerda[i] = vetor[inicio + i];

    for (j = 0; j < tamanhoDir; j++)
        direita[j] = vetor[meio + 1 + j];

    i = 0; // índice da esquerda
    j = 0; // índice da direita
    k = inicio; // índice do vetor original

    // Intercala os vetores auxiliares em ordem
    while (i < tamanhoEsq && j < tamanhoDir) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    // Copia elementos restantes da esquerda
    while (i < tamanhoEsq) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    // Copia elementos restantes da direita
    while (j < tamanhoDir) {
        vetor[k] = direita[j];
        j++;
        k++;
    }
}

// Função Merge Sort
void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        // Ordena a metade esquerda
        mergeSort(vetor, inicio, meio);

        // Ordena a metade direita
        mergeSort(vetor, meio + 1, fim);

        // Junta as duas metades
        merge(vetor, inicio, meio, fim);
    }
}

// Imprime o vetor
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
int main() {
    int vetor[] = {8, 3, 5, 2};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    mergeSort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}
