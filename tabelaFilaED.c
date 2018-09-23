#include <stdio.h>
#include "tabelaFilaED.h"

void ed_fl_inicializa(TipoFila *f){
	f->inicio = NULL;
	f->fim = NULL;
}

int ed_fl_insere(TipoFila *queue, TipoItem e){
	
	Node *NewNode;
	NewNode = (Node *) malloc(sizeof(Node));
	
	if(!NewNode) return 0;
	
	NewNode->info = e;
	NewNode->prox = NULL;
	
	if(queue->inicio == NULL) queue->inicio = NewNode;
	
	else queue->fim->prox = NewNode;
	
	queue->fim = NewNode;
	
	return 1;
}



int ed_fl_remove(TipoFila *queue, TipoItem *e){
	
	Node *aux;
	
	if(queue->inicio == NULL) return 0;
	
	*e = queue->inicio->info;
	aux = queue->inicio;
	
	if(queue->inicio == queue->fim) queue->inicio = queue->fim = NULL;
	else queue->inicio = queue->inicio->prox;
	
	free(aux);
	
	return 1;
	
}
