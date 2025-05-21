
#include <stdio.h>
void fillWithDash(char word[], int *size) {
    for( int i = 0; i < *size; i++){
        word[i] = ' ';
    }
}

void cleanInputBuffer(void) {
    int garbage = getchar();
    if (garbage == '\n') return;
    //Find a way to consume other letters/numbers/symbols if user enters one.
}

char takeInput(void) {
    char input = ' ';
    printf("Enter a letter: ");
    input = getchar();
    cleanInputBuffer();
    return input;
}
