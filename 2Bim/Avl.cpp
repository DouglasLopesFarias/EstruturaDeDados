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
    if(raiz){
	    printf("Valor da raiz: %d", raiz->valor);
	    printf("\n");
	}	
	printf("01 - Insere\n");	
	printf("02 - Altura \n");
	printf("03 - Imprimir\n");
	printf("04 - Sair do sistema\n");
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
	n->altura = 0;
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
	printf("Digite o valor: \n");
	scanf("%d", &valor);
	if(raiz==NULL){
		raiz = create(valor);
		printf("Raiz criada com sucesso!\n");		
	}else{
		add(raiz, valor);
		printf("No adicionado com sucesso!\n");			
	}
	system("pause");
}

int altura(Nodo *n){
	if(n == NULL){
		return -1;
	}else{
		int alturaEsquerda = altura(n->esq);
		printf("Valor: %d", n->valor);		
		printf("\nvalor da esquerda: %d", alturaEsquerda);
		printf("\n");
		int alturaDireita  = altura(n->dir);
		printf("Valor: %d", n->valor);
		printf("\nvalor da direita: %d", alturaDireita);
		printf("\n");
		printf("\Rodou");
		printf("\n");
		printf("\n");
		if(alturaEsquerda > alturaDireita){
			return alturaEsquerda + 1;
		}else{
			return alturaDireita + 1;
		}
		
				
	}
}

short maiorAltura(short esq, short dir){
	return (esq>dir) ? esq : dir;
}

short alturaDoNo(Nodo *no){
	if(no == NULL){
		return -1;
	}else{
		return no->altura;
	}
}

short fatorDeBalancemento(Nodo *no){
	if(no){
		return (alturaDoNo(no->esq) - alturaDoNo(no->dir));
	}else{
		return 0;
	}
}

Nodo* rotacaoEsquerda(Nodo *raiz){
	//== ponteiro para a nova raiz depois de rotacionada
	//== ponteiro para guardar o filho do lado esquerdo   	
	Nodo *novaRaiz, *filhoBackup; 
	
	novaRaiz = raiz->dir; //== a nova raiz e o ponteiro direito da raiz atual
	filhoBackup = novaRaiz->esq;  //== faz o backup, uma copia do ponteiro do filho do lado esq	
	
	//== atualiza a nova raiz trazendo a raiz anterior para o lado esquerdo
	novaRaiz->esq = raiz; 
	
	//== pega o backup, a copia do filho do lado esquerdo da nova raiz
	//== e aloca do lado direito da raiz antiga
	raiz->dir = filhoBackup; 	
	
	//==atualiza a altura depois de rotacionar
	raiz->altura     = maiorAltura(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;
	novaRaiz->altura = maiorAltura(alturaDoNo(novaRaiz->esq), alturaDoNo(novaRaiz->dir)) + 1;
	
	return novaRaiz;
}

Nodo* rotacaoDireita(Nodo *raiz){
	Nodo *novaRaiz, *filhoBackup;	
	
	novaRaiz = raiz->esq;	
	filhoBackup = novaRaiz->dir;
		
	novaRaiz->dir = raiz;
	raiz->esq = filhoBackup;
		
	raiz->altura     = maiorAltura(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;
	novaRaiz->altura = maiorAltura(alturaDoNo(novaRaiz->esq), alturaDoNo(novaRaiz->dir)) + 1;
	
	return novaRaiz;
}

Nodo* rotacaoDireitaEsquerda(Nodo *raiz){
	raiz->dir = rotacaoDireita(raiz->dir);
	return rotacaoEsquerda(raiz);
}

Nodo* rotacaoEsquerdaDireita(Nodo *raiz){
	raiz->esq = rotacaoEsquerda(raiz->esq);
	return rotacaoDireita(raiz);
}




int main(){
	while(!sair){
		system("CLS");
		menu();
		scanf("%d", &op);
		switch(op){			
			case 1: insere(); break;
			case 2: printf("Altura: %d\n", altura(raiz)); system("pause");break;
			case 3: imprimir(raiz);	printf("\n"); system("pause"); break;
			case 4: sairDoSistema(); break;			
			default: printf("Opção inválida!\n"); system("pause");
		}
	}
	return 0;
}
