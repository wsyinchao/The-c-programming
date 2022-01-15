/*Define a macro swap(t, a, b) that interchages two arguments
of type t. (Block structure will help).
*/

#include <stdio.h>

// #undef swap
#define swap(t, a, b) {t temp = a; a = b; b = temp;}

int main(void)
{
    int v1 = 10;
    int v2 = 20;
    swap(int, v1, v2);
    printf("%d %d\n", v1, v2);

    int *pv1 = &v1;
    int *pv2 = &v2;
    swap(int *, pv1, pv2);
    printf("%d %d\n", *pv1, *pv2);

    return 0;
}
