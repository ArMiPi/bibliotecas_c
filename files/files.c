#include<stdlib.h>
#include<string.h>

#include"files.h"

#define MAX_SIZE 200

bool fileExists(char *filename) {
    if(filename == NULL) return false;

    FILE *fptr = fopen(filename, "r");

    bool exists = (fptr == NULL) ? false : true;

    if(exists) fclose(fptr);

    return exists;
}

int filePutContent(char *filename, char *content, int flag) {
    if(filename == NULL || content == NULL) return 0;

    FILE *fptr;
    if(flag == 0) fptr = fopen(filename, "w");
    else fptr = fopen(filename, "a");

    if(fptr == NULL) return 0;

    fprintf(fptr, content);

    fclose(fptr);

    return 1;
}

char *fileGetLine(FILE *file) {
    if(file == NULL) return NULL;

    char *line = (char *) malloc(MAX_SIZE * sizeof(char));
    if(!fgets(line, MAX_SIZE, file)) {
        fclose(file);
        free(line);
        return NULL;
    }

    return line;
}
