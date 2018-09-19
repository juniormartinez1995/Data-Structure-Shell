#include <stdio.h>
#include "tabelaSequencialED.h"

void ed_ts_inicializa (TipoTabela *T)
{ 
  	T->n = 0; 
}

TipoIndice ed_ts_busca(TipoChave x , TipoTabela *t){ 
	int i ;
	t->item[0].chave = x ; 
	i = t->n + 1;
	do { i--;} 
	while (t->item[i].chave != x) ;
	return i ;
}

int ed_ts_insere(TipoRegistro reg, TipoTabela *t){ 
	if (t->n == MAXN) return 2; //  Erro de tabela cheia
	else {
		t->n++;
		t->item[t->n] = reg;
		return 1;
		}
}


