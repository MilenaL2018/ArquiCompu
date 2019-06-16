
#include "menu.h"
#include "go_in.h"
#include "string.h"





int main() {

    char password[6];

    strcpy(password, "12345");

   char real[6];

   printf("Ingrese su contraseña: \n");

     for (int i= 0; i < 5; i++){
         int p = getch1();
         real[i] = p;
        putchar('*');
     }

    system("clear");
    go_in(password, real);

   return 0;
}



