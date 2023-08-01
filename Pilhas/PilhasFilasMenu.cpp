#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
	int dado;
	NO* prox;
}NO;

typedef struct PILHA{
	NO* topo;
}PILHA;

typedef struct FILA{
	NO* inicio;
	NO* fim;
}FILA;

FILA *f;
PILHA *p;


void empilha(int dado){
	NO* ptr = (NO *) malloc(sizeof(NO));
	ptr->dado = dado;
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
	else{
		printf("Erro!\n");
		system("pause");
		return -1;
	}
}

void imprimePilha(){
	NO *ptr = p->topo;
	if(ptr == NULL){
		printf("PILHA VAZIA.\n");
		return;
	} else {	
		printf("=== Conteúdo da Pilha ===\n\n");
		printf(" TOPO-> ");
		while(ptr != NULL){
			printf("%d ", ptr->dado);
			
			ptr = ptr->prox;
		}
		printf("\n");
	}
}

void enfileira(int dado){
	NO* ptr = (NO *) malloc(sizeof(NO));
	ptr->dado = dado;
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
	}else{
		printf("Erro!\n");
		system("pause");
		return -1;
	}
}

void imprimeFila(){
	NO *ptr = f->inicio;
	if(ptr == NULL){
		printf("FILA VAZIA.\n");
		return;
	} else {
		printf("=== Conteúdo da Fila ===\n\n");
		printf(" INÍCIO-> ");
		while(ptr != NULL){
			printf("%d ", ptr->dado);
			ptr = ptr->prox;
		}
		printf("<-FIM\n ");
	}
}

void menu(){
	printf("1 - Para empilhar;\n");
	printf("2 - Para desempilhar;\n");
	printf("3 - Para mostrar a pilha;\n");	
	printf("4 - Para enfileirar;\n");
	printf("5 - Para desenfileirar;\n");
	printf("6 - Para mostrar a fila;\n");
	printf("0 - Para encerrar;\n");
}

void dispose(){
	NO *ptr;
	NO *del;
	
	printf("Liberando o espaço da pilha;\n");
	ptr = p->topo;
	while(ptr != NULL){
		del = ptr;
		ptr = ptr->prox;
		free(del);
	}
	p->topo = NULL;
	imprimePilha();
	
	printf("Liberando o espaço da fila;\n");
	ptr = f->inicio;
	while(ptr != NULL){
		del = ptr;
		ptr = ptr->prox;
		free(del);
	}
	f->inicio = NULL;
	imprimeFila();
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int op, dado;
	
	f = (FILA *) malloc(sizeof(FILA));
	p = (PILHA *) malloc(sizeof(PILHA));
	
	p->topo = NULL;
	f->inicio = NULL;
	f->fim = NULL;
	
	do{
		system("cls");
		menu();
		scanf("%d", &op);
		fflush(stdin);
		system("cls");
		switch(op){
			case 0:
				dispose();
				break;
			case 1:
				printf("Informe o dado:\n");;
				scanf("%d", &dado);
				fflush(stdin);
				empilha(dado);
				system("pause");
				break;
			case 2:
				dado = desempilha(); 
				if(dado != -1){
					printf("Desempilhando: %d\n", dado);
					system("pause");
				}
				break;
			case 3:
				imprimePilha();
				system("pause");
				break;
			case 4:
				printf("Informe o dado:\n");;
				scanf("%d", &dado);
				fflush(stdin);
				enfileira(dado);
				system("pause");
				break;
			case 5:
				dado = desenfileira(); 
				if(dado != -1){ 
					printf("Desenfileirando: %d\n", dado);
					system("pause");
				}
				break;
			case 6:
				imprimeFila();
				system("pause");
				break;
			default:
				printf("Opção inválida.\n");
				break;
		}
	}while(op != 0);
	
}

