#include <stdio.h>
#include <stdlib.h>
#include "tabelaSequencialED.h"


int ts_init (char **args)
{ 
  TipoTabela *defn;
  if (args[1] == NULL) {
    	fprintf(stderr, "ED: nome da estrutura esperado\n");
		return 2;
  } else {
	if (tabelaSequencial != NULL) {
    	fprintf(stderr, "ED: estrutura jah inicializada - delete-a antes de inicializar\n");
		return 3;
	} else {
		defn = (TipoTabela *) malloc(sizeof(TipoTabela));
	  	if (defn == NULL) {
			fprintf(stderr, "ED: Incapaz de alocar espaco para a estrutura\n");
			return 4;
		};
	   tabelaSequencial = defn;
	   ed_ts_inicializa(tabelaSequencial);
	   printf("Estrutura %s criada\n",args[1]);
	   return 1;
  	};
	};
}


int ts_print (char **args)
{ 
	if (tabelaSequencial == NULL) {
    	fprintf(stderr, "ED: tabela nao inicializada\n");
		return 1;
	} else {
		int size = tabelaSequencial->n;
		fflush(stdout);
		printf("Tabela =================================\n");
		int i = 1;
		while (i <= size) {
			printf("%5d ",tabelaSequencial->item[i].chave);
			if (i % 6 == 0) printf("\n");
			fflush(stdout);
			i++;
		}
		printf("\n");
		fflush(stdout);
		return 1;
	}
}


int ts_destroy (char **args)
{ 
	if (tabelaSequencial == NULL) {
    	fprintf(stderr, "ED: tabela nao inicializada\n");
		return 1;
	} else {
		free(tabelaSequencial);
		tabelaSequencial = NULL;
	    printf("Estrutura %s apagada\n");
		return 1;
	}
}


/* converte string to integer */
int toString(char a[]) {
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


int ts_insere (char **args)
{ 
    TipoRegistro *defn;
	if (tabelaSequencial == NULL) {
    	fprintf(stderr, "ED: tabela nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado um inteiro para insercao \n");
			return 1;
 		 } else {
			int n = toString(args[1]);
			defn = (TipoRegistro *) malloc(sizeof(TipoRegistro));
	  		if (defn == NULL) {
				fprintf(stderr, "ED: Incapaz de alocar espaco para a estrutura\n");
				return 2;
			} else {
				defn -> chave = n;
				int i = ed_ts_insere(*defn,tabelaSequencial);
				if (i==1) printf("Registro Inserido\n");
				else printf( "ED: tabela cheia\n" ) ;
			}
		return 1;
		}
	}
}

int ts_remove (char **args){
	if(tabelaSequencial == NULL){
		fprintf(stderr,"ED: Tabela nao inicializada\n ");
		return 1;
	}
	else{
		if(args[1] == NULL){
			fprintf(stderr, "ED: Esperado uma chave para remocao\n");
			return 1;
		}
		else{
			int n = toString(args[1]);
			int i = ed_ts_remove(n, tabelaSequencial);
			if(i) printf("Registro removido \n");
			else printf("Registo nao encontrado\n");
		}
		return 1;
	}
}


int ts_insere_varios (char **args)
{ 
	TipoRegistro *defn;
	if (tabelaSequencial == NULL) {
		fprintf(stderr, "ED: tabela nao inicializada\n");
		return 1;
	} 
	else{
		if (args[1] == NULL) {
			fprintf(stderr, "ED: esperado pelo menos um inteiro para insercao \n");
			return 1;
		}
		int j = 1;
		while(args[j] != NULL ) {
			int n = toString(args[j]);
			defn = (TipoRegistro *) malloc(sizeof(TipoRegistro));
			if (defn == NULL) {
				fprintf(stderr, "ED: Incapaz de alocar espaco para a estrutura\n");
				return 2;
			} 
			else{
				defn -> chave = n;
				int i = ed_ts_insere(*defn,tabelaSequencial);
				if (i==1) printf("Registro Inserido\n");
				else {
					printf("ED: tabela encheu, %do param em diante nao foi inserido\n",j);
					break;
					}
			}
			j++;
		}
		return 1;
	}
}


int ts_busca (char **args)
{ 
	if (tabelaSequencial == NULL) {
    	fprintf(stderr, "ED: tabela nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado uma chave para busca \n");
			return 1;
 		 } else {
			int n = toString(args[1]);
			int i = ed_ts_busca(n,tabelaSequencial);
			if (i) printf("Registro encontrado em na %da posicao\n",i);
			else printf("Registro n�o encontrado\n");
			}
		return 1;
		}
}


