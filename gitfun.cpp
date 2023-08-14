#include <stdio.h>

void convertirMinusculas(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            // Convertir a minúscula sumando 32 a su valor numérico en ASCII
            cadena[i] = cadena[i] + 32;
        }
    }
}

void convertirMayuscula(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            // Convertir a minúscula restando 32 a su valor numérico en ASCII
            cadena[i] = cadena[i] - 32;
        }
    }
}

void intercalar(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (i % 2 == 0) {
            if (cadena[i] >= 'a' && cadena[i] <= 'z') {
                cadena[i] = cadena[i] - 32;
            }
        } else {
            if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
                cadena[i] = cadena[i] + 32;
            }
        }
    }
}


void ingresar(char cadena[][50], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        scanf("%s", cadena[i]);
    }
}

void imprimir(char cadena[][50], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        puts(cadena[i]);
    }
}

int main() {
    int tam;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tam);

    char palabras[tam][50];

    ingresar(palabras, tam);
    for(int i=0; i<tam;i++){
        convertirMinusculas(palabras[i]);
    }

    //for (int i = 0; i < tam; i++) {
        //convertirMayuscula(palabras[i]);
    //}

    for(int i=0; i<tam;i++){
        intercalar(palabras[i]);
    }
    printf("Palabras ingresadas intercalado:\n");
    imprimir(palabras, tam);
    //printf("Palabras ingresadas minusculas:\n");
    //imprimir(palabras, tam);
    //printf("Palabras ingresadas mayuscula:\n");
    //imprimir(palabras, tam);

    return 0;
}
