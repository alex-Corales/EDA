#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#endif // ABB_H_INCLUDED

int cantVendedoresABB = 0;
int j = 0;
int numDni = 0;

struct nodoABB{
    datosVendedor vipdABB;
    struct nodoABB *nodoPadre;
    struct nodoABB *nodoDerecho;
    struct nodoABB *nodoIzquierdo;
};

struct nodoABB *raiz = NULL;
struct nodoABB *anterior;
struct nodoABB *cursor;
struct nodoABB *auxs;
struct nodoABB *aux1;
struct nodoABB *aux2;

datosVendedor evocarABB(int);

void menuABB(){

    int auxABB, opcABB;
    char opc1ABB[10];
    datosVendedor vendedorABB;
    datosVendedor tempABB;
    do{
        printf("------------------------------");
        printf("\nMENU ARBOL BINARIO");
        printf("\n------------------------------");
        printf("\n<1> Dar de alta");
        printf("\n<2> Dar de baja");
        printf("\n<3> Consultar vendedor");
        printf("\n<4> Mostrar estructura");
        printf("\n<5> Memorizacion previa");
        printf("\n<6> Salir");
        printf("\n- ");
        scanf("%d", &opcABB);

        system("cls");
        switch(opcABB){
        case 1:
            printf("\nIngrese el dni: ");
            fflush(stdin);
            scanf("%d", &vendedorABB.numDni);
            printf("\nIngrese el nombre y apellido: ");
            fflush(stdin);
            scanf("%s", vendedorABB.nombreApellido);
            printf("\nIngrese el numero de telefono: ");
            fflush(stdin);
            scanf("%s", vendedorABB.numTelefono);
            printf("\nIngrese el monto vendido: ");
            fflush(stdin);
            scanf("%f", &vendedorABB.montoVendido);
            printf("\nIngrese la cantidad vendida: ");
            fflush(stdin);
            scanf("%d", &vendedorABB.cantVendido);
            printf("\nIngrese el canal de venta: ");
            fflush(stdin);
            scanf("%s", vendedorABB.canalDeVenta);

            int auxAlta = altaABB(vendedorABB);
            if(auxAlta == 0) printf("\nEl vendedor ya se encuentra cargado en el sistema");
            else printf("\nEl vendedor fue cargado");
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 2:
            printf("\nIngrese el dni del vendedor que desea eliminar: ");
            scanf("%d", &vendedorABB.numDni);
            int auxBaja = bajaABB(vendedorABB);
            if(auxBaja == 2) printf("\nBaja cancelada");
            else printf("\nBorrado");
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:

            printf("\nIngrese el dni del vendedor que desea buscar: ");
            scanf("%d", &numDni);

            datosVendedor tempABB = evocarABB(numDni);

            if(tempABB.numDni == 1) printf("\nEl vendedor no se encuentra cargado");
            else imprimirABB(tempABB);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 4:
            printf("------------------------------");
            printf("\nMENU ARBOL BINARIO");
            printf("\n------------------------------");
            printf("\nComo desea ver el Arbol");
            printf("\n<1> Pre-Orden");
            printf("\n<2> Pre-Orden con hijos");
            printf("\n<3> Otros");
            printf("\n- ");
            scanf("%d", &opcABB);

            switch(opcABB){
            case 1:
                system("cls");
                printf("------------------------------");
                printf("\npreOrden\n");
                printf("------------------------------");
                int aux = preOrden(raiz);
                if(aux == 1) printf("\nNo hay vendedores cargados");
                printf("\n------------------------------");
                printf("\nADVERTENCIA: ULTIMO VENDEDOR");
                printf("\nSi presiona una tecla volvera al menu");
                printf("\n------------------------------");
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                printf("------------------------------");
                printf("\npreOrden\n");
                printf("------------------------------");
                aux = preOrdenHijos(raiz);
                if(aux == 1) printf("\nNo hay vendedores cargados");
                printf("\n------------------------------");
                printf("\nADVERTENCIA: ULTIMO VENDEDOR");
                printf("\nSi presiona una tecla volvera al menu");
                printf("\n------------------------------");
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                printf("------------------------------");
                printf("\nMENU ARBOL BINARIO");
                printf("\n------------------------------");
                printf("\n<1> In-Orden");
                printf("\n<2> Post-Orden");
                printf("\n<3> Por niveles");
                printf("\n- ");
                scanf("%d", &opcABB);
                switch(opcABB){
                case 1:
                    system("cls");
                    printf("\ninOrden\n");
                    inOrden(raiz);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    printf("\npostOrden\n");
                    postOrden(raiz);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    break;
                }
                break;
            }

            break;
        case 5:
            aux = memorizacionPreviaABB(vendedorABB);
            if (aux != 0) printf("\nSe cargo el archivo con exito");
            else printf("\nHubo un problema al leer el archivo vendedores.txt");
            printf("\n");
            system("pause");
            system("cls");
            break;
        }

    }while(opcABB != 6);

}

