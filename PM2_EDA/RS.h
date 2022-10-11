#ifndef RS_H_INCLUDED
#define RS_H_INCLUDED
#endif // RS_H_INCLUDED
#include "controles.h"
#include "listaEnlazada.h"
#define M 61 //p= 1.84 -> M = N/p -> M = 110/1.84 -> M = 59.78 -> M = 61.

int cantRS;
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
            aux = memorizacionPreviaRS(RS,vendedor);
            if (aux != 0) printf("\nSe cargo el archivo con exito");
            else printf("\nHubo un problema al leer el archivo vendedores.txt");
            printf("\n");
            system("pause");
            system("cls");
            break;
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

int localizarRS(lista dat[], int dni, int *posRS){
    *posRS = hashingRS(dni);
    int aux = localizarLista(&dat[*posRS], dni);
    if(aux == 1) return 1; //No hay elementos en la lista
    if(aux == 0) return 0; //El elemento no esta en la lista
    if(aux == 2) return 2; //El elemento esta en la lista
}

int altaRS(lista dat[], datosVendedor empleado){
    if(cantRS == 110) return 0;
    aux = localizarRS(dat, empleado.numDni, &posRS);
    if(aux == 2) return 0; //No puedo dar de alta por que el elemento ya existe

    altaLista(&dat[posRS], empleado);
    cantRS++;
    return 1;
}

int bajaRS(lista dat[], int dni){
    int aux = localizarRS(dat, dni, &posRS);
    if(aux == 1) return 1; //No hay elementos en la lista
    if(aux == 0) return 0; //El elemento no esta en la lista

    bajaLista(&dat[posRS], dni);
    cantRS--;
    return 2;
}

datosVendedor evocarRS(lista dat[], int dni){
    datosVendedor aux;
    aux.numDni = -1;
    return temp;
}

int perteneceRS(lista dat[], int dni){
    if(localizarRS(dat, dni, &posRS) == 2) return 1; //El vendedor esta cargado
}

void mostrarRS(lista dat[]){
    for(int i = 0; i < M; i++){
        printf("\nBalde N: %d", i);
        mostrarLista(dat[i]);
    }
}

int memorizacionPreviaRS(lista dat[], datosVendedor empleado){
    FILE *fp;
    if((fp = fopen("vendedores.txt","r"))==NULL) return 0;
    else{
        while(!feof(fp)){
            fscanf(fp,"%d %[^\n] %[^\n] %f %d %[^\n]", &empleado.numDni, empleado.nombreApellido, empleado.numTelefono, &empleado.montoVendido, &empleado.cantVendido, empleado.canalDeVenta);
            altaRS(dat, empleado);
        }
        return 1;
    }
    fclose(fp);
}





