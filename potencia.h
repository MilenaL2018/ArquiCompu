//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_POTENCIA_H
#define ARQUICOMPU_POTENCIA_H


unsigned int potencia(unsigned int base, unsigned int exp) {
    if (exp == 0)
        return 1;

    return base * potencia (base, exp-1);
}


#endif //ARQUICOMPU_POTENCIA_H
