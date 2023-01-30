#include <stdio.h>
#include  <stdlib.h> 

int main(int argc, char *argv[]){
    //checking to make sure one argument is given
    if(argc != 2){
        printf("Invalid amount of arguments...Program Terminated\n");
        return -1;
    }
    //converting the given arguement into an ints
    int param = atoi(argv[1]);
    // printf("%d ", param);

    if(param == 0){
        printf("%12d \n",0);
        exit(0);
    }

    long n1 = 0, n2 = 1,n3 = 1;
    int i;
    printf("%12ld %12ld ",n1, n2);

    //starting at index 2, since we initialized the first two elements
    for(i = 2; i <= param; i++){
        if(i%5 == 0){
            printf("\n");
        }
        n3 = n1 + n2;
        printf("%12ld ",n3);
        n1 = n2;
        n2 = n3;
    }
    printf("\n");
    return 0;
}