//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_GO_IN_H
#define ARQUICOMPU_GO_IN_H

#include "menu.h"
#include <termios.h>
#include <unistd.h>


int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}


void go_in(char password[], char real[]) {
    int error = 0;
    char again[6], caracter = 0;

    if (strcmp(password, real) == 0) {
        printf("Bienvenido al sistema \n");
        menu();
    } else {
        while (error < 3 && strcmp (password, again) != 0) {
            printf("\n¡Contraseña incorrecta! Intente de nuevo.\n");

            for (int i = 0; i < 5; i++) {
                caracter = getch();
                if (caracter != 13 && caracter != 8) {
                    again[i] = caracter;
                    putchar('*');
                }
                if(caracter == 13)
                    break;
            }

            if(strcmp(password, again) != 0){
                error++;
            }else {
                printf("Bienvenido al sistema \n");
                menu();
            }
        }
    }
}


#endif //ARQUICOMPU_GO_IN_H
