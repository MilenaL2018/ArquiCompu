
#include "string.h"
#include <ncurses.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "potencia.h"
#include <stdlib.h>
#include "KBHIT.h"



int VEL = 700;
int MAXVEL = 30;
int MINVEL = 100;



void menu();
int go_in(char*);
void delayc(int);
void Fantastic_Car_byAlgorithm();
void the_Crush_byTable();
void Caderita();

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

    initscr();
    keypad(stdscr, 1);
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
            printw("\n Contraseña Incorrecta, intente de nuevo \n");
        }
    }while(error < 3 && strcmp(password, ingreso) != 0);
    echo();
    endwin();
    return strcmp(password, ingreso);
}
//
//bool speed_control() {
//    initscr();
//    noecho();
//    cbreak();
//    int c;
//    keypad(stdscr, TRUE);
//    nodelay(stdscr, TRUE);
//    c = getch();
//    nocbreak();
//
//
//    if (c == 'e'){
//        echo();
//        endwin();
//        return false;
//    }
//
//    if (c == KEY_UP){
//        if (VEL > MAXVEL){
//            VEL -= 10;
//            return true;
//        }
//    }else {
//        if (VEL < MINVEL){
//            VEL += 10;
//            return true;
//        }
//    }
//
//    echo();
//    endwin();
//
//    return true;
//}


void delayc(int v) {

        unsigned char ch1;
        unsigned char ch2;

        while(v){

            v--;

            noecho();
            if (kbhit())
            {
                ch1 = getch();
                if(ch1 == 224 || ch1 == 0){

                    ch2 = getch();

                    switch (ch2)
                    {
                        case 72:               // Arriba
                            if(v > MINVEL)
                                v-=10;
                            break;
                        case 80:               // Abajo
                            if(v < MAXVEL)
                                v+=10;
                            break;
                        default:
                            break;
                    }
                }else if(ch1 == 13){// Enter
                    return;
                }
            }
        }
        echo();

}



void output(unsigned int a){
    int i;
    for (i = 7; i >= 0; --i) {
        if (a%2 == 0) {
            printf("-");
        }else {
            printf("*");
        }
        a = a/2;
    }
    printf("\r");
    fflush(stdout);
}

//void Fantastic_Car_byAlgorithm() {
//    for (char j = 0; j < 7; j++){
//        output(potencia(2, j));
//       // outputLED(j);
//        delayc(VEL);
//    }
//    delayc(VEL);
//    for (char i = 7; i >= 0; --i) {
//        output(potencia(2, i));
//       // outputLED(i);
//        delayc(VEL);
//    }
//}

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
        output(dataCrush[i]);
        //outputLED(dataCrush[i]);
        int v = VEL;
        delayc(v);
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
        output(dataCaderita[i]);
        // outputLED(dataCaderita[i]);
        int v = VEL;
        delayc(v);

    }
}

void Fantastic_Car_byAlgorithm() {
    int v = VEL;
    for (char j = 0; j < 7; j++){
        output(potencia(2, j));
        // outputLED(j);
        delayc(v);
    }
    delayc(v-10);
    for (char i = 7; i >= 0; --i) {
        output(potencia(2, i));
        // outputLED(i);
        delayc(v);
    }

}






void menu() {
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
                break;
            case 1:
                system("clear");
                printf("Seleccionaste el Auto Fantástico\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                printf("\nPresione e para salir\n");
                Fantastic_Car_byAlgorithm();
                break;
            case 2:
                printf("Seleccionaste el Choque\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                printf("\nPresione e para salir\n");
                the_Crush_byTable();
                break;

            case 3:
                system("clear");
                printf("Seleccionaste la Caderita\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                printf("\nPresione e para salir\n");
                Caderita();

                break;

            case 4:
                system("clear");
                printf("Seleccionaste Tenis\n");
                printf("Flecha arriba aumenta velocidad, flecha abajo disminuye velocidad\n");
                printf("\nPresione e para salir\n");

                break;
            default:
                break;
        }
    }while(selection != 0);

}




int main() {

    char password[6];

    strcpy(password, "12345");

    if(go_in(password) == 0){
        printf("\nBIENVENIDO AL SISTEMA\n");

        menu();
    }else{
        printf("\nCONTRASEÑA INCORRECTA, NOS VIMOS\n");
        return 0;
    }

    return 0;
}



