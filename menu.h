//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_MENU_H
#define ARQUICOMPU_MENU_H

#include <stdlib.h>
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

        enable_raw_mode();
        scanf("%d", &selection);
        disable_raw_mode();

        switch(selection){

            case 0:
                return 0;

            case 1:
                system("clear");
                printf("Seleccionaste el Auto Fantástico\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                int a;
                do{
                    enable_raw_mode();
                    a = getch1();
                    //for detect the function\arrow keys
                    //we must call the getch() again
                    //testing if a is '0' or '0xE0'
                    if (a==0 || a==0xE0) a=getch1();

                    if (a==72){
                        speed(a);
                    }else if (a==80){
                        speed(a);
                    }

                    Fantastic_Car_byAlgorithm(a);

                }while(a != 27);

                system("clear");
                break;

            case 2:

                system("clear");
                printf("Seleccionaste el Choque\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                do{
                    enable_raw_mode();
                    a = getch1();
                    //for detect the function\arrow keys
                    //we must call the getch() again
                    //testing if a is '0' or '0xE0'
                    if (a==0 || a==0xE0) a=getch1();

                    if (a==72){
                        speed(a);
                    }else if (a==80){
                        speed(a);
                    }

                    the_Crush_byTable(a);

                }while(a != 27);
                system("clear");
                break;

            case 3:

                system("clear");
                printf("Seleccionaste la Caderiiiita\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                do{
                    enable_raw_mode();
                    a = getch1();
                    //for detect the function\arrow keys
                    //we must call the getch() again
                    //testing if a is '0' or '0xE0'
                    if (a==0 || a==0xE0) a=getch1();

                    if (a==72){
                        Caderita(a);
                    }else if (a==80){
                        Caderita(a);
                    }

                    Caderita(a);

                }while(a != 27);
                system("clear");
                break;

            case 4:
                printf("Seleccionaste funcion 2\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                system("clear");
                break;

            default:
                printf("No seleccionaste ninguna opcion\n");
                break;
        }

    }while(1);
}

#endif //ARQUICOMPU_MENU_H
