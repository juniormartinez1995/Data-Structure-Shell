#include <stdio.h>
#include "z_arvEncED.h"

// Árvores Binárias Encadeadas / Costuradas

void ed_arvEnc_init(TipoArvEnc *a)
{ 
	a->raiz = NULL;
}

/*
	Atravessamento em Ordem da Árvore Costurada
*/
void ed_arvEnc_emOrd(TipoNoArvEnc *raiz){
	TipoNoArvEnc *anterior,*atual;
	
	atual = raiz;
	do{
		anterior = NULL;
		while(atual != NULL) {
			anterior = atual;
			atual = atual->esq;
		} // vai para ponta esquerda da sub-arvore
		if (anterior != NULL) { // se não é raiz
			printf("%d ", anterior->reg.chave); // visita no'
			atual = anterior->dir;   // vai para direita
			while (anterior->enc && atual != NULL) { // enquanto for costura
				printf("%d ", atual->reg.chave); // visita no'
				anterior = atual;
				atual = atual->dir; // continua indo para direita
			}
		}
	} while (anterior != NULL);
}


/*
int ed_arvEnc_busca(int chave, TipoNoArvEnc* atual){

	while(atual != NULL){ // começa na raiz
      if(atual->reg.chave == chave){
	   return 1;
      } else {
         if(atual->reg.chave > chave) atual = atual->esq;
         else  atual = atual->dir;			
      }
   }
   return 0; // não encontrado
}
*/
