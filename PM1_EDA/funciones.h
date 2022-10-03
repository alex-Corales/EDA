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

/*
    ls contiene la posicion del mas infinito y se actualiza en cada corrimiento, se incrementa una posicion si se
    agregan elementos y decrementa cuando se da de baja un elemento.
    En la funcion main.c se inicializa el array con el mas infinito en la primer posicion.

*/

int ls = 0;
int pos = 0;

void imprimirVendedorLSO(datosVendedor dat){
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

int corrimientoElementosAgregando(datosVendedor dat[], int *pos, int posMasInfinito){
    int i = 0;
    int j = posMasInfinito;

    for(i = posMasInfinito; i >= *pos; i--)
    {
        dat[i+1] = dat[i];
    }

    return j + 1;
}

int corrimientoElementoEliminando(datosVendedor dat[], int *pos, int posMasInfinito){
    int i = 0;
    int j = posMasInfinito;

    for(i = *pos; i < posMasInfinito; i++)
    {
        dat[i] = dat[i+1];
    }

    return j - 1;

}

int altaLSO(datosVendedor dat[], char nombreApellido[], int numDni, char numTelefono[], float montoVendido, int cantVendido, char canalDeVenta[]){

    if(ls == 110) return -1;
    int i = 0;
    int aux = localizarLSO(dat,numDni,&pos);
    if(aux == 1) return 0;

    ls = corrimientoElementosAgregando(dat, &pos, ls);

    dat[pos].numDni = numDni;
    strcpy(dat[pos].nombreApellido, nombreApellido);
    strcpy(dat[pos].numTelefono, numTelefono);
    dat[pos].montoVendido = montoVendido;
    dat[pos].cantVendido = cantVendido;
    strcpy(dat[pos].canalDeVenta, canalDeVenta);

    return 1;
}// ingreso de nuevos vendedores

int bajaLSO(datosVendedor dat[], int dni){

    int i = 0, auxopc = 0, opc = 0;
    char opc1[10];
    int aux = localizarLSO(dat, dni, &pos);
    if (aux != 1) return -1;

    printf("------------------------------\n");
    printf("Nombre y Apellido: %s\n", dat[pos].nombreApellido);
    printf("Dni: %d\n", dat[pos].numDni);
    printf("Numero de telefono: %s\n", dat[pos].numTelefono);
    printf("Monto vendido: %f\n", dat[pos].montoVendido);
    printf("Cantidad vendida: %d\n", dat[pos].cantVendido);
    printf("Canal de venta: %s\n", dat[pos].canalDeVenta);
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
        ls = corrimientoElementoEliminando(dat, &pos, ls);
        return 1;
    }

} //eliminacion de vendedores existentes

int localizarLSO(datosVendedor dat[], int numDni, int *pos){
    int i = 0;
    while(dat[i].numDni < numDni) i++;

    if (dat[i].numDni == numDni){
        *pos = i;
        return 1;
    }else{
        *pos = i;
        return -1;
    }

} //determinar si un vendedor esta presente en el registro

datosVendedor evocarLSO(datosVendedor dat [], int numDni){
    datosVendedor aux;
    aux.numDni = -1;
    if (localizarLSO(dat, numDni, &pos) == -1) return aux;
    return dat[pos];

} //consulta de vendedores

int perteneceLSO(datosVendedor dat[], int dni, int masInfinito){
    int aux = (localizarLSO(dat, dni, &pos) && dat[pos].numDni != masInfinito);
    if(aux == 1) return 1;
    else return -1;
}

void mostrarEstrutura(datosVendedor dat[]){

    if (ls == 0) printf("\nNo hay vendedores cargados en el sistema\n");
    for(int i = 0; i < ls; i++){
        printf("\n------------------------------");
        printf("\nNombre y Apellido: %s", dat[i].nombreApellido);
        printf("\nDni: %d", dat[i].numDni);
        printf("\nNumero de telefono: %s", dat[i].numTelefono);
        printf("\nMonto vendido: %f", dat[i].montoVendido);
        printf("\nCantidad vendida: %d", dat[i].cantVendido);
        printf("\nCanal de venta: %s", dat[i].canalDeVenta);
    }
} //mostrar estructura

int memorizacionPrevia(datosVendedor dat []){

    int aux;
    char nombreApellido[50];
    int numDni;
    char numTelefono[15];
    float montoVendido;
    int cantVendido;
    char canalDeVenta[20];
    int i = 0;

    FILE *fp;

    if((fp = fopen("vendedores.txt","r"))==NULL)
        return 0;
    else
    {
        while(!feof(fp))
        {
            if(ls == 110) return -1;

            fscanf(fp,"%d %[^\n] %[^\n] %f %d %[^\n]", &numDni, nombreApellido, numTelefono, &montoVendido, &cantVendido, canalDeVenta);

            if(localizarLSO(dat, numDni, &pos)!=1){
                altaLSO(dat,nombreApellido,numDni,numTelefono,montoVendido,cantVendido,canalDeVenta);
            }
        }
        return 1;
    }
    fclose(fp);
} //Guarda los datos del archivo

void mas_Infinito(datosVendedor dat[]){ //En el menu principal ingresar el 256 para ver la posicion del mas infinito.
    printf("\nMas infinito: %d", dat[ls].numDni);
    printf("\nPosicion mas infinito: %d\n", ls);
    system("pause");
    system("cls");
}

