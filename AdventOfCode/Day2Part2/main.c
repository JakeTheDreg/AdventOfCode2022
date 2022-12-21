#include <stdio.h>

int getScore(char move){
    if(move == 'A'){
        return 1;
    }
    else if(move == 'B'){
        return 2;
    }
    else if(move == 'C'){
        return 3;
    }
}

int match(char opponent, char outcome){
    int score = 0;
    int oScore = getScore(opponent);
    if(outcome == 'X'){
        if(opponent == 'A'){
            score = 3;
        }
        else if(opponent == 'B'){
            score = 1;
        }
        else if(opponent == 'C'){
            score = 2;
        }
    }
    else if(outcome == 'Y'){
        score = 3;
        score += oScore;
    }
    else if(outcome == 'Z'){
        score = 6;
        if(opponent == 'A'){
            score += 2;
        }
        else if(opponent == 'B'){
            score += 3;
        }
        else if(opponent == 'C'){
            score += 1;
        }
    }
    return score;
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
        char outcome;
        if(sscanf(line, "%c %c", &opponent, &outcome) == 2){
            total += match(opponent, outcome);
            printf("%d\n", match(opponent, outcome));
        }
    }

    printf("%d", total);
    fclose(file);
    return 0;
}
