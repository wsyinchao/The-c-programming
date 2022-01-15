#include <stdio.h>
#include "GetCh.h"

#define BUFFSIZE 1000

char buff[BUFFSIZE];
char bufp = 0;

int getch(void)
{
    return bufp > 0 ? buff[--bufp] : getchar();
}

void ungetch(char ch)
{
    if (bufp >= BUFFSIZE) {
        printf("ungetch: too many characters.");
    }
    else {
        buff[bufp++] = ch;
    }
}
