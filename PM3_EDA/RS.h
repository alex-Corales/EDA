/*
    Grupo 30 - Corales Alex Nahuel
*/

#ifndef RS_H_INCLUDED
#define RS_H_INCLUDED
#endif // RS_H_INCLUDED

#include "controles.h"
#define M 60 //p= 1.84 -> M = N/p -> M = 110/1.84 -> M = 59.78 -> M = 60.

typedef struct{
    datosVendedor vipd;
    struct nodo *next;
}nodo;

typedef struct{
    nodo *acceso;
    nodo *cursor;
}lista;

/*
    VARIABLES
*/

nodo *anteriorRS;
int contRS;
int opcAuxRS = 0;
char auxDni[20];
char opc1[10];
int aux, num, dni, auxopc;
int posRS;
int exito;
char auxS[50];
datosVendedor vendedor;
lista RS[M];

/*
    PROTOTIPOS
*/

datosVendedor evocarRS(lista *, int, float *);
int localizarRS(lista *, int, int *, float *);
int altaRS(lista *, datosVendedor, float *);
int bajaRS(lista *, datosVendedor, float *, int);
int perteneceRS(lista *, int, int *);
int mostrarRS(lista *);
int memorizacionPreviaRS(lista *, datosVendedor);
int hashingRS(int);
void imprimirRS(datosVendedor);
void initRS(lista *);

void init(lista *p){
    (*p).acceso = NULL;
    (*p).cursor = NULL;
}

void menuRS(){

    if(opcAuxRS == 0){initRS(RS); opcAuxRS++;}
    int opc = 0;
    do{
        printf("------------------------------");
        printf("\nMENU REBALSE SEPARADO");
        printf("\n------------------------------");
        printf("\n<1> Dar de alta");
        printf("\n<2> Dar de baja");
        printf("\n<3> Consultar vendedor");
        printf("\n<4> Mostrar estructura");
        printf("\n<5> Memorizacion previa");
        printf("\n<6> Salir");
        printf("\n- ");
        do{
            scanf("%s", opc1);
            auxopc = controlIngresoNum(opc1);
        }while(auxopc==0);
        opc = atoi(opc1);

        system("cls");
        switch(opc){
        case 1:
            printf("\nIngrese el dni: ");
            do{
                scanf("%s", auxS);
                auxopc = controlIngresoNum(auxS);
            }while(auxopc==0);
            vendedor.numDni = atoi(auxS);

            printf("\nIngrese el nombre y apellido: ");
            do{
                getchar();
                gets(vendedor.nombreApellido);
                num=controlIngresoLetras(vendedor.nombreApellido);
            }while(num==0);

            printf("\nIngrese el numero de telefono: ");
            do{
                getchar();
                gets(vendedor.numTelefono);
                num=controlIngresoLetrasNumero(vendedor.numTelefono);
            }while(num == 0);

            printf("\nIngrese el monto vendido: ");
            do{
                scanf("%s", auxS);
                auxopc = controlIngresoNum(auxS);
            }while(auxopc==0);
            vendedor.montoVendido = atoi(auxS);

            printf("\nIngrese la cantidad vendida: ");
            do{
                scanf("%s", auxS);
                auxopc = controlIngresoNum(auxS);
            }while(auxopc==0);
            vendedor.cantVendido = atoi(auxS);

            printf("\nIngrese el canal de venta: ");
            do{
                getchar();
                gets(vendedor.canalDeVenta);
                num = controlIngresoLetras(vendedor.canalDeVenta);
            }while(num==0);

            aux = altaRS(RS, vendedor, &costo);

            if (aux == 1) printf("\nEl vendedor se cargo con exito");
            else if(aux == 2) printf("\nLa estructura esta llena");
            else printf("\nEl vendedor ya se encuentra cargado");
            printf("\n");
            system("pause");
            system("cls");

            break;
        case 2:
            printf("\nIngrese el dni del vendedor: ");
            scanf("%d", &vendedor.numDni);
            int aux = bajaRS(RS, vendedor, &costo, 1);
            if(aux == 1) printf("\nNo hay elementos para dar de baja");
            else if(aux == 0) printf("\nEl vendendor no se encuentra cargado en la lista");
            else if(aux == -1) printf("\nSe cancelo la baja del vendedor");
            else printf("\nFue dado de baja exitosamente");
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:
            printf("\nIngrese el dni que desea buscar: ");
            scanf("%d", &dni);
            datosVendedor consult = evocarRS(RS, dni, &costo);

            if(consult.numDni == -1) printf("\nEl vendedor no esta cargado");
            else imprimirRS(consult);
            printf("\n");
            system("pause");
            system("cls");

            break;
        case 4:
            aux = mostrarRS(RS);
            if(aux == 1) printf("\nNo hay vendedores cargados para mostrar");
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 5:
            aux = memorizacionPreviaRS(RS,vendedor);
            if (aux == 1) printf("\nSe cargo el archivo con exito");
            else if(aux == -1) printf("\nSe cargo el archivo con exito y se lleno la estructura");
            else printf("\nHubo un problema al leer el archivo vendedores.txt");
            printf("\n");
            system("pause");
            system("cls");
            break;
        }

    }while(opc != 6);
}

