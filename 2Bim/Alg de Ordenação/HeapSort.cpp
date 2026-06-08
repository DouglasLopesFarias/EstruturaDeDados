#include <stdio.h>

// Função para ajustar o Heap
void heapify(int vetor[], int n, int i)
{
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && vetor[esquerda] > vetor[maior])
        maior = esquerda;

    if (direita < n && vetor[direita] > vetor[maior])
        maior = direita;

    if (maior != i)
    {
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;

        heapify(vetor, n, maior);
    }
}

// Função Heap Sort
void heapSort(int vetor[], int n)
{
    // Construção do Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vetor, n, i);

    // Extração dos elementos
    for (int i = n - 1; i > 0; i--)
    {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        heapify(vetor, i, 0);
    }
}

// Impressão do vetor
void imprimir(int vetor[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);

    printf("\n");
}

int main()
{
    int vetor[] = {8, 5, 6, 4, 7, 9};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimir(vetor, n);

    heapSort(vetor, n);

    printf("Vetor ordenado:\n");
    imprimir(vetor, n);

    return 0;
}
