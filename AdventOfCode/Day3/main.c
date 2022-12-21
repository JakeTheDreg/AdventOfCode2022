#include <stdio.h>
#include <string.h>
#include <malloc.h>


int getPriorities(char rucksack[64]){
    int len = strlen(rucksack);
    int len1 = len/2;
    int len2 = len - len1;
    char *compartment1 = malloc(len1+1);
    memcpy(compartment1, rucksack, len1);
    compartment1[len1] = '\0';
    char *compartment2 = malloc(len2+1);
    memcpy(compartment2, rucksack+len1, len2);
    compartment2[len2] = '\0';



    free(compartment2);
    free(compartment1);
}

int main() {
    FILE* file;
    if((file = fopen("C:\\Users\\jrbra\\CLionProjects\\AdventOfCode\\Day3", "r")) == NULL){
        printf("Error reading file\n");
        return -1;
    }
    char line[64];
    int sum;
    while(fgets(line, 64, file) != NULL){
        char rucksack[64];
        if(sscanf(line, "%s", rucksack) == 1){
            sum += getPriorities(rucksack);
        }
    }
    printf("%d", sum);

    return 0;
}
