#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 64
#define WIDTH 21
#define LENGTH 9

char *bigs[MAX] = {"DBJV", "PVBWRDF", "RGFLDCWQ", "WJPMLNDB", "HNBPCSQ", "RDBSNG", "ZBPMQFSH", "WLF", "SVFMR"};

char** initStacks(){
    char** stacks = malloc(sizeof(char*) * LENGTH);
    for(int i = 0; i<LENGTH; i++){
        char* temp = calloc(MAX, sizeof(char));
        strcpy(temp, bigs[i]);
        stacks[i] = temp;
    }
    return stacks;
}

void freeStacks(char** stacks){
    for(int i =0; i < LENGTH; i++){
        free(stacks[i]);
    }
    free(stacks);
}

void moveOne(char **src, char **dst){
    int srcIndex = strlen(*src)-1;
    int dstIndex = strlen(*dst);
    (*dst)[dstIndex] = (*src)[srcIndex];
    (*dst)[dstIndex+1]='\0';
    (*src)[srcIndex]='\0';
}

void moveCrates(char *stacks[], int num, int src, int dst){
    while(num>0){
        moveOne(&stacks[src], &stacks[dst]);
        num--;
    }
}

int main() {
    FILE* puzzleFile;

    if((puzzleFile = fopen("..\\puzzle.txt", "r")) == NULL){
        printf("Error opening puzzle.txt\n");
        return -1;
    }

    char** stacks = initStacks();
    char line[WIDTH];
    int num;
    int src;
    int dst;

    while(fgets(line, WIDTH, puzzleFile) != NULL){
        sscanf(line, "move %d from %d to %d", &num, &src, &dst);
        moveCrates(stacks, num, src-1, dst-1);
    }
    for(int i = 0; i < 9; i++){
        int this = strlen(stacks[i])-1;
        printf("%c", stacks[i][this]);
    }

    fclose(puzzleFile);
    freeStacks(stacks);

    return 0;
}