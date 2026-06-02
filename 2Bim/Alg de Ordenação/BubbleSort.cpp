#include <stdio.h>

/*1. Bubble Sort (Ordenação por Bolha)
Este algoritmo funciona comparando pares de elementos vizinhos. 
Se eles estiverem na ordem errada, o algoritmo os troca de lugar. 
Os maiores elementos "flutuam" para o final da lista como bolhas de ar.
Vantagem: Muito simples de entender.
Desvantagem: Muito lento para listas grandes.
*/

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            // Se o elemento atual for maior que o próximo, troca
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



int main() {
    int dados[] = {64, 25, 12, 22, 11};
    int tamanho = sizeof(dados) / sizeof(dados[0]);    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", dados[i]);
    }
    printf("\n");
    printf("\ordenado\n");    
    bubbleSort(dados, tamanho);    
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", dados[i]);
    }    
    return 0;
}

