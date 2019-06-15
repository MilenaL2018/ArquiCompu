//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_CADERITA_H
#define ARQUICOMPU_CADERITA_H

#include<stdio.h>
#include<stdlib.h>
#include "kbhit.h"

int datoCaderita[]= {
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

void Caderita(){
    for(int i = 0; i < 16; i++){
        output(datoCaderita[i]);
        if (!kbhit())
            retardo(speed('0'));
        else{
            char s = getchar();
            retardo(speed(s));
        }

    }
}



#endif //ARQUICOMPU_CADERITA_H
