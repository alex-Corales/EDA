#ifndef RS_H_INCLUDED
#define RS_H_INCLUDED
#endif // RS_H_INCLUDED
//#include "vendedores.h"
#include "listaEnlazada.h"
#define M 100

datosVendedor evocarRS(lista *, int, int *);
void imprimir(datosVendedor);
int hashingRS(int);
void initRS(lista *);
int localizarRS(lista *, int, int *);
int altaRS(lista *, datosVendedor);

int posRS = 0;
int cantRS = 0;


void menuRS(){

    lista RS[M];
    initRS(RS);
    datosVendedor empleado;
    empleado.numDni = 42125797;
    altaRS(RS, empleado);
    empleado.numDni = 43123517;
    altaRS(RS, empleado);
    empleado.numDni = 49696181;
    altaRS(RS, empleado);

    /*
    int dni = 42;
    int exito;
    datosVendedor temp;
    temp = evocarRS(RS, dni, &exito);
    printf("\nEXITO: %d\n", exito);
    if (exito == 2){
        imprimir(temp);
    }
    */
    mostrarRS(RS);
}

void imprimir(datosVendedor dat){
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

int localizarRS(lista dat[], int dni, int *posRS){

    *posRS = hashingRS(dni);
    printf("\nHASH: %d", *posRS);
    int aux = localizarLista(&dat[*posRS], dni);
    if(aux == 1) return 1; //No hay elementos en la lista
    if(aux == 0) return 0; //El elemento no esta en la lista
    if(aux == 2) return 2; //El elemento esta en la lista
}

int altaRS(lista dat[], datosVendedor empleado){
    //if(cantRS == M) return 0;
    int aux = localizarRS(dat, empleado.numDni, &posRS);
    if(aux == 2) return 0; //No puedo dar de alta por que el elemento ya existe

    altaLista(&dat[posRS], empleado);

    return 1;
}

datosVendedor evocarRS(lista dat[], int dni, int *exito){
    datosVendedor temp;
    *exito = localizarRS(dat, dni, &posRS);
    return evocarLista(dat[posRS]);
}

int bajaRS(){

}

void mostrarRS(lista dat[]){
    for(int i = 0; i < M; i++){
        printf("\nBalde N°: %d: ", i);
        mostrarLVD(dat[i]);
    }
}

void mostrarLVD(lista dat){
    isEmpty(dat);
    reset(&dat);
    while(isOos(dat) != 1){
        imprimir(evocarLista(dat));
        forwardlist(&dat);
    }
}






