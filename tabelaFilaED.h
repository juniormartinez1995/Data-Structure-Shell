#include <stdlib.h>
#include <stdio.h>

typedef int	TipoItem;

typedef struct Node{
	
	TipoItem info;
	
	struct Node *prox;
	
}Node;

typedef struct{
	
	Node *inicio;
	Node *fim;

}TipoFila;


static struct TipoFila *Fila = NULL;