void imprimirRS(datosVendedor dat){
    printf("\n------------------------------");
    printf("\nNombre y Apellido: %s", dat.nombreApellido);
    printf("\nDni: %d", dat.numDni);
    printf("\nNumero de telefono: %s", dat.numTelefono);
    printf("\nMonto vendido: %f", dat.montoVendido);
    printf("\nCantidad vendida: %d", dat.cantVendido);
    printf("\nCanal de venta: %s", dat.canalDeVenta);
    printf("\n------------------------------\n");
}

int hashingRS(int dni){
    char x[8];
    int longitud, i;
    int contador = 0;
    sprintf(x,"%d",dni);
    longitud = strlen(x);
    for(i = 0; i < longitud; i++) contador+= ((int)x[i]) * (i+1);
    return (contador % M);
}

void initRS(lista dat[]){
    for(int i = 0; i < M; i++){
        init(&dat[i]);
    }
}

int localizarRS(lista dat[], int dni, int *posRS, float *costo){
    *posRS = hashingRS(dni);
    *costo = 1.0;
    if(dat[*posRS].acceso == NULL) return 1; //Veo si hay elementos
    dat[*posRS].cursor = dat[*posRS].acceso;
    anteriorRS = dat[*posRS].acceso;

    while(dat[*posRS].cursor != NULL && dat[*posRS].cursor->vipd.numDni != dni){
        anteriorRS = dat[*posRS].cursor;
        dat[*posRS].cursor = dat[*posRS].cursor->next;
        *costo = *costo + 1;
    }

    if(dat[*posRS].cursor == NULL) return 0; //El elemento no esta en la lista
    if(dat[*posRS].cursor->vipd.numDni == dni) return 2;
}

int altaRS(lista dat[], datosVendedor empleado, float *costo){
    float costoAux;
    aux = localizarRS(dat, empleado.numDni, &posRS, &costoAux);
    if(aux == 2) return 0; //No puedo dar de alta por que el elemento ya existe

    nodo *aux = (nodo*)malloc(sizeof(nodo));
    if(aux == NULL) return 2; //No se puede dar de alta por que no hay mas espacio

    dat[posRS].cursor = dat[posRS].acceso;

    dat[posRS].acceso = aux;
    aux->next = dat[posRS].cursor;
    dat[posRS].cursor = dat[posRS].acceso;
    *costo = *costo + 2; //Actualizo dos punteros, acceso apunta a aux y aux a cursor.

    dat[posRS].cursor->vipd = empleado;

    contRS++;
    return 1;
}

