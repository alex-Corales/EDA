/*
    Grupo 30
    Corales Alex Nahuel
    alexcorales21@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#define MAX 111
#define MAXLSOBT 110

int main(){
    char opc1[10];
    int opc = 0;
    int masInfinito = 100000000;
    vendedorLSO[0].numDni = masInfinito;

    do{
        printf("<1> Lista Secuencial Ordenada con terminacion por contenido (LSO)\n");
        printf("<2> Lista Secuencial Ordenada - Busqueda Binaria (LSOBT)\n");
        printf("<3> Salir\n");
        printf("- ");
        do{
            scanf("%s", opc1);
            auxopc = controlIngresoNum(opc1);
        }while(auxopc==0);
        opc = atoi(opc1);
        system("cls");

        switch(opc){
        case 1:
            listaSecuencialOrdenadaConTerminacionPorContenido();
            break;
        case 2:
            listaSecuencialOrdenadaBusquedaBinaria();
            break;
        case 256: //Ver la posicion del mas infinito.
            mas_Infinito(vendedorLSO);
        }

    }while (opc != 3);

    return 0;
}
