/* A comprasion against '\0' is redundant, sice the question 
    is merely whether the expression is zero.

    So all compression against '\0' is absence.
*/

void str_cp(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

int str_cmp(char *s, char *t)
{
    while (*s == *t && *s != '\0'){
        ++s;
        ++t;
    }

    return *s - *t;
}

unsigned int str_len(char *s)
{
    char *p = s;
    while (*p){
        ++p;
    }

    return p - s;
}

/*The s must be have enough space to hold characters that froms t.*/
void str_cat(char *s, char *t)
{
    while (*s != '\0'){
        ++s;
    }

    while (*s++ = *t++)
        ;
}

unsigned int str_end(char *s, char *t)
{
    int len_s = str_len(s);
    int len_t = str_len(t);

    s = s + len_s - 1;
    t = t + len_t - 1;

    while (len_t && len_s && *s == *t){
        --s;
        --t;
        --len_t;
        --len_s;
    }

    return len_t == 0 ? 1 : 0;
}

void str_ncp(char *s, char *t, int n)
{
    while (n-- && (*s = *t)){
        ++s;
        ++t;
    }

    *s = '\0';
}

void str_ncat(char *s, char *t, int n)
{
    while (*s){
        ++s;
    }

    while (n-- && (*s = *t)){
        ++s;
        ++t;
    }

    *s = '\0';
}

int str_ncmp(char *s, char *t, int n)
{
    while (--n && *s == *t && *s != '\0'){
        ++s;
        ++t;
    }

    return *s - *t;
}
