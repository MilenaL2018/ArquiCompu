//
// Created by milena on 29/05/19.
//

#ifndef ARQUICOMPU_VERIFICATION_H
#define ARQUICOMPU_VERIFICATION_H

#include <string.h>
#include <stdio.h>

char verification(char password[], char real[]){
    char warning;
    if (strcmp (real, password) == 0){
        warning = 'C';
    }else {
        warning = 'I';
    }
    return warning;
}


#endif //ARQUICOMPU_VERIFICATION_H
