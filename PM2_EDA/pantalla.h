/*
    Grupo 30
    Corales Alex Nahuel
    alexcorales21@gmail.com
*/

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
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD cordenadas;
    cordenadas.X = x;
    cordenadas.Y = y;

    SetConsoleCursorPosition(wHnd,cordenadas);
}
