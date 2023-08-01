#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
	int dado;
	NO* prox;
}NO;

typedef struct PILHA{
	NO* topo;
} PILHA;

typedef struct FILA{
	NO* inicio;
	NO* fim;
} FILA;

FILA *f;
PILHA *p;

void imprimir(NO* ptr){
	system("cls");
	while(ptr != NULL){
		printf("%d ", ptr->dado);
		ptr = ptr->prox;
	}
}

void empilha(){
	NO* ptr = (NO *) malloc(sizeof(NO));
	ptr->dado = rand()%100;
	ptr->prox = p->topo;
	p->topo = ptr;
}

int desempilha(){
	NO* ptr = p->topo;
	int dado;
	if(ptr != NULL){
		p->topo = ptr->prox;
		ptr->prox = NULL;
		dado = ptr->dado;
		free(ptr);
		return dado;
	}
}

void enfileira(){
	NO* ptr = (NO *) malloc(sizeof(NO));
	ptr->dado = rand()%100;
	ptr->prox = NULL;
	if(f->inicio == NULL)
		f->inicio = ptr;
	else
		f->fim->prox = ptr;
	f->fim = ptr;
}

int desenfileira(){
	NO* ptr = f->inicio;
	int dado;
	if(ptr != NULL){
		f->inicio = ptr->prox;
		ptr->prox = NULL;
		dado = ptr->dado;
		free(ptr);
		return dado;
	}
}

int main(){
	
	f = (FILA *) malloc(sizeof(FILA));
	p = (PILHA *) malloc(sizeof(PILHA));
	
	p->topo = NULL;
	f->inicio = NULL;
	f->fim = NULL;
	
	empilha();
	empilha();
	empilha();
	
	NO *it = p->topo;
	imprimir(it);
	system("pause");
	
	desempilha();
		
	it = p->topo;
	imprimir(it);
	system("pause");
	
	desempilha();
	
	it = p->topo;
	imprimir(it);
	system("pause");
	
	desempilha();
	
	it = p->topo;
	imprimir(it);
	system("pause");
	
	desempilha();
	
	it = p->topo;
	imprimir(it);
}

