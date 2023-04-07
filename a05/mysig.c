#include    <stdio.h>
#include    <signal.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <string.h>
#include    <ctype.h>
#include    <termios.h>

int main()
{
        void    f(int);                 /* declare the handler    */
        int     i;

        signal( SIGINT, f );            /* install the handler    */
        for(i=0; i<5; i++ ) {           /* do something else    */
                printf("hello\n");
                sleep(1);
        }

        return 0;
}

void f(int signum)                      /* this function is called */
{   
        char psswd[10] = "Laurier";
        char user_psswd[20];
        char user_input;
        struct termios old, new;    /*making attributes struct*/


        tcgetattr(STDIN_FILENO, &old);      /*get old attributes*/
        new = old;                          /*set new attributes to old*/
        new.c_lflag &= ~(ECHO);             /*remove the echo function in the new attribute*/
        

        printf("\tInterrupted!\tOK to quit(y/n)? ");
        scanf("%c", &user_input);
        
        tcsetattr(STDIN_FILENO, TCSANOW, &new);     /*toggle new attribute*/
        if(tolower(user_input) == 'y'){
            
            printf("Please enter the password: ");
            scanf("%s", user_psswd);
            tcsetattr(STDIN_FILENO, TCSANOW, &old);     /*switch to old*/
            int i = 1;
            while(strcmp(psswd,user_psswd) != 0 && i != 2){
                tcsetattr(STDIN_FILENO, TCSANOW, &new);     /*toggle new attribute*/
                printf("\nYou have entered an invalid password!\n");
                printf("Please enter the password: ");
                scanf("%s", user_psswd);
                tcsetattr(STDIN_FILENO, TCSANOW, &old);     /*switch to old*/
                i++;
            }

            if(strcmp(psswd,user_psswd) == 0){
                printf("\nExiting\n");
                exit(0);
            }        
        }
        printf("\n");
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
}
