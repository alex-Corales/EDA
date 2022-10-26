#ifndef COMESTRUCTURAS_H_INCLUDED
#define COMESTRUCTURAS_H_INCLUDED
#endif // COMESTRUCTURAS_H_INCLUDED

float costo = 0.0;

#include "RAL.h"
#include "RS.h"
#include "abb.h"
#include "LSO.h"
#include "LSOBB.h"
#define Mral 149
#define Mrs 60
#define MAXlso 111
#define MAXlsobb 110


typedef struct{
    float costoAcumulado; //Suma de costos
    float costoMax; //Costo maximo
    int cant; //Cantidad de elemetos
}bloque;

bloque costoABB[4];
bloque costoRAL[4];
bloque costoRS[4];
bloque costoLSO[4];
bloque costoLSOBB[4];

/*
    prototipos
*/

void initC(bloque *);
void initM(float *);

/*
    variables
*/

celda RAL[Mral];
lista RS[Mrs];
datosVendedor LSO[MAXlso];
datosVendedor LSOBB[MAXlsobb];
int exito = 0;
datosVendedor exitoE;
float mRAL[4] ,mABB[4], mRS[4], mLSO[4], mLSOBB[4]; //Costos medios
datosVendedor dat;

int comparacionEstructuras(){
    initRAL(&RAL);
    initRS(&RS);
    int masInfinito = 100000000;
    LSO[0].numDni = masInfinito;
    initC(costoRAL);
    initC(costoRS);
    initC(costoLSO);
    initC(costoLSOBB);
    initM(mRAL);
    initM(mRS);
    initM(mLSO);
    initM(mLSOBB);

    FILE *fp;
    if((fp = fopen("Operaciones.txt","r"))==NULL) return 1;
    else{
        while(!feof(fp)){

            /*
                1 - Alta
                2 - Baja
                3 - Evocacion -> Exito
                              -> Fracaso
            */
            fscanf(fp,"%d\n", &opc);
            fflush(stdin);
            fscanf(fp,"%d\n", &dat.numDni);
            fflush(stdin);
            switch(opc){
            case 1: //Alta
                fscanf(fp,"%[^\n] %[^\n] %f %d %[^\n]",
                       dat.nombreApellido,
                       dat.numTelefono,
                       &dat.montoVendido,
                       &dat.cantVendido,
                       dat.canalDeVenta);
                //RAL
                costo = 0;
                exito = altaRAL(RAL, dat, &costo);
                if(exito == 2){
                    costoRAL[0].costoAcumulado = costoRAL[0].costoAcumulado + costo;
                    costoRAL[0].cant++;
                    if(costo > costoRAL[0].costoMax) costoRAL[0].costoMax = costo;
                }
                //RS
                costo = 0;
                exito = altaRS(RS, dat, &costo);
                if(exito == 1){
                    costoRS[0].costoAcumulado = costoRS[0].costoAcumulado + costo;
                    costoRS[0].cant++;
                    if(costo > costoRS[0].costoMax) costoRS[0].costoMax = costo;
                }
                //ABB
                costo = 0;
                exito = altaABB(dat, &costo);
                if(exito == 2){
                    costoABB[0].costoAcumulado = costoABB[0].costoAcumulado + costo;
                    costoABB[0].cant++;
                    if(costo > costoABB[0].costoMax) costoABB[0].costoMax = costo;
                }
                //LSO
                costo = 0;
                exito = altaLSO(LSO, dat.nombreApellido, dat.numDni, dat.numTelefono, dat.montoVendido, dat.cantVendido, dat.canalDeVenta, &costo);
                if(exito == 1){
                    costoLSO[0].costoAcumulado = costoLSO[0].costoAcumulado + costo;
                    costoLSO[0].cant++;
                    if(costo > costoLSO[0].costoMax) costoLSO[0].costoMax = costo;
                }
                //LSOBB
                costo = 0;
                exito = altaLSOBT(LSOBB, dat.nombreApellido, dat.numDni, dat.numTelefono, dat.montoVendido, dat.cantVendido, dat.canalDeVenta, &costo);
                if(exito == 1){
                    costoLSOBB[0].costoAcumulado = costoLSOBB[0].costoAcumulado + costo;
                    costoLSOBB[0].cant++;
                    if(costo > costoLSOBB[0].costoMax) costoLSOBB[0].costoMax = costo;
                }
                break;
            case 2: //BAJAS
                fscanf(fp,"%[^\n] %[^\n] %f %d %[^\n]",
                       dat.nombreApellido,
                       dat.numTelefono,
                       &dat.montoVendido,
                       &dat.cantVendido,
                       dat.canalDeVenta);
                //RAL
                costo = 0;
                exito = bajaRAL(RAL, dat.numDni, &costo);
                if(exito == 2){
                    costoRAL[1].costoAcumulado = costoRAL[1].costoAcumulado + costo;
                    costoRAL[1].cant++;
                    if(costo > costoRAL[1].costoMax) costoRAL[1].costoMax = costo;
                }
                //RS
                /*costo = 0;
                exito = bajaRS(RS, dni, &costo);
                if(exito == 2){
                    costoRS[1].costoAcumulado = costoRS[1].costoAcumulado + costo;
                    costoRS[1].cant++;
                    if(costo > costoRS[1].costoMax) costoRS[1].costoMax = costo;
                }*/
                //ABB
                costo = 0;
                exito = bajaABB(dat, &costo);
                if(exito == 0){
                    costoABB[1].costoAcumulado = costoABB[1].costoAcumulado + costo;
                    costoABB[1].cant++;
                    if(costo > costoABB[1].costoMax) costoABB[1].costoMax = costo;
                }
                //LSO
                costo = 0;
                exito = bajaLSO(LSO, dat.numDni, &costo);
                if(exito == 1){
                    costoLSO[1].costoAcumulado = costoLSO[1].costoAcumulado + costo;
                    costoLSO[1].cant++;
                    if(costo > costoLSO[1].costoMax) costoLSO[1].costoMax = costo;
                }
                //LSOBB
                costo = 0;
                exito = bajaLSOBT(LSOBB, dat.numDni, &costo);
                if(exito == 1){
                    costoLSOBB[1].costoAcumulado = costoLSOBB[1].costoAcumulado + costo;
                    costoLSOBB[1].cant++;
                    if(costo > costoLSOBB[1].costoMax) costoLSOBB[1].costoMax = costo;
                }
                break;
            case 3: //Evocaciones
                //RAL
                costo = 0;
                exitoE = evocarRAL(RAL, dat.numDni, &costo);
                if(exitoE.numDni != -1){
                    costoRAL[2].costoAcumulado = costoRAL[2].costoAcumulado + costo;
                    costoRAL[2].cant++;
                    if(costo > costoRAL[2].costoMax) costoRAL[2].costoMax = costo;
                }else if(exitoE.numDni == -1){
                    costoRAL[3].costoAcumulado = costoRAL[3].costoAcumulado + costo;
                    costoRAL[3].cant++;
                    if(costo > costoRAL[3].costoMax) costoRAL[3].costoMax = costo;
                }
                //RS
                costo = 0;
                exitoE = evocarRS(RS, dat.numDni, &costo);
                if(exitoE.numDni != -1){
                    costoRS[2].costoAcumulado = costoRS[2].costoAcumulado + costo;
                    costoRS[2].cant++;
                    if(costo > costoRS[2].costoMax) costoRS[2].costoMax = costo;
                }else if(exitoE.numDni == -1){
                    costoRS[3].costoAcumulado = costoRS[3].costoAcumulado + costo;
                    costoRS[3].cant++;
                    if(costo > costoRS[3].costoMax) costoRS[3].costoMax = costo;
                }
                //ABB
                costo = 0;
                exitoE = evocarABB(dat.numDni, &costo);
                if(exitoE.numDni != 1){
                    costoABB[2].costoAcumulado = costoABB[2].costoAcumulado + costo;
                    costoABB[2].cant++;
                    if(costo > costoABB[2].costoMax) costoABB[2].costoMax = costo;
                }else if(exitoE.numDni == 1){
                    costoABB[3].costoAcumulado = costoABB[3].costoAcumulado + costo;
                    costoABB[3].cant++;
                    if(costo > costoABB[3].costoMax) costoABB[3].costoMax = costo;
                }
                //LSO
                costo = 0;
                exitoE = evocarLSO(LSO, dat.numDni, &costo);
                printf("\nHOLA"); //Se rompe, controlar
                if(exitoE.numDni != -1){
                    costoLSO[2].costoAcumulado = costoLSO[2].costoAcumulado + costo;
                    costoLSO[2].cant++;
                    if(costo > costoLSO[2].costoMax) costoLSO[2].costoMax = costo;
                }else if(exitoE.numDni == -1){
                    costoLSO[3].costoAcumulado = costoLSO[3].costoAcumulado + costo;
                    costoLSO[3].cant++;
                    if(costo > costoLSO[3].costoMax) costoLSO[3].costoMax = costo;
                }
                break;
            }
        }
        fclose(fp);
    }
    //RAL
    if(costoRAL[0].cant != 0) mRAL[0] = costoRAL[0].costoAcumulado * (1.0/costoRAL[0].cant); //Alta
    if(costoRAL[1].cant != 0) mRAL[1] = costoRAL[1].costoAcumulado * (1.0/costoRAL[1].cant); //Baja
    if(costoRAL[2].cant != 0) mRAL[2] = costoRAL[2].costoAcumulado * (1.0/costoRAL[2].cant); //Evocacion exitosa
    if(costoRAL[3].cant != 0) mRAL[3] = costoRAL[3].costoAcumulado * (1.0/costoRAL[3].cant); //Evocacion que fracasa
    //RS
    if(costoRS[0].cant != 0) mRS[0] = costoRS[0].costoAcumulado * (1.0/costoRS[0].cant); //Alta
    if(costoRS[1].cant != 0) mRS[1] = costoRS[1].costoAcumulado * (1.0/costoRS[1].cant); //Baja
    if(costoRS[2].cant != 0) mRS[2] = costoRS[2].costoAcumulado * (1.0/costoRS[2].cant); //Evocacion exitosa
    if(costoRS[3].cant != 0) mRS[3] = costoRS[3].costoAcumulado * (1.0/costoRS[3].cant); //Evocacion que fracasa
    //ABB
    if(costoABB[0].cant != 0) mABB[0] = costoABB[0].costoAcumulado * (1.0/costoABB[0].cant); //Alta
    if(costoABB[1].cant != 0) mABB[1] = costoABB[1].costoAcumulado * (1.0/costoABB[1].cant); //Baja
    if(costoABB[2].cant != 0) mABB[2] = costoABB[2].costoAcumulado * (1.0/costoABB[2].cant); //Evocacion exitosa
    if(costoABB[3].cant != 0) mABB[3] = costoABB[3].costoAcumulado * (1.0/costoABB[3].cant); //Evocacion que fracasa
    //LSO
    if(costoLSO[0].cant != 0) mLSO[0] = costoLSO[0].costoAcumulado * (1.0/costoLSO[0].cant); //Alta
    if(costoLSO[1].cant != 0) mLSO[1] = costoLSO[1].costoAcumulado * (1.0/costoLSO[1].cant); //Baja
    if(costoLSO[2].cant != 0) mLSO[2] = costoLSO[2].costoAcumulado * (1.0/costoLSO[2].cant); //Evocacion exitosa
    if(costoLSO[3].cant != 0) mLSO[3] = costoLSO[3].costoAcumulado * (1.0/costoLSO[3].cant); //Evocacion que fracasa
    //LSOBB
    if(costoLSOBB[0].cant != 0) mLSOBB[0] = costoLSOBB[0].costoAcumulado * (1.0/costoLSOBB[0].cant); //Alta
    if(costoLSOBB[1].cant != 0) mLSOBB[1] = costoLSOBB[1].costoAcumulado * (1.0/costoLSOBB[1].cant); //Baja
    if(costoLSOBB[2].cant != 0) mLSOBB[2] = costoLSOBB[2].costoAcumulado * (1.0/costoLSOBB[2].cant); //Evocacion exitosa
    if(costoLSOBB[3].cant != 0) mLSOBB[3] = costoLSOBB[3].costoAcumulado * (1.0/costoLSOBB[3].cant); //Evocacion que fracasa

    printf("\t COMPARACION DE ESTRUCTURAS\n\n");
    printf("COSTOS\t\tRAL\tRS\tABB\tLSO\tLSOBT\n");
    printf("_____________________________________________________\n");
    printf("MAX.ALTA\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", costoRAL[0].costoMax, costoRS[0].costoMax, costoABB[0].costoMax, costoLSO[0].costoMax, costoLSOBB[0].costoMax);
    printf("MED.ALTA\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", mRAL[0], mRS[0], mABB[0], mLSO[0], mLSOBB[0]);
    printf("MAX.BAJA\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", costoRAL[1].costoMax, costoRS[1].costoMax, costoABB[1].costoMax, costoLSO[1].costoMax, costoLSOBB[1].costoMax);
    printf("MED.BAJA\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", mRAL[1], mRS[1], mABB[1], mLSO[1], mLSOBB[1]);
    printf("MAX.EVOEX\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", costoRAL[2].costoMax, costoRS[2].costoMax, costoABB[2].costoMax, costoLSO[2].costoMax, costoLSOBB[2].costoMax);
    printf("MED.EVOEX\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", mRAL[2], mRS[2], mABB[2], mLSO[2], mLSOBB[2]);
    printf("MAX.EVONOEX\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", costoRAL[3].costoMax, costoRS[3].costoMax, costoABB[3].costoMax, costoLSO[3].costoMax, costoLSOBB[3].costoMax);
    printf("MED.EVONOEX\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n\n", mRAL[3], mRS[3], mABB[3], mLSO[3], mLSOBB[3]);
    system("PAUSE");
    system("cls");
}

void initC(bloque c[]){ //Init costos maximos
    int i;
    for(i = 0; i < 4; i++){
        c[i].costoAcumulado = 0.0;
        c[i].costoMax = 0.0;
        c[i].cant = 0;
    }
}

void initM(float c[]){ //Init costos medios
    int i;
    for(i = 0; i < 4; i++){
        c[i] = 0.0;
    }
}
