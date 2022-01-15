#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

int htoi(char *hexs);

int main()
{
    char * hexsa[] = {
        "0x13fa",
        "0Xasdf",
        "0xf",
        "0xff",
        "0x7fffffff",
        "0x80000001", // 负数是用补码计算的...
    };

    int n = 6; // hexsa 的长度.
    while (n--){
        printf("%d\n", htoi(hexsa[n]));
    }

    printf("below is standard library\n");
    n = 6; // hexsa 的长度.
    while (n--){
        printf("%d\n", strtol(hexsa[n], NULL, 16));
    }

    char *unconverted = "";
    strtol(hexsa[1], &unconverted, 16);
    printf("%s\n", unconverted); // sdf

    return 0;
}

int htoi(char *hexs)
{
    assert(hexs != NULL);
    if (hexs == NULL){
        return 0;
    }

    if (hexs[0] != '0' || (hexs[1] != 'x' && hexs[1] != 'X')){
        return 0;
    }

    int i = 2;
    int result = 0;
    while (hexs[i] != '\0'){
        int each_value = 0;

        if (hexs[i] >= 'a' && hexs[i] <= 'f'
            || hexs[i] >= 'A' && hexs[i] <= 'F'){
                char ch = tolower(hexs[i]);
                each_value = 10 + (ch - 'a');
            }
        else if (hexs[i] >= '0' && hexs[i] <= '9') {
            each_value = hexs[i] - '0';
        }
        else {
            // do nothing.
        }

        // 满16进1
        result = result * 16 + each_value;

        ++i;
    }

    return result;
}
