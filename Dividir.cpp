#include <iostream>

int divideConRestas(int dividendo, int divisor) {
    if (divisor == 0) {
        return -1;
    } else if (dividendo < divisor) {
        return 0;
    } else {
        return 1 + divideConRestas(dividendo - divisor, divisor);
    }
}

int main() {
    int dividendo, divisor;

    printf("Ingrese el dividendo: ");
    scanf("%d", &dividendo);

    printf("Ingrese el divisor: ");
    scanf("%d", &divisor);

    int resultado = divideConRestas(dividendo, divisor);

    printf("Resultado de la division: %d\n", resultado);

    return 0;
}
