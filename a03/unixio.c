#include <fcntl.h> // open
#include <unistd.h> // read
#include <sys/types.h> // read
//#include <sys/uio.h> // read
#include <stdio.h> // fopen, fread
#include <stdlib.h>
#include <sys/time.h> // gettimeofday

struct timeval start, end; // maintain starting and finishing wall time.

void startTimer( ) { // memorize the starting time
    gettimeofday( &start, NULL );
}
void stopTimer( char *str ) { // checking the finishing time and computes the elapsed time
    gettimeofday( &end, NULL );
    printf("%s's elapsed time\t= %ld\n",str, ( end.tv_sec - start.tv_sec ) * 1000000 +
    (end.tv_usec - start.tv_usec));
}
int main( int argc, char *argv[] ) {
    int typeofcalls, numbytes;
    
    // validate arguments -0. file name,  1. name of file to be read, 2. number of bytes to read, 3. type of I/O call (1 or 2)
    //invalid arguments: invalid number of arguments, file argument that doesn't exist, invalid number of bytes/buffer size,
    //ex neg number of bytes, the type of I/O calls entered is invalid
    //ex unixio filename 1024: 0:argv[0] the program name, 1 : argv[1] = the file name, argv[2] = number of bytes to read, argv[3] = type of call (1 or 2)
    // implementation

    //invalid number of arguments 

    //file argument doesn't exist
    if (fopen(argv[1], "r") == NULL) {
        fprintf(stderr, "usage: %s filename does not exist\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    //invalid number of bytes size
    
    //invalid type of I/O call
    if (*argv[3] != '1' || *argv[3] != '2') {
        fprintf(stderr, "usage: %s type I/O call invalid (1 or 2)\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    // Parsing the arguments passed to your C programs
    // Including the number of bytes to read per read( ) or fread( ), and
    // the type of i/o calls used
    // implementation

    numbytes = (int) *argv[2];
    typeofcalls = (int) *argv[3];


    if (typeofcalls == 1) {
        // Use unix I/O system calls
        // open: is a Unix system call that opens a given file.
        // read: is a Unix system call that reads a file into a given buffer.
        // close: is a Unix system call that closes a given file
        // implementation
        
    

        printf("Using Unix I/O systems calls to read a file by %d bytes per read");
 

    } else if (typeofcalls == 0) {
        // Use standard I/O
        // fopen: is a C standard I/O function that opens a given file.
        // fgetc: is a C standard I/O function that reads one byte from a file.
        //note: when the number of bytes to read is 1, fgetc() needs to be used to read the file
        // fread: is a C standard I/O function that reads a file into a given data structure.
        // fclose: is a C standard I/O function that closes a give file.
        // implementation
        
        FILE *fp;
        fp = fopen(argv[1], "r");
        char buffer [100];

        //the note said to use fgetc when the number of bytes is 1 
        if (numbytes == 1) {
            startTimer;
            fgetc(fp);
            printf("Using C functions to read a file by %d bytes per fread", numbytes);
            //idk how to use the stoptimer bro im sorry its all u
            stopTimer(fp);

        } else {
          
            
        }

        fclose;

        printf("Using C functions to read a file by %d bytes per fread");


    }
    return 0;
}