int bajaRS(lista dat[], datosVendedor datRS, float *costo, int opcAux){
    if(contRS == 0) return 1; //No hay elementos
    float costoAux;
    int aux = localizarRS(dat, datRS.numDni, &posRS, &costoAux);
    if(aux == 0) return 0; //El elemento no esta en la lista
    if(aux == 1) return 1;
    *costo = 0.0;
    if(opcAux == 1){
        if(datRS.numDni == dat[posRS].cursor->vipd.numDni && datRS.cantVendido == dat[posRS].cursor->vipd.cantVendido && datRS.montoVendido == dat[posRS].cursor->vipd.montoVendido && (strcmp(dat[posRS].cursor->vipd.canalDeVenta, datRS.canalDeVenta) == 0) && (strcmp(dat[posRS].cursor->vipd.nombreApellido, datRS.nombreApellido) == 0) && (strcmp(dat[posRS].cursor->vipd.numTelefono, datRS.numTelefono) == 0)){
            opc = 1;
        }else opc = 0;
    }
    if(opc == 0) return 3;
    if(opcAux == 0){
        imprimirRS(dat[posRS].cursor->vipd);
        printf("\nDesea eliminar los datos del vendedor");
        printf("\n<1> Si");
        printf("\n<2> No");
        printf("\n- ");
        scanf("%d", &opc);
        if(opc == 1){

        }else return -1;
    }
    if(dat[posRS].cursor == dat[posRS].acceso){
        dat[posRS].acceso = dat[posRS].cursor->next;
        free(dat[posRS].cursor);
        dat[posRS].cursor = dat[posRS].acceso;
        anteriorRS = dat[posRS].acceso;
        *costo = *costo + 1;
    }else{
        anteriorRS->next = dat[posRS].cursor->next;
        free(dat[posRS].cursor);
        dat[posRS].cursor = anteriorRS->next;
        *costo = *costo + 1;
    }
    contRS--;
    return 2;
}

datosVendedor evocarRS(lista dat[], int dni, float *costo){
    datosVendedor aux;
    aux.numDni = -1;
    float costoAux;
    if(localizarRS(dat, dni, &posRS, &costoAux) != 2){
        *costo = costoAux;
        return aux;
    }

    if(costoAux == 6) printf("\n%d", hashingRS(dni));
    *costo = costoAux;
    return dat[posRS].cursor->vipd;
}

int mostrarRS(lista dat[]){
    if(contRS == 0) return 1;
    int j = 0;
    for(int i = 0; i < M; i++){
        //if(j == 10){
            //printf("\n");
            //system("pause");
            //printf("\n");
            //j = 0;
        //}
        printf("\nBalde N: %d", i);
        mostrarLista(dat[i]);
        j++;
    }
}

void mostrarLista(lista dat){
    dat.cursor = dat.acceso;
    while(dat.cursor != NULL){
        imprimirRS(dat.cursor->vipd);
        dat.cursor = dat.cursor->next;
    }
}

int memorizacionPreviaRS(lista dat[], datosVendedor empleado){
    int auxMemo = 0;
    FILE *fp;
    if((fp = fopen("vendedores.txt","r"))==NULL) return 0;
    else{
        while(!feof(fp)){
            fscanf(fp,"%d %[^\n] %[^\n] %f %d %[^\n]", &empleado.numDni, empleado.nombreApellido, empleado.numTelefono, &empleado.montoVendido, &empleado.cantVendido, empleado.canalDeVenta);
            auxMemo = altaRS(dat, empleado, &costo);
            if(auxMemo == 2){
                fclose(fp);
                return -1; //Se lleno la estructura
            }else if(auxMemo == 0){
                printf("\nHay un vendedor repetido");
                printf("\nDesea ver el vendedor repetido?");
                printf("\n<1> Si");
                printf("\n<2> No");
                printf("\n- ");
                scanf("%d", &auxMemo);
                if(auxMemo == 1) imprimirRS(empleado);
                system("pause");
                system("cls");
            }
        }
        fclose(fp);
        return 1;
    }
}
