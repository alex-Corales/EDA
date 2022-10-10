#ifndef RAC_H_INCLUDED
#define RAC_H_INCLUDED
#endif // RAC_H_INCLUDED
#include "vendedores.h"
#define M 149 //p= 0.77 -> M = N/p -> M = 110/0.77 -> M = 142.85 -> M = 149.

/*
    Estados de una celda
    *(virgen)
    +(libre)
    -(ocupada)
*/

int *cant = 0;
int pos = 0;
int opc = 0;
char auxDni[20];
char opc1[10];
int aux, num, dni, auxopc;
int posRS;
int exito;

typedef struct{
    char estado;
    datosVendedor dat;
}celda;


void menuRAC(){

    celda RAC[M];
    initRAC(RAC);
    int opc = 0;
    datosVendedor vendedor;
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
            printf("\nIngrese el dni: ");
            fflush(stdin);
            scanf("%d", &vendedor.numDni);
            printf("\nIngrese el nombre y apellido: ");
            fflush(stdin);
            scanf("%s", vendedor.nombreApellido);
            printf("\nIngrese el numero de telefono: ");
            fflush(stdin);
            scanf("%s", vendedor.numTelefono);
            printf("\nIngrese el monto vendido: ");
            fflush(stdin);
            scanf("%f", &vendedor.montoVendido);
            printf("\nIngrese la cantidad vendida: ");
            fflush(stdin);
            scanf("%d", &vendedor.cantVendido);
            printf("\nIngrese el canal de venta: ");
            fflush(stdin);
            scanf("%s", vendedor.canalDeVenta);

            aux = altaRAC(RAC, vendedor);

            if (aux == 1) printf("\nEl vendedor se cargo con exito");
            else printf("\nEl vendedor ya se encuentra cargado");
            printf("\n");
            system("pause");
            system("cls");

            break;
        case 2:
            printf("\nIngrese el dni del vendedor: ");
            scanf("%d", &dni);
            int aux = bajaRAC(RAC, dni);
            if(aux == 1) printf("\nNo hay elementos para dar de baja");
            if(aux == 0) printf("\nEl vendendor no se encuentra cargado en la lista");
            else printf("\nFue dado de baja exitosamente");
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 3:
            /*
            printf("\nIngrese el dni que desea buscar: ");
            scanf("%d", &dni);
            datosVendedor consult = evocarRS(RS, dni, &exito);

            if(exito == 1 || exito == 0) printf("\nNO");
            else imprimir(consult);
            printf("\n");
            system("pause");
            system("cls");
            */
            break;
        case 4:
            mostrarRAC(RAC);
            printf("\n");
            system("pause");
            system("cls");
            break;
            break;
        case 5:
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

int localizarRAC(celda RAC[] ,int dni ,int *pos){
    int i = hashingRAC(dni);
    *pos = i;
    printf("\nHash: %d", i);
    int j = 0;
    int k = 0;
    int libre = 0;
    while(j != M && RAC[i].estado != '*'){
        if(RAC[i].dat.numDni == dni && RAC[i].estado == '-'){
            *pos = i;
            return 1; //El elemento se encuentra en la estructura
        }else if(RAC[i].estado == '+' && libre == 0){
            libre++;
            *pos = i;
        }
        j++;
        k++;
        i = (i+k) % M;
    }
    if(j == M) return 0; //El elemento no se encuentra en la lista
    if(libre == 1) return 2; //Encontre un lugar libre
}

int altaRAC(celda RAC[], datosVendedor dat){
    if (cant == M) return 0; //fracasa por que la estructura esta llena
    int aux = localizarRAC(RAC, dat.numDni, &pos);
    if(aux == 1) return 1; //fracasa por que el elemento se encuentra cargado

    RAC[pos].estado = '-';
    RAC[pos].dat = dat;

    *cant++;
    return 2; //Exito
}

int bajaRAC(celda RAC[], int numDni){
    int aux = localizarRAC(RAC, numDni, &pos);
    if(aux == 0) return 0; //Fracasa, el elemento no esta en la lista

    printf("\n----------------------------");
    printf("\nDni: %d", RAC[pos].dat.numDni);
    printf("\n----------------------------");

    printf("\nDesea eliminar los datos del vendedor");
    printf("\n<1> Si");
    printf("\n<2> No");
    scanf("%d", &opc);
    if(opc == 1){
        RAC[pos].estado = '+';
        *cant--;
    }

}

void mostrarRAC(celda RAC[]){
    for(int i = 0; i < M; i++){
        printf("\n-----------------------");
        printf("\nNumero de balde: %d", i);
        printf("\nEstado: %c", RAC[i].estado);
        printf("\nDni: %d", RAC[i].dat.numDni);
    }
}