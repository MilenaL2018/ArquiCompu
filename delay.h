//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_DELAY_H
#define ARQUICOMPU_DELAY_H

#include <ncurses.h>
#include <termios.h>
#include <sys/ioctl.h>

void retardo(int a){
    for (int j = 0; j < a; j++) {
      unsigned int i = 0x4fffff; //raspberry 0x3fffff
        while (i)i--;
    }
}




#endif //ARQUICOMPU_DELAY_H
