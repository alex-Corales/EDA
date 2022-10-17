/*
    Grupo 30
    Corales Alex Nahuel
    alexcorales21@gmail.com
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
struct nodoABB *aux1;
struct nodoABB *aux2;

/*
    PROTOTIPOS
*/

datosVendedor evocarABB(int);
int localizarABB(int);
int altaABB(datosVendedor);
int bajaABB(datosVendedor);
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

            int auxAlta = altaABB(vendedorABB);
            if(auxAlta == 0) printf("\nEl vendedor ya se encuentra cargado en el sistema");
            else if(auxAlta == -1) printf("\nEl vendedor no se puede cargar por que la estructura esta llena");
            else if(auxAlta == 1) printf("\nError, no se puede cargar el vendedor");
            else printf("\nEl vendedor fue cargado");
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 2:
            printf("\nIngrese el dni del vendedor que desea eliminar: ");
            scanf("%d", &vendedorABB.numDni);
            int auxBaja = bajaABB(vendedorABB);
            if(auxBaja == 2) printf("\nSe cancelo la baja");
            else if(auxBaja == 1) printf("\nEl vendedor no se encuentra cargado");
            else printf("\nEL vendedor se borro con exito");
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
    int aux = localizarABB(dat.numDni);
    if(aux == 0) return 0; //No puedo dar de alta por que el vendedor ya esta cargado

    struct nodoABB *nuevo = malloc(sizeof(struct nodoABB));
    if(nuevo == NULL) return 1; //fallo, no se pueden agregar mas vendedores

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

    if(cursor->nodoIzquierdo == NULL && cursor->nodoDerecho == NULL){ //No tiene hijos
        if(cursor == raiz) raiz = NULL;
        else{
            if(anterior->vipdABB.numDni > dat.numDni) anterior->nodoIzquierdo = NULL;
            else anterior->nodoDerecho = NULL;
        }
    }else if((cursor->nodoIzquierdo == NULL && cursor->nodoDerecho != NULL) || (cursor->nodoIzquierdo != NULL && cursor->nodoDerecho == NULL)){ //Tiene solo un hijo
        if(cursor == raiz){
            if(cursor->nodoIzquierdo == NULL) raiz = cursor->nodoDerecho;
            else raiz = cursor->nodoIzquierdo;
        }else{
            if(anterior->nodoDerecho == cursor){
                if(cursor->nodoDerecho != NULL)
                    anterior->nodoDerecho = cursor->nodoDerecho;
                else
                    anterior->nodoDerecho = cursor->nodoIzquierdo;
            }else{
                if(cursor->nodoIzquierdo != NULL)
                    anterior->nodoIzquierdo = cursor->nodoIzquierdo;
                else
                    anterior->nodoIzquierdo = cursor->nodoDerecho;
            }
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
    free(cursor);
    cantVendedoresABB--;
    return 0; //El vendedor se elimino
}

datosVendedor evocarABB(int dni){
    datosVendedor temp;
    temp.numDni = 1;

    int aux = localizarABB(dni);
    if(aux == 1) return temp; //El vendedor no esta cargado

    return cursor->vipdABB;
}

int pertenece(int dni){
    if(localizarABB(dni) == 0) return 1; //El vendedor se encuentra cargado
}

int preOrdenHijos(struct nodoABB *cursor){
    if(raiz == NULL) return 1;
    system("cls");
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
    int auxMemo = 0;
    FILE *fp;
    if((fp = fopen("vendedoresPrueba.txt","r"))==NULL) return 0;
    else{
        while(!feof(fp)){
            fscanf(fp,"%d %[^\n] %[^\n] %f %d %[^\n]", &dat.numDni, dat.nombreApellido, dat.numTelefono, &dat.montoVendido, &dat.cantVendido, dat.canalDeVenta);
            auxMemo = altaABB(dat);
            if(auxMemo == 1){
                fclose(fp);
                return -1; //Se lleno la estructura
            }
        }
        fclose(fp);
        return 1;
    }
}


