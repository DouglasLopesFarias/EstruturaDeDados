//Para criar uma Fila (FIFO - First In, First Out), a lógica muda: 
//inserimos sempre no fim e removemos sempre no início. Para isso, usamos dois ponteiros auxiliares.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tp_produto {
    int codigo;
    char nome[100];    
    struct tp_produto *prox;
};

typedef struct tp_produto Produto;

// Ponteiros para controlar as extremidades da fila
Produto *inicio = NULL;
Produto *fim = NULL;

// Inserção (Enqueue): Entra pelo fim
void inserir(int cod, char n[]) {
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    novo->codigo = cod;
    strcpy(novo->nome, n);
    novo->prox = NULL; // O último elemento sempre aponta para NULL

    if (inicio == NULL) {
        inicio = novo; // Se for o primeiro, é início e fim ao mesmo tempo
    } else {
        fim->prox = novo; // O antigo fim aponta para o novo
    }
    fim = novo; // Atualiza o ponteiro fim para o novo elemento
    printf("Inserido na fila: %s\n", n);
}

// Remoção (Dequeue): Sai pelo início
void remover() {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }
    Produto *aux = inicio; // Guarda o início para liberar depois
    printf("Removendo da fila: %s\n", aux->nome);
    
    inicio = inicio->prox; // O início agora é o segundo da fila
    
    if (inicio == NULL) {
        fim = NULL; // Se a fila esvaziou, o fim também fica nulo
    }
    
    free(aux); // Deleta o elemento que saiu
}

int main() {
    // Ilustração das operações
    inserir(10, "Arroz");
    inserir(20, "Feijão");
    inserir(30, "Macarrão");

    printf("\nEstado: O primeiro a sair será o Arroz (FIFO)\n\n");

    remover(); // Remove Arroz
    remover(); // Remove Feijão

    return 0;
}

