
#include "verification.h"
#include "menu.h"
#include "go_in.h"
#include <unistd.h>
#include <stdio.h>
#include "string.h"





int main() {

    char password[6];

    strcpy(password, "12345");

   char real[6];

   printf("Ingrese su contraseña: \n");

     for (int i= 0; i < 5; i++){
         int p = getch();
         real[i] = p;
        putchar('*');
     }

    go_in(password, real);

   return 0;

}



