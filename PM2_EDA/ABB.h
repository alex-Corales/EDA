#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#endif // ABB_H_INCLUDED

int *cantVendedores = 0;

struct nodoABB{
    datosVendedor vipdABB;
    struct nodoABB *nodoPadre;
    struct nodoABB *nodoDerecho;
    struct nodoABB *nodoIzquierdo;
};

struct nodoABB *raiz = NULL;
struct nodoABB *anterior;
struct nodoABB *cursor;
struct nodoABB *aux1;
struct nodoABB *aux2;

void menuABB(){

    int auxABB, opcABB;
    char opc1ABB[10];
    datosVendedor vendedorABB;
    do{
        printf("<1> Dar de alta\n");
        printf("<2> Dar de baja\n");
        printf("<3> Consultar vendedor\n");
        printf("<4> Mostrar estructura\n");
        printf("<5> Memorizacion previa\n");
        printf("<6> Salir\n");
        printf("- ");
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
            break;
        case 3:
            /*printf("\nIngrese el dni del vendedor que desea buscar: ");
            scanf("%d", &vendedorABB.numDni);

            datosVendedor consultABB = evocarABB(vendedorABB.numDni);
            if(consultABB.numDni == 1) printf("\nEl vendedor no se encuentra cargado");
            else imprimirABB(consultABB);
            printf("\n");
            system("pause");
            system("cls");*/
            break;
        case 4:
            printf("\npreOrden\n");
            preOrden(raiz);
            printf("\n");
            system("pause");
            system("cls");
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

    }while(opc != 6);

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
    if(*cantVendedores == 110) return -1; //No se pueden ingresar mas vendedores
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
    *cantVendedores++;
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
    *cantVendedores--;
    return 0; //El vendedor se elimino
}

/*datosVendedor evocarABB(int dni){
    struct nodoABB *auxs;
    auxs->vipdABB.numDni = 1;
    int aux = localizarABB(dni);
    if(aux == 1) return auxs->vipdABB; //El vendedor no esta cargado
    else cursor->vipdABB;
}*/

int pertenece(){}

void preOrden(struct nodoABB *cursor){
    if (cursor != NULL){
        imprimirABB(cursor->vipdABB);
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
} //Guarda los datos del archivo
