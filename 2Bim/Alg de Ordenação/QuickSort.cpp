#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Função de particionamento
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim]; // último elemento como pivô
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] < pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }

    trocar(&vetor[i + 1], &vetor[fim]);
    return i + 1; // posição final do pivô
}

// Função Quick Sort
void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int posicaoPivo = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, posicaoPivo - 1);
        quickSort(vetor, posicaoPivo + 1, fim);
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {5, 3, 8, 2, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    quickSort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}
