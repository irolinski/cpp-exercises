//Program oznacz:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDMAX 100

//int charcomp(char *x, char *y){ return(*x - *y); }
int charcomp(const void *a, const void *b) {
    return (*(const char *)a - *(const char *)b);
}

int main(void){
    char word[WORDMAX], sig[WORDMAX];
    while (scanf("%s", word) != EOF) {
        strcpy(sig, word);
        qsort(sig, strlen(sig),sizeof(char), charcomp);
        printf("%s %s\n", sig, word);
    }
    return 0;
}

