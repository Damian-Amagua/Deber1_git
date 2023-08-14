#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>  // Solo para Windows

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

int main() {
    std::string mensaje;
    std::cout << "Ingrese un mensaje: ";
    std::getline(std::cin, mensaje);

    int screenHeight = 20;  
    int y = 0;

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 27)  
                break;
        }

        clearScreen();
        for (int i = 0; i < y; ++i)
            std::cout << std::endl;

        std::cout << mensaje << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        ++y;
        if (y > screenHeight)
            y = 0;
    }

    return 0;
}
