#include <iostream>

double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    } else if (exponent > 0) {
        return base * power(base, exponent - 1);
    } else {
        return 1.0 / power(base, -exponent);
    }
}

int main() {
    double base;
    int exponent;

    printf("Ingrese la base: ");
    scanf("%lf", &base);

    printf("Ingrese el exponente: ");
    scanf("%d", &exponent);

    double result = power(base, exponent);

    printf("Resultado: %lf\n", result);

    return 0;
}
