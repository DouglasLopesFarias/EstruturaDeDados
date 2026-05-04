#include <stdio.h>
#include <stdlib.h>

struct nodo
{
	int valor;
	struct nodo *esq;
	struct nodo *dir;
	int altura;
};

typedef struct nodo Nodo;
int valorRaiz;
bool sair = false;
int op;
Nodo *raiz;

void menu() {
    printf("01 - Cira Raiz\n");
    printf("02 - Insere nó \n");
    printf("03 - Altura\n");
    printf("04 - Imprimir\n"); 
    printf("05 - Sair do Sistema\n");
    printf("Digite uma opção: ");
}

void sairDoSistema() {    
    printf("\nSaindo do sistema...\n");
    sair = true;
}

Nodo* create(int valor){
	Nodo *n = (Nodo*)malloc(sizeof(Nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
}

void imprimir(Nodo *n){
	if(n==NULL)
		return;
	imprimir(n->esq);
	printf("\n%d",n->valor);
	imprimir(n->dir);
}

void add(Nodo *n, int valor){	
	if(valor < n->valor)	{
		if(n->esq == NULL)
			n->esq = create(valor);
		else
			add(n->esq,valor);
	} else	{
		if(n->dir == NULL)
			n->dir = create(valor);
		else
			add(n->dir,valor);
	}
}

void insere(){
	int valor;
	printf("Digite o valor do no: ");
    scanf("%d", valor);
    add(raiz, valor);	
}

void criaRaiz(){
	int valorRaiz;
	printf("Digite o valor da raiz: ");
    scanf("%d", valorRaiz);
	raiz = create(valorRaiz);	
}

int altura(Nodo *n){	
	if(n == NULL){
		return -1;
	}else{
		int esq = altura(n->esq);
		int dir = altura(n->dir);
		if(esq > dir){
			return esq + 1;
		}else{
			return dir + 1;
		}
	}	
		
}

void main(void) {	
	while (sair == false) {
        system("CLS");
        menu();
        scanf("%i", &op);
        switch (op) {
            case 1: criaRaiz(); break;
            case 2: insere(); break;
            case 3: printf("\nAltura: %d", altura(raiz)); break;
            case 4: imprimir(raiz); break;            
            case 5: sairDoSistema(); break;
            default: printf("Opção inválida!\n"); system("pause");
        }
    }
    
}