void imprimirABB(datosVendedor dat){
    printf("\n------------------------------");
    printf("\nNombre y Apellido: %s", dat.nombreApellido);
    printf("\nDni: %d", dat.numDni);
    printf("\nNumero de telefono: %s", dat.numTelefono);
    printf("\nMonto vendido: %f", dat.montoVendido);
    printf("\nCantidad vendida: %d", dat.cantVendido);
    printf("\nCanal de venta: %s", dat.canalDeVenta);
    printf("\n------------------------------\n");
}

int localizarABB(int numDni){
    cursor = raiz;
    while(cursor != NULL && cursor->vipdABB.numDni != numDni){
        anterior = cursor;
        if(numDni < cursor->vipdABB.numDni){
            cursor = cursor->nodoIzquierdo;
        }
        else{
            cursor = cursor->nodoDerecho;
        }
    }
    if(cursor == NULL) return 1; //El vendedor no esta en el arbol
    else return 0; //El vendedor se encuentra en el arbol
}

int altaABB(datosVendedor dat){
    if(cantVendedoresABB == 110) return -1; //No se pueden ingresar mas vendedores
    int aux = localizarABB(dat.numDni);
    if(aux == 0) return 0; //No puedo dar de alta por que el vendedor ya esta cargado

    struct nodoABB *nuevo = malloc(sizeof(struct nodoABB));
    if(nuevo == NULL) return 1;

    nuevo->vipdABB = dat;
    nuevo->nodoDerecho = NULL;
    nuevo->nodoIzquierdo = NULL;
    if(raiz == NULL){
        raiz = nuevo;
    }else{
        if(dat.numDni < anterior->vipdABB.numDni)
            anterior->nodoIzquierdo = nuevo;
        else
            anterior->nodoDerecho = nuevo;
    }
    cantVendedoresABB++;
    return 2; //El vendedor se cargo
}

