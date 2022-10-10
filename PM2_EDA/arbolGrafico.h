void mostrarArbolBinRec(arbol *nodo, char cad[]){

    printf("Hola\n", nodo->cursor->vipdABB.numDni);

    if(nodo->cursor->nodoIzquierdo != NULL){
        char cad2[MAXTAMCAD]; strcpy(cad2, cad);
        if(nodo->cursor->nodoDerecho != NULL){
            printf("%s%c%c%c%c%c", cad, 195,196,196,196,196);
            char simb = 179, aux[2];
            aux[0] = simb; aux[1] = '\0'; strcat(cad2, aux);
            strcat(cad2, "      ");
            mostrarArbolBinRec(nodo->cursor->nodoIzquierdo,cad2);
        }else{
            printf("%s%c%c%c%c%c", cad, 195,196,196,196,196);
            strcat(cad2, "      ");
            mostrarArbolBinRec(nodo->cursor->nodoIzquierdo,cad2);
        }
    }

    if(nodo->cursor->nodoDerecho != NULL){
        char cad3[MAXTAMCAD]; strcpy(cad3, cad);
        printf("%s%c%c%c%c%c", cad, 195,196,196,196,196);
        strcat(cad3, "      ");
        mostrarArbolBinRec(nodo->cursor->nodoDerecho, cad3);
    }
}

void mostrarArbolBin(arbol nodo){
    if(nodo.acceso == NULL) printf("\nEl arbol esta vacio");
    else mostrarArbolBinRec(nodo.acceso,"");
}
