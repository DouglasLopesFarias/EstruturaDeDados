#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

struct tp_produto {
    int codigo;
    char nome[100];
    struct tp_produto *prox;
};

typedef struct tp_produto Produto;

// Variáveis globais para controle
Produto *topo = NULL;
bool sair = false;
int op;

void cadastrar() {
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    if (novo == NULL) {
        printf("Erro de memória!\n");
        return;
    }
    printf("Digite o código: ");
    scanf("%d", &novo->codigo);
    printf("Digite o nome: ");
    fflush(stdin); // Limpa o buffer
    gets(novo->nome);

    novo->prox = topo; // O novo elemento aponta para o antigo topo
    topo = novo;       // O topo agora é o novo elemento
    printf("Produto cadastrado com sucesso!\n");
    system("pause");
}

void consultar() {
    int cod;
    printf("Código para consulta: ");
    scanf("%d", &cod);
    Produto *atual = topo;
    while (atual != NULL) {
        if (atual->codigo == cod) {
            printf("Produto encontrado: %s\n", atual->nome);
            system("pause");
            return;
        }
        atual = atual->prox;
    }
    printf("Produto não encontrado.\n");
    system("pause");
}

void listar() {
    Produto *atual = topo;
    printf("\n--- LISTA DE PRODUTOS (PILHA) ---\n");
    while (atual != NULL) {
        printf("Código: %d | Nome: %s\n", atual->codigo, atual->nome);
        atual = atual->prox;
    }
    printf("---------------------------------\n");
    system("pause");
}

void remover() {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
    } else {
        Produto *aux = topo;
        topo = topo->prox; // O topo passa a ser o próximo elemento
        printf("Produto %s removido do topo.\n", aux->nome);
        free(aux); // Libera a memória do elemento removido
    }
    system("pause");
}

void menu() {
    printf("\n01 - Cadastrar (Push)\n");
    printf("02 - Consultar\n");
    printf("03 - Listar\n");
    printf("04 - Remover (Pop)\n");
    printf("05 - Sair do Sistema\n");
    printf("Digite uma opção: ");
}

void limparPilha() {
    Produto *atual = topo;
    Produto *proximo;

    while (atual != NULL) {
        proximo = atual->prox; // Guarda a referência do próximo antes de apagar o atual
        free(atual);           // Libera a memória do nó atual
        atual = proximo;       // Move para o próximo
    }
    topo = NULL;
    printf("\nMemória liberada com sucesso!");
}

void sairDoSistema() {
    limparPilha(); // Chama a limpeza antes de fechar
    printf("\nSaindo do sistema...\n");
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
            default: printf("Opção inválida!\n"); system("pause");
        }
    }
    return 0;
}


//Cadastrar (Push): Insere o novo nó sempre no início (topo), fazendo o novo->prox apontar para onde o topo apontava.
//Remover (Pop): Como é uma pilha, a remoção acontece obrigatoriamente no topo. O ponteiro topo avança para o próximo e o anterior é liberado da memória.
//Listar: Percorre a lista do topo até a base (do último inserido para o primeiro).
//Gerenciamento de Memória: Uso de malloc para criar nós e free para evitar vazamentos ao remover.


