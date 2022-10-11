#ifndef LISTAENLAZADA_H_INCLUDED
#define LISTAENLAZADA_H_INCLUDED
#endif // LISTAENLAZADA_H_INCLUDED

#include <malloc.h>

typedef struct{
    datosVendedor vipd;
    struct nodo *next;
}nodo;

typedef struct{
    nodo *acceso; //cabecera de la lista
    nodo *cursor;
    nodo *cursoraux;
}lista;

void init(lista *p){
    (*p).acceso = NULL;
    (*p).cursor = NULL;
    (*p).cursoraux = NULL;
}

datosVendedor evocarLista(lista p){
    return p.cursor->vipd;
}

int localizarLista(lista *p, int dni){
    int numDni = dni;
    if(p->acceso == NULL) return 1; //Veo si hay elementos
    p->cursor = p->acceso;
    p->cursoraux = p->acceso;

    while(p->cursor != NULL && p->cursor->vipd.numDni != numDni){
        p->cursoraux = p->cursor;
        p->cursor = p->cursor->next;
    }

    if(p->cursor == NULL) return 0;
    if(p->cursor->vipd.numDni == numDni) return 2;
}


//Insertar un elemento a la lista
void altaLista(lista *p, datosVendedor varado){

    nodo *aux = (nodo*)malloc(sizeof(nodo));
    if(aux != NULL){
        if(((*p).cursor) == ((*p).acceso)){
            (*p).acceso=aux;
            aux->next = (*p).cursor;
            (*p).cursor = (*p).acceso;
            (*p).cursoraux = (*p).acceso;
        }
        else{
            (*p).cursoraux->next = aux;
            aux->next = (*p).cursor;
            (*p).cursor = aux;
        }
        (*p).cursor->vipd = varado;
    }
}

void bajaLista(lista *p, int dni){

    if(((*p).cursor) == ((*p).acceso)){
        (*p).acceso = (*p).cursor->next;
        free((*p).cursor);
        (*p).cursor = (*p).acceso;
        (*p).cursoraux = (*p).acceso;
    }
    else{
        (*p).cursoraux->next = (*p).cursor->next;
        free((*p).cursor);
        (*p).cursor = (*p).cursoraux->next;
    }
}

void mostrarLista(lista dat){
    dat.cursor = dat.acceso;
    dat.cursoraux = dat.acceso;
    while(dat.cursor != NULL){
        imprimirRS(evocarLista(dat));
        dat.cursoraux = dat.cursor;
        dat.cursor = dat.cursor->next;
    }
}



