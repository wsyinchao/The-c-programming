/*This illustrate How the void* type pointer wo works.
*/
/*Any pointer can be cast to void * and back again
    without loss of information.
*/

/*The return value should be 1 when first argument is great than the second argument that both from
    cmp function, and 0 for equal and -1 for less.
*/
void quik_sort_plus(void *parr[], int left, int right, int (*cmp)(void *, void *) )
{
    if (left >= right){
        return ;
    }

    int start = left;
    int end = right;
    void *key = parr[left];
    while (left < right){
        while (left < right && cmp(parr[right], key) >= 0){
            --right;
        }
        if (left < right){
            parr[left++] = parr[right];
        }

        while (left < right && cmp(parr[left], key) <= 0){
            ++left;
        }
        if (left < right){
            parr[right--] = parr[left];
        }
    }

    //From now, left should be equal to right.
    parr[left] = key;
    quik_sort_plus(parr, start, left - 1, cmp);
    quik_sort_plus(parr, left + 1, end, cmp);
}
