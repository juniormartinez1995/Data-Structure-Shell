#include <stdlib.h>
#define MAXN 10

typedef long TipoChave;

typedef struct TipoRegistro {
	TipoChave chave;
	// int conteudo;
	// outros componentes //
} TipoRegistro;

typedef int TipoIndice;

typedef struct TipoTabela {
	TipoRegistro item[MAXN + 1] ;
	TipoIndice n;
} TipoTabela;


/*
   ============== Commands ===========
*/
void ed_ts_inicializa (TipoTabela *);
int ed_ts_insere(TipoRegistro reg, TipoTabela *t);
TipoIndice ed_ts_busca(TipoChave x , TipoTabela *t);

/*
  a tabela propriamente dita
  */
static struct TipoTabela *tabelaSequencial = NULL;
