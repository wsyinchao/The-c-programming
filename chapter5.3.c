/*??? getchar 是怎么做到等待输入的*/

/* gcc --ctd=c99 chapter5.3.c examine_string.c GetCh.c */

#include <stdio.h>
#include <ctype.h>
#include "GetCh.h"

int getInt(int *np);

extern void str_cp(char *s, char *t);
extern int str_cmp(char *s, char *t);
extern unsigned int  str_len(char *s);
extern void str_cat(char *s, char *t);
extern unsigned int str_end(char *s, char *t);
extern void str_ncp(char *s, char *t, int n);
extern void str_ncat(char *s, char *t, int n);
extern int str_ncmp(char *s, char *t, int n);

int main()
{
    // int out;
    // int status = getInt(&out);
    // if (status != 0 && status != EOF){
    //     printf("%d\n", out);
    // }

    char ch1[16] = "wsyinchao";
    char *ch2 = "yin";
    printf("%d %d\n", str_len(ch1), str_len(ch2));

    str_cat(ch1, ch2);
    printf("%s\n", ch1);

    str_ncat(ch1, ch2, 2);
    printf("%s\n", ch1);

    str_cp(ch1, ch2);
    printf("%s\n", ch1);

    str_ncp(ch1, ch2, 10);
    printf("%s\n", ch1);

    str_cat(ch1, ch2);
    printf("%s\n", ch1);
    printf("%d\n", str_cmp(ch1, ch2));
    str_cp(ch1, ch2);
    printf("%d\n", str_cmp(ch1, ch2));

    str_cat(ch1, ch2);
    printf("%d\n", str_ncmp(ch1, ch2, 3));

    str_cat(ch1, "c");
    printf("%s\n", ch1);
    printf("%d\n", str_end(ch1, ch2));

    str_cp(ch1, "yin");
    printf("%d\n", str_end(ch1, ch2));

    return 0;
}

int getInt(int *pn)
{
    int c, sign;
    while (isspace(c = getch())) /*skip white space*/
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch()){
        *pn = *pn * 10 + (c - '0');
    }
    *pn = *pn * sign;
    if (c != EOF){
        ungetch(c);
    }
    return c;
}
