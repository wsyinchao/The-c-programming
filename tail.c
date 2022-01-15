/*write a program tail, which prints the last n lines
    of its input. By default n is 10, let us say, but
    can be changed by an optional argument, so that 
    tail -n
    prints the last n lines. The program should rationally 
    no matter how unrasonable the input or the value of n.
    Write the program so it makes the best use of available 
    storage; lines should be stored as in the sorting program 
    of Section 5.6, not in a two-dimensional array of fixed size.

    Notice: How to read file begining from the end?
    The tail program come from UNIX system is How to implement???

    A failed program.

    详情参考 tail_plus.c)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 1000
#define MAX_LINE_LEN 1000

extern int getline(FILE *fp, char line[], int max_len);

int main(int argc, char *argv[])
{
    char *file_name = NULL;
    int n = 10;
    if (argc >= 3){
        file_name = *++argv;
        // This style for use of point is hard to understand.
        // less to use it.
        if (**++argv == '-'){
            n = (int) strtol(++(*argv), NULL, 10);
        }
    }
    printf("The file name for got is %s\n", file_name);
    printf("Then number is %d\n", n);

    // get filename.
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL){
        return 1;
    }

    // read line by line.
    int len;
    char line[MAX_LINE_LEN];
    char *lines[MAX_LINES];
    int linep = 0;
    while ((len = getline(fp, line, MAX_LINE_LEN)) > 0){
        char *p = (char *) malloc(sizeof(char) * len + 1);
        if (p == NULL) {
            break;
        }

        strcpy(p, line);
        p[len - 1] = '\0'; // remove the newline character.
        lines[linep++] = p;
    }

    // print the last n lines.
    for (int i = (linep - n >= 0) ? linep - n : 0;
        i < linep; ++i){
            printf("%s\n", lines[i]);
    }

    fclose(fp);

    return 0;
}
