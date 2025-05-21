#include <stdio.h>
#include <string.h>

#include "./hangman.h"

int main(void) {
    char word[] = "hello";
    int size = strlen(word);
    char dashedStr[size];
    fillWithDash(dashedStr, &size);

    int life = 0;

    while(life != 5 && strcmp(word, dashedStr) != 0) {

    }


}
