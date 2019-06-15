//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_OUTPUT_H
#define ARQUICOMPU_OUTPUT_H

#include <stdio.h>
#include <stdlib.h>



int output(unsigned int a){
    int i;
    for (i = 7; i >= 0; --i) {
        if (a%2 == 0) {
            printf("-");
        }else {
            printf("*");
        }
        a = a/2;
    }
    printf("\r");
    fflush(stdout);
}


#endif //ARQUICOMPU_OUTPUT_H
