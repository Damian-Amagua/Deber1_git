#include <iostream>
#include <math.h>

float coseno(float x, int n){
    int expo=1, signo=-1;
    float resultado=0;
    double factorial;

    for(int i=0; i<=n; i++){
        factorial=1
        for(int j=1; j<=expo; j++){
            factorial*=j;
            }
        signo*=-1;
        resultado= resultado+signo*pow(x,expo)/factorial;
        expo=expo+2
    }
    return resultado;


}

int main (){
    float x, resultado;
    int n;

    printf("Introduzca el ángulo x (radianes): ");
    scanf("%f", &x);
    printf("El número de términos (n): ");
    scanf("%i", &n);
    resultado = cosen(x, n);
    printf("El coseno de x es: %f", resultado);


    return 0;
}
