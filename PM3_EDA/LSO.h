/*
    Grupo 30 - Corales Alex Nahuel
*/

#ifndef LSO_H_INCLUDED
#define LSO_H_INCLUDED
#endif // LSO_H_INCLUDED

#define MAX 111


/*
    Prototipos
*/

datosVendedor evocarLSO(datosVendedor *, int, float *);
int altaLSO(datosVendedor *, char *, int , char *, float , int , char *, float *);


/*
    Variables
*/

int opcAuxLSO = 0;
int ls = 0;
int posLSO = 0;
char auxDni[20];
char opc1[10];
int aux, num, dni, auxopc;
char nombreApellido[50];
char numeroTelefono[15];
float montoVendido;
int cantVendido;
char canalDeVenta[20];
int masInfinito = 100000000;


void listaSecuencialOrdenadaConTerminacionPorContenido(){

    datosVendedor vendedorLSO[MAX]; //Lista Secuencial Ordenada con terminacion por contenido
    if(opcAuxLSO == 0){vendedorLSO[0].numDni = masInfinito; opcAuxLSO++;}

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

            aux = altaLSO(vendedorLSO, nombreApellido, dni, numeroTelefono, montoVendido, cantVendido, canalDeVenta, &costo);

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

            datosVendedor consult = evocarLSO(vendedorLSO, dni, &costo);

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

void imprimirVendedorLSO(datosVendedor dat){
    system("cls");
    printf("\n------------------------------");
    printf("\nNombre y Apellido: %s", dat.nombreApellido);
    printf("\nDni: %d", dat.numDni);
    printf("\nNumero de telefono: %s", dat.numTelefono);
    printf("\nMonto vendido: %f", dat.montoVendido);
    printf("\nCantidad vendida: %d", dat.cantVendido);
    printf("\nCanal de venta: %s", dat.canalDeVenta);
    printf("\n------------------------------\n");
}

int localizarLSO(datosVendedor dat[], int numDni, int *posLSO, float *costo){
    int i = 0;
    *costo = 0.0;
    while(dat[i].numDni < numDni){
        *costo = *costo + 1;
        i++;
    }

    if (dat[i].numDni == numDni){
        *costo = *costo + 1;
        *posLSO = i;
        return 1;
    }else{
        *costo = *costo + 1;
        *posLSO = i;
        return -1;
    }

}

int altaLSO(datosVendedor dat[], char nombreApellido[], int numDni, char numTelefono[], float montoVendido, int cantVendido, char canalDeVenta[], float *costo){

    if(ls == 110) return -1;
    int i = 0;
    float costoAux;
    int aux = localizarLSO(dat,numDni,&posLSO,&costoAux);
    if(aux == 1) return 0;

    for(i = ls; i >= posLSO; i--){
        dat[i+1] = dat[i];
        *costo = *costo + 1.5;
    }

    dat[posLSO].numDni = numDni;
    strcpy(dat[posLSO].nombreApellido, nombreApellido);
    strcpy(dat[posLSO].numTelefono, numTelefono);
    dat[posLSO].montoVendido = montoVendido;
    dat[posLSO].cantVendido = cantVendido;
    strcpy(dat[posLSO].canalDeVenta, canalDeVenta);

    ls++;
    return 1;
}// ingreso de nuevos vendedores

int bajaLSO(datosVendedor dat[], datosVendedor datLSO, float *costo, int opcAux){
    if(ls == 0) return -1;
    int i = 0, auxopc = 0, opc = 0;
    char opc1[10];
    float costoAux;
    int aux = localizarLSO(dat, datLSO.numDni, &posLSO, &costoAux);
    if (aux != 1) return -1;

    if(opcAux == 1){
        if(datLSO.numDni == dat[posLSO].numDni && datLSO.cantVendido == dat[posLSO].cantVendido && datLSO.montoVendido == dat[posLSO].montoVendido && (strcmp(dat[posLSO].canalDeVenta, datLSO.canalDeVenta) == 0) && (strcmp(dat[posLSO].nombreApellido, datLSO.nombreApellido) == 0) && (strcmp(dat[posLSO].numTelefono, datLSO.numTelefono) == 0)){
            opc = 1;
        }else opc = 0;
    }
    if(opc == 0) return 3;
    if(opcAux == 0){
        printf("------------------------------\n");
        printf("Nombre y Apellido: %s\n", dat[posLSO].nombreApellido);
        printf("Dni: %d\n", dat[posLSO].numDni);
        printf("Numero de telefono: %s\n", dat[posLSO].numTelefono);
        printf("Monto vendido: %f\n", dat[posLSO].montoVendido);
        printf("Cantidad vendida: %d\n", dat[posLSO].cantVendido);
        printf("Canal de venta: %s\n", dat[posLSO].canalDeVenta);
        printf("------------------------------\n");

        printf("Desea eliminar los datos del vendedor?\n");
        printf("<1> Si\n");
        printf("<2> No\n");
        printf("- ");
        do{
            scanf("%s", opc1);
            auxopc = controlIngresoNum(opc1);
        }while(auxopc==0 && atoi(opc1) != 1 && atoi(opc1) != 2);
        opc = atoi(opc1);
        if(opc == 1){

            return 1;
        }
    }

    for(i = posLSO; i < ls; i++){
        dat[i] = dat[i+1];
        *costo = *costo + 1.5;
    }

    ls--;

    return 1;

} //eliminacion de vendedores existentes

datosVendedor evocarLSO(datosVendedor dat[], int numDni, float *costo){
    datosVendedor aux;
    aux.numDni = -1;
    float costoAux;
    if (localizarLSO(dat, numDni, &posLSO, &costoAux) == -1){
        *costo = costoAux;
        return aux;
    }
    *costo = costoAux;
    return dat[posLSO];

}

int perteneceLSO(datosVendedor dat[], int dni, int masInfinito){
    float costoAux;
    int aux = (localizarLSO(dat, dni, &posLSO, &costoAux) && dat[posLSO].numDni != masInfinito);
    if(aux == 1) return 1;
    else return -1;
}

void mostrarEstrutura(datosVendedor dat[]){

    if (ls == 0) printf("\nNo hay vendedores cargados en el sistema\n");
    for(int i = 0; i < ls; i++){
        printf("\n------------------------------");
        printf("\nNombre y Apellido: %s", dat[i].nombreApellido);
        printf("\nDni: %d", dat[i].numDni);
        printf("\nNumero de telefono: %s", dat[i].numTelefono);
        printf("\nMonto vendido: %f", dat[i].montoVendido);
        printf("\nCantidad vendida: %d", dat[i].cantVendido);
        printf("\nCanal de venta: %s", dat[i].canalDeVenta);
    }
} //mostrar estructura

int memorizacionPrevia(datosVendedor dat[]){

    int aux;
    float costoAux;
    int i = 0;
    int auxMemo;

    FILE *fp;

    if((fp = fopen("vendedores.txt","r"))==NULL)return 0;
    else{
        while(!feof(fp)){
            fscanf(fp,"%d %[^\n] %[^\n] %f %d %[^\n]", &dat->numDni, dat->nombreApellido, dat->numTelefono, &dat->montoVendido, &dat->cantVendido, dat->canalDeVenta);
            auxMemo = altaLSO(dat, dat->nombreApellido,dat->numDni,dat->numTelefono,dat->montoVendido,dat->cantVendido,dat->canalDeVenta,&costo);
            if(auxMemo == -1){
                fclose(fp);
                return -1;
            }else if(auxMemo == 0){
                printf("\nHay un vendedor repetido");
                printf("\nDesea ver el vendedor repetido?");
                printf("\n<1> si");
                printf("\n<2> No");
                printf("\n- ");
                scanf("%d", &auxMemo);
                if(auxMemo == 1) imprimirVendedorLSO(*dat);
                system("pause");
                system("cls");
            }
        }
        fclose(fp);
        return 1;
    }
}
