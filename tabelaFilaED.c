#include <stdio.h>
#include "tabelaFilaED.h"

void ed_fl_inicializa(TipoFila *f){
	f->inicio = NULL;
	f->fim = NULL;
}

int ed_fl_insere(TipoFila *f, TipoItem e){
	
	Node *NewNode;
	NewNode = (Node *) malloc(sizeof(Node));
	
	if(!NewNode) return 0;
	
	NewNode->info = e;
	NewNode->prox = NULL;
	
	if(f->inicio == NULL) f->inicio = NewNode;
	
	else f->fim->prox = NewNode;
	
	f->fim = NewNode;
	
	return 1;
}



int ed_fl_remove(TipoFila *f, TipoItem *e){
	
	Node *aux;
	
	if(f->inicio == NULL) return 0;
	
	*e = f->inicio->info;
	aux = f->inicio;
	
	if(f->inicio == f->fim) f->inicio = f->fim = NULL;
	else f->inicio = f->inicio->prox;
	
	free(aux);
	
	return 1;
	
}
