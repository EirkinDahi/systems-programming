#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("No arguments given...Exiting program\n");
        exit(1);
    }
    for(int i = argc - 1; i > 0; i--){
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}