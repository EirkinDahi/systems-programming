#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <ctype.h>
#include <curses.h>

struct timeval start, end;
void startTimer() {
    gettimeofday(&start, NULL);
}

double stopTimer() {
    gettimeofday(&end, NULL);

    return(( end.tv_sec - start.tv_sec ) * 1000000 +
    (end.tv_usec - start.tv_usec));
}

int main() {
    int i, ch, correct = 0;
    double total_time = 0;
    double min_time = 1000000;
    double max_time = 0;
    struct timeval start, end;
    srand(time(NULL)); // seed the random number generator with the current time

    initscr(); // initialize the curses library
    cbreak(); // disable line buffering
    noecho(); // disable echoing of input characters
    clear(); // clear the screen
    double results[10];
    int row,col;
    getmaxyx(stdscr,row,col);

    for (i = 0; i < 10; i++) {
        // generate random character and coordinates
        int x = rand() % COLS;
        int y = rand() % LINES;
        int c = rand() % 36;
        char ch = (c < 10) ? (c + '0') : (c - 10 + 'a'); // convert digit to ASCII character

        // wait for random time interval (0.5-2 seconds)
        int delay = rand() % 1500 + 500;
        usleep(delay * 1000);
        mvprintw(row/2,col, ("TEST %d"), i);
        refresh();
        usleep(delay * 1000);

        // display the character at random coordinates
        mvaddch(y, x, ch);
        refresh();

        // record start time
        startTimer();

        // read user input and check if correct
        ch = getch();
        if (tolower(ch) == tolower(ch)) {
            correct++;
        }

        // record end time and calculate response time
        
        double response_time = stopTimer();

        results[i] = response_time;
        
        // update summary statistics
        total_time += response_time;
        if (response_time < min_time) {
            min_time = response_time;
        }
        if (response_time > max_time) {
            max_time = response_time;
        }

        // clear the screen
        clear();
        
    }


    // print summary statistics????
    //I NEED HELP !!!! I CANT SEEM TO GET IT TO PRINT
    //I ODNT EVEN KNOW IF THE TIMERS WORKING
    double avg=total_time/10;

    move(0,0);

    for (i = 0; i < 10; i++) {
         mvprintw(i,0,"%d.\t%.4f\n", i, &results[i]);
        move(i,0);
        
    }

    move(11,0);
    mvprintw(11,0,"max\t%.4f\tmin\t%.4f\tavg\t%.4f", &max_time, &min_time, &avg);
   
   

    // clean up curses library
    endwin();

    return 0;
}
