/*
    Grupo 30
    Corales Alex Nahuel
    alexcorales21@gmail.com
*/

#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED
#endif // LISTAENLAZADA_H_INCLUDED
#include <malloc.h>

typedef struct{
    datosVendedor vipd;
    struct nodo *next;
}nodo;

typedef struct{
    nodo *acceso;
    nodo *cursor;
    nodo *cursoraux;
}lista;

void init(lista *p){
    (*p).acceso = NULL;
    (*p).cursor = NULL;
    (*p).cursoraux = NULL;
}

int altaLista(lista *p, datosVendedor varado){

    nodo *aux = (nodo*)malloc(sizeof(nodo));
    if(aux == NULL) return 1;

    p->cursor = p->acceso;

    if(((*p).cursor) == ((*p).acceso)){
        (*p).acceso=aux;
        aux->next = (*p).cursor;
        (*p).cursor = (*p).acceso;
    }else{
        aux->next = p->acceso;
        p->acceso = aux;
    }
    (*p).cursor->vipd = varado;
}

void bajaLista(lista *p, int dni){

    if(p->cursor == p->acceso){
        p->acceso = p->cursor->next;
        free(p->cursor);
        p->cursor = p->acceso;
        p->cursoraux = p->acceso;
    }else{
        p->cursoraux->next = p->cursor->next;
        free(p->cursor);
        p->cursor = p->cursoraux->next;
    }
}

void mostrarLista(lista dat){
    dat.cursor = dat.acceso;
    while(dat.cursor != NULL){
        imprimirRS(dat.cursor->vipd);
        dat.cursor = dat.cursor->next;
    }
}



