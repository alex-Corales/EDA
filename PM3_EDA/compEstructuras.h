#ifndef COMPESTRUCTURAS_H_INCLUDED
#define COMPESTRUCTURAS_H_INCLUDED

typedef struct{
    int costoAcumulado; //Suma de costos
    int costoMax; //Costo maximo
    int cant; //Cantidad de elemetos
}componente;

componente costoABB[4];
componente costoRAC[4];
componente costoRS[4];

/*
    prototipos
*/

void initC(componente *);
void initM(float *);

/*
    variables
*/

celda RAC[Mrac];
lista RS[Mrs];
int costo = 0;
float mRAC[4] ,mABB[4], mRS[4];
datosVendedor dat;

void comparacionEstructuras(){
    initRAC(&RAC);
    initRS(&RS);
    initC(costoRAC);
    initC(costoRS);
    initM(mRAC);
    initM(mRS);

    FILE *fp;
    if(fp == fopen("operaciones.txt","r") == NULL)
        return 1;

    while(!(feof(fp))){
        fscanf(fp,"%d\n", &opc);
        fscanf(fp,"%s\n", dat.numDni);
        switch(opc){
        case 1:
            fscanf(fp,"%d\n", dat.)
            break;
        }
    }

}

void initC(componente c[]){
    int i;
    for(i = 0; i < 4; i++){
        c[i].costoAcumulado = 0;
        c[i].costoMax = 0;
        c[i].cant = 0;
    }
}

void initM(float c[]){
    int i;
    for(i = 0; i < 4; i++){
        c[i] = 0.0;
    }
}


#endif // COMPESTRUCTURAS_H_INCLUDED
