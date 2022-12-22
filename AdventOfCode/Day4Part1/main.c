#include <stdio.h>
#include <stdbool.h>

#define SIZE 16

bool totalOverlap(int start1,int stop1,int start2,int stop2){
    if((start1 <= start2 && stop1 >= stop2) || (start2 <= start1 && stop2 >= stop1)){
        return true;
    }
    return false;
}

bool overlap(int start1,int stop1,int start2,int stop2){
    if((start2 >= start1 && start2 <= stop1) || (start1 >= start2 && start1 <= stop2)){
        return true;
    }
    return false;
}

int main() {
    FILE* file;
    if((file = fopen("..\\Pairs.txt", "r")) == NULL){
        printf("Error opening file\n");
        return -1;
    }


    int start1;
    int start2;
    int stop1;
    int stop2;
    char line[SIZE];
    int sum;
    int otherSum;

    while(fgets(line, SIZE, file) != NULL){
        sscanf(line, "%d-%d,%d-%d", &start1, &stop1, &start2, &stop2);
        sum += totalOverlap(start1, stop1, start2, stop2);
        otherSum += overlap(start1, stop1, start2, stop2);
    }

    printf("Total overlap: %d\n"
           "Any overlap: %d\n", sum, otherSum);

    fclose(file);
    return 0;
}
