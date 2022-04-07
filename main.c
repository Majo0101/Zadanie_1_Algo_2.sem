//Marian Bodnar
//Zadanie 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int priority;
    char ID[8];
}structure;

char* wayName(){
    char name[20];
    char way[60] = "C:/Users/PC/ClionProjects/Untitled8/";
    char *ptr;

    printf("Enter a file name with a type...\n");
    scanf("%20s", name);

    strcat(way , name); //addition

    ptr = (char*) malloc(60);

    strcpy(ptr, way);   //copy

    return ptr;
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapChar(char *a, char *b){
    char *buffer;
    buffer = (char *) malloc(8);

    strcpy(buffer , a);
    strcpy(a, b);
    strcpy(b , buffer);

    free(buffer);
}

int main() {

    int size = 100000;

    FILE *inputFile;
    FILE *outputFile;

    inputFile = fopen(wayName(), "r");
    outputFile = fopen("Vystup.txt", "w");

    structure *str = NULL;
    str = (structure*) malloc(sizeof (structure)*100000);

    if(str != NULL && inputFile){
        int i = 0;
        while (fscanf(inputFile, "%i %6s", &(str+i)->priority, (str+i)->ID) != EOF){
            i++;
        }
    }else{
        printf("Something went wrong...");
        exit(1) ;
    }

    printf("Sorting...\n");

    for (int i = 0; i < size; i++) {
        int min_idx = i;

        for (int j = i + 1; j < size; j++) {
            if ((str + j)->priority < (str + min_idx)->priority) {
                min_idx = j;
            }
        }
        swap(&(str + i)->priority, &(str + min_idx)->priority);
        swapChar((str + i)->ID,(str + min_idx)->ID );
    }

    for (int i = 0; i < size; i++) {
        fprintf(outputFile,"%d %s\n", (str + i)->priority , (str + i)->ID);
    }

    fclose(inputFile);
    fclose(outputFile);

    free(str);

    printf("All done....");
    return 0;
}
