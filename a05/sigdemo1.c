/* sigdemo1.c - shows how a signal handler works.
 *            - run this and press Ctrl-C a few times
 */

#include    <stdio.h>
#include    <signal.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <string.h>

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
        printf("\tInterrupted!\tOK to quit(y/n)? ");
        scanf("%s", user_input);
        // putchar(user_input);

        if(strcmp(user_input,"y") == 0){
            printf("Please enter the password: ");
            scanf("%s", user_psswd);

            while(strcmp(psswd,user_psswd) != 0){
                printf("You have entered an invalid password!\n");
                printf("Please enter the password: ");
                scanf("%s", user_psswd);
            }
            printf("Exiting\n");
            exit(0);
        }
        
}
