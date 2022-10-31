/*
    Grupo 30 - Corales Alex Nahuel

    "Comparacion de estructuras"

    Altas -->             RAL     RS      ABB     LSO     LSOBB
              MAX.ALTA    0.00    1.00    1.00    159.00  157.50
              MED.ALTA    0.00    1.00    1.00    26.56   25.06

              En altas se puede ver que es mejor el rebalse abierto lineal (RAL) ya que
              no nos cuesta nada.

    Bajas -->                 RAL     RS      ABB     LSO     LSOBB
              MAX.BAJA        0.00    1.00    1.50    135.00  133.50
              MED.BAJA        0.00    1.00    1.25    47.48   45.98

              En bajas se puede ver que es mejor el rebalse abierto lineal (RAL) ya que
              no nos cuesta nada.

    Evocacion exitosa -->                 RAL     RS      ABB     LSO     LSOBB
    y no exitosa          MAX.EVOEX       74.00   6.00    13.00   109.00  7.00
                          MED.EVOEX       3.00    0.80    7.42    44.55   5.66
                          MAX.EVONOEX     78.00   3.00    12.00   71.00   7.00
                          MED.EVONOEX     15.44   1.54    3.34    14.16   6.06

                          En evocacion exitosa y no exitosa se ve que es mejor el rebalse
                          separado (RS).

    Analizando los costos obtenidos por cada estructura, llegue a la conclusion de que la
    mejor estructura es el rebalse separado(RS) por que si bien en altas y bajas es mejor el
    rebalse abierto cuadratico(RAC) pero no por mucho solo un costo mas, y en evocacion
    tanto exitosa como no exitosa es mucho mejor el rebalse separado(RS).

*/

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
