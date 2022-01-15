#include <stdio.h>
#include <limits.h>

int main()
{
    /* determine the ranges of char, short, int, and long variables, both signed and unsigned
    by printing appropriate values from standard headers and by direct computation.
    Harder if you compute them: determine the ranges of the various floating-point types. */

    /*Anything else is define in file limits.h*/
    char ch_schar_max = SCHAR_MAX;
    char ch_schar_min = SCHAR_MIN;
    printf("%d\n", ch_schar_min);

    /*Determing the ranges of the various floating-point types.*/
    /*to do*/

    printf("%.3f\n", 1e-2);

    /**/
    char ch = -1;
    int in;
    in = ch;
    printf("%d\n", in); // -1
    ch = in;
    printf("%d\n", ch); // -1

    return 0;
}
