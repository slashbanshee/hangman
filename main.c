#include <stdlib.h>
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
        printf("Can you guess the following word ?\n%s\n", dashedStr);
        char input = takeInput();
        char *found = strchr(word, input);
        if(found == NULL) {
            life += 1;
        } else {
            for(int i = 0; i < size; i++){
                if (word[i] == input) {
                    dashedStr[i] = input;
                }
            }
        }
        clearScreen();
    }
    return EXIT_SUCCESS;
}
