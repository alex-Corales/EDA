/*
    Grupo 30
    Corales Alex Nahuel
    alexcorales21@gmail.com
*/

void mostrarArbolBinRec(struct nodoABB *nodo, char cad[]){

    if(nodo->nodoIzquierdo != NULL){
        char cad2[MAXTAMCAD]; strcpy(cad2, cad);
        if(nodo->nodoDerecho != NULL){
            printf("%s%c%c%c%c%c", cad, 195,196,196,196,196);
            char simb = 179, aux[2];
            aux[0] = simb; aux[1] = '\0'; strcat(cad2, aux);
            strcat(cad2, "      ");
            mostrarArbolBinRec(nodo->nodoIzquierdo,cad2);
        }else{
            printf("%s%c%c%c%c%c", cad, 195,196,196,196,196);
            strcat(cad2, "      ");
            mostrarArbolBinRec(nodo->nodoIzquierdo,cad2);
        }
    }

    if(nodo->nodoDerecho != NULL){
        char cad3[MAXTAMCAD]; strcpy(cad3, cad);
        printf("%s%c%c%c%c%c", cad, 195,196,196,196,196);
        strcat(cad3, "      ");
        mostrarArbolBinRec(nodo->nodoDerecho, cad3);
    }
}

void mostrarArbolBin(){
    if(raiz == NULL) printf("\nEl arbol esta vacio");
    else mostrarArbolBinRec(raiz,"");
}
