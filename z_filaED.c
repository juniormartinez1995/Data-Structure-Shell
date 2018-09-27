#include <stdio.h>
#include "z_filaED.h"

void ed_fila_inicializa (TipoFila *f)
{ 
  	f->inicio = NULL;
	f->fim = NULL;
}

int ed_fila_enfila(TipoRegistro registro, TipoFila *f){
    TipoNoFila *defn;
	defn = (TipoNoFila *) malloc(sizeof(TipoNoFila));
	if (defn == NULL) { // Erro de alocacao
		return 2;
	} 
	defn->reg = registro;
	defn->prox = NULL;
    if (f->inicio == NULL) { // primeiro elemento
    	f->inicio = defn;
	    f->fim = defn;
	} else {
		f->fim->prox = defn;
		f->fim = defn;
	}
	return 1;
}

int ed_fila_desenfila(TipoRegistro *registro, TipoFila *f){
	
	TipoNoFila *faux;
	
    if (f->inicio == NULL) { // fila vazia
    	return 2;
	} else { // remove elemento
		(*registro) = f->inicio->reg; // copia o conteudo pra registro
		faux = f->inicio; 
		f->inicio = f->inicio->prox; // ajusta o inicio para o proximo no'
		free(faux); // remove o nó
		if (f->inicio == NULL) f->fim = NULL;
	}
	return 1; // retorna sucesso
}
