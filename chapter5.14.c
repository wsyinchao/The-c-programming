/*
    Point to function and the point type void *,
    Rewrite quik_sort.

    gcc --std=c99 chapter5.14.c chapter5.7.c examine_string.c chapter1.9.c examine_quik_sort.c

    转成void *类型是时需要cast(即明确表明), 
    转回来的时候不用.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LEN 1000

extern int getline(FILE *fp, char line[], int max_len);
extern void print_lines(char *lineptr[], int nlines);
extern void quik_sort_plus(void *parr[], int left, int right, int (*cmp)(void *, void *) );

int main(int argc, char *argv)
{
    FILE *fp = fopen("chapter5.14.c", "r");
    if (fp == NULL) {
        printf("the special file opened failed.\n");
        return 1;
    }

    char *lines[MAX_LINES];
    int linesp = 0;
    char *p;

    int len = 0;
    char line[MAX_LINE_LEN];
    while ((len = getline(fp, line, MAX_LINE_LEN)) > 0){
        if (linesp >= MAX_LINES || (p = (char *)malloc(sizeof(char) * len + 1)) == NULL){
            printf("too many lines for read or no more space to hold the readed line.\n");
            return 2;
        }
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lines[linesp++] = p;
        }
    }
    quik_sort_plus((void **)lines, 0, linesp - 1, (int (*)(void *, void *))strcmp);
    print_lines(lines, linesp);
    // printf("How many the lines %d\n", linesp);

    fclose(fp);

    return 0;
}
