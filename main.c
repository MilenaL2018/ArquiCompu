
#include "potencia.h"
#include <stdio.h>
#include <ncurses.h>
//#include "EasyPIO.h"
#include <string.h>



unsigned int global_speed = 500;
const unsigned int min_speed_cap = 1000;
const unsigned int max_speed_cap = 100;

void menu();
int go_in(char*);
//void delayc(int);
void Fantastic_Car_byAlgorithm();
void the_Crush_byTable();
void Caderita();


void delay(int a){
    for (int j = 0; j < a; j++) {
        unsigned int i = 0x4fffff; //raspberry 0x3fffff
        while (i)i--;
    }
}


//void outputLED(unsigned char);
//
//void outputLED(unsigned char b){
//    const char led[] = {14,15,18,23,25,8,7};
//    const char sw[] = {12,16,20,21};
//    for(int i = 8; i > 0; i--){
//        if((b&1) == 1){
//            //prender
//            digitalWrite(led[i], OUTPUT);
//        }else digitalWrite(led[i], 0); //apagar
//        b = b >> 1;
//    }
//}


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
    printw("Presione 'q' para volver al modo de selección.\n");
    printw("Utilice las flechas arriba/abajo para manejar la velocidad del patrón.\n\n");

    echo();
    fn();

    keypad(stdscr, FALSE);
    nodelay(stdscr, FALSE);
    curs_set(1);

    clear();
    menu();
}

int pattern_controls() {
    switch (getch()) {
        case 'q':
            return 1;
        case KEY_UP:
            if (global_speed > max_speed_cap)
                global_speed -= 100;
            break;
        case KEY_DOWN:
            if (global_speed < min_speed_cap)
                global_speed += 100;
            break;
    }
    return 0;
}
//
//void delayc(int v) {
//    cbreak();
//    noecho();
//
//    unsigned char ch1;
//        unsigned char ch2;
//
//        while(v){
//
//            v--;
//
//             ch1 = getch();
//                if(ch1 == 224 || ch1 == 0){
//
//                    ch2 = getch();
//
//                    switch (ch2)
//                    {
//                        case 72:               // Arriba
//                            if(v > MINVEL)
//                                v-=10;
//                            break;
//                        case 80:               // Abajo
//                            if(v < MAXVEL)
//                                v+=10;
//                            break;
//                        default:
//                            break;
//                    }
//                }else if(ch1 == 13){// Enter
//                    return;
//                }
//            }
//}



void output(unsigned int a){
    int i;
    for (i = 7; i >= 0; --i) {
        if (a%2 == 0) {
            printw("-");
        }else {
            printw("*");
        }
        a = a/2;
    }
    printw("\r");
    clear();
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
    for (int  i = 0;  i <= 6; ++ i) {
        if (pattern_controls())
            return;
        output(dataCrush[i]);
        //outputLED(dataCrush[i]);
//        int v = VEL;
        delay(global_speed);
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
    for (int i = 0; i < 16; i++) {
        if (pattern_controls())
            return;
        output(dataCaderita[i]);
        // outputLED(dataCaderita[i]);
       // int v = VEL;
        delay(global_speed);

    }
}

void Fantastic_Car_byAlgorithm() {
    if (pattern_controls())
        return;
   // int v = VEL;
    for (char j = 0; j < 7; j++){
        output(potencia(2, j));
        // outputLED(j);
        delay(global_speed);
    }
    delay(global_speed-10);
    for (char i = 7; i >= 0; --i) {
        output(potencia(2, i));
        // outputLED(i);
        delay(global_speed);
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
        printw("4) funcion 2\n");
        printw("0) Salir\n");
        printw(" \n");

        scanw("%d", &selection);

        switch(selection){
            case 0:
                break;
            case 1:
               run(Fantastic_Car_byAlgorithm);
                break;
            case 2:
                run(the_Crush_byTable);
                break;

            case 3:
                run(Caderita);

                break;

            case 4:

                break;
            default:
                break;
        }
    }while(selection != 0);

}




int main() {

    char password[6];

    strcpy(password, "12345");

    initscr();

    if(go_in(password) == 0){
        printw("\nBIENVENIDO AL SISTEMA\n");
        menu();
    }else{
        printw("\nCONTRASEÑA INCORRECTA, NOS VIMOS\n");
        return 0;
    }

    endwin();



    return 0;
}



