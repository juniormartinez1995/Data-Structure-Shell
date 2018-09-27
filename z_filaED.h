#include <stdlib.h>
#include "z_a_registro.h"

typedef struct TipoNoFila {
	TipoRegistro reg;
	struct TipoNoFila *prox;
} TipoNoFila;

typedef struct TipoFila {
	TipoNoFila *inicio ;
	TipoNoFila *fim ;
} TipoFila;


/*
  a fila propriamente dita
  */
static  TipoFila *fila = NULL;
