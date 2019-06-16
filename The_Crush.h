//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_THE_CRUSH_H
#define ARQUICOMPU_THE_CRUSH_H

#include<stdio.h>
#include<stdlib.h>
#include "kbhit.h"

void the_Crush_byTable();

int dataCrush[]= {
        0x81,
        0x42,
        0x24,
        0x18,
        0x24,
        0x42,
        0x81
};

void the_Crush_byTable(int a){
    for (int  i = 0;  i <= 6; ++ i) {
        output(dataCrush[i]);
            retardo(speed(a));
    }
}


#endif //ARQUICOMPU_THE_CRUSH_H
