/**
 * Árboles binarios en C
 * Operaciones de:
 * Inserción
 * Recorrido inorden, postorden y preorden
 * Uso de malloc
 *
 * @author parzibyte
 * @see https://parzibyte.me/blog
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
}Nodo;


Nodo *nuevoNodo(int dato){
    // Solicitar memoria
    size_t tamanioNodo = sizeof(Nodo);
    Nodo *nodo = (Nodo *) malloc(tamanioNodo);
    // Asignar el dato e iniciar hojas
    nodo->dato = dato;
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    return nodo;
}

void insertar(Nodo *nodo, int dato) {
    // ¿Izquierda o derecha?
    // Si es mayor va a la derecha
    if (dato > nodo->dato) {
        // Tienes espacio a la derecha?
        if (nodo->derecha == NULL) {
            nodo->derecha = nuevoNodo(dato);
        } else {
            // Si la derecha ya está ocupada, recursividad ;)
            insertar(nodo->derecha, dato);
        }
    } else {
        // Si no, a la izquierda
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo(dato);
        } else {
            // Si la izquierda ya está ocupada, recursividad ;)
            insertar(nodo->izquierda, dato);
        }
    }
}


void preorden(Nodo *nodo) {
    if (nodo != NULL) {
        printf("%d,", nodo->dato);
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }
}

void inorden(Nodo *nodo) {
    if (nodo != NULL) {
        inorden(nodo->izquierda);
        printf("%d,", nodo->dato);
        inorden(nodo->derecha);
    }
}

void postorden(Nodo *nodo) {
    if (nodo != NULL) {
        postorden(nodo->izquierda);
        postorden(nodo->derecha);
        printf("%d,", nodo->dato);
    }
}

int evocarMenor(Nodo *nodo){
    while(nodo != NULL){
        if(nodo->izquierda == NULL) return nodo->dato;
        else nodo = nodo->izquierda;
    }
    return nodo->dato;
}

int evocarMayor(Nodo *nodo){
    while(nodo != NULL){
        if(nodo->derecha == NULL) return nodo->dato;
        else nodo = nodo->derecha;
    }
    return nodo->dato;
}

int rango(Nodo *nodo){
    int menor = evocarMenor(nodo);
    int mayor = evocarMayor(nodo);

    return mayor - menor;
}

int main(void) {
    Nodo *raiz = nuevoNodo(28);
    insertar(raiz, 11);
    insertar(raiz, 96);
    insertar(raiz, 21);
    insertar(raiz, 6);
    insertar(raiz, 97);
    insertar(raiz, 1);
    insertar(raiz, 30);
    insertar(raiz, 10);
    insertar(raiz, 2);
    printf("\nImprimiendo preorden\n");
    preorden(raiz);
    printf("\nImprimiendo inorden\n");
    inorden(raiz);
    printf("\nImprimiendo postorden\n");
    postorden(raiz);


    printf("\nRango: %d\n", rango(raiz));
}