int bajaABB(datosVendedor dat){ //Politica de remplazo: Menor de los mayores con copia de datos
    int aux = localizarABB(dat.numDni);
    if(aux == 1) return 1; //El vendedor no se encuentra en el arbol
    int opcBaja;
    printf("\nDni: %d", cursor->vipdABB.numDni);
    printf("\nNombre y apellido: %s", cursor->vipdABB.nombreApellido);
    printf("\nNumero de telefono: %s", cursor->vipdABB.numTelefono);
    printf("\nMonto vendido: %f", cursor->vipdABB.montoVendido);
    printf("\nCantidad vendida: %d", cursor->vipdABB.cantVendido);
    printf("\nCanal de venta: %s", cursor->vipdABB.canalDeVenta);
    printf("\nDesea eliminar el vendedor?");
    printf("\n<1> Si");
    printf("\n<2> No");
    printf("\n- ");
    scanf("%d", &opcBaja);
    if(opcBaja == 2) return 2;

    if(cursor->nodoIzquierdo == NULL && cursor->nodoDerecho == NULL){
        if(cursor == raiz) raiz = NULL;
        else{
            if(anterior->vipdABB.numDni > dat.numDni) anterior->nodoIzquierdo = NULL;
            else anterior->nodoDerecho = NULL;
            free(cursor);
        }
    }else if((cursor->nodoIzquierdo == NULL && cursor->nodoDerecho != NULL) || (cursor->nodoIzquierdo != NULL && cursor->nodoDerecho == NULL)){
        if(cursor == raiz){
            if(cursor->nodoIzquierdo != NULL) raiz = cursor->nodoIzquierdo;
            else raiz = cursor->nodoDerecho;
        }else{
            if(anterior->vipdABB.numDni > dat.numDni && cursor->nodoIzquierdo == NULL) anterior->nodoIzquierdo = cursor->nodoDerecho;
            else if(anterior->vipdABB.numDni > dat.numDni && cursor->nodoDerecho == NULL) anterior->nodoDerecho = cursor->nodoIzquierdo;
            else if(anterior->vipdABB.numDni < dat.numDni && cursor->nodoDerecho == NULL) anterior->nodoDerecho = cursor->nodoIzquierdo;
            else if(anterior->vipdABB.numDni < dat.numDni && cursor->nodoIzquierdo == NULL) anterior->nodoIzquierdo = cursor->nodoDerecho;
            free(cursor);
        }
    }else{
        aux2 = cursor->nodoDerecho;
        aux1 = cursor->nodoDerecho;
        while(aux1->nodoIzquierdo != NULL){
            aux2 = aux1;
            aux1 = aux1->nodoIzquierdo;
        }
        if(aux1 == aux2){
            cursor->nodoDerecho = aux1->nodoDerecho;
            cursor->vipdABB = aux1->vipdABB;
        }else{
            cursor->vipdABB = aux1->vipdABB;
            aux2->nodoIzquierdo = aux1->nodoDerecho;
        }
    }
    cantVendedoresABB--;
    return 0; //El vendedor se elimino
}

datosVendedor evocarABB(int dni){
    datosVendedor temp;
    temp.numDni = 1;

    int aux = localizarABB(dni);
    if(aux == 1) return temp; //El vendedor no esta cargado

    else cursor->vipdABB;
}

int pertenece(){}

int preOrdenHijos(struct nodoABB *cursor){
    if(raiz == NULL) return 1;
    if (cursor != NULL){
        printf("\nPADRE: ");
        imprimirABB(cursor->vipdABB);

        if(cursor->nodoIzquierdo == NULL){
            printf("\n------------------------------");
            printf("\nHIJO IZQUIERDO: NO TIENE");
            printf("\n------------------------------");
        }else{
            printf("\nHIJO IZQUIERDO: ");
            imprimirABB(cursor->nodoIzquierdo->vipdABB);
        }

        if(cursor->nodoDerecho == NULL){
            printf("\n------------------------------");
            printf("\nHIJO DERECHO: NO TIENE");
            printf("\n------------------------------");
        }else{
            printf("\nHIJO DERECHO: ");
            imprimirABB(cursor->nodoDerecho->vipdABB);
        }
        printf("\n");
        system("pause");
        preOrdenHijos(cursor->nodoIzquierdo);
        preOrdenHijos(cursor->nodoDerecho);
    }
}

int preOrden(struct nodoABB *cursor){
    if(raiz == NULL) return 1;
    if (cursor != NULL){
        imprimirABB(cursor->vipdABB);
        if ((j % 5) == 0){system("\n pause");}j++;
        preOrden(cursor->nodoIzquierdo);
        preOrden(cursor->nodoDerecho);
    }
}

void inOrden(struct nodoABB *cursor){
    if (cursor != NULL){
        inOrden(cursor->nodoIzquierdo);
        imprimirABB(cursor->vipdABB);
        inOrden(cursor->nodoDerecho);
    }
}

void postOrden(struct nodoABB *cursor){
    if (cursor != NULL){
        postOrden(cursor->nodoIzquierdo);
        postOrden(cursor->nodoDerecho);
        imprimirABB(cursor->vipdABB);
    }
}

int memorizacionPreviaABB(datosVendedor dat){
    FILE *fp;
    if((fp = fopen("vendedores.txt","r"))==NULL) return 0;
    else{
        while(!feof(fp)){
            fscanf(fp,"%d %[^\n] %[^\n] %f %d %[^\n]", &dat.numDni, dat.nombreApellido, dat.numTelefono, &dat.montoVendido, &dat.cantVendido, dat.canalDeVenta);
            altaABB(dat);
        }
        return 1;
    }
    fclose(fp);
}
