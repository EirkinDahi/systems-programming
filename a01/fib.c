#include <stdio.h>
#include  <stdlib.h> 

int main(int argc, char *argv[]){
    if(argc != 2){
        exit(1);
    }
    int param = atoi(argv[1]);

    if(param == 0){
        printf("%12d \n",0);
        exit(0);
    }

    long n1 = 0, n2 = 1,n3 = 1;

    printf("%12ld %12ld ",n1, n2);

    for(int i = 2; i <= param; i++){
        if(i == 5){
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