//
// Created by milena on 15/06/19.
//

#ifndef ARQUICOMPU_KBHIT_H
#define ARQUICOMPU_KBHIT_H

#include <sys/ioctl.h>
#include <termios.h>
#include <stdbool.h>


bool kbhit()
{
    struct termios term;
    tcgetattr(0, &term);

    struct termios term2;
    term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}

#endif //ARQUICOMPU_KBHIT_H
