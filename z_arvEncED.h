#include <stdlib.h>
#include "z_a_registro.h"

typedef struct TipoNoArvEnc {
	TipoRegistro reg;
	int enc;
	struct TipoNoArvEnc *esq;
	struct TipoNoArvEnc *dir;
} TipoNoArvEnc;

typedef struct TipoArvEnc {
	TipoNoArvEnc *raiz ;
} TipoArvEnc;


/*
  a arvore propriamente dita
  */
static struct TipoArvEnc *arvEnc = NULL;
