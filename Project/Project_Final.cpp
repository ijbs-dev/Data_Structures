#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define max 100

//Variáveis
int opt=-1;
int total = 0;
char nome[max], cpf[max], sexo[max], idade[max];

//Prototipação
void cadastrar_paciente();
void questinario(void);
void mostrar_menu(void);

//void mostrar_lista(void);


int main(void){
	
	char nome[max], cpf[max], sexo[max], idade[max];
	int i, j;
	FILE *arq;

//char *arquivo = "texto.txt";
	arq = fopen ("Relatório_COVID.txt", "w");
	
	setlocale(LC_ALL, "");
	srand(time(NULL));
	
	do {
		system("cls");
		mostrar_menu();
		//mostrar_lista();		
		scanf("%d",&opt);
		
		switch (opt){
			
			case 1:
				cadastrar_paciente();
				break;
			
			case 2:
				questinario();
				break;
		
			default:
				if(opt != 0){
					printf("Opção inválida.\n");
					system("pause");
				}
				break;
		}
	}while(opt!=0);
	
		system("pause");
		return(0);
}

void mostrar_menu(void){
	
	printf("\n   ===> Pandemia do COVID-19 <===  \n\n");
	printf("\n        >>> MENU <<< \n\n");
	printf("1) Cadastrar paciente...\n");	
	printf("2) Responder questionário...\n");	
	printf("0) Sair...\n\n");
}

void cadastrar_paciente(){
	
	FILE *arq;
	
	

			printf("\n Digite seu nome: ");
			scanf("%s", &nome);
			fflush(stdin);
			fprintf(arq, "%s\n", nome);
			
			printf("\n Digite seu cpf: ");
			scanf("%s", &cpf);
			fflush(stdin);
			fprintf(arq, "%s\n", cpf);
			
			printf("\n Digite seu sexo: ");
			scanf("%s", &sexo);
			fflush(stdin);
			fprintf(arq, "%s\n", sexo);
		
			printf("\n Digite sua idade: ");
			scanf("%s", &idade);
			fflush(stdin);
			fprintf(arq, "%s\n", idade);
	

}

void questinario(void){
	FILE *arq;
	char febre[max],cabeca[max],aglomeracao[max],secrecao[max],garganta[max],tosse[max],respirar[max],dores[max],diarreia[max],contato[max],sair[max], s[max], n[max];
	int soma1, soma2, soma3, soma4 = 0;
	
	do{
		
	printf("\n\n Tem Febre? (s/n)");
	scanf("%s", &febre);
		
	
	printf("\n\n Tem dor de cabeça? (s/n)");
	scanf("%s", &cabeca);
	
	
	printf("\n\n Tem secreção nasal ou espirros? (s/n)");
	scanf("%s", &secrecao);
	
		
	printf("\n\n Tem dor/irritação na garganta? (s/n)");
	scanf("%s", garganta);
	
	printf("\n\n Tem tosse seca? (s/n)");
	scanf("%s", &tosse);

	
	printf("\n\n Tem dificuldade respiratória? (s/n)");
	scanf("%s", &respirar);
	
	
	printf("\n\n Tem dores no corpo? (s/n)");
	scanf("%s", &dores);
	
	
	printf("\n\n Tem diarréia? (s/n)");
	scanf("%s", &diarreia);
	
	
	printf("\n\n Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19? (s/n)");
	scanf("%s", &contato);
	
	
	printf("\n\n Esteve em locais com grande aglomeração? (s/n)");
	scanf("%s", &aglomeracao);
	
	
	} while(("%s" == "s" ) || ("%s" == "n") || ("%s" == "0"));
	
	
	if (cabeca == s || secrecao == s || garganta == s || dores == s || diarreia == s){
	
		int cab, sec, gar, dor, dia = 0;
	
		if (cabeca == s)
			cab = 1;
			if (secrecao == s)
				sec = 1;
				if (garganta == s)
					gar = 1;
					if (dores == s)
						dor = 1;
						if (diarreia == s)
							dia = 1;
							
		soma1 = cab + sec + gar + dor + dia;
	}
	
	if (tosse == s || aglomeracao){		
		int tos, agl = 0;
	
		if (tosse  == s)
			tos = 3;
			if (aglomeracao == s)
				agl = 3;
				
		soma2 = tos + agl;
	}
	
	if (febre == s){
		
		soma3 = 5;
		
	}
	
	if (respirar == s || contato == s){
		int res, con = 0;
	
		if (respirar  == s)
			res = 10;
			if (contato == s)
				con = 10;
				
		soma4 = res + con;
	
	}
	
	total = soma1 + soma2 + soma3 + soma4;
		
	printf("\n\n Dados : \n Nome = %s\n CPF = %s\n Sexo = %s\n Idade = %s",nome, cpf, sexo, idade);
	printf("\n Pontuação Total = %d\n\n",total);
	system("pause");
	
}


