/*
    Grupo 30
    Corales Alex Nahuel
    alexcorales21@gmail.com
*/

#ifndef CONTROLES_H_INCLUDED
#define CONTROLES_H_INCLUDED

#endif // CONTROLES_H_INCLUDED

int controlIngresoNum(char numero[]){
    int i;
    for(i=0; i < strlen(numero); i++){
        if(!(isdigit(numero[i]))){
            printf("Error. ingrese nuevamente un valor valido.\n");
            printf("- ");
            //getch();
            return 0;
        }
    }
    return 1;
}

int controlIngresoLetras(char palabra[]){
    int i;
    for(i=0; i<strlen(palabra); i++){
        if(!((palabra[i] >= 65 && palabra[i] <= 90) || (palabra[i] >= 97 && palabra[i] <= 122) || (palabra[i] == 32) || (palabra[i] == 164) || (palabra[i] == 165))){
            printf("Error. ingrese nuevamente un valor valido.\n");
            printf("- ");
            return 0;
        }
    }
    return 1;
}

int controlIngresoLetrasNumero(char palabra[]){
    int i;
    for(i=0; i<strlen(palabra); i++){
        if(!((palabra[i] >= 48 && palabra[i] <= 57) || (palabra[i] == 45))){
            printf("Error. ingrese nuevamente un valor valido.\n");
            printf("- ");
            return 0;
        }
    }
    return 1;
}
