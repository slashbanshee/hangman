
#include <stdio.h>
void fillWithDash(char word[], int *size) {
    for( int i = 0; i < *size; i++){
        word[i] = '_';
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

//ANSI escape sequence to clear the screen and place the cursor in home position.
void clearScreen(void){
    printf("\x1B[2J\x1B[H");
}
