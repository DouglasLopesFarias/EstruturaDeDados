#include <stdio.h>

void countingSort(int vetor[], int n) {
    int i;

    // Encontrar o maior elemento
    int maior = vetor[0];

    for(i = 1; i < n; i++) {
        if(vetor[i] > maior)
            maior = vetor[i];
    }

    int contagem[maior + 1];

    // Inicializar vetor de contagem
    for(i = 0; i <= maior; i++)
        contagem[i] = 0;

    // Contar ocorrências
    for(i = 0; i < n; i++)
        contagem[vetor[i]]++;

    // Reconstruir vetor ordenado
    int indice = 0;

    for(i = 0; i <= maior; i++) {
        while(contagem[i] > 0) {
            vetor[indice++] = i;
            contagem[i]--;
        }
    }
}

int main() {
    int vetor[] = {4, 2, 2, 8, 3, 3, 1};

    int n = sizeof(vetor)/sizeof(vetor[0]);

    countingSort(vetor, n);

    printf("Vetor ordenado:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", vetor[i]);

    return 0;
}
