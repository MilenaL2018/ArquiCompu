
#include "potencia.h"
#include "tenis.h"
#include <stdio.h>
#include <ncurses.h>
//#include "EasyPIO.h"
#include <string.h>



const char led[] = {7, 8, 25, 24, 23, 18, 15, 14};



void menu();
int go_in(char*);
void Fantastic_Car_byAlgorithm();
void the_Crush_byTable();
void Caderita();
void delay(int);
void output(unsigned int);
void run(void (*fn)());
int controles_secuencia();

void Pink_Panther();


void delay(int a){
    while (a){
        a--;
    }
}


int go_in(char password[]) {

    cbreak();
    noecho();

    int error = 0;
    char c;
    char ingreso[5];
    do {
        printw("Ingrese la contraseña:\n");

        for (int i = 0; i < 5; i++) {
            c = getch();
            ingreso[i] = c;
            printw("*");
        }
        if(strcmp(password, ingreso) != 0){
            error++;
            clear();
            printw("\n Contraseña Incorrecta, intente de nuevo \n");
        }
        refresh();
    }while(error < 3 && strcmp(password, ingreso) != 0);
    echo();

    return strcmp(password, ingreso);
}

void run(void (*fn)()) {
    cbreak();
    noecho();

    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);

    clear();
    printw("Presione 'Esc' para volver al modo de selección.\n");
    printw("Utilice las flechas arriba/abajo para manejar la velocidad del patrón.\n\n");


    fn();

    keypad(stdscr, FALSE);
    nodelay(stdscr, FALSE);
    curs_set(1);

    clear();
    menu();
}

int controles_secuencia() {
    switch (getch()) {
        case 0x1B:
            return 1;
        case KEY_UP:
            if (velocidad_estandar > MAXVEL){
                velocidad_estandar -= 10000000;
                FILE *f = fopen("file.txt", "w");
                fprintf(f, "Integer: %d \n", velocidad_estandar);
                fclose(f);

            }
            break;
        case KEY_DOWN:
            if (velocidad_estandar < MINVEL){
                velocidad_estandar += 10000000;
                FILE *f = fopen("file.txt", "w");
                fprintf(f, "Integer: %d \n", velocidad_estandar);
                fclose(f);
            }

            break;
    }

    return 0;
}


void output(unsigned int a){
    int i;
    for (i = 7; i >= 0; --i) {
        if (a%2 == 0) { // status 1
            printw("-");
          //  digitalWrite(led[i], 1);
        }else { // status 0
            printw("*");
         //   digitalWrite(led[i], 0);
        }
        a = a/2;
    }
    printw("\r");
    refresh();
}

char dataCrush[]= {
        0x81,
        0x42,
        0x24,
        0x18,
        0x24,
        0x42,
        0x81
};

void the_Crush_byTable(){
    printw("Usted eligió el Choque\n");
    while (1){
        for (int  i = 0;  i <= 6; ++ i) {
            if (controles_secuencia())
                return;
            output(dataCrush[i]);
            delay(velocidad_estandar);
            //delayMillis(velocidad_estandar);


        }
    }
}

char dataCaderita[]= {
        0xF0,
        0XF,
        0XF0,
        0XF0,
        0XF1,
        0XF3,
        0XF1,
        0XF,
        0XF0,
        0XF,
        0XF,
        0X8F,
        0XCF,
        0X8F
};

void Caderita() {
    printw("Usted eligió la Caderita\n");
    while (1){
        for (int i = 0; i < 16; i++) {
            if (controles_secuencia())
                return;
            output(dataCaderita[i]);
            delay(velocidad_estandar);
          //  delayMillis(velocidad_estandar);
        }
    }

}

void Fantastic_Car_byAlgorithm() {
    printw("Usted eligió el auto Fantástico\n");
    while (1){
        if (controles_secuencia())
            return;
        for (char j = 0; j < 7; j++){
            output(potencia(2, j));
            delay(velocidad_estandar);
           // delayMillis(velocidad_estandar);
        }
        delay(velocidad_estandar-1000000);
        for (char i = 7; i >= 0; --i) {
            output(potencia(2, i));
            delay(velocidad_estandar);
           // delayMillis(velocidad_estandar);
        }
    }

}



char dataPink [] = {0x80, 0x40, 0x40, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x04, 0x04,
                    0x08, 0x10, 0x20};


void Pink_Panther(){
    printw("Usted eligió la Pantera Rosa\n");
    while (1){
        for (int i = 0; i<16; i++){
            if (controles_secuencia())
                return;
            output(dataPink[i]);
            delay(velocidad_estandar);
        }
    }
}


void menu() {
    nocbreak();
    echo();

    int selection;

    do{

        printw("--------------MENU---------------\n");
        printw("Seleccione una opción: \n");


        printw("1) Auto fantástico\n");
        printw("2) El choque\n");
        printw("3) La caderita\n");
        printw("4) El partido\n");
        printw("5) La Pantera Rosa\n");
        printw("0) Salir\n");
        printw(" \n");

        scanw("%d", &selection);


        switch(selection){
            case 0:
                break;
            case 1:
                printw("Usted eligió el auto Fantástico\n");
                run(Fantastic_Car_byAlgorithm);
                break;
            case 2:
                run(the_Crush_byTable);
                break;

            case 3:
                run(Caderita);
                break;

            case 4:
                run(tenis);
                break;
            case 5:
                run(Pink_Panther);
                break;
        }
    }while(selection != 0);

}




int main() {

//    pioInit();
//
//    for (int i=0; i<8;i++){
//        pinMode(led[i], OUTPUT);
//    }


    char password[6];

    strcpy(password, "12345");g

    initscr();
     if(go_in(password) == 0){
        clear();
        printw("\nBIENVENIDO AL SISTEMA\n");
        menu();
    }else{
        clear();
        printw("\nCONTRASEÑA INCORRECTA, NOS VIMOS\n");
        return 0;
    }


    printw("\nBIENVENIDO AL SISTEMA\n");
    menu();
    endwin();



    return 0;
}