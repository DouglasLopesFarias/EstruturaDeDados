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

// Na fila, precisamos controlar o in�cio e o fim
Produto *inicio = NULL;
Produto *fim = NULL;
bool sair = false;
int op;

void cadastrar() {
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    if (novo == NULL) return;

    printf("Digite o c�digo: ");
    scanf("%d", &novo->codigo);
    printf("Digite o nome: ");
    fflush(stdin);
    getw(novo->nome);
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
    printf("C�digo para consulta: ");
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
    printf("N�o encontrado.\n");
    system("pause");
}

/*void listar() {
    Produto *atual = inicio;
    printf("\n--- FILA DE PRODUTOS ---\n");
    while (atual != NULL) {
        printf("C�digo: %d | Nome: %s\n", atual->codigo, atual->nome);
        atual = atual->prox;
    }
    system("pause");
}*/

void listar() {
    Produto *atual = inicio;
    int contador = 0; // Inicializa o contador

    printf("\n--- FILA DE PRODUTOS ---\n");
    if (inicio == NULL) {
        printf("A fila est� vazia!\n");
    } else {
        while (atual != NULL) {
            printf("[%02d] C�digo: %d | Nome: %s\n", contador + 1, atual->codigo, atual->nome);
            atual = atual->prox;
            contador++; // Incrementa para cada n� encontrado
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
        inicio = inicio->prox; // Avan�a o in�cio
        
        if (inicio == NULL) fim = NULL; // Se esvaziou, o fim tamb�m � nulo
        
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
    printf("Digite uma op��o: ");
}

void sairDoSistema() {
    // Limpeza de mem�ria antes de sair
    Produto *atual = inicio;
    while (atual != NULL) {
        Produto *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    printf("\nSaindo e liberando mem�ria...");
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
//Dois Ponteiros: Adicionamos o ponteiro fim para que a inser��o seja r�pida (O(1)), sem precisar percorrer a lista toda vez.
//L�gica de Inser��o: O cadastrar coloca o novo elemento ap�s o fim e atualiza o fim.
//L�gica de Remo��o: O remover retira sempre o elemento do inicio.


