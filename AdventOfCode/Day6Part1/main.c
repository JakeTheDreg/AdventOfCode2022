#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LENGTH 4097

//Parts 1 and 2 ask the same thing, so you only need one function that can be adjusted to parameter
int findMessage(const char *data, int len){
    char* temp = calloc(len+1, sizeof(char));
    for(int i = 0; i < LENGTH; i++){
        bool flag = false;
        temp = strncpy(temp, &data[i], len);
        for(int k = 0; k < len; k++){
            for(int j = k+1; j < len; j++){
                if(temp[k] == temp [j]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            free(temp);
            return i+len;
        }
    }
    free(temp);
    return -1;
}

int main() {
    FILE* signal;
    if((signal = fopen("..\\signal.txt", "r")) == NULL){
        printf("Error opening file");
        return -1;
    }

    char line[LENGTH];
    fgets(line, LENGTH, signal);;
    printf("First packet: %d\n", findMessage(line, 4));
    printf("First message: %d\n", findMessage(line, 14));
    fclose(signal);
    return 0;
}
