//
// Created by milena on 15/06/19.
//

#ifndef ARQUICOMPU_SPEED_CONTROL_H
#define ARQUICOMPU_SPEED_CONTROL_H





#include <ncurses.h>

int speed(int a){
    int speed = 60;
    if (a==72)
        speed-=20;
    else if (a==80)
        speed+= 20;

return speed;
}


#endif //ARQUICOMPU_SPEED_CONTROL_H
