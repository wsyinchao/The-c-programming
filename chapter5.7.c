/* Write program to sort an array that saved text line.

    read all the line of input
    sort them
    print them in order
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1000
#define MAX_LINE_LEN 1000

extern int getline(FILE *fp, char line[], int max_len);
extern int str_cmp(char *s, char *t);
extern void str_cp(char *s, char *t);

int read_lines(char *lineptr[], int maxlines);
void quik_sort(char *lineptr[], int left, int right);
void print_lines(char *lineptr[], int nlines);
void swap(char *lineptr[], int i, int j);

// int main()
// {
//     char *lines[MAX_LINE];
//     int nlines = read_lines(lines, MAX_LINE);
//     if (nlines != -1){
//         quik_sort(lines, 0, nlines - 1);
//         print_lines(lines, nlines);
//     }

//     return 0;
// }

int read_lines(char *lineptr[], int maxlines)
{
    FILE *fp = fopen("chapter5.7.c", "r");

    int nlines = 0;
    int len = 0;
    char line[MAX_LINE_LEN];
    char *p;
    while ((len = getline(fp, line, MAX_LINE_LEN)) > 0){
        if (nlines >= maxlines || (p = (char *)malloc(sizeof(char) * len + 1)) == NULL){ // 没有与之对应的 free 来释放内存!!!
            return -1;
        }
        else {
            /*maybe exclude the newline.*/
            line[len - 1] = '\0';

            str_cp(p, line);
            lineptr[nlines++] = p;
        }
    }

    if (fp != NULL){
        fclose(fp);
    }

    return nlines;
}

void quik_sort(char *lineptr[], int left, int right)
{
    if (left >= right){
        return ;
    }
    // printf("the right is %d\n", right);

    char *key = lineptr[left];
    int start = left;
    int end = right;
    while (left < right){
        while (left < right && str_cmp(lineptr[right], key) >= 0){
            --right;
        }
        if (left < right){
            lineptr[left++] = lineptr[right];
        }

        while (left < right && str_cmp(lineptr[left], key) <= 0){
            ++left;
        }
        if (left < right){
            lineptr[right--] = lineptr[left];
        }
    }

    // printf("through here!\n");

    lineptr[left] = key; // 此时 left == right. 一次操作完成.

    quik_sort(lineptr, start, left - 1);
    quik_sort(lineptr, left + 1, end);
}

void print_lines(char *lineptr[], int nlines)
{
    for (int i = 0; i < nlines; ++i){
        printf("%s\n", lineptr[i]);
    }
}

void swap(char *lineptr[], int i, int j)
{
    char *temp = lineptr[i];
    lineptr[i] = lineptr[j];
    lineptr[j] = temp;
}
