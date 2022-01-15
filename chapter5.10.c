/*write the program which evaluates a reverse 
    Polish expression from the command line, 
    where each operator or operand is a separate 
    argument. For example, 

    expr 2 3 4 + *
    evaluates 2 * (3 + 4)

    Notation:
        Because the character '*' type from keyboard is 
        defference to it that type from this file.
        Now, use character 'x' instead of '*' for multiple 
        operation.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 100

void print_arr(char *buff[]);
long compute(long n1, long n2, char operator);

int main(int argc, char *argv[])
{
    char *buff[MAX_LEN] = {NULL};//set the value of each element of arr is 0;
    int bufflen = 0;

    while (--argc > 0 && bufflen < MAX_LEN){
        // printf((argc > 1) ? "%s " : "%s\n", *++argv);
        buff[bufflen++] = *++argv;
    }
    // print_arr(buff);

    long result = 0;
    char operators[MAX_LEN] = {0};
    int opelen = 0;
    while (bufflen-- > 0){
        if (strcmp(buff[bufflen], "+") == 0 ||
            strcmp(buff[bufflen], "-") == 0 ||
            strcmp(buff[bufflen], "x") == 0 ||
            strcmp(buff[bufflen], "/") == 0){
                operators[opelen++] = *buff[bufflen];
        }
        else if (isdigit(*buff[bufflen])){ //以第一个数字来判断是否是数字
            // begine compute
            long operand = strtol(buff[bufflen], NULL, 10);
            while (opelen > 0 && bufflen > 0){
                long operand2 = strtol(buff[--bufflen], NULL, 10);
                operand = compute(operand2, operand, operators[--opelen]);
            }
            result = operand;
        }
        else {
            // skeep other string consist of characters.
        }
    }

    printf("%d\n", result);

    return 0;
}

void print_arr(char *buff[])
{
    while (*buff != NULL){
        printf("%s\n", *buff++);
    }
}

long compute(long n1, long n2, char operator)
{
    switch(operator){
        case '+':
            return n1 + n2;
            break;
        case '-':
            return n1 - n2;
            break;
        case 'x':
            return n1 * n2;
            break;
        case '/':
            return n1 / n2;
            break;
        default:
            return n1;
            break;
    }
}
