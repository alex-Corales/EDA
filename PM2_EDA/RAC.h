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

typedef struct{
    char estado;
    datosVendedor dat;
}celda;


void menuRAC(){

    celda RAC[M];
    initRAC(RAC);
    altaRAC(RAC,1);
    altaRAC(RAC,2);
    altaRAC(RAC,3);
    altaRAC(RAC,4);
    altaRAC(RAC,5);
    altaRAC(RAC,6);
    altaRAC(RAC,16);
    printf("\n");
    system("pause");
    mostrarRAC(RAC);
    bajaRAC(RAC, 1);
    mostrarRAC(RAC);
    return 0;
}

int hashing(int dni){
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
    int i = hashing(dni);
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

int altaRAC(celda RAC[], int numDni){
    if (cant == M) return 0; //fracasa por que la estructura esta llena
    int aux = localizarRAC(RAC,numDni,&pos);
    if(aux == 1) return 1; //fracasa por que el elemento se encuentra cargado

    RAC[pos].estado = '-';
    RAC[pos].dat.numDni = numDni;

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
