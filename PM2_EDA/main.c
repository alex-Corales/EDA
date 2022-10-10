#include <stdio.h>
#include <stdlib.h>
#include "RAC.h"
#include "RS.h"
#include "abb.h"

int main(){

    int opc = 0;
    do{
        printf("------------------------------");
        printf("\nBIENVENIDO AL MENU PRINCIPAL");
        printf("\n------------------------------");
        printf("\n<1> Arbol binario de busque");
        printf("\n<2> Rebalse abierto cuadratico");
        printf("\n<3> Rebalse separado");
        printf("\n<4> Salir");
        printf("\n- ");
        scanf("%d", &opc);

        switch(opc){
        case 1:
            system("cls");
            menuABB();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            menuRAC();
            system("pause");
            break;
        case 3:
            system("cls");
            menuRS();
            system("pause");
            break;
        }
    }while(opc != 4);

}
