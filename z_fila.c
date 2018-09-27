#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "z_filaED.h"

int fi_init (char **args)
{
    TipoFila *defn;
  	printf("Processando %s ...\n",args[0]);
	if (fila != NULL) {
    	fprintf(stderr, "ED: estrutura jah inicializada - delete-a antes de inicializar\n");
		return 3;
	} else {
		defn = (TipoFila *) malloc(sizeof(TipoFila));
	  	if (defn == NULL) {
			fprintf(stderr, "ED: Incapaz de alocar espaco para a estrutura\n");
			return 4;
		}
	   fila = defn;
	   ed_fila_inicializa(fila);
	   printf("Estrutura criada\n");
	   return 1;
  	}
}



int fi_enfile (char **args)
{ 
    TipoRegistro *defn;
	printf("Processando %s ...\n",args[0]);	
	if (fila == NULL) {
    	fprintf(stderr, "ED: fila nao inicializada\n");
		return 1;
	} else {
  		if (args[1] == NULL) {
    		fprintf(stderr, "ED: esperado um inteiro para enfileirar \n");
			return 1;
 		 } else {
			int n = toString(args[1]);
			defn = (TipoRegistro *) malloc(sizeof(TipoRegistro));
	  		if (defn == NULL) {
				fprintf(stderr, "ED: Incapaz de alocar espaco para registro\n");
				return 2;
			} else {
				defn -> chave = n;
				int i = ed_fila_enfila(*defn,fila);
				if (i==1) printf("Registro Enfileirado\n");
				else printf( "ED: Erro na alocacao do no' na fila\n" ) ;
			}
		return 1;
		}
	}
}


int fi_desenfile (char **args)
{ 
	printf("Processando %s ...\n",args[0]);
	if (fila == NULL) {
    	fprintf(stderr, "ED: fila nao inicializada\n");
		return 1;
	} else {
		TipoRegistro reg;
  		int i = ed_fila_desenfila(&reg,fila);
		if (i==1) printf("Registro %d retirado\n",reg.chave);
		else printf("Fila vazia\n");
		}
	return 1;
}


int fi_print (char **args)
{ 
  	printf("Processando %s ...\n",args[0]);
	if (fila == NULL) {
    	fprintf(stderr, "ED: tabela nao inicializada\n");
		return 1;
	} else {
		TipoNoFila *apontador;
		apontador = fila->inicio;
		printf("Fila =================================\n");
		int i = 1;
		while (apontador != NULL) {
			printf("%5d ",apontador->reg.chave);
			if (i % 6 == 0) printf("\n");
			i++;
			apontador = apontador->prox;
		}
		printf("\n");
		fflush(stdout);
		return 1;
	}
}

