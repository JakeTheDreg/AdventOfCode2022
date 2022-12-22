#include <stdio.h>
#include <string.h>

#define MAX 56
#define WIDTH 20

int main() {
    FILE* puzzleFile;

    if((puzzleFile = fopen("..\\puzzle.txt", "r")) == NULL){
        printf("Error opening puzzle.txt\n");
        return -1;
    }

    char stack1[MAX] = "DBJV";
    char stack2[MAX] = "PVBWRDF";
    char stack3[MAX] = "RGFLDCWQ";
    char stack4[MAX] = "WJPMLNDB";
    char stack5[MAX] = "HNBPCSQ";
    char stack6[MAX] = "RDBSNG";
    char stack7[MAX] = "ZBPMQFSH";
    char stack8[MAX] = "WLF";
    char stack9[MAX] = "SVFMR";
    char* stacks[9] = {stack1, stack2, stack3, stack4, stack5, stack6, stack7, stack8, stack9};
    char line[WIDTH];
    int num;
    int src;
    int dst;

    while(fgets(line, WIDTH, puzzleFile) != NULL){
        sscanf(line, "move %d from %d to %d", &num, &src, &dst);
    }

    fclose(puzzleFile);
    return 0;
}
