#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h> // Adicionado para lidar com strings

struct tp_produto {
    int codigo;
    char nome[100];
    struct tp_produto *prox;
};

typedef struct tp_produto Produto;

Produto *inicio = NULL;
Produto *fim = NULL;
bool sair = false;
int op;

// Função para simular o "pause" no Linux
void pausa() {
    printf("\nPressione ENTER para continuar...");
    getchar(); // Pega o '\n' pendente
    getchar(); // Espera o novo ENTER
}

void cadastrar() {
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    if (novo == NULL) return;

    printf("Digite o código: ");
    scanf("%d", &novo->codigo);
    
    // Limpeza de buffer compatível com Linux
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o nome: ");
    // fgets é seguro e funciona no Linux
    fgets(novo->nome, 100, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = 0; // Remove o '\n' que o fgets captura

    novo->prox = NULL;

    if (inicio == NULL) { 
        inicio = novo;
        fim = novo;
    } else {              
        fim->prox = novo;
        fim = novo;
    }
    printf("Produto enfileirado!\n");
    pausa();
}

void consultar() {
    int cod;
    printf("Código para consulta: ");
    scanf("%d", &cod);
    Produto *atual = inicio;
    while (atual != NULL) {
        if (atual->codigo == cod) {
            printf("Encontrado: %s\n", atual->nome);
            pausa();
            return;
        }
        atual = atual->prox;
    }
    printf("Não encontrado.\n");
    pausa();
}

void listar() {
    Produto *atual = inicio;
    int contador = 0;

    printf("\n--- FILA DE PRODUTOS ---\n");
    if (inicio == NULL) {
        printf("A fila está vazia!\n");
    } else {
        while (atual != NULL) {
            printf("[%02d] Código: %d | Nome: %s\n", contador + 1, atual->codigo, atual->nome);
            atual = atual->prox;
            contador++;
        }
    }
    printf("------------------------\n");
    printf("Total de itens na fila: %d\n", contador);
    printf("------------------------\n");
    pausa();
}

void remover() {
    if (inicio == NULL) {
        printf("Fila vazia!\n");
    } else {
        Produto *aux = inicio;
        printf("Removendo primeiro da fila: %s\n", aux->nome);
        inicio = inicio->prox; 
        
        if (inicio == NULL) fim = NULL; 
        
        free(aux);
    }
    pausa();
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
    Produto *atual = inicio;
    while (atual != NULL) {
        Produto *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    printf("\nSaindo e liberando memória...\n");
    sair = true;
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    while (sair == false) {
        system("clear"); // "CLS" no Windows é "clear" no Linux
        menu();
        if (scanf("%i", &op) != 1) break; // Proteção básica contra entrada inválida
        
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
