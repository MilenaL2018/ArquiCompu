//
// Created by milena on 25/06/19.
//

#ifndef ARQUICOMPU_TENIS_H
#define ARQUICOMPU_TENIS_H


unsigned int velocidad_estandar = 80000000;
const unsigned int MINVEL = 130000000;
const unsigned int MAXVEL = 10000000;



void tenis() {
    printw("Usted eligió el partido de tenis\n");
    while (1) {
        if (controles_secuencia())
            return;

        for (int i= 1; i < 7; i++){
            output(potencia(2, i));
            delay(velocidad_estandar);
            delayMillis(velocidad_estandar);
        }
        for (int j = 6; j > 0; --j) {
            output(potencia(2, j));
            delay(velocidad_estandar);
            delayMillis(velocidad_estandar);
        }
    }
}

#endif //ARQUICOMPU_TENIS_H
