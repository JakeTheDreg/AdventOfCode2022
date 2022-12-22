#include <stdio.h>
#include <string.h>

int totStrings = 0;
#define SIZE 64
int getBadges(char s1[SIZE], char s2[SIZE], char s3[SIZE]){
    int priority;

    for(int i = 0; i < strlen(s1); i++){
        for(int j = 0; j < strlen(s2); j++){
            if(s1[i] == s2[j]){
                for(int k = 0; k < strlen(s3); k++){
                    if(s1[i] == s3[k]){
                        priority = s1[i];
                        break;
                    }
                }
            }
        }
    }

    if(priority > 96){
        priority -= 96;
    }
    else{
        priority -= 38;
    }

    printf("%d\n", priority);
    return priority;
}

int main() {
    FILE* file;
    if((file = fopen("..\\RuckSacks.txt", "r")) == NULL){
        printf("Error opening file\n");
        return -1;
    }

    int sum;
    char line[SIZE];
    int count;
    char sack1[SIZE];
    char sack2[SIZE];
    char sack3[SIZE];
    while(fgets(line, SIZE, file) != NULL){
        totStrings++;
        count++;
        if(count ==1){
            sscanf(line, "%s", sack1);
        }
        else if(count == 2){
            sscanf(line, "%s", sack2);
        }
        else if(count == 3){
            sscanf(line, "%s", sack3);
            count = 0;
            sum += getBadges(sack1, sack2, sack3);
        }
    }

    printf("%d\n%d\n", sum, totStrings);

    fclose(file);
    return 0;
}
