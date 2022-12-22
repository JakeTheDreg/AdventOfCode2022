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

    int item;

    for(int i = 0; i<len1; i++){
        for(int j = 0; j<len2; j++){
            if(compartment1[i] == compartment2[j]){
                item = compartment1[i];
                break;
            }
        }
    }

    if(item > 96){
        item -= 96;
    }
    else{
        item -= 38;
    }


    free(compartment2);
    free(compartment1);
    printf("%d\n", item);
    return item;
}

int main() {
    FILE* file;
    if((file = fopen("..\\RuckSacks.txt", "r")) == NULL){
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

    fclose(file);
    return 0;
}
