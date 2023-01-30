#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char *argv[]){
    //checking to make sure arguments are passed
    if(argc == 1){
        printf("Invalid arguments given...Exiting program\n");
        return -1;
    }
    int i ;
    for(i = argc - 1; i > 0; i--){
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}