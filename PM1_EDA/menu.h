/*
    Grupo 30
    Corales Alex Nahuel
    alexcorales21@gmail.com
*/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#endif // MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "vendedor.h"
#include "funciones.h"
#include "funcionesLSOBT.h"
#include "controles.h"
#define MAX 111
#define MAXLSOBT 110

datosVendedor vendedorLSO[MAX]; //Lista Secuencial Ordenada con terminacion por contenido
datosVendedor vendedorLSOBT[MAXLSOBT]; //Lista Secuencial Ordenada - Busqueda Binaria

char auxDni[20];
char opc1[10];
int opc = 0;
int aux, num, dni, auxopc;
char nombreApellido[50];
char numeroTelefono[15];
float montoVendido;
int cantVendido;
char canalDeVenta[20];
int masInfinito = 100000000;


void listaSecuencialOrdenadaConTerminacionPorContenido(void){

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
            do{
                scanf("%s", auxDni);
                auxopc = controlIngresoNum(auxDni);
            }while(auxopc==0);
            dni = atoi(auxDni);

            printf("\nIngrese el nombre y apellido: ");
            do{
                getchar();
                gets(nombreApellido);
                num=controlIngresoLetras(nombreApellido);
            }while(num==0);

            printf("\nIngrese el numero de telefono: ");
            do{
                getchar();
                gets(numeroTelefono);
                num=controlIngresoLetrasNumero(numeroTelefono);
            }while(num==0);

            printf("\nIngrese el monto vendido: ");
            do{
                scanf("%s", opc1);
                auxopc = controlIngresoNum(opc1);
            }while(auxopc==0);
            montoVendido = atoi(opc1);

            printf("\nIngrese la cantidad vendida: ");
            do{
                scanf("%s", opc1);
                auxopc = controlIngresoNum(opc1);
            }while(auxopc==0);
            cantVendido = atoi(opc1);

            printf("\nIngrese el canal de venta: ");
            do{
                getchar();
                gets(canalDeVenta);
                num=controlIngresoLetras(canalDeVenta);
            }while(num==0);

            aux = altaLSO(vendedorLSO, nombreApellido, dni, numeroTelefono, montoVendido, cantVendido, canalDeVenta);

            if (aux == 1) printf("\nEl vendedor se cargo con exito");
            else if (aux == -1)printf("\nNo hay mas espacio para cargar el vendedor");
            else printf("\nEl vendedor ya se encuentra cargado");
            printf("\n");
            system("pause");
            system("cls");

            break;
        case 2:
            fflush(stdin);
            int auxs;
            printf("\nIngrese el dni: ");
            do{
                scanf("%s", auxDni);
                auxopc = controlIngresoNum(auxDni);
            }while(auxopc==0);
            dni = atoi(auxDni);

            auxs = bajaLSO(vendedorLSO, dni);
            if(auxs == 1) printf("\nEl vendedor se elimino con exito");
            else if (auxs == -1)printf("\nEl vendedor no se encuentra cargado en el sistema");
            else printf("\nEl vendedor no se elimino");
            printf("\n");
            system("pause");
            system("cls");


            break;
        case 3:
            printf("\nIngrese el dni que desea buscar: ");
            do{
                scanf("%s", auxDni);
                auxopc = controlIngresoNum(auxDni);
            }while(auxopc==0);
            dni = atoi(auxDni);

            datosVendedor consult = evocarLSO(vendedorLSO, dni);

            if(consult.numDni == -1)printf("\nEl vendedor no se encuentra cargado");
            else imprimirVendedorLSO(consult);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 4:
            mostrarEstrutura(vendedorLSO);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 5:
            aux = memorizacionPrevia(vendedorLSO);
            if (aux != 0) printf("\nSe cargo el archivo con exito");
            else printf("\nHubo un problema al leer el archivo vendedores.txt");
            printf("\n");
            system("pause");
            system("cls");
            break;
        }

    }while(opc != 6);
}

void listaSecuencialOrdenadaBusquedaBinaria(void){
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
            do{
                scanf("%s", auxDni);
                auxopc = controlIngresoNum(auxDni);
            }while(auxopc==0);
            dni = atoi(auxDni);

            printf("\nIngrese el nombre y apellido: ");
            do{
                getchar();
                gets(nombreApellido);
                num=controlIngresoLetras(nombreApellido);
            }while(num==0);

            printf("\nIngrese el numero de telefono: ");
            do{
                getchar();
                gets(numeroTelefono);
                num=controlIngresoLetrasNumero(numeroTelefono);
            }while(num==0);

            printf("\nIngrese el monto vendido: ");
            do{
                scanf("%s", opc1);
                auxopc = controlIngresoNum(opc1);
            }while(auxopc==0);
            montoVendido = atoi(opc1);

            printf("\nIngrese la cantidad vendida: ");
            do{
                scanf("%s", opc1);
                auxopc = controlIngresoNum(opc1);
            }while(auxopc==0);
            cantVendido = atoi(opc1);

            printf("\nIngrese el canal de venta: ");
            do{
                getchar();
                gets(canalDeVenta);
                num=controlIngresoLetras(canalDeVenta);
            }while(num==0);

            aux = altaLSOBT(vendedorLSOBT, nombreApellido, dni, numeroTelefono, montoVendido, cantVendido, canalDeVenta);

            if(aux == 1) printf("\nEl vendedor se cargo con exito");
            else if(aux == -1) printf("\nNo se pueden cargar mas vendedores por falta de espacio en la estructura");
            else printf("\nEl vendedor ya se encuentra cargado");
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 2:
            fflush(stdin);
            int auxs;
            printf("\nIngrese el dni: ");
            do{
                scanf("%s", auxDni);
                auxopc = controlIngresoNum(auxDni);
            }while(auxopc==0);
            dni = atoi(auxDni);

            auxs = bajaLSOBT(vendedorLSOBT, dni);
            if(auxs == 1) printf("\nEl vendedor se elimino con exito");
            else if (auxs == -1)printf("\nEl vendedor no se encuentra cargado en el sistema");
            else printf("\nEl vendedor no se elimino");
            printf("\n");
            system("pause");
            system("cls");

            break;
        case 3:
            printf("\nIngrese el dni que desea buscar: ");
            do{
                scanf("%s", auxDni);
                auxopc = controlIngresoNum(auxDni);
            }while(auxopc==0);
            dni = atoi(auxDni);

            datosVendedor consult = evocarLSOBT(vendedorLSOBT, dni);

            if(consult.numDni == -1)printf("\nEl vendedor no se encuentra cargado");
            else imprimirVendedorLSOBT(consult);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 4:
            mostrarEstruturaLSOBT(vendedorLSOBT);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 5:
            aux = memorizacionPreviaLSOBT(vendedorLSOBT);
            if (aux != 0) printf("\nSe cargo el archivo con exito");
            else printf("\nHubo un problema al leer el archivo vendedores.txt");
            printf("\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(opc != 6);
}
