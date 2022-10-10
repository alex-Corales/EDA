#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#endif // ABB_H_INCLUDED
# define MAXTAMCAD 100


typedef struct{
    datosVendedor vipdABB;
    struct nodoABB *nodoPadre;
    struct nodoABB *nodoDerecho;
    struct nodoABB *nodoIzquierdo;
}nodoABB;

typedef struct{
    nodoABB *acceso;
    nodoABB *cursor;
    nodoABB *cursorAux;
}arbol;

void menuABB(){

    int aux;
    datosVendedor vendedorABB;
    arbol arbol;
    initABB(&arbol);
    do{
        printf("<1> Dar de alta\n");
        printf("<2> Dar de baja\n");
        printf("<3> Consultar vendedor\n");
        printf("<4> Mostrar estructura\n");
        printf("<5> Memorizacion previa\n");
        printf("<6> Salir\n");
        printf("- ");
        do{
            scanf("%s", opc1);
            auxopc = controlIngresoNum(opc1);
        }while(auxopc==0);
        opc = atoi(opc1);

        system("cls");
        switch(opc){
        case 1:

            vendedorABB.numDni = 28;
            aux = altaABB(&arbol, vendedorABB);
            vendedorABB.numDni = 11;
            aux = altaABB(&arbol, vendedorABB);
            vendedorABB.numDni = 96;
            aux = altaABB(&arbol, vendedorABB);
            vendedorABB.numDni = 21;
            aux = altaABB(&arbol, vendedorABB);
            vendedorABB.numDni = 6;
            aux = altaABB(&arbol, vendedorABB);
            vendedorABB.numDni = 1;
            aux = altaABB(&arbol, vendedorABB);
            vendedorABB.numDni = 30;
            aux = altaABB(&arbol, vendedorABB);
            vendedorABB.numDni = 10;
            aux = altaABB(&arbol, vendedorABB);
            vendedorABB.numDni = 2;
            aux = altaABB(&arbol, vendedorABB);


            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            //resetABB(&arbol);
            mostrarArbolBin(arbol);
            break;
        case 5:
            break;
        }

    }while(opc != 6);

}

void initABB(arbol *p){
    p->acceso = NULL;
    p->cursor = NULL;
    p->cursorAux = NULL;
}

int isFullABB(arbol p){
    nodoABB *n;
    n = (nodoABB*)malloc(sizeof(nodoABB));

    if(n == NULL){
        free(n);
        return 1;
    }else{
        free(n);
        return 0;
    }
}

int isEmptyABB(arbol p){
    if(p.acceso == NULL) return 1;
    else return 0;
}


int isOosABB(arbol p){
    if(p.cursor == NULL) return 1;
    else return 0;
}

void resetABB(arbol *p){
    p->cursor = p->acceso;
    p->cursorAux = p->acceso;
}

int localizarABB(arbol *p, int dni){
    int numDni = dni;
    if(isEmptyABB(*p) == 1) return 1; //No hay elementos en el arbol
    resetABB(&p);

    while(isOosABB(*p) != NULL){
        if(p->cursor->vipdABB.numDni != numDni){
            p->cursorAux = p->cursor;
            if(p->cursor->vipdABB.numDni < numDni){
                p->cursor = p->cursor->nodoDerecho;
            }else{
                p->cursor = p->cursor->nodoIzquierdo;
            }
        }else return 2;
    }

        if(isOosABB(*p) == 1) return 1;
}

int altaABB(arbol *p, datosVendedor dat){

    int auxExito = localizarABB(&p, dat.numDni);
    if(auxExito == 2) return 0;

    nodoABB *aux = (nodoABB*)malloc(sizeof(nodoABB));
    if(aux == NULL) return 1;
    if(p->cursor == NULL){
        printf("\nCabeza\n");
        p->acceso = aux;
        aux->nodoDerecho = NULL;
        aux->nodoIzquierdo = NULL;
        p->cursor = p->acceso;
        p->cursorAux = p->acceso;
    }else if(p->cursor->vipdABB.numDni > dat.numDni){
        printf("\nIzquierda\n");
        p->cursorAux = p->cursor;
        p->cursor = p->cursor->nodoIzquierdo;
        p->cursorAux->nodoIzquierdo = aux;
        aux->nodoIzquierdo = NULL;
        aux->nodoDerecho = NULL;
        p->cursor = aux;
    }else{
        printf("\nDerecha\n");
        p->cursorAux = p->cursor;
        p->cursor = p->cursor->nodoDerecho;
        p->cursorAux->nodoDerecho = aux;
        aux->nodoDerecho = NULL;
        aux->nodoIzquierdo = NULL;
        p->cursor = aux;
    }
    p->cursor->vipdABB = dat;

    printf("\nAcceso: %d", p->acceso->vipdABB.numDni);
    printf("\nAnterior: %d", p->cursorAux->vipdABB.numDni);
    printf("\nNuevo: %d", p->cursor->vipdABB.numDni);

}

void preOrden(arbol *p){
    if (p->cursor != NULL){
        printf("%d, ", p->cursor->vipdABB.numDni);
        preOrden(p->cursor->nodoIzquierdo);
        preOrden(p->cursor->nodoDerecho);
    }
}

void inOrden(arbol *p){
    if (p->cursor != NULL){
        inOrden(p->cursor->nodoIzquierdo);
        printf("%d, ", p->cursor->vipdABB.numDni);
        inOrden(p->cursor->nodoDerecho);
    }
}

void postOrden(arbol *p){
    if (p->cursor != NULL){
        postOrden(p->cursor->nodoIzquierdo);
        postOrden(p->cursor->nodoDerecho);
        printf("%d, ", p->cursor->vipdABB.numDni);
    }
}

void mostrarArbolBinRec(arbol *nodo, char cad[]){

    printf("Hola\n", nodo->cursor->vipdABB.numDni);

    if(nodo->cursor->nodoIzquierdo != NULL){
        char cad2[MAXTAMCAD]; strcpy(cad2, cad);
        if(nodo->cursor->nodoDerecho != NULL){
            printf("%s%c%c%c%c%c", cad, 195,196,196,196,196);
            char simb = 179, aux[2];
            aux[0] = simb; aux[1] = '\0'; strcat(cad2, aux);
            strcat(cad2, "      ");
            mostrarArbolBinRec(nodo->cursor->nodoIzquierdo,cad2);
        }else{
            printf("%s%c%c%c%c%c", cad, 195,196,196,196,196);
            strcat(cad2, "      ");
            mostrarArbolBinRec(nodo->cursor->nodoIzquierdo,cad2);
        }
    }

    if(nodo->cursor->nodoDerecho != NULL){
        char cad3[MAXTAMCAD]; strcpy(cad3, cad);
        printf("%s%c%c%c%c%c", cad, 195,196,196,196,196);
        strcat(cad3, "      ");
        mostrarArbolBinRec(nodo->cursor->nodoDerecho, cad3);
    }
}

void mostrarArbolBin(arbol nodo){
    if(nodo.acceso == NULL) printf("\nEl arbol esta vacio");
    else mostrarArbolBinRec(nodo.acceso,"");
}













