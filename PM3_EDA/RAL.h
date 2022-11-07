/*
    Grupo 30 - Corales Alex Nahuel
*/

#ifndef RAL_H_INCLUDED
#define RAL_H_INCLUDED
#endif // RAL_H_INCLUDED
#include "vendedores.h"
#define M 149 //p= 0.77 -> M = N/p -> M = 110/0.77 -> M = 142.85 -> M = 149.

typedef struct{
    char estado;
    datosVendedor dat;
}celda;

/*
    PROTOTIPOS
*/

datosVendedor evocarRAL(celda *, int, float *);
int localizarRAL(celda *, int, int *, float *);
int altaRAL(celda *, datosVendedor, float *);
int bajaRAL(celda *, datosVendedor, float *, int);
int perteneceRAL(celda *, int, int *);
int memorizacionPreviaRAL(celda *, datosVendedor, float *);
int mostrarRAL(celda *);
int hashingRAL(int);
void imprimirRAL(datosVendedor);
void initRAL(celda *);

/*
    VARIABLES
*/

int opcAuxRAL = 0;
int cantVendido;
int cantVendedoresRAC = 0;
int dni = 0;
int pos = 0;
int auxopc = 0;
int opc = 0;
int num = 0;
int aux = 0;
int exito;
char auxS[50];
char opc1[10];
celda RAL[M];
datosVendedor vendedorRAC;

void menuRAC(){

    if(opcAuxRAL == 0){initRAL(RAL); opcAuxRAL++;}
    int opc = 0;
    do{
        printf("------------------------------");
        printf("\nMENU REBALSE ABIERTO CUADRATICO");
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
            vendedorRAC.numDni = atoi(auxS);

            printf("\nIngrese el nombre y apellido: ");
            do{
                getchar();
                gets(vendedorRAC.nombreApellido);
                num=controlIngresoLetras(vendedorRAC.nombreApellido);
            }while(num==0);

            printf("\nIngrese el numero de telefono: ");
            do{
                getchar();
                gets(vendedorRAC.numTelefono);
                num=controlIngresoLetrasNumero(vendedorRAC.numTelefono);
            }while(num == 0);

            printf("\nIngrese el monto vendido: ");
            do{
                scanf("%s", auxS);
                auxopc = controlIngresoNum(auxS);
            }while(auxopc==0);
            vendedorRAC.montoVendido = atoi(auxS);

            printf("\nIngrese la cantidad vendida: ");
            do{
                scanf("%s", auxS);
                auxopc = controlIngresoNum(auxS);
            }while(auxopc==0);
            vendedorRAC.cantVendido = atoi(auxS);

            printf("\nIngrese el canal de venta: ");
            do{
                getchar();
                gets(vendedorRAC.canalDeVenta);
                num=controlIngresoLetras(vendedorRAC.canalDeVenta);
            }while(num==0);

            aux = altaRAL(RAL, vendedorRAC, &costo);
            if (aux == 1) printf("\nEl vendedor se cargo con exito");
            else if (aux == 0) printf("\nEl vendedor no se puede cargar por que no hay mas lugar");
            else printf("\nEl vendedor fue cargado con exito");
            printf("\n");
            system("pause");
            system("cls");

            break;
        case 2:
            printf("\nIngrese el dni del vendedor: ");
            scanf("%d", &dni);
            int aux = bajaRAL(RAL, vendedorRAC, &costo, 1);
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
            datosVendedor consult = evocarRAL(RAL, dni, &costo);
            if(consult.numDni == -1) printf("\nEl vendedor no esta cargado");
            else if(consult.numDni == 1) printf("\nNo hay vendedores cargados");
            else imprimirRAL(consult);
            printf("\n");
            system("pause");
            system("cls");

            break;
        case 4:
            aux = mostrarRAL(RAL);
            if(aux == 1) printf("\nNo hay vendedores cargados");
            printf("\n");
            system("pause");
            system("cls");
            break;
            break;
        case 5:
            aux = memorizacionPreviaRAL(RAL, vendedorRAC, &costo);
            if (aux == 1) printf("\nSe cargo el archivo con exito");
            else if(aux == -1) printf("\nSe cargo el archivo con exito y se lleno la estructura");
            else printf("\nHubo un problema al leer el archivo vendedores.txt");
            printf("\n");
            system("pause");
            system("cls");
            break;
        }

    }while(opc != 6);
    return 0;
}

