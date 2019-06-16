//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_GO_IN_H
#define ARQUICOMPU_GO_IN_H

#include "menu.h"
#include "kbhit.h"
#include "string.h"




void go_in(char password[], char real[]) {
    int error = 0;
    char again[6], caracter = 0;

    if (strcmp(password, real) == 0) {
        printf("Bienvenido al sistema \n");
        system("clear");
        menu();
    } else {
        while (error < 3 && strcmp (password, again) != 0) {
            printf("\n¡Contraseña incorrecta! Intente de nuevo.\n");
            for (int i = 0; i < 5; i++) {
                caracter = getch1();
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
                system("clear");
                printf("Bienvenido al sistema \n");
                menu();
            }
        }
    }
}


#endif //ARQUICOMPU_GO_IN_H
