
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodo{
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

void menu(){
	printf("01 - Criar a raiz\n");
	printf("02 - Insere no\n");	
	printf("03 - Altura \n");
	printf("04 - Imprimir\n");
	printf("05 - Sair do sistema\n");
	printf("Digite uma opção:\n");
}

void sairDoSistema(){
	printf("Saindo do sistema...\n");
	sair = true;
}

Nodo* create(int valor){
	Nodo *n = (Nodo*)malloc(sizeof(Nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	n->altura = -1;
	return n;
}

void imprimir(Nodo *n){	
	if(n==NULL){
		return;
	}
	imprimir(n->esq);
	printf("\n%d", n->valor);
	imprimir(n->dir);	
}


void add(Nodo *n, int valor){
	if(valor < n-> valor){
		if(n->esq == NULL){
			n->esq = create(valor);
		}else{
			add(n->esq,valor);
		}
	}else{
		if(n->dir == NULL){
			n->dir = create(valor);
		}else{
			add(n->dir,valor);
		}
	}
}

void insere(){
	int valor;
	printf("Digite o valor do no: \n");
	scanf("%d", &valor);
	add(raiz, valor);
}

void criaRaiz(){
	int valorRaiz;
	printf("Digite o valor da raiz: \n");
	scanf("%d", &valorRaiz);
	raiz = create(valorRaiz);
	system("pause");
}


int altura(Nodo *n){
	if(n == NULL){
		return -1;
	}else{
		int alturaEsquerda = altura(n->esq);
		int alturaDireita  = altura(n->dir);
		if(alturaEsquerda > alturaDireita){
			return alturaEsquerda + 1;
		}else{
			return alturaDireita + 1;
		}		
	}
}

int main(){
	while(!sair){
		system("CLS");
		menu();
		scanf("%d", &op);
		switch(op){
			case 1: criaRaiz(); break;
			case 2: insere(); break;
			case 3: printf("Altura: %d\n", altura(raiz)); system("pause");break;
			case 4: imprimir(raiz);	printf("\n"); system("pause"); break;
			case 5: sairDoSistema(); break;			
			default: printf("Opção inválida!\n"); system("pause");
		}
	}
	return 0;
}
