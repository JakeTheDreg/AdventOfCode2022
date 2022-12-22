#include <stdio.h>
#include <string.h>

#define MAX 56
#define STACKWIDTH 36

int main() {
    FILE* puzzleFile;
    FILE* cratesFile;

    if((puzzleFile = fopen("..\\puzzle.txt", "r")) == NULL){
        printf("Error opening puzzle.txt\n");
        return -1;
    }
    if((cratesFile = fopen("..\\crates.txt", "r")) == NULL){
        printf("Error opening crates.txt\n");
        return -1;
    }


    char stack1[MAX];
    char stack2[MAX];
    char stack3[MAX];
    char stack4[MAX];
    char stack5[MAX];
    char stack6[MAX];
    char stack7[MAX];
    char stack8[MAX];
    char stack9[MAX];


    fclose(cratesFile);




    fclose(puzzleFile);

    return 0;
}
