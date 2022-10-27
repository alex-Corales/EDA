#include <stdio.h>
#include <stdlib.h>
#include "comEstructuras.h"


int main(){
    system("color f");
    int opc = 0;

    do{
        printf("------------------------------");
        printf("\nBIENVENIDO AL MENU PRINCIPAL");
        printf("\n------------------------------");
        printf("\n<1> Comparacion de estructuras");
        printf("\n<2> Estructuras");
        printf("\n<3> Salir");
        printf("\n- ");
        scanf("%d", &opc);

        switch(opc){
        case 1:
            system("cls");
            int aux = comparacionEstructuras();
            if(aux == 1) printf("\nHubo un problema\n");
            system("cls");
            break;
        case 2:
            do{
                system("cls");
                printf("------------------------------");
                printf("\nBIENVENIDO AL MENU DE ESTRUCTURAS");
                printf("\n------------------------------");
                printf("\n<1> Arbol binario de busqueda");
                printf("\n<2> Rebalse abierto lineal");
                printf("\n<3> Rebalse separado");
                printf("\n<4> Lista secuencial ordenada con terminacion por contenido");
                printf("\n<5> Lista secuencial ordenada con busqueda binaria");
                printf("\n<6> Salir");
                printf("\n- ");
                scanf("%d", &opc);

                switch(opc){
                case 1:
                    system("cls");
                    preOrdenHijos(raiz);
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    mostrarRAL(RAL);
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    mostrarRS(RS);
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    mostrarEstrutura(LSO);
                    system("pause");
                    system("cls");
                    break;
                case 5:
                    system("cls");
                    mostrarEstruturaLSOBT(LSOBB);
                    system("pause");
                    system("cls");
                    break;
                }
            }while(opc != 6);
            break;

        }
    }while(opc != 3);



}
