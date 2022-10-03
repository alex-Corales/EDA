/*
    Grupo 30
    Corales Alex Nahuel
    alexcorales21@gmail.com
*/

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#endif // FUNCIONES_H_INCLUDED
#include <string.h>
#include <stdlib.h>


int lsLSOBT = -1;
int posLSOBT = 0;

void imprimirVendedorLSOBT(datosVendedor dat){
    system("cls");
    printf("\n------------------------------");
    printf("\nNombre y Apellido: %s", dat.nombreApellido);
    printf("\nDni: %d", dat.numDni);
    printf("\nNumero de telefono: %s", dat.numTelefono);
    printf("\nMonto vendido: %f", dat.montoVendido);
    printf("\nCantidad vendida: %d", dat.cantVendido);
    printf("\nCanal de venta: %s", dat.canalDeVenta);
    printf("\n------------------------------\n");
}

int corrimientoElementosAgregandoLSOBT(datosVendedor dat[], int pos){
    int i = 0;
    int j = lsLSOBT;

    for(i = lsLSOBT; i >= pos; i--)
    {
        dat[i+1] = dat[i];
    }

    return j + 1;
}

int corrimientoElementoEliminandoLSOBT(datosVendedor dat[], int pos){
    int i = 0;
    int j = lsLSOBT;

    for(i = pos; i < lsLSOBT; i++)
    {
        dat[i] = dat[i+1];
    }

    return j - 1;

}

int localizarLSOBT(datosVendedor arreglo[], int busqueda, int ls, int *posLSOBT){

    int li = -1;

    while (li <= ls){
        int m = (li + ls) / 2;
        if (busqueda == arreglo[m].numDni){
            *posLSOBT = m;
            return 1;
        }
        if (busqueda < arreglo[m].numDni) ls = m-1;
        else li = m+1;
    }
    return -1;
}

int altaLSOBT(datosVendedor dat[], char nombreApellido[], int numDni, char numTelefono[], float montoVendido, int cantVendido, char canalDeVenta[]){

    if(localizarLSOBT(dat,numDni,lsLSOBT,&posLSOBT)==1) return 0;
    if(lsLSOBT == 109) return -1;
    int i = 0;

    if(lsLSOBT!=-1){ //si lsLSOBT es igual a -1, el arreglo esta vacio
        if(dat[lsLSOBT].numDni < numDni){
            dat[lsLSOBT+1].numDni = numDni;
            strcpy(dat[lsLSOBT+1].nombreApellido, nombreApellido);
            strcpy(dat[lsLSOBT+1].numTelefono, numTelefono);
            dat[lsLSOBT+1].montoVendido = montoVendido;
            dat[lsLSOBT+1].cantVendido = cantVendido;
            strcpy(dat[lsLSOBT+1].canalDeVenta, canalDeVenta);
            lsLSOBT++;
        }
        else{
            while(dat[i].numDni < numDni) i++;
            lsLSOBT = corrimientoElementosAgregandoLSOBT(dat, i);
            dat[i].numDni = numDni;
            strcpy(dat[i].nombreApellido, nombreApellido);
            strcpy(dat[i].numTelefono, numTelefono);
            dat[i].montoVendido = montoVendido;
            dat[i].cantVendido = cantVendido;
            strcpy(dat[i].canalDeVenta, canalDeVenta);
        }

    }
    else{
        dat[i].numDni = numDni;
        strcpy(dat[i].nombreApellido, nombreApellido);
        strcpy(dat[i].numTelefono, numTelefono);
        dat[i].montoVendido = montoVendido;
        dat[i].cantVendido = cantVendido;
        strcpy(dat[i].canalDeVenta, canalDeVenta);
        lsLSOBT++;
    }

    return 1;
}// ingreso de nuevos vendedores

int bajaLSOBT(datosVendedor dat[], int dni){
    int auxopc = 0, opc = 0;
    char opc1[10];
    if(localizarLSOBT(dat, dni, lsLSOBT,&posLSOBT) == -1) return -1;

    printf("------------------------------\n");
    printf("Nombre y Apellido: %s\n", dat[posLSOBT].nombreApellido);
    printf("Dni: %d\n", dat[posLSOBT].numDni);
    printf("Numero de telefono: %s\n", dat[posLSOBT].numTelefono);
    printf("Monto vendido: %f\n", dat[posLSOBT].montoVendido);
    printf("Cantidad vendida: %d\n", dat[posLSOBT].cantVendido);
    printf("Canal de venta: %s\n", dat[posLSOBT].canalDeVenta);
    printf("------------------------------\n");

    printf("¿Desea eliminar los datos del vendedor?\n");
    printf("<1> Si\n");
    printf("<2> No\n");
    printf("- ");
    do{
        scanf("%s", opc1);
        auxopc = controlIngresoNum(opc1);
    }while(auxopc==0 && atoi(opc1) != 1 && atoi(opc1) != 2);
    opc = atoi(opc1);

    if(opc == 1){
        lsLSOBT = corrimientoElementoEliminandoLSOBT(dat, posLSOBT);
        return 1;
    }

} //eliminacion de vendedores existentes

datosVendedor evocarLSOBT(datosVendedor dat [], int numDni){
    datosVendedor aux;
    aux.numDni = -1;
    if(localizarLSOBT(dat, numDni, lsLSOBT, &posLSOBT)==-1) return aux;

    return dat[posLSOBT];

} //consulta de vendedores

void mostrarEstruturaLSOBT(datosVendedor dat[]){
    if(lsLSOBT == -1) printf("\nNo hay vendedores cargados en el sistema\n");
    for(int i = 0; i <= lsLSOBT; i++){
        printf("\n------------------------------");
        printf("\nNombre y Apellido: %s", dat[i].nombreApellido);
        printf("\nDni: %d", dat[i].numDni);
        printf("\nNumero de telefono: %s", dat[i].numTelefono);
        printf("\nMonto vendido: %f", dat[i].montoVendido);
        printf("\nCantidad vendida: %d", dat[i].cantVendido);
        printf("\nCanal de venta: %s", dat[i].canalDeVenta);
    }

} //mostrar estructura

int perteneceLSOBT(datosVendedor dat[], int dni){
    int aux = localizarLSOBT(dat, dni,lsLSOBT,&pos);
    if(aux == 1) return 1;
    else return -1;
}

int memorizacionPreviaLSOBT(datosVendedor dat []){

    char nombreApellido[50];
    int numDni;
    char numTelefono[15];
    float montoVendido;
    int cantVendido;
    char canalDeVenta[20];
    int i = 0;

    FILE *fp;

    if((fp = fopen("vendedores.txt","r"))==NULL) return 0;
    else{
        while(!feof(fp)){
            if(lsLSOBT == 109) return -1;
            fscanf(fp,"%d %[^\n] %[^\n] %f %d %[^\n]", &numDni, nombreApellido, numTelefono, &montoVendido, &cantVendido, canalDeVenta);

            if(localizarLSOBT(dat,numDni,lsLSOBT,&pos)!=1){
                altaLSOBT(dat, nombreApellido,numDni,numTelefono,montoVendido,cantVendido,canalDeVenta);
            }
        }
        return 1;
    }
    fclose(fp);
} //Guarda los datos del archivo
