/*
    Grupo 30
    Corales Alex Nahuel
    alexcorales21@gmail.com
*/

#ifndef RAC_H_INCLUDED
#define RAC_H_INCLUDED
#endif // RAC_H_INCLUDED
#include "vendedores.h"
#define M 149 //p= 0.77 -> M = N/p -> M = 110/0.77 -> M = 142.85 -> M = 149.

typedef struct{
    char estado;
    datosVendedor dat;
}celda;

/*
    PROTOTIPOS
*/

datosVendedor evocarRAC(celda *, int);
int localizarRAC(celda *, int, int *);
int altaRAC(celda *, datosVendedor);
int bajaRAC(celda *, int);
int perteneceRAC(celda *, int);
int memorizacionPreviaRAC(celda *, datosVendedor);
int mostrarRAC(celda *);
int hashingRAC(int);
void imprimirRAC(datosVendedor);
void initRAC(celda *);

/*
    VARIABLES
*/

int opcAuxRAC = 0;
int cantVendido;
int cantVendedoresRAC = 0;
int dni = 0;
int pos = 0;
int auxopc = 0;
int opc = 0;
int num = 0;
int aux = 0;
int posRS;
int exito;
char auxS[50];
char opc1[10];
celda RAC[M];
datosVendedor vendedorRAC;

