#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    FILE *file = fopen(argv[1], "r");
    if(file == NULL){
        printf("Error: File Path Not Found\n");
        return 1;
    }
    
    char *line; //Stores current line
    char *last_line = NULL;
    char *last_line_2 = NULL;
    size_t len = 0;
    ssize_t read;
    while(read = getline(&line, &len, file) != EOF){

        if(last_line != NULL){
            if(last_line_2 != NULL){
                free(last_line_2);
            }
            last_line_2 = strdup(last_line);
            free(last_line);
        }
        last_line = strdup(line);
    }
    //Print last 2 lines
    printf("%s", last_line_2);
    printf("%s\n", last_line);

    //Free all memory
    free(line);
    free(last_line);
    free(last_line_2);
    fclose(file);
    return 0; //Successfully ran
}