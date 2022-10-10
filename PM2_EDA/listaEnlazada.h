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

//Lista llena
int isFull(lista p){
    nodo *n;
    n = (nodo*)malloc(sizeof(nodo));

    if(n == NULL){
        free(n);
        return 1;
    }else{
        free(n);
        return 0;
    }
}

//Lista vacia
int isEmpty(lista p){
    if(p.acceso == NULL)
        return 1;
    else
        return 0;

}

//Fuera de estructura
int isOos(lista p){
    if(p.cursor == NULL)
        return 1;
    else
        return 0;
}

//colocar el cursor al principio
void reset(lista *p){
    (*p).cursor=(*p).acceso;
    (*p).cursoraux=(*p).acceso;
}

//Apuntar al nodo siguiente
void forwardlist(lista *p){
     (*p).cursoraux=(*p).cursor;
     (*p).cursor=(*p).cursor->next;
}

datosVendedor evocarLista(lista p){
    return p.cursor->vipd;
}

int localizarLista(lista *p, int dni){
    int numDni = dni;
    if(isEmpty(*p) == 1) return 1; //Veo si hay elementos
    reset(&p); //Si hay coloco el cursor en la primer posicion

    while(isOos(*p) != 1){
        if(p->cursor->vipd.numDni != numDni) forwardlist(p);
        else return 2;
    }

    if(isOos(*p) == 1) return 0;
}


//Insertar un elemento a la lista
void altaLista(lista *p, datosVendedor varado){

    if(isEmpty(*p)==0) reset(p);
    while(isOos(*p) != 1){
        forwardlist(p);
    }

    nodo *aux=(nodo*)malloc(sizeof(nodo));
    if(aux!=NULL){
        if(((*p).cursor)==((*p).acceso)){
            (*p).acceso=aux;
            aux->next=(*p).cursor;
            (*p).cursor=(*p).acceso;
            (*p).cursoraux=(*p).acceso;
        }
        else{
            (*p).cursoraux->next=aux;
            aux->next=(*p).cursor;
            (*p).cursor=aux;
        }
        (*p).cursor->vipd=varado;
    }
}

void bajaLista(lista *p, int dni){

    if(isEmpty(*p)==0) reset(p);
    while(isOos(*p) != 1 && p->cursor->vipd.numDni != dni){
        forwardlist(p);
    }

    if(((*p).cursor)==((*p).acceso)){
        (*p).acceso=(*p).cursor->next;
        free((*p).cursor);
        (*p).cursor=(*p).acceso;
        (*p).cursoraux=(*p).acceso;
    }
    else{
        (*p).cursoraux->next=(*p).cursor->next;
        free((*p).cursor);
        (*p).cursor=(*p).cursoraux->next;
    }
}

void mostrarLista(lista dat){
    isEmpty(dat);
    reset(&dat);
    while(isOos(dat) != 1){
        imprimir(evocarLista(dat));
        forwardlist(&dat);
    }
}



