#include <stdio.h>
#include <string.h>

#define ARR_LEN 1000

/* delete all c from s */
void squeeze(char s[], char c);
void strcat_(char to[], char from[]);

int main()
{
    char cha[] = "wsyinchao";
    squeeze(cha, 'o');
    printf("%s\n", cha);

    char cha2[ARR_LEN] = "hello, man.";
    strcat(cha, cha2);
    printf("%s\n", cha);

    return 0;
}

void squeeze(char s[], char c)
{
    int j = 0;
    for (int i = 0; s[i] != '\0'; ++i){
        if (s[i] != c){
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

void strcat_(char to[], char from[])
{
    int i = 0;
    while (to[i] != '\0'){
        ++i;
    }

    int j = 0;
    while ((to[i++] = from[j++]) != '\0'){
        ;
    }
}
