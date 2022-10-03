#ifndef RAL_H_INCLUDED
#define RAL_H_INCLUDED
#endif // RAL_H_INCLUDED
#include "vendedor.h"
#define M 149 //p= 0.77 -> M = N/p -> M = 110/0.77 -> M = 142.85 -> M = 149.

int *pos = 0;

/*
    Estados de una celda
    *(virgen)
    +(libre)
    -(ocupada)
*/

typedef struct{
    char estado;
    datosVendedor dat;
}celda;

void rebalseAbiertoLineal(){

    int h, x;
    celda RAL[M];
    init(RAL);
    mostrar(RAL);
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

void mostrar(celda RAL[]){
    for(int i = 0; i < M; i++) printf("\n%d - %c", i+1, RAL[i].estado);
}

void init(celda RAL[]){
    for(int i = 0; i < M; i++) RAL[i].estado= '*';
}

int localizar(celda RAL[] ,int dni ,int *pos){
    int i = hashing(dni);
    int j = 0;
    while(j != M && RAL[i].estado != '*'){
        if(RAL[i].dat.numDni == dni){
            *pos = i;
            return 1;
        }
        j++;
        i++;
    }
}

int alta(celda RAL[],), char nombreApellido[], int numDni, char numTelefono[], float montoVendido, int cantVendido, char canalDeVenta[]){

}