int hashingRAL(int dni){
    char x[8];
    int longitud, i;
    int contador = 0;
    sprintf(x,"%d",dni);
    longitud = strlen(x);
    for(i = 0; i < longitud; i++) contador+= ((int)x[i]) * (i+1);
    return (contador % M);
}

void initRAL(celda RAL[]){
    for(int i = 0; i < M; i++){
        RAL[i].estado = '*';
        RAL[i].dat.numDni = 0;
    }
}

void imprimirRAL(datosVendedor dat){
    printf("\n------------------------------");
    printf("\nNombre y Apellido: %s", dat.nombreApellido);
    printf("\nDni: %d", dat.numDni);
    printf("\nNumero de telefono: %s", dat.numTelefono);
    printf("\nMonto vendido: %f", dat.montoVendido);
    printf("\nCantidad vendida: %d", dat.cantVendido);
    printf("\nCanal de venta: %s", dat.canalDeVenta);
    printf("\n------------------------------\n");
}

int localizarRAL(celda RAL[] ,int dni ,int *pos, float *costo){
    /*
        Estados de una celda
        *(virgen)
        +(libre)
        -(ocupada)
    */

    int i = hashingRAL(dni);
    int j = 0;
    int libre = 0;
    while(j != M && RAL[i].estado != '*'){
        *costo = *costo + 1;
        if(RAL[i].dat.numDni == dni && RAL[i].estado == '-'){ //Dni igual y celda ocupada
            *pos = i;
            return 1; //El elemento se encuentra en la estructura
        }else{
            if(RAL[i].estado == '+' && libre == 0){
                libre++;
                *pos = i;
            }
            j++;
            i = (i+1) % M;
        }
    }
    if(RAL[i].estado == '*') *costo = *costo + 1;
    if(libre == 1) return 2; //Encontre un lugar libre
    if(j == M) return 0; //El elemento no se encuentra en la lista, estan todas las celdas llenas
    if(libre == 0){ // No encontre libre y pero hay una celda virgen
        *pos = i;
        return 2;
    }
}

int altaRAL(celda RAL[], datosVendedor dat, float *costo){
    if (cantVendedoresRAC == M) return 0; //fracasa por que la estructura esta llena
    float costoAux;
    int aux = localizarRAL(RAL, dat.numDni, &pos, &costoAux);
    if(aux == 1) return 1; //fracasa por que el elemento se encuentra cargado
    if(aux == 0) return 0; //fracasa por que estan todas las celdas llenas

    RAL[pos].estado = '-';
    RAL[pos].dat = dat;
    *costo = 0;

    cantVendedoresRAC++;
    return 2; //Exito
}

