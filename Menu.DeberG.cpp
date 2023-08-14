#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#else
#include <stdio.h>
#include <unistd.h>
#endif

#define ANSI_BACKGROUND_GREEN "\033[42m"
#define ANSI_BACKGROUND_RESET "\033[0m"

using namespace std;

double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    } else if (exponent > 0) {
        return base * power(base, exponent - 1);
    } else {
        return 1.0 / power(base, -exponent);
    }
}

int divideConRestas(int dividendo, int divisor) {
    if (divisor == 0) {
        return -1;
    } else if (dividendo < divisor) {
        return 0;
    } else {
        return 1 + divideConRestas(dividendo - divisor, divisor);
    }
}

void convertirMinusculas(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            cadena[i] = cadena[i] + 32;
        }
    }
}

void convertirMayuscula(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
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
        cin >> cadena[i];
    }
}

void imprimir(char cadena[][50], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        cout << cadena[i] << endl;
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char getKey() {
#ifdef _WIN32
    return _getch();
#else
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}

void mostrarMenu(int opcionActual) {
    cout << "\t MENU\n" << endl;

    for (int i = 1; i <= 5; i++) {
        if (i == opcionActual) {
            cout << ANSI_BACKGROUND_GREEN;
        } else {
            cout << ANSI_BACKGROUND_RESET;
        }
        switch (i) {
            case 1:
                cout << "Base elevado a Exponente" << endl;
                break;
            case 2:
                cout << "Dividir con Resta" << endl;
                break;
            case 3:
                cout << "Minuscula y Mayuscula" << endl;
                break;
            case 4:
                cout << "Frase Movil" << endl;
                break;
            case 5:
                cout << "Salir" << ANSI_BACKGROUND_RESET << endl;
                break;
        }
    }
}

void regresarMenu() {
    while (true) {
        if (_kbhit()) {
            int tecla = _getch();
            if (tecla == 27) {
                break;
            }
        }
    }
}

int main() {
    int opcionActual = 1;
    double base;
    int exponent, dividendo, divisor;
    double result;
    int resultado;
    int tam;
    int screenHeight = 20;
    int y = 0;
    char palabras[50][50]; 
    char ch;
    while (true) {
        system("cls");
        mostrarMenu(opcionActual);
        char tecla = _getch();

        switch (tecla) {
            case 72:
                opcionActual = (opcionActual > 1) ? opcionActual - 1 : 5;
                break;
            case 80:
                opcionActual = (opcionActual < 5) ? opcionActual + 1 : 1;
                break;
            case 13:
                system("cls");

                switch (opcionActual) {
                    case 1:
                        cout << "\t Base elevado a exponente" << endl;
                        cout << "Ingrese la base: ";
                        cin >> base;
                        cout << "Ingrese el exponente: ";
                        cin >> exponent;
                        result = power(base, exponent);
                        cout << "Resultado: " << result << endl;
                        break;
                    case 2:
                        cout << "Ingrese el dividendo: ";
                        cin >> dividendo;
                        cout << "Ingrese el divisor: ";
                        cin >> divisor;
                        resultado = divideConRestas(dividendo, divisor);
                        cout << "Resultado de la division: " << resultado << endl;
                        break;
                    case 3:
                        cout << "Ingrese el tamaño del arreglo: ";
                        cin >> tam;
                        ingresar(palabras, tam);
                        for (int i = 0; i < tam; i++) {
                            convertirMinusculas(palabras[i]);
                        }
                        for (int i = 0; i < tam; i++) {
                            intercalar(palabras[i]);
                        }
                        cout << "Palabras ingresadas intercalado:" << endl;
                        imprimir(palabras, tam);
                        break;
                    case 4:
                        cin.ignore();
                        string mensaje;
                        cout << "Ingrese un mensaje: ";
                        getline(cin, mensaje);
                        while (true) {
                            if (_kbhit()) {
                                ch = _getch();
                                if (ch == 27)
                                    break;
                            }
                            clearScreen();
                            for (int i = 0; i < y; ++i)
                                cout << endl;
                            cout << mensaje << endl;
                            this_thread::sleep_for(chrono::milliseconds(100));
                            ++y;
                            if (y > screenHeight)
                                y = 0;
                        }
                        break;     	
                }
                _getch();
                regresarMenu();
                break;
        }
    }

    return 0;
}