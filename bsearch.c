/* void 指针的转换需要重点复习... */

#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int len);
int cmp(const void *, const void *);

int main()
{
    int arr[20];
    for (int i = 0; i < 20; ++i){
        arr[i] = rand() % 20;
    }
    printArr(arr, 20);

    qsort(arr, 20, sizeof(int), cmp);
    printArr(arr, 20);

    int key = 7;
    int *result = bsearch(&key, arr, 20, sizeof(int), cmp);
    if (result != NULL){
        printf("%d\n", *result);
    }

    return 0;
}

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int cmp(const void *first, const void *second)
{
    if (*(int*)first < *(int*)second) {
        return 1;
    }
    else if (*(int*)first > *(int*)second){
        return -1;
    }
    else {
        return 0;
    }
}