//
// Created by milena on 15/06/19.
//

#ifndef ARQUICOMPU_SPEED_CONTROL_H
#define ARQUICOMPU_SPEED_CONTROL_H


static const int DELAYBAJO = 40;

static const int DELAYMEDIO = 60;

static const int DELAYALTO = 80;


int speed(char character){
    int a = 60;

if (character == 38){
     a-=20;
}
if (character == 40){
     a+= 20;
}

return a;
}


#endif //ARQUICOMPU_SPEED_CONTROL_H
