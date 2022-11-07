/*
    Grupo 30 - Corales Alex Nahuel
*/

#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#endif // ABB_H_INCLUDED
#define MAXTAMCAD 100

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
struct nodoABB *aux1 = NULL;
struct nodoABB *aux2 = NULL;

/*
    PROTOTIPOS
*/

datosVendedor evocarABB(int, float *);
int localizarABB(int, float *);
int altaABB(datosVendedor, float *);
int bajaABB(datosVendedor, float *, int);
int pertenece(int);
int preOrdenHijos(struct nodoABB *);
int preOrden(struct nodoABB *);
int memorizacionPreviaABB(datosVendedor);
void imprimirABB(datosVendedor);
void inOrden(struct nodoABB *);
void postOrden(struct nodoABB *);

/*
    VARIABLES
*/

int cantVendedoresABB = 0;
int j = 0;
int numDni = 0;
char auxS[50];


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
            do{
                scanf("%s", auxS);
                auxopc = controlIngresoNum(auxS);
            }while(auxopc==0);
            vendedorABB.numDni = atoi(auxS);

            printf("\nIngrese el nombre y apellido: ");
            do{
                getchar();
                gets(vendedorABB.nombreApellido);
                num=controlIngresoLetras(vendedorABB.nombreApellido);
            }while(num==0);

            printf("\nIngrese el numero de telefono: ");
            do{
                getchar();
                gets(vendedorABB.numTelefono);
                num=controlIngresoLetrasNumero(vendedorABB.numTelefono);
            }while(num == 0);

            printf("\nIngrese el monto vendido: ");
            do{
                scanf("%s", auxS);
                auxopc = controlIngresoNum(auxS);
            }while(auxopc==0);
            vendedorABB.montoVendido = atoi(auxS);

            printf("\nIngrese la cantidad vendida: ");
            do{
                scanf("%s", auxS);
                auxopc = controlIngresoNum(auxS);
            }while(auxopc==0);
            vendedorABB.cantVendido = atoi(auxS);

            printf("\nIngrese el canal de venta: ");
            do{
                getchar();
                gets(vendedorABB.canalDeVenta);
                num=controlIngresoLetras(vendedorABB.canalDeVenta);
            }while(num==0);

            int auxAlta = altaABB(vendedorABB, &costo);
            if(auxAlta == 0) printf("\nEl vendedor ya se encuentra cargado en el sistema");
            else if(auxAlta == 1) printf("\nEl vendedor no se puede cargar por que la estructura esta llena");
            else printf("\nEl vendedor fue cargado");
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 2:
            printf("\nIngrese el dni del vendedor que desea eliminar: ");
            scanf("%d", &vendedorABB.numDni);
            int auxBaja = bajaABB(vendedorABB, &costo, 1);
            if(auxBaja == 2) printf("\nSe cancelo la baja");
            else if(auxBaja == 1) printf("\nEl vendedor no se encuentra cargado");
            else if(auxBaja == 0) printf("\nEL vendedor se borro con exito");
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:

            printf("\nIngrese el dni del vendedor que desea buscar: ");
            scanf("%d", &numDni);

            datosVendedor tempABB = evocarABB(numDni, &costo);

            if(tempABB.numDni == 1) printf("\nEl vendedor no se encuentra cargado");
            else imprimirABB(tempABB);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 4:
            do{
                printf("------------------------------");
                printf("\nMENU ARBOL BINARIO");
                printf("\n------------------------------");
                printf("\nComo desea ver el Arbol");
                printf("\n<1> Pre-Orden");
                printf("\n<2> Pre-Orden con hijos");
                printf("\n<3> Salir");
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
                }
            }while(opcABB != 3);

            break;
        case 5:
            aux = memorizacionPreviaABB(vendedorABB);
            if (aux == 1) printf("\nSe cargo el archivo con exito");
            else if(aux == -1) printf("\nSe cargo el archivo con exito y se lleno la estructura");
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

int localizarABB(int numDni, float *costo){
    cursor = raiz;
    *costo = 0.0;
    while(cursor != NULL && cursor->vipdABB.numDni != numDni){
        *costo = *costo + 1;
        anterior = cursor;
        if(numDni < cursor->vipdABB.numDni){
            cursor = cursor->nodoIzquierdo;
        }
        else{
            cursor = cursor->nodoDerecho;
        }
    }

    if(cursor == NULL){ //El vendedor no esta en el arbol
        *costo = *costo + 1;
        return 1;
    }else if(cursor->vipdABB.numDni == numDni){ //El vendedor se encuentra en el arbol
        *costo = *costo + 1; //Cuando sale por que encuentra el dni costo no cuenta el nodo en el que esta el dni
        return 0;
    }
}

int altaABB(datosVendedor dat, float *costo){
    float costoAux;
    int aux = localizarABB(dat.numDni, &costoAux);
    if(aux == 0) return 0; //No puedo dar de alta por que el vendedor ya esta cargado

    struct nodoABB *nuevo = malloc(sizeof(struct nodoABB));
    if(nuevo == NULL) return 1; //fallo, no se pueden agregar mas vendedores

    nuevo->vipdABB = dat;
    nuevo->nodoDerecho = NULL;
    nuevo->nodoIzquierdo = NULL;
    if(raiz == NULL){
        raiz = nuevo;
        *costo = *costo + 1;
    }else{
        if(dat.numDni < anterior->vipdABB.numDni){
            anterior->nodoIzquierdo = nuevo;
            *costo = *costo + 1;
        }else{
            anterior->nodoDerecho = nuevo;
            *costo = *costo + 1;
        }
    }
    cantVendedoresABB++;
    return 2; //El vendedor se cargo
}

