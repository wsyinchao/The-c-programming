/*Word couting.
The best solution is map, but here using binary tree.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define v 0x7fffffff //4 bytes
#define LEN 50

// tree node 
struct TNode {
    char *word;
    int count;
    struct TNode *left;
    struct TNode *right;
};

char *getword(FILE *pf);
struct TNode *addtree(struct TNode *p, char *word);
void printtree(struct TNode *p);

int main()
{
    char *pw = NULL;
    struct TNode *root;
    FILE *pf = fopen("chapter6.1.c", "r");
    if (pf == NULL){
        return 1;
    }

    while ((pw = getword(pf)) != NULL){
        root = addtree(root, pw);
        // printf("%s\n", pw);
    }

    printtree(root);
    fclose(pf);
    return 0;
}

char *getword(FILE *pf)
{
    if (pf == NULL){
        return NULL;
    }

    char ch;
    do { // skip white space.
        ch = fgetc(pf);
    } while (!isalpha(ch) && ch != EOF);

    if (ch == EOF){
        return NULL;
    }

    char charr[LEN] = "";
    int i = 0;
    do {
        charr[i++] = ch;
        ch = fgetc(pf);
    } while (i < LEN -1 && isalpha(ch) && ch != EOF);
    charr[i] = '\0';

    char *ret = (char *)malloc(sizeof(char) * strlen(charr) + 1);
    if (ret == NULL) {
        return NULL;
    }
    strcpy(ret, charr);
    return ret;
}

struct TNode *addtree(struct TNode *p, char *word)
{
    if (p == NULL){ // add new tree node.
        p = (struct TNode*)malloc(sizeof(struct TNode));
        if (p == NULL)
            return NULL;
        
        p->word = word;
        p->count = 1;
        p->left = p->right = NULL;

        return p;
    }

    int cond = strcmp(p->word, word);
    if (cond == 0){
        p->count++;
    }
    else if (cond > 0){
        p->left = addtree(p->left, word);
    }
    else if (cond < 0) {
        p->right = addtree(p->right, word);
    }

    return p;
}

void printtree(struct TNode *p)
{
    if (p == NULL) {
        return ;
    }

    printtree(p->left);
    printf("%s--%d\n", p->word, p->count);
    printtree(p->right);
}
