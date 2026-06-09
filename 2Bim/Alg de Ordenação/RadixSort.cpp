#include <stdio.h>

int getMax(int vetor[], int n) {
    int max = vetor[0];
    for(int i = 1; i < n; i++)
        if(vetor[i] > max)
            max = vetor[i];
    return max;
}
void countingSort(int vetor[], int n, int exp) {
    int saida[n];
    int contagem[10] = {0};
    // Contagem dos dígitos
    for(int i = 0; i < n; i++)
        contagem[(vetor[i] / exp) % 10]++;
    // Soma acumulada
    for(int i = 1; i < 10; i++)
        contagem[i] += contagem[i - 1];
    // Construção do vetor ordenado
    for(int i = n - 1; i >= 0; i--) {
        int indice = (vetor[i] / exp) % 10;
        saida[contagem[indice] - 1] = vetor[i];
        contagem[indice]--;
    }
    // Copiar para o vetor original
    for(int i = 0; i < n; i++)
        vetor[i] = saida[i];
}

void radixSort(int vetor[], int n) {
    int max = getMax(vetor, n);

    for(int exp = 1; max / exp > 0; exp *= 10)
        countingSort(vetor, n, exp);
}
int main() {
    int vetor[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    radixSort(vetor, n);
    printf("Vetor ordenado:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    return 0;
}
