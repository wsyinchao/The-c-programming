/*
    根据文件指针位置，设置从后往前读取，
    统计\n出现的个数，匹配要输出的行，
    然后从当前位置往下读取文件.

    还有一个 -f 的实现，这里是保持一个
    循环，定时检测是否有新的内容写入了
    文件，如果有，则将新内容输出到stdout.
    todo...
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern int getline(FILE *fp, char line[], int max_len);

int main(int argc, char *argv[])
{
    char *file_name = "tail_plus.c";
    int n = 10;
    if (argc >= 3){
        file_name = *++argv;
        // This style for use of point is hard to understand.
        // less to use it.
        if (**++argv == '-'){
            n = (int) strtol(++(*argv), NULL, 10);
        }
    }

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        return 1;
    }

    char ch;
    long t = 0;
    fseek(fp, 0, SEEK_END);
    while (n >= 0 && ftell(fp) > 0){ // 0 起始位置, 
        fseek(fp, --t, SEEK_END);
        ch = fgetc(fp); // Notice: 这里每一次读取的时候会改变文件流中指针的位置.
        fseek(fp, t, SEEK_END); // 所以，再设一次.

        if (ch == '\n'){
            --n;
        }
    }

    if (n < 0){
        fseek(fp, 1, SEEK_CUR); //跳过当前换行符
    }
    while ((ch = fgetc(fp)) != EOF){
        putchar(ch);
    }

    // fseek(fp, LONG_MAX, SEEK_END);
    // fgetc(fp); // nothing , 内部有上下限限制.

    fclose(fp);

    return 0;
}
