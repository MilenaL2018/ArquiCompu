//
// Created by milena on 20/06/19.
//

#ifndef ARQUICOMPU_KBHIT_H
#define ARQUICOMPU_KBHIT_H
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>
/*
 * Este es un programa para leer el teclado....
 */

static struct termios initial_settings, new_settings;
static int peek_character = -1;
void init_keyborad();
void close_keyborad();
int kbhit();
int readch();

void init_keyborad(){
    tcgetattr(0, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_cflag &= ~ICANON;
    new_settings.c_cflag &= ~ECHO;
    new_settings.c_cflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;

}
void close_keyborad(){
    tcsetattr(0, TCSANOW, &initial_settings);

}
int kbhit(){
    char ch;
    int nread;
    if(peek_character != -1 )
        return 1;
    new_settings.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &initial_settings);
    nread = read(0, &ch, 1);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &initial_settings);
    if(nread == 1){
        peek_character = ch;
        return 1;
    }
    return 0;

}
int readch(){
    char ch;
    if(peek_character != -1){
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0, &ch, 1);
    return ch;
}
void detectarpulsaciones(){
    int ch = 0;
    while(ch != 'q'){
        printf("Loping\n");
        sleep(1);
        if(kbhit()){
            ch = readch();
            printf("Your key is %c \n", ch);

        }

    }
    close_keyborad();
    exit(0);
}
void modificar(){
    int ch = 0;
    while(ch != '0'){
        sleep(1);
        if(kbhit()){
            ch = readch();
            printf("Your key is %c \n", ch);

        }

    }
    close_keyborad();
    exit(0);
}
#endif //ARQUICOMPU_KBHIT_H
