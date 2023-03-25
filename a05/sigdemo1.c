/* sigdemo1.c - shows how a signal handler works.
 *            - run this and press Ctrl-C a few times
 */

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
        char user_input[2];
        struct termios old, new;    /*making attributes struct*/


        tcgetattr(STDIN_FILENO, &old);      /*get old attributes*/
        new = old;                          /*set new attributes to old*/
        new.c_lflag &= ~(ECHO);             /*remove the echo function in the new attribute*/
        

        printf("\tInterrupted!\tOK to quit(y/n)? ");
        scanf("%s", user_input);
        
        tcsetattr(STDIN_FILENO, TCSANOW, &new);     /*toggle new attribute*/

        if(strcmp(user_input,"y") == 0){
            
            printf("Please enter the password: ");
            scanf("%s", user_psswd);
            tcsetattr(STDIN_FILENO, TCSANOW, &old);     /*switch to old*/
            int i = 1;
            while(strcmp(psswd,user_psswd) != 0){
                tcsetattr(STDIN_FILENO, TCSANOW, &new);     /*toggle new attribute*/
                printf("You have entered an invalid password!\n");
                printf("Please enter the password: ");
                scanf("%s", user_psswd);
                tcsetattr(STDIN_FILENO, TCSANOW, &old);     /*switch to old*/
                i++;
            }
            if (i==2) {
                printf("\nexit\n");
                exit(0);
            }
            if(strcmp(psswd,user_psswd) == 0){
                printf("Exiting\n");
                exit(0);
            }        
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
}
