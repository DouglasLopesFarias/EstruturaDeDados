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

Produto *topo = NULL;
bool sair = false;
int op;

// Função para substituir o system("pause") no Linux
void pausa() {
    printf("\nPressione ENTER para continuar...");
    getchar(); // Limpa o buffer do scanf
    getchar(); // Aguarda o ENTER do usuário
}

void cadastrar() {
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    if (novo == NULL) {
        printf("Erro de memória!\n");
        return;
    }
    printf("Digite o código: ");
    scanf("%d", &novo->codigo);
    
    // Limpeza de buffer correta para Linux
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o nome: ");
    fgets(novo->nome, 100, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = 0; // Remove o \n do final

    novo->prox = topo; 
    topo = novo;       
    printf("Produto cadastrado com sucesso!\n");
    pausa();
}

void consultar() {
    int cod;
    printf("Código para consulta: ");
    scanf("%d", &cod);
    Produto *atual = topo;
    while (atual != NULL) {
        if (atual->codigo == cod) {
            printf("Produto encontrado: %s\n", atual->nome);
            pausa();
            return;
        }
        atual = atual->prox;
    }
    printf("Produto não encontrado.\n");
    pausa();
}

void listar() {
    Produto *atual = topo;
    printf("\n--- LISTA DE PRODUTOS (PILHA) ---\n");
    while (atual != NULL) {
        printf("Código: %d | Nome: %s\n", atual->codigo, atual->nome);
        atual = atual->prox;
    }
    printf("---------------------------------\n");
    pausa();
}

void remover() {
    if (topo == NULL) {
        printf("Pilha vazia!\n");
    } else {
        Produto *aux = topo;
        topo = topo->prox; 
        printf("Produto %s removido do topo.\n", aux->nome);
        free(aux); 
    }
    pausa();
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
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    topo = NULL;
}

void sairDoSistema() {
    limparPilha();
    printf("\nSaindo do sistema...\n");
    sair = true;
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    while (!sair) {
        system("clear"); // Comando Linux
        menu();
        if (scanf("%i", &op) != 1) break;
        
        switch (op) {
            case 1: cadastrar(); break;
            case 2: consultar(); break;
            case 3: listar(); break;
            case 4: remover(); break;
            case 5: sairDoSistema(); break;
            default: printf("Opção inválida!\n"); pausa();
        }
    }
    return 0;
}
