/* find the longest line */

#include <stdio.h>

#define MAX_LEN 1000

int getline(FILE *fp, char line[], int max_len);
void copy(char to[], char from[]);
int getLen(char line[]);

// int main()
// {
//     FILE *fp = fopen("chapter1.9.c", "r");
//     if (fp == NULL)
//         return 1;

//     int len;
//     int max;
//     char max_len_line[MAX_LEN];
//     char cur_len_line[MAX_LEN];

//     max = 0;
//     while ((len = getline(fp, cur_len_line, MAX_LEN)) > 0){
//         if (len > max){
//             max = len;
//             copy(max_len_line, cur_len_line);
//         }
//     }

//     if (max != 0)
//         printf("%s", max_len_line);

//     fclose(fp);
//     // printf("%d\n", getLen("hello\0"));
//     return 0;
// }

int getline(FILE *fp, char line[], int max_len)
{
    if (fp == NULL)
        return 0;

    int c;
    int i;
    for (i = 0; i < max_len - 1 && (c = getc(fp)) != EOF && c != '\n'; ++i){
        line[i] = c;
    }
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';

    return getLen(line);
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int getLen(char line[])
{
    int len = 0;
    while (line[len++] != '\0')
        ;

    return len - 1;
}
