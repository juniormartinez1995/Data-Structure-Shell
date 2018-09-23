#include <stdio.h>
#include <stdlib.h>
#include "tabelaFilaED.h"
	
int fl_init (char **args){ 
  TipoFila *defn;

	if (args[1] == NULL) {
    	fprintf(stderr, "ED: nome da estrutura esperado\n");
		return 2;
	} 
	else {
		if (Fila != NULL) {
	    	fprintf(stderr, "ED: estrutura jah inicializada - delete-a antes de inicializar\n");
			return 3;
		} else {
			defn = (TipoFila *) malloc(sizeof(TipoFila));
			if (defn == NULL) {
				fprintf(stderr, "ED: Incapaz de alocar espaco para a estrutura\n");
				return 4;
			}
			Fila = defn;
			ed_fl_inicializa(Fila);
			printf("Estrutura %s criada\n",args[1]);
			return 1;
		}
	}
}

int ConvertToInt(char a[]) {
	int c, sign, offset, n;
	
	if (a[0] == '-') {  // Handle negative integers
    	sign = -1;
  	}
 
  	if (sign == -1) {  // Set starting position to convert
    	offset = 1;
  	}
  	else {
    	offset = 0;
  	}
 
  	n = 0;
 
 	 for (c = offset; a[c] != '\0'; c++) {
    	n = n * 10 + a[c] - '0';
  	}
 
	if (sign == -1) {
    	n = -n;
 	}
 
  return n;
}

int fl_insere (char **args)
{ 
    TipoItem *defn;
	if (Fila == NULL) {
    	fprintf(stderr, "ED: tabela nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado um inteiro para insercao \n");
			return 1;
 		 } else {
			int n = ConvertToInt(args[1]);
			defn = (TipoItem *) malloc(sizeof(TipoItem));
	  		if (defn == NULL) {
				fprintf(stderr, "ED: Incapaz de alocar espaco para a estrutura\n");
				return 2;
			} else {
				*defn = n;
				int i = ed_fl_insere(Fila, *defn);
				if (i==1) printf("Registro Inserido\n");
				else printf( "ED: tabela cheia\n" );
			}
		return 1;
		}
	}
}

int fl_remove (char **args){
	if(Fila == NULL){
		fprintf(stderr,"ED: Tabela nao inicializada\n ");
		return 1;
	}
	else{
		int n;
		int i = ed_fl_remove(Fila, &n);
		if(i) printf("O registro %d foi removido \n", n);
		else printf("Registo nao encontrado\n");

		return 1;
	}
}

int fl_print (char **args)
{ 
	if (Fila == NULL) {
    	fprintf(stderr, "ED: tabela nao inicializada\n");
		return 1;
	} else {

		fflush(stdout);
		printf("Tabela =================================\n");
	
		TipoFila *Aux, *FAux;
		TipoItem e;
		
		FAux = (TipoFila *) malloc(sizeof(TipoFila));
		Aux = (TipoFila *) malloc(sizeof(TipoFila));
		ed_fl_inicializa(Aux);
		ed_fl_inicializa(FAux);
		
		FAux = Fila;
		
		
		while(FAux->inicio != NULL){
			
			ed_fl_remove(Fila, &e);
				
			printf("%d ", e);
			
			ed_fl_insere(Aux, e);
				
		}
		
		while(Aux->inicio != NULL){
			
			ed_fl_remove(Aux, &e);
			ed_fl_insere(Fila, e);
			
		}
		printf("\n");
		fflush(stdout);
		return 1;
	}
}