int bajaRAL(celda RAL[], datosVendedor dat, float *costo, int opcAux){
    if(cantVendedoresRAC == 0) return 1;
    float costoAux;
    int aux = localizarRAL(RAL, dat.numDni, &pos, &costoAux);
    if(aux == 0) return 0; //Fracasa, el elemento no esta en la lista
    if(aux == 2) return 0;

    if(opcAux == 1){
        if(dat.numDni == RAL[pos].dat.numDni && dat.cantVendido == RAL[pos].dat.cantVendido && dat.montoVendido == RAL[pos].dat.montoVendido && (strcmp(RAL[pos].dat.canalDeVenta, dat.canalDeVenta) == 0) && (strcmp(RAL[pos].dat.nombreApellido, dat.nombreApellido) == 0) && (strcmp(RAL[pos].dat.numTelefono, dat.numTelefono) == 0)){
            opc = 1;
        }else opc = 0;
    }
    if(opc == 0) return 3; //No son iguales los campos
    if(opcAux == 0){
        printf("\n----------------------------");
        printf("\nDni: %d", RAL[pos].dat.numDni);
        printf("\nNombre y Apellido: %s", RAL[pos].dat.nombreApellido);
        printf("\nNumero de telefono: %s", RAL[pos].dat.numTelefono);
        printf("\nMonto vendido: %f", RAL[pos].dat.montoVendido);
        printf("\nCantidad vendida: %d", RAL[pos].dat.cantVendido);
        printf("\nCanal de venta: %s", RAL[pos].dat.canalDeVenta);
        printf("\n----------------------------");

        printf("\nDesea eliminar los datos del vendedor");
        printf("\n<1> Si");
        printf("\n<2> No");
        printf("\n- ");
        scanf("%d", &opc);
        if(opc == 1){
            RAL[pos].estado = '+';
            *costo = 0;
            cantVendedoresRAC--;
        }else return -1;
    }

    RAL[pos].estado = '+';
    *costo = 0;
    cantVendedoresRAC--;

    return 2;
}

int mostrarRAL(celda RAL[]){
    if(cantVendedoresRAC == 0) return 1;
    for(int i = 0; i < M; i++){
        printf("\n-----------------------");
        printf("\nNumero de balde: %d", i);
        if(RAL[i].estado == '-'){
            printf("\nHash: %d", hashingRAL(RAL[i].dat.numDni));
            printf("\nEstado de la celda: [%c] (Ocupada)", RAL[i].estado);
            printf("\nDni: %d", RAL[i].dat.numDni);
            printf("\nNombre y Apellido: %s", RAL[i].dat.nombreApellido);
            printf("\nNumero de telefono: %s", RAL[i].dat.numTelefono);
            printf("\nMonto vendido: %f", RAL[i].dat.montoVendido);
            printf("\nCantidad vendida: %d", RAL[i].dat.cantVendido);
            printf("\nCanal de venta: %s", RAL[i].dat.canalDeVenta);
        }else if(RAL[i].estado == '*') printf("\nEstado de la celda: [%c] (Virgen)", RAL[i].estado);
        else printf("\nEstado de la celda: [%c] (Libre)", RAL[i].estado);
    }
}

datosVendedor evocarRAL(celda RAL[], int numDni, float *costo){
    datosVendedor aux;
    //aux.numDni = 1;
    //if(cantVendedoresRAC == 0) return aux;
    aux.numDni = -1;
    float costoAux;
    int auxOpc = localizarRAL(RAL, numDni, &pos, &costoAux);
    if(auxOpc == 2 || auxOpc == 0){
        *costo = costoAux;
        return aux; //El vendedor no esta cargado
    }else if(auxOpc == 1){
        *costo = costoAux;
        aux.numDni = 1;
        return aux;
        //return RAL[pos].dat;
    }
}

int memorizacionPreviaRAL(celda RAL[], datosVendedor dat, float *costo){
    int auxMemo = 0;
    FILE *fp;
    if((fp = fopen("vendedores.txt","r"))==NULL) return 0;
    else{
        while(!feof(fp)){
            fscanf(fp,"%d %[^\n] %[^\n] %f %d %[^\n]", &dat.numDni, dat.nombreApellido, dat.numTelefono, &dat.montoVendido, &dat.cantVendido, dat.canalDeVenta);
            auxMemo = altaRAL(RAL, dat, &costo);
            if(auxMemo == 0){
                fclose(fp);
                return -1; //Se lleno la estructura
            }else if(auxMemo == 1){
                printf("\nHay un vendedor repetido");
                printf("\nDesea ver el vendedor repetido?");
                printf("\n<1> Si");
                printf("\n<2> No");
                printf("\n- ");
                scanf("%d", &auxMemo);
                if(auxMemo == 1) imprimirRAL(dat);
                system("pause");
                system("cls");
            }
        }
        fclose(fp);
        return 1;
    }
}
