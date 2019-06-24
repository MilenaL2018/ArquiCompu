//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_DELAY_H
#define ARQUICOMPU_DELAY_H



void delay(int a){
    for (int j = 0; j < a; j++) {
      unsigned int i = 0x4fffff; //raspberry 0x3fffff
        while (i)i--;
    }
}




#endif //ARQUICOMPU_DELAY_H
