#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
#endif // PANTALLA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
HANDLE wHnd;

void tamanioPantalla(){
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 60, 30};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
}

void gotoxy(int x , int y){
    // CONTROLADOR PARA NUESTRA VENTANA, Y MANIPULACION DE CONSOLA
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

    // CREAMOS OBJETO DE LAS CORDENADAS DENTRO DE UNA ESTRUCTURA
    COORD cordenadas;
    // REDIRECCIONAMOS LAS VARIABLES DE LA ESTRUCTURA A NUESTRAS VARIABLES DE LA FUNCION
    cordenadas.X = x;
    cordenadas.Y = y;

    // POSICIONAMOS EL MENSAJE DENTRO DE NUESTRA CONSOLA, A NUESTRA VENTANA CON LAS CORDENADAS DADAS.
    SetConsoleCursorPosition(wHnd,cordenadas);
}
