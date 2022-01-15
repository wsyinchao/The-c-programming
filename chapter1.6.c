#include <stdio.h>

#define ARR_LEN 12

void printArr(int *arr, int len);
void printHorizontalHistogram(int *arr, int len);
void printVerticalHistogram(int *arr, int len);

int main()
{
    FILE *p = fopen("chapter1.6.c", "r");

    if (p != NULL){
        int c;
        int arr[ARR_LEN] = {0}; /* 所有初始化为0 */
        while ((c = getc(p)) != EOF){
            if (c >= '0' && c <= '9')
                ++arr[c - '0'];

            if (c == '\n' || c == ' ' || c == '\t')
                ++arr[10];
            else
                ++arr[11];
        }
        // printHorizontalHistogram(arr, ARR_LEN);
        // printVerticalHistogram(arr, ARR_LEN);
        printArr(arr, ARR_LEN);
    }

    fclose(p);

    return 0;
}

void printArr(int *arr, int len)
{
    for (int i = 0; i < len; ++i){
        printf("%d ", arr[i]);
    }
    putchar(10); /*print \n*/
}

void printHorizontalHistogram(int *arr, int len)
{
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < arr[i]; ++j){
            printf("*");
        }
        putchar(10);
    }
}

void printVerticalHistogram(int *arr, int len)
{
    int most_hight = 0;
    for (int i = 0; i < len; ++i){
        if (arr[i] > most_hight)
            most_hight = arr[i];
    }

    while (most_hight){
        for (int i = 0; i < len; ++i){
            if (arr[i] >= most_hight)
                printf("*");
            else
                printf(" ");
        }
        putchar(10);

        --most_hight;
    }
}
