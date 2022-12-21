#include <stdio.h>

int getScore(char move){
    if(move == 'A' || move == 'X'){
        return 1;
    }
    else if(move == 'B' || move == 'Y'){
        return 2;
    }
    else if(move == 'C' || move == 'Z'){
        return 3;
    }
}

int match(char opponent, char you){
    int y = getScore(you);
    int x = getScore(opponent);
    if(x == y){
        y += 3;
    }
    else if(x == 1 && y == 2){
        y += 6;
    }
    else if(x == 2 && y == 3){
        y += 6;
    }
    else if(x == 3 && y == 1){
        y += 6;
    }
    return y;
}

int main() {

    FILE* file;
    if((file = fopen("C:\\Users\\jrbra\\CLionProjects\\AdventOfCode\\Day2\\Cipher.txt", "r")) == NULL){
        printf("Error opening file\n");
        return -1;
    }

    char line[4];
    int total = 0;

    while(fgets(line, 4, file) != NULL){
        char opponent;
        char you;
        if(sscanf(line, "%c %c", &opponent, &you) == 2){
            total += match(opponent, you);
            printf("%d\n", match(opponent, you));
        }
    }

    printf("%d", total);
    fclose(file);
    return 0;
}
