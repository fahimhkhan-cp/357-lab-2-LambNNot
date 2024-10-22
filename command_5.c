#include <stdio.h>

int main(int argc, char *argv[]){

    int i;
    for(i=0;i<argc;i++){ //Iterate through arguments
        //Compare argument's first char
        if(argv[i][0] == '-'){
            printf("%s\n", argv[i]);
        }
    }
    
    return 0; //Successfully ran
}