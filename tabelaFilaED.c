#include <stdio.h>
#include "tabelaFilaED.h"

void ed_fl_inicializa(TipoFila *f){
	f = (TipoFila *) malloc(sizeof(TipoFila));
	f->inicio = NULL;
	f->fim = NULL;

}