void menuRAC(){

    if(opcAuxRAC == 0){initRAC(RAC); opcAuxRAC++;}
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

            aux = altaRAC(RAC, vendedorRAC);
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
            int aux = bajaRAC(RAC, dni);
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
            datosVendedor consult = evocarRAC(RAC, dni);
            if(consult.numDni == -1) printf("\nEl vendedor no esta cargado");
            else if(consult.numDni == 1) printf("\nNo hay vendedores cargados");
            else imprimirRAC(consult);
            printf("\n");
            system("pause");
            system("cls");

            break;
        case 4:
            aux = mostrarRAC(RAC);
            if(aux == 1) printf("\nNo hay vendedores cargados");
            printf("\n");
            system("pause");
            system("cls");
            break;
            break;
        case 5:
            aux = memorizacionPreviaRAC(RAC, vendedorRAC);
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

int hashingRAC(int dni){
    char x[8];
    int longitud, i;
    int contador = 0;
    sprintf(x,"%d",dni);
    longitud = strlen(x);
    for(i = 0; i < longitud; i++) contador+= ((int)x[i]) * (i+1);
    return (contador % M);
}

void initRAC(celda RAC[]){
    for(int i = 0; i < M; i++){
        RAC[i].estado = '*';
        RAC[i].dat.numDni = 0;
    }
}

void imprimirRAC(datosVendedor dat){
    printf("\n------------------------------");
    printf("\nNombre y Apellido: %s", dat.nombreApellido);
    printf("\nDni: %d", dat.numDni);
    printf("\nNumero de telefono: %s", dat.numTelefono);
    printf("\nMonto vendido: %f", dat.montoVendido);
    printf("\nCantidad vendida: %d", dat.cantVendido);
    printf("\nCanal de venta: %s", dat.canalDeVenta);
    printf("\n------------------------------\n");
}

int localizarRAC(celda RAC[] ,int dni ,int *pos){
    /*
        Estados de una celda
        *(virgen)
        +(libre)
        -(ocupada)
    */

    int i = hashingRAC(dni);
    int j = 0;
    int k = 0;
    int libre = 0;
    while(j != M && RAC[i].estado != '*'){
        if(RAC[i].dat.numDni == dni && RAC[i].estado == '-'){ //Dni igual y celda ocupada
            *pos = i;
            return 1; //El elemento se encuentra en la estructura
        }else{
            if(RAC[i].estado == '+' && libre == 0){
                libre++;
                *pos = i;
            }
            j++;
            k++;
            i = (i+k) % M;
        }
    }
    if(j == M) return 0; //El elemento no se encuentra en la lista, estan todas las celdas llenas
    if(libre == 1) return 2; //Encontre un lugar libre
    if(libre == 0){ // No encontre libre y pero hay una celda virgen
        *pos = i;
        return 2;
    }
}

int altaRAC(celda RAC[], datosVendedor dat){
    if (cantVendedoresRAC == 110) return 0; //fracasa por que la estructura esta llena
    int aux = localizarRAC(RAC, dat.numDni, &pos);
    if(aux == 1) return 1; //fracasa por que el elemento se encuentra cargado
    if(aux == 0) return 0; //fracasa por que estan todas las celdas llenas

    RAC[pos].estado = '-';
    RAC[pos].dat = dat;

    cantVendedoresRAC++;
    return 2; //Exito
}

int bajaRAC(celda RAC[], int numDni){
    if(cantVendedoresRAC == 0) return 1;
    int aux = localizarRAC(RAC, numDni, &pos);
    if(aux == 0) return 0; //Fracasa, el elemento no esta en la lista

    printf("\n----------------------------");
    printf("\nDni: %d", RAC[pos].dat.numDni);
    printf("\nNombre y Apellido: %s", RAC[pos].dat.nombreApellido);
    printf("\nNumero de telefono: %s", RAC[pos].dat.numTelefono);
    printf("\nMonto vendido: %f", RAC[pos].dat.montoVendido);
    printf("\nCantidad vendida: %d", RAC[pos].dat.cantVendido);
    printf("\nCanal de venta: %s", RAC[pos].dat.canalDeVenta);
    printf("\n----------------------------");

    printf("\nDesea eliminar los datos del vendedor");
    printf("\n<1> Si");
    printf("\n<2> No");
    printf("\n- ");
    scanf("%d", &opc);
    if(opc == 1){
        RAC[pos].estado = '+';
        cantVendedoresRAC--;
    }else return -1;

    return 2;
}

int mostrarRAC(celda RAC[]){
    if(cantVendedoresRAC == 0) return 1;
    int j = 0;
    for(int i = 0; i < M; i++){
        printf("\n-----------------------");
        printf("\nNumero de balde: %d", i);
        if(RAC[i].estado == '-'){
            printf("\nEstado de la celda: [%c] (Ocupada)", RAC[i].estado);
            printf("\nDni: %d", RAC[i].dat.numDni);
            printf("\nNombre y Apellido: %s", RAC[i].dat.nombreApellido);
            printf("\nNumero de telefono: %s", RAC[i].dat.numTelefono);
            printf("\nMonto vendido: %f", RAC[i].dat.montoVendido);
            printf("\nCantidad vendida: %d", RAC[i].dat.cantVendido);
            printf("\nCanal de venta: %s", RAC[i].dat.canalDeVenta);
        }else if(RAC[i].estado == '*') printf("\nEstado de la celda: [%c] (Virgen)", RAC[i].estado);
        else printf("\nEstado de la celda: [%c] (Libre)", RAC[i].estado);
        if(j == 10){
            printf("\n");
            system("pause");
            printf("\n");
            j = 0;
        }
        j++;
    }
}

datosVendedor evocarRAC(celda RAC[], int numDni){
    datosVendedor aux;
    aux.numDni = 1;
    if(cantVendedoresRAC == 0) return aux;
    aux.numDni = -1;
    if(localizarRAC(RAC,numDni,&pos) != 1) return aux; //El vendedor no esta cargado
    return RAC[pos].dat;
}

int memorizacionPreviaRAC(celda RAC[], datosVendedor dat){
    int auxMemo = 0;
    FILE *fp;
    if((fp = fopen("vendedores.txt","r"))==NULL) return 0;
    else{
        while(!feof(fp)){
            fscanf(fp,"%d %[^\n] %[^\n] %f %d %[^\n]", &dat.numDni, dat.nombreApellido, dat.numTelefono, &dat.montoVendido, &dat.cantVendido, dat.canalDeVenta);
            auxMemo = altaRAC(RAC, dat);
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
                if(auxMemo == 1) imprimirRAC(dat);
                system("pause");
                system("cls");
            }
        }
        fclose(fp);
        return 1;
    }
}
