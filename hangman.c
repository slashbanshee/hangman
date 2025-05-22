
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>



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

int takeWord(char* filePath){
    struct stat fileInfo;
    stat(filePath, &fileInfo);
    char words[fileInfo.st_size + 1];

    FILE *fp;
    char word[1024];
    fp = fopen(filePath, "r");
    while(fgets(word, sizeof(word), fp) != NULL){
        strcat(words, word);
    }

    fclose(fp);
    words[fileInfo.st_size] = '\0';
    printf("%s", words);
    return 0;
}
