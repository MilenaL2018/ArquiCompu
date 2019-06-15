//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_MENU_H
#define ARQUICOMPU_MENU_H

#include "Fantastic_Car.h"
#include "Caderita.h"
#include "The_Crush.h"

int menu() {
    int selection;

    do{

        printf("--------------MENU---------------\n");
        printf("Seleccione una opción: \n");


        printf("1) Auto fantástico\n");
        printf("2) El choque\n");
        printf("3) La caderita\n");
        printf("4) funcion 2\n");
        printf("0) Salir\n");


        scanf("%d", &selection);

        switch(selection){

            case 0:
                return 0;

            case 1:
                printf("Seleccionaste el Auto Fantástico\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                Fantastic_Car_byAlgorithm();
                break;

            case 2:
                printf("Seleccionaste el Choque\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                the_Crush_byTable();
                break;

            case 3:
                printf("Seleccionaste la Caderiiiita\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                Caderita();
                break;

            case 4:
                printf("Seleccionaste funcion 2\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                break;

            default:
                printf("No seleccionaste ninguna opcion\n");
                break;
        }

    }while(1);
}

#endif //ARQUICOMPU_MENU_H
