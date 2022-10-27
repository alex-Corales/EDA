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

void mostrarLista(lista dat){
    dat.cursor = dat.acceso;
    //dat.cursoraux = dat.acceso;
    while(dat.cursor != NULL){
        imprimirRS(dat.cursor->vipd);
        //dat.cursoraux = dat.cursor;
        dat.cursor = dat.cursor->next;
    }
}
