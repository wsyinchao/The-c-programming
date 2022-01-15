/* write function any(s1, s2), which returns the first 
    location in the string s1 where any character from the
    string s2 occurs, or -1 if s1 contains no characters 
    from s2. (The standard library 'strpbrk' does the same
    job but returns a pointer to the location.)
*/

#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main()
{
    char ch1[] = "wsyinchao";
    char ch2[] = "daqwj";

    printf("%d\n", any(ch1, ch2));

    printf("The below is result that calling standard library strpbrk.\n");
    char *p = strpbrk(ch1, ch2);
    if (p != NULL){
        printf("%c\n", *p); // 指针加减法，指针转换
    }

    return 0;
}

int any(char s1[], char s2[])
{
    int result = -1;
    int j = 0;
    for (int i = 0; s2[i] != '\0'; ++i){
        j = 0;
        while (s1[j] != '\0' && s1[j] != s2[i]){
            ++j;
        }

        /*find the character in the s1 which from the s2.*/
        if (s1[j] != '\0'){
            if (result == -1){
                result = j;
            }
            else if (j < result){
                result = j;
            }
        }
    }

    return result;
}
