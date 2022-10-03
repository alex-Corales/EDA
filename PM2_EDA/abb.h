#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#endif // ABB_H_INCLUDED
#include <malloc.h>

//Creacion de un Nodo
typedef struct{
    int dato;
    //struct nodo *padre;
    struct nodo *izquierda;
    struct nodo *derecha;
}arbol;

arbol raiz;

void arbolBinario(void){



}


void init(arbol *nodo){
    //nodo->padre = NULL;
    nodo->derecha = NULL;
    nodo->izquierda = NULL;
}

//Dar de alta un nuevo nodo
void alta(arbol *nodo, int dato){
    if(nodo == NULL){
        nodo = (arbol *)malloc(sizeof(arbol));
        nodo->dato = dato;
        nodo->izquierda = NULL;
        nodo->derecha = NULL;
        printf("%d", dato);
        printf("%d", nodo->dato);
    }else if(raiz == NULL) raiz = nodo;
    else if (dato > nodo->dato) alta(nodo->derecha, dato);
    else alta(nodo->izquierda, dato);
}

//Localizar un dato
int localizacion(arbol *nodo, int dato){
    if (nodo == NULL) return 0;

    if(dato > nodo->dato) localizacion(nodo->derecha, dato);
    else if (dato < nodo->dato) localizacion(nodo->izquierda, dato);
    else return nodo->dato;
}

void remplazar(arbol *nodo, arbol *aux){
    if(nodo->derecha == NULL){
        aux->dato = nodo->dato;
        aux = nodo;
        nodo = nodo->izquierda;
    }else remplazar(nodo->derecha, aux);
}

//Dar de baja un elemento
void baja(arbol *nodo, int dato){
    arbol *aux;

    if(nodo == NULL) return;

    if (nodo->dato < dato) baja(nodo->derecha, dato);
    else if (nodo->dato > dato) baja(nodo->izquierda, dato);
    else if (nodo->dato == dato){
        aux = nodo;
        if (nodo->izquierda == NULL) nodo = nodo->derecha;
        else if (nodo->derecha == NULL) nodo = nodo->izquierda;
        else remplazar(nodo->izquierda, dato);

        free(dato);
    }
}

void preOrden(arbol *nodo){
    if (nodo != NULL){
        printf("%d, ", nodo->dato);
        preOrden(nodo->izquierda);
        preOrden(nodo->derecha);
    }
}

void inOrden(arbol *nodo){
    if (nodo != NULL){
        inOrden(nodo->izquierda);
        printf("%d, ", nodo->dato);
        inOrden(nodo->derecha);
    }
}

void postOrden(arbol *nodo){
    if (nodo != NULL){
        postOrden(nodo->izquierda);
        postOrden(nodo->derecha);
        printf("%d, ", nodo->dato);
    }
}


void comparacionABB(arbol *nodo1, arbol *nodo2){
    int aux1 = 0, aux2 = 0;
    if(nodo != NULL){
        aux1 = aux1 + nodo1->dato;
        aux2 = aux2 + nodo2->dato;
        comparacionABB(nodo1->derecha, nodo2->derecha);
        comparacionABB(nodo1->izquierda, nodo2->izquierda);
    }
}

/*
int rangoABB(arbol *nodo){
    int menor = 0, mayor = 0;
    if(nodo != NULL){
        menor = nodo->dato;
        randoABB(nodo->izquierda);
        mayor = nodo->dato;
        rangoABB(nodo->derecha);
    }

    return mayor-menor;
}
*/

