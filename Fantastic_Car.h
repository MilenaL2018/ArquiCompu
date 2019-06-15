//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_FANTASTIC_CAR_H
#define ARQUICOMPU_FANTASTIC_CAR_H

#include "delay.h"
#include "output.h"
#include "potencia.h"
#include <stdio.h>
#include <stdlib.h>
#include "kbhit.h"



void Fantastic_Car_byAlgorithm() {
    int j;
        for (j = 0; j < 7; j++){
            output(potencia(2, j));
            if (!kbhit())
                retardo(speed('0'));
            else{
                char s = getchar();
                retardo(speed(s));
            }
        }
    retardo(DELAYMEDIO);
        for (int i = 7; i >= 0; --i) {
            output(potencia(2, i));
            if (!kbhit())
                retardo(speed('0'));
            else{
                char s = getchar();
                retardo(speed(s));
            }
    }
}



int dataFantasticCar[] = {
        0x01,
        0x02,
        0x04,
        0x08,
        0x10,
        0x20,
        0x40,
        0x80,
        0x80,
        0x40,
        0x20,
        0x10,
        0x08,
        0x04,
        0x02,
        0x01
};




void Fantastic_Car_byTable(){
    for (int i = 0; i <= 15; i++) {
        output(dataFantasticCar[i]);
        if (!kbhit())
            retardo(speed('0'));
        else{
            char s = getchar();
            retardo(speed(s));
        }
    }
}


#endif //ARQUICOMPU_FANTASTIC_CAR_H
