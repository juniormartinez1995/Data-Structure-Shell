#include <stdio.h>
#include "z_arvED.h"


void ed_arv_init(TipoArv *a)
{ 
	a->raiz = NULL;
}


int ed_arv_insere(TipoRegistro registro, TipoArv *a){
    TipoNoArv *defn;
	defn = (TipoNoArv *) malloc(sizeof(TipoNoArv));
	if (defn == NULL) { // Erro de alocacao
		return 2;
	} 
	defn->reg = registro;
	defn->esq = NULL;
	defn->dir = NULL;
	
    if (a->raiz == NULL) { // primeiro elemento
    	a->raiz = defn;    // insere na raiz
	} else { // insere na árvore indo para esquerda e direita
		TipoNoArv *atual = a->raiz;
		TipoNoArv *ant = NULL;
		while(atual != NULL){
			ant=atual;
			if(registro.chave == atual->reg.chave){ // elemento já existe
		 	 free(defn);
			 return 4;
			}
		if(registro.chave > atual->reg.chave)
            atual = atual->dir;
         else
            atual = atual->esq;
		}
    if(registro.chave > ant->reg.chave) ant->dir = defn;
    else ant->esq = defn;
   } 
   return 1;
}





TipoNoArv* no_remove(TipoNoArv *a){
	TipoNoArv *atual, *ant;
	
	if(a->esq == NULL){ // tem zero ou um filho
		atual = a->dir;
		free(a);
		return atual;
	} else { // tem dois filhos
	    ant = a;
		atual = a->esq;
		while(atual->dir != NULL){ // acha maior da subarv da esquerda
			ant = atual;
			atual = atual->dir;
		}
		if (ant != a) { // se o maior NAO for o filho imediato
			ant->dir = atual->esq;
			atual->esq = a->esq;
		}
		atual->dir = a->dir;
		free(a);
		return atual;
	}
}

int ed_arv_remove(int chave, TipoArv *a){
    TipoNoArv *atual, *ant;

    ant = NULL;
    atual = a->raiz;
    while(atual != NULL){ // começa na raiz
      if(atual->reg.chave == chave){
	   break;
      } else {
      	ant = atual;
        if(chave < atual->reg.chave) atual = atual->esq;
        else  atual = atual->dir;			
      }
    }
    if (atual == NULL) return 4; // reg não achado
    if (ant == NULL) {
    	a->raiz = no_remove(atual);
	} else {
		if(chave > ant->reg.chave) {
			ant->dir = no_remove(atual);
		} else {
			ant->esq = no_remove(atual);
		}
		
	}
	return 1;
}





/*
   Percurso em ordem que imprime chave do no´´ 
*/
void ed_arv_emOrd(TipoNoArv* raiz){
    if(raiz != NULL){
      ed_arv_emOrd(raiz->esq);
      printf("%d ", raiz->reg.chave);
      ed_arv_emOrd(raiz->dir);
   }
}

/*
   Versão genérica do percurso em ordem
   Faz o Call Back  
*/


/*
   Percurso em pre ordem que imprime chave do no´
*/
void ed_arv_preOrd(TipoNoArv* raiz){
    if(raiz != NULL){
      printf("%d ", raiz->reg.chave);
      ed_arv_preOrd(raiz->esq);
      ed_arv_preOrd(raiz->dir);
   }
}


/*
   Percurso em pos ordem que imprime chave do no´ 
*/
void ed_arv_posOrd(TipoNoArv* raiz){
    if(raiz != NULL){
      ed_arv_posOrd(raiz->esq);
      ed_arv_posOrd(raiz->dir);
      printf("%d ", raiz->reg.chave);
   }
}

int ed_arv_altura(TipoNoArv* raiz){
	int altEsq, altDir;
	if(raiz == NULL){
		return 0;
		}
	else {
		altEsq = ed_arv_altura(raiz->esq);
		altDir = ed_arv_altura(raiz->dir);
		if (altEsq > altDir) return altEsq+1;
		else return altDir+1;
	}
}


int ed_arv_nNos(TipoNoArv* raiz){
	int nosEsq, nosDir;
	if(raiz == NULL){
		return 0;
		}
	else {
		nosEsq = ed_arv_nNos(raiz->esq);
		nosDir = ed_arv_nNos(raiz->dir);
		return nosEsq+nosDir+1;
	}
}


int ed_arv_busca(int chave, TipoNoArv* atual){

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


