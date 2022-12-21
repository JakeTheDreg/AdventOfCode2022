#include <stdio.h>

int main() {
    FILE* file;

    if((file = fopen("C:\\Users\\jrbra\\CLionProjects\\AdventOfCode\\Day1\\list.txt", "r")) == NULL){
        printf("Error opening file\n");
        return 1;
    }
    char line[10];
    int max;
    int second;
    int third;
    int current;

    while(fgets(line, 10, file) != NULL){
        int cals;
        if(sscanf(line, "%d", &cals) == 1){
            current += cals;
        }
        else{
            if(current > max){
                third = second;
                second = max;
                max = current;
            }
            else if(current > second){
                third = second;
                second = current;
            }
            else if(current > third){
                third = current;
            }
            current = 0;
        }
    }
    printf("%d, %d, %d\n", max, second, third);
    printf("Sum: %d\n", (max + second + third));


    fclose(file);
    return 0;
}
