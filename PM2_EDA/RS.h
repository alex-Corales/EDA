#ifndef RS_H_INCLUDED
#define RS_H_INCLUDED
#endif // RS_H_INCLUDED
#include "controles.h"
#include "listaEnlazada.h"
#define M 100


char auxDni[20];
char opc1[10];
int aux, num, dni, auxopc;
int posRS;
int exito;

void menuRS(){

    int opc = 0;
    datosVendedor vendedor;
    lista RS[M];
    initRS(RS);
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

            aux = altaRS(RS, vendedor);

            if (aux == 1) printf("\nEl vendedor se cargo con exito");
            else printf("\nEl vendedor ya se encuentra cargado");
            printf("\n");
            system("pause");
            system("cls");

            break;
        case 2:
            printf("\nIngrese el dni del vendedor: ");
            scanf("%d", &dni);
            int aux = bajaRS(RS, dni);
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
            mostrarRS(RS);
            printf("\n");
            system("pause");
            system("cls");
            break;
            break;
        case 5:
            break;
        }

    }while(opc != 6);
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
    int aux = localizarLista(&dat[*posRS], dni);
    if(aux == 1) return 1; //No hay elementos en la lista
    if(aux == 0) return 0; //El elemento no esta en la lista
    if(aux == 2) return 2; //El elemento esta en la lista
}

int altaRS(lista dat[], datosVendedor empleado){
    //if(cantRS == M) return 0;
    aux = localizarRS(dat, empleado.numDni, &posRS);
    if(aux == 2) return 0; //No puedo dar de alta por que el elemento ya existe

    altaLista(&dat[posRS], empleado);

    return 1;
}

int bajaRS(lista dat[], int dni){
    int aux = localizarRS(dat, dni, &posRS);
    if(aux == 1) return 1; //No hay elementos en la lista
    if(aux == 0) return 0; //El elemento no esta en la lista

    bajaLista(&dat[posRS], dni);
    return 2;
}

datosVendedor evocarRS(lista dat[], int dni, int *exito){
    datosVendedor temp;
    *exito = localizarRS(dat, dni, &posRS);
    return temp;
}

void mostrarRS(lista dat[]){
    for(int i = 0; i < M; i++){
        printf("\nBalde N: %d", i);
        mostrarLista(dat[i]);
    }
}







