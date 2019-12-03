#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../common/getword.c"

#define MAXWORD 32

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *talloc()
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strdump(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}
struct tnode *addtree(struct tnode *node, char *word)
{
    int cond;
    if (node == NULL) {
        node = talloc();
        node->word = strdump(word);
        node->count = 1;
        node->left = NULL;
        node->right = NULL;
    } else if ((cond = strcmp(word, node->word)) == 0) {
        node->count++;
    } else if (cond < 0) {
        node->left = addtree(node->left, word);
    } else {
        node->right = addtree(node->right, word);
    }
    return node;
}

void printtree(struct tnode *node)
{
    if (node != NULL) {
        printtree(node->left);
        printf("%s : %d\n", node->word, node->count);
        printtree(node->right);
    }
}

int main()
{
    char *word;
    struct tnode *root = NULL;
    struct tnode *t;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }

    printtree(root);
    return 0;
}