
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

int countWords(char* words){
    int count = 0;
    for(int i = 0; i < strlen(words); i++){
        if(words[i] == '\n') count++;
    }
    return count;
}




int takeWord(char* filePath){
    struct stat fileInfo;
    stat(filePath, &fileInfo);
    char words[fileInfo.st_size + 1];

    FILE *fp;
    //char word[1024];
    fp = fopen(filePath, "r");

    //This commented snippet cause some bugs that I have to investigate
    /*while(fgets(word, sizeof(word), fp) != NULL){
        strcat(words, word);
        }*/
    fread(words, 1, fileInfo.st_size, fp);

    fclose(fp);
    words[fileInfo.st_size] = '\0';
    //printf("%s\nNumber of words: %d", words, countWords(words));

    int const size = countWords(words);
    char wordList[size][256];
    char word[256] = "";
    char *token;
    token = strtok(words, "\n");

    int count = 0;
    while(token != NULL) {
        strcpy(wordList[count], token);
        token = strtok(NULL, "\n");
        count++;
    }

    for(int i = 0; i < size; i++){
        printf("The word is: %s\n", wordList[i]);
    }


    /*int count = 0;
    int index = 0;

    while(count != countWords(words)){
        if(count == 0){
            index += strlen(word);
        }else {
         index += strlen(word) - 1;
        }
        word[0] = '\0';
        printf("The value of index is: %d\n", index);
        for(int i = 0; words[i] != '\n'; i++){
            word[i] = words[i + index];
        }
        //index -= 1;
        word[strlen(word)] = '\0';
        strcpy(wordList[count], word);
        printf("The quote inserted in the wordList is: %s\n", wordList[count]);
        count++;
    }

    printf("%s\n", wordList[1]);
*/
    return 0;
}