int bajaABB(datosVendedor dat, float *costo, int opcAux){

    float costoAux;
    int aux = localizarABB(dat.numDni, &costoAux);
    if(aux == 1) return 1; //El vendedor no se encuentra en el arbol

    if(opcAux == 1){
        if(dat.numDni == cursor->vipdABB.numDni && dat.cantVendido == cursor->vipdABB.cantVendido && dat.montoVendido == cursor->vipdABB.montoVendido && (strcmp(cursor->vipdABB.canalDeVenta, dat.canalDeVenta) == 0) && (strcmp(cursor->vipdABB.nombreApellido, dat.nombreApellido) == 0) && (strcmp(cursor->vipdABB.numTelefono, dat.numTelefono) == 0)){
            opc = 1;
        }else opc = 0;
    }
    if(opc == 0) return 3;
    if(opcAux == 0){
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
    }

    if(cursor->nodoIzquierdo == NULL && cursor->nodoDerecho == NULL){ //No tiene hijos
        if(cursor == raiz){
            raiz = NULL;
            *costo = *costo + 1;
        }else{
            if(anterior->vipdABB.numDni > dat.numDni){
                anterior->nodoIzquierdo = NULL;
                *costo = *costo + 1;
            }else{
                anterior->nodoDerecho = NULL;
                *costo = *costo + 1;
            }
        }
    }else if((cursor->nodoIzquierdo == NULL && cursor->nodoDerecho != NULL) || (cursor->nodoIzquierdo != NULL && cursor->nodoDerecho == NULL)){ //Tiene solo un hijo
        if(cursor == raiz){
            if(cursor->nodoIzquierdo == NULL){
                raiz = cursor->nodoDerecho;
                *costo = *costo + 1;
            }else{
                raiz = cursor->nodoIzquierdo;
                *costo = *costo + 1;
            }
        }else{
            if(anterior->nodoDerecho == cursor){
                if(cursor->nodoDerecho != NULL){
                    anterior->nodoDerecho = cursor->nodoDerecho;
                    *costo = *costo + 1;
                }else{
                    anterior->nodoDerecho = cursor->nodoIzquierdo;
                    *costo = *costo + 1;
                }
            }else{
                if(cursor->nodoIzquierdo != NULL){
                    anterior->nodoIzquierdo = cursor->nodoIzquierdo;
                    *costo = *costo + 1;
                }else{
                    anterior->nodoIzquierdo = cursor->nodoDerecho;
                    *costo = *costo + 1;
                }
            }
        }
    }else{ //Politica de remplazo: Mayor de los menores con copia de datos
        aux2 = cursor->nodoIzquierdo;
        aux1 = cursor->nodoIzquierdo;
        while(aux1->nodoDerecho != NULL){
            aux2 = aux1;
            aux1 = aux1->nodoDerecho;
        }
        if(aux1 == aux2){
            cursor->nodoIzquierdo = aux1->nodoIzquierdo;
            cursor->vipdABB = aux1->vipdABB;
            *costo = *costo + 1;
            //*costo = *costo + 1.5;
        }else{
            cursor->vipdABB = aux1->vipdABB;
            aux2->nodoDerecho = aux1->nodoIzquierdo;
            *costo = *costo + 1;
            //*costo = *costo + 1.5;
        }
        cursor = aux1;
        *costo = *costo + 1.5;
        /*
            Un costo por la actulizacion del puntero a null
            y 1.5 por la copia de datos, seria entonces
            2.5 (PREGUNTAR)
        */
    }
    free(cursor);
    cantVendedoresABB--;
    return 0; //El vendedor se elimino
}

datosVendedor evocarABB(int dni, float *costo){
    datosVendedor aux;
    aux.numDni = 1;
    float costoAux;
    int auxE = localizarABB(dni, &costoAux);
    if(auxE == 1){
        *costo = costoAux;
        return aux; //El vendedor no esta cargado
    }else if(auxE == 0){
        *costo = costoAux;
        //return 0;
        return cursor->vipdABB;
    }
}

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
            printf("\n------------------------------");
            printf("\nDni: %d", cursor->nodoIzquierdo->vipdABB.numDni);
            printf("\n------------------------------");
        }

        if(cursor->nodoDerecho == NULL){
            printf("\n------------------------------");
            printf("\nHIJO DERECHO: NO TIENE");
            printf("\n------------------------------");
        }else{
            printf("\nHIJO DERECHO: ");
            printf("\n------------------------------");
            printf("\nDni: %d", cursor->nodoDerecho->vipdABB.numDni);
            printf("\n------------------------------");
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
        if (j == 10){
            system("pause");
            j = 0;
        }
        j++;
        preOrden(cursor->nodoIzquierdo);
        preOrden(cursor->nodoDerecho);
    }
}

int memorizacionPreviaABB(datosVendedor dat){
    int auxMemo = 0;
    FILE *fp;
    if((fp = fopen("vendedores.txt","r"))==NULL) return 0;
    else{
        while(!feof(fp)){
            fscanf(fp,"%d %[^\n] %[^\n] %f %d %[^\n]", &dat.numDni, dat.nombreApellido, dat.numTelefono, &dat.montoVendido, &dat.cantVendido, dat.canalDeVenta);
            auxMemo = altaABB(dat, &costo);
            if(auxMemo == 1){
                fclose(fp);
                return -1; //Se lleno la estructura
            }else if(auxMemo == 0){
                printf("\nHay un vendedor repetido");
                printf("\nDesea ver el vendedor repetido?");
                printf("\n<1> Si");
                printf("\n<2> No");
                printf("\n- ");
                scanf("%d", &auxMemo);
                if(auxMemo == 1) imprimirABB(dat);
                system("pause");
                system("cls");
            }
        }
        fclose(fp);
        return 1;
    }
}
