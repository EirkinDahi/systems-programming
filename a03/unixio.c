#include <fcntl.h> /* open */
#include <unistd.h> /*  read */
#include <sys/types.h> /* read */
#include <sys/uio.h> // read
#include <stdio.h> /* fopen, fread */
#include <stdlib.h>
#include <sys/time.h> /* gettimeofday */
#include <string.h> 

struct timeval start, end; /* maintain starting and finishing wall time. */

void startTimer( ) { /* memorize the starting time */
    gettimeofday( &start, NULL );
}
void stopTimer( char *str ) { /* checking the finishing time and computes the elapsed time */
    gettimeofday( &end, NULL );
    printf("%s's elapsed time\t= %ld\n",str, ( end.tv_sec - start.tv_sec ) * 1000000 +
    (end.tv_usec - start.tv_usec));
}
int main( int argc, char *argv[] ) {
    int typeofcall, numbytes;
    numbytes = atoi(argv[2]);
    typeofcall = atoi(argv[3]);
    
    /* error checking */
    if(argc != 4){
        fprintf(stderr, "usage: %s: invalid amount of arguemnents\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(numbytes < 0){
        fprintf(stderr, "usage: %s: invalid amount of bytes\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if(typeofcall != 0 && typeofcall != 1){
        fprintf(stderr, "usage: %s: invalid type of call\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    if (typeofcall == 1) {
        int fd = open(argv[1],O_RDONLY);
        int sz;
        char *c = (char *) calloc(1000, sizeof(char));
        /* error checking if file exists or does not */
        if(fd == -1){
            fprintf(stderr, "usage: %s: file does not exist\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        printf("Using Unix I/O system calls to read a file by %d bytes per read\n",numbytes);
        startTimer();
        sz = read(fd, c, numbytes);
        stopTimer("Unix read");
        close(fd);


    } else if (typeofcall == 0) {
        FILE *fp;
        fp = fopen(argv[0],"r");
        /* error checking if file exists or does not */
        if(fp == NULL){
            fprintf(stderr, "usage: %s: file does not exist\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        printf("Using C functions to read a file by %d bytes per read\n",numbytes);
        /* if number of bytes passed is 1, then we use fgetc() */
        if(numbytes == 1){
            do{
                startTimer();
                char c = fgetc(fp);
                if (feof(fp)){
                    break;
                }
            } while(1);
            stopTimer("C fgetc");
            fclose(fp);
        } else{
            /* using regular fread() */
            char buffer[10000];
            startTimer();
            fread(buffer, numbytes, 1, fp);
            stopTimer("C fread");
            fclose(fp);
        }
    }
    return 0;
}