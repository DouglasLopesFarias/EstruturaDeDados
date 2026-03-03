#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

struct tp_produto {
    int codigo;
    char nome[100];
    struct tp_produto *prox;
};

typedef struct tp_produto Produto;

// Na fila, precisamos controlar o início e o fim
Produto *inicio = NULL;
Produto *fim = NULL;
bool sair = false;
int op;

void cadastrar() {
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    if (novo == NULL) return;

    printf("Digite o código: ");
    scanf("%d", &novo->codigo);
    printf("Digite o nome: ");
    fflush(stdin);
    gets(novo->nome);
    novo->prox = NULL;

    if (inicio == NULL) { // Se a fila estiver vazia
        inicio = novo;
        fim = novo;
    } else {              // Insere sempre no final
        fim->prox = novo;
        fim = novo;
    }
    printf("Produto enfileirado!\n");
    system("pause");
}

void consultar() {
    int cod;
    printf("Código para consulta: ");
    scanf("%d", &cod);
    Produto *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == cod) {
            printf("Encontrado: %s\n", atual->nome);
            system("pause");
            return;
        }
        atual = atual->prox;
    }
    printf("Não encontrado.\n");
    system("pause");
}

/*void listar() {
    Produto *atual = inicio;
    printf("\n--- FILA DE PRODUTOS ---\n");
    while (atual != NULL) {
        printf("Código: %d | Nome: %s\n", atual->codigo, atual->nome);
        atual = atual->prox;
    }
    system("pause");
}*/

void listar() {
    Produto *atual = inicio;
    int contador = 0; // Inicializa o contador

    printf("\n--- FILA DE PRODUTOS ---\n");
    if (inicio == NULL) {
        printf("A fila está vazia!\n");
    } else {
        while (atual != NULL) {
            printf("[%02d] Código: %d | Nome: %s\n", contador + 1, atual->codigo, atual->nome);
            atual = atual->prox;
            contador++; // Incrementa para cada nó encontrado
        }
    }
    printf("------------------------\n");
    printf("Total de itens na fila: %d\n", contador);
    printf("------------------------\n");
    system("pause");
}

void remover() {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
    } else {
        Produto *aux = inicio;
        printf("Removendo primeiro da fila: %s\n", aux->nome);
        inicio = inicio->prox; // Avança o início
        
        if (inicio == NULL) fim = NULL; // Se esvaziou, o fim também é nulo
        
        free(aux);
    }
    system("pause");
}

void menu() {
    printf("\n01 - Cadastrar (Enqueue)\n");
    printf("02 - Consultar\n");
    printf("03 - Listar\n");
    printf("04 - Remover (Dequeue)\n");
    printf("05 - Sair do Sistema\n");
    printf("Digite uma opção: ");
}

void sairDoSistema() {
    // Limpeza de memória antes de sair
    Produto *atual = inicio;
    while (atual != NULL) {
        Produto *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    printf("\nSaindo e liberando memória...");
    sair = true;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    while (sair == false) {
        system("CLS");
        menu();
        scanf("%i", &op);
        switch (op) {
            case 1: cadastrar(); break;
            case 2: consultar(); break;
            case 3: listar(); break;
            case 4: remover(); break;
            case 5: sairDoSistema(); break;
        }
    }
    return 0;
}

//O que mudou para ser uma Fila:
//Dois Ponteiros: Adicionamos o ponteiro fim para que a inserção seja rápida (O(1)), sem precisar percorrer a lista toda vez.
//Lógica de Inserção: O cadastrar coloca o novo elemento após o fim e atualiza o fim.
//Lógica de Remoção: O remover retira sempre o elemento do inicio.


