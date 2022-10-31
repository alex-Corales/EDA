/*
    Grupo 30 - Corales Alex Nahuel
*/

#ifndef LSOBB_H_INCLUDED
#define LSOBB_H_INCLUDED
#endif // LSOBB_H_INCLUDED
#define MAXLSOBT 110

/*
    Prototipos
*/

datosVendedor evocarLSOBT(datosVendedor *, int, float *);
int altaLSOBT(datosVendedor *, char *, int, char *, float, int, char *, float *);



char auxDni[20];
int lsLSOBT = -1;
int posLSOBT = 0;
char opc1[10];
int aux, num, dni, auxopc;
char nombreApellido[50];
char numeroTelefono[15];
float montoVendido;
int cantVendido;
char canalDeVenta[20];
datosVendedor vendedorLSOBT[MAXLSOBT]; //Lista Secuencial Ordenada - Busqueda Binaria


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

            aux = altaLSOBT(vendedorLSOBT, nombreApellido, dni, numeroTelefono, montoVendido, cantVendido, canalDeVenta, &costo);

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

            datosVendedor consult = evocarLSOBT(vendedorLSOBT, dni, &costo);

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

void imprimirVendedorLSOBT(datosVendedor dat){
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

int localizarLSOBT(datosVendedor arreglo[], int busqueda, int ls, int *posLSOBT, float *costo){

    int li = 0;
    int testigo = 0;
    *costo = 0.0;
    if(lsLSOBT != -1){
        while (li <= ls){
            *costo = *costo + 1;
            testigo = (li + ls)/2;
            if (busqueda == arreglo[testigo].numDni){
                *posLSOBT = testigo;
                return 1;
            }
            if (busqueda < arreglo[testigo].numDni) ls = testigo - 1;
            else li = testigo + 1;
        }
        *posLSOBT = li;
        return -1;
    }else{
        *posLSOBT = 0;
        return -1;
    }
}

int altaLSOBT(datosVendedor dat[], char nombreApellido[], int numDni, char numTelefono[], float montoVendido, int cantVendido, char canalDeVenta[], float *costo){

    if(lsLSOBT == 109) return -1; //La estructura esta llena
    float costoAux;
    int exito = localizarLSOBT(dat,numDni,lsLSOBT,&posLSOBT,&costoAux);
    if(exito == 1) return 0; //El vendedor ya esta cargado

    int i;

    for(i = lsLSOBT; i >= posLSOBT; i--){
        dat[i+1] = dat[i];
        *costo = *costo + 1.5;
    }

    dat[posLSOBT].numDni = numDni;
    strcpy(dat[posLSOBT].nombreApellido, nombreApellido);
    strcpy(dat[posLSOBT].numTelefono, numTelefono);
    dat[posLSOBT].montoVendido = montoVendido;
    dat[posLSOBT].cantVendido = cantVendido;
    strcpy(dat[posLSOBT].canalDeVenta, canalDeVenta);
    lsLSOBT++;

    return 1;
}

int bajaLSOBT(datosVendedor dat[], datosVendedor datLSOBB, float *costo, int opcAux){
    int auxopc = 0, opc = 0;
    char opc1[10];
    float costoAux;
    if(localizarLSOBT(dat, datLSOBB.numDni, lsLSOBT,&posLSOBT,&costoAux) == -1) return -1;

    if(opcAux == 1){
        if(datLSOBB.numDni == dat[posLSO].numDni && datLSOBB.cantVendido == dat[posLSO].cantVendido && datLSOBB.montoVendido == dat[posLSO].montoVendido && (strcmp(dat[posLSO].canalDeVenta, datLSOBB.canalDeVenta) == 0) && (strcmp(dat[posLSO].nombreApellido, datLSOBB.nombreApellido) == 0) && (strcmp(dat[posLSO].numTelefono, datLSOBB.numTelefono) == 0)){
            opc = 1;
        }else opc = 0;
    }
    if(opc == 0) return 3;
    if(opcAux == 0){
        printf("------------------------------\n");
        printf("Nombre y Apellido: %s\n", dat[posLSOBT].nombreApellido);
        printf("Dni: %d\n", dat[posLSOBT].numDni);
        printf("Numero de telefono: %s\n", dat[posLSOBT].numTelefono);
        printf("Monto vendido: %f\n", dat[posLSOBT].montoVendido);
        printf("Cantidad vendida: %d\n", dat[posLSOBT].cantVendido);
        printf("Canal de venta: %s\n", dat[posLSOBT].canalDeVenta);
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

    for(int i = posLSOBT; i < lsLSOBT; i++){
        dat[i] = dat[i+1];
        *costo = *costo + 1.5;
    }

    lsLSOBT--;
    return 1;

} //eliminacion de vendedores existentes

datosVendedor evocarLSOBT(datosVendedor dat [], int numDni, float *costo){
    datosVendedor aux;
    aux.numDni = -1;
    float costoAux;
    if(localizarLSOBT(dat, numDni, lsLSOBT, &posLSOBT, &costoAux)==-1){
        *costo = costoAux;
        return aux;
    }
    *costo = costoAux;
    return dat[posLSOBT];

} //consulta de vendedores

void mostrarEstruturaLSOBT(datosVendedor dat[]){
    if(lsLSOBT == -1) printf("\nNo hay vendedores cargados en el sistema\n");
    for(int i = 0; i <= lsLSOBT; i++){
        printf("\n------------------------------");
        printf("\nNombre y Apellido: %s", dat[i].nombreApellido);
        printf("\nDni: %d", dat[i].numDni);
        printf("\nNumero de telefono: %s", dat[i].numTelefono);
        printf("\nMonto vendido: %f", dat[i].montoVendido);
        printf("\nCantidad vendida: %d", dat[i].cantVendido);
        printf("\nCanal de venta: %s", dat[i].canalDeVenta);
    }

} //mostrar estructura

int perteneceLSOBT(datosVendedor dat[], int dni){
    float costoAux;
    int aux = localizarLSOBT(dat, dni,lsLSOBT,&pos,&costoAux);
    if(aux == 1) return 1;
    else return -1;
}

int memorizacionPreviaLSOBT(datosVendedor dat[]){

    char nombreApellido[50];
    float costoAux;
    int i = 0;
    int auxMemo;

    FILE *fp;

    if((fp = fopen("vendedores.txt","r"))==NULL) return 0;
    else{
        while(!feof(fp)){
            fscanf(fp,"%d %[^\n] %[^\n] %f %d %[^\n]", &dat->numDni, dat->nombreApellido, dat->numTelefono, &dat->montoVendido, &dat->cantVendido, dat->canalDeVenta);
            auxMemo = altaLSOBT(dat, dat->nombreApellido,dat->numDni,dat->numTelefono,dat->montoVendido,dat->cantVendido,dat->canalDeVenta,&costo);
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
                if(auxMemo == 1) imprimirVendedorLSOBT(*dat);
                system("pause");
                system("cls");
            }

        }
        fclose(fp);
        return 1;
    }
}
