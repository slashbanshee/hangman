
#include <stdio.h>
void fillWithDash(char word[], int *size) {
    for( int i = 0; i < *size; i++){
        word[i] = ' ';
    }
}

void cleanInputBuffer(void) {
    int garbage;
    while((garbage = getchar() != '\n' && garbage != EOF)) {
        //Just consume extra characters
    }
}

char takeInput(void) {
    char input = ' ';
    printf("Enter a letter: ");
    input = getchar();
    cleanInputBuffer();
    return input;
}
