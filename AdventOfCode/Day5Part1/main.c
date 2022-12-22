#include <stdio.h>
#include <string.h>

#define MAX 56
#define STACKWIDTH 36

int getCrates(char s1[MAX], char s2[MAX], char s3[MAX], char s4[MAX], char s5[MAX], char s6[MAX], char s7[MAX], char s8[MAX], char s9[MAX]){
    FILE* cratesFile;
    if((cratesFile = fopen("..\\crates.txt", "r")) == NULL){
        printf("Error opening crates.txt\n");
        return -1;
    }
    char line[STACKWIDTH];
    //these act as buffers, so I don't have to make an extra loop
    char b1;
    char b2;
    char b3;
    char b4;
    char b5;
    char b6;
    char b7;
    char b8;
    char b9;

    //This loop grabs the crate values without the crate or space from the line. It is hard coded to possible values of ' ', '[', and ']'. Why? Because at the moment I don't know a better way.
    int count = 7;
    while(fgets(line, STACKWIDTH, cratesFile) != NULL || count >= 0){
        sscanf(line, "%*c%c%*c%*c%*c%c%*c%*c%*c%c%*c%*c%*c%c%*c%*c%*c%c%*c%*c%*c%c%*c%*c%*c%c%*c%*c%*c%c%*c%*c%*c%c%*c", &b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8, &b9);
        //yes, this is ugly, but now I don't have to make a loop that does this more than it needs to.
        if(b1 != ' '){
            s1[count] = b1;
        }
        if(b2 != ' '){
            s2[count] = b2;
        }
        if(b3 != ' '){
            s3[count] = b3;
        }
        if(b4 != ' '){
            s4[count] = b4;
        }
        if(b5 != ' '){
            s5[count] = b5;
        }
        if(b6 != ' '){
            s6[count] = b6;
        }
        if(b7 != ' '){
            s7[count] = b7;
        }
        if(b8 != ' '){
            s8[count] = b8;
        }
        if(b9 != ' '){
            s9[count] = b9;
        }
        count--;
    }
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", s1, s2, s3, s4, s5, s6, s7, s8, s9);
    //this does not work at all!! Will try again later

    fclose(cratesFile);
    return 0;
}

int main() {
    FILE* puzzleFile;

    if((puzzleFile = fopen("..\\puzzle.txt", "r")) == NULL){
        printf("Error opening puzzle.txt\n");
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

    if(getCrates(stack1, stack2, stack3, stack4, stack5, stack6, stack7, stack8, stack9) == -1){
        return -1;
    }





    fclose(puzzleFile);

    return 0;
}
