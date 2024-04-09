#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

/** global variables necessary for handling different modes*/
/** make status volatile so it does not get optimized by compiler,
 * without volatile it will work with -O0 but not with -O2 because compiler
 * doesn't see the path leading to change this variable (since the handler is called by system, not explicitly by our program) so it optimizes every usage
 * of this variable as it was constant value.
 *
 * We have to tell compiler explicitly that we don't want to optimize the variable
*/
volatile int status = -1;
volatile int status_changes = 0;

/**
 * @brief Handler that updates current status based on argument get from signal
 *
 * @param argument argument coming from signal
*/
void argument_handler(int argument){
    status_changes++;
    status = argument;
}

/**
 * @brief Handler for signal action, it is called when proccess receives an signal
 *
 * @param signo number of the signal that was received
 * @param info structure holding data held by signal
 * @param extra
 *
*/
void SIGUSR1_action(int signo, siginfo_t *info, void *extra){
    int int_val = info->si_int;
    printf("Received status: %d from pid: %d\n", int_val, info->si_pid);

    argument_handler(int_val);

    kill(info->si_pid, SIGUSR1);
}

int main() {
    /* Print out current catcher's PID*/
    printf("Catcher PID: %d\n", getpid());

    struct sigaction action;
    action.sa_sigaction = SIGUSR1_action;   /
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);

    sigaction(SIGUSR1, &action, NULL);


    while(1) {
        switch(status){
            case 1:
                for(int i = 1; i <= 100; i++){
                    printf("%i, ", i);
                }
                printf("\n");
                status = -1;
                break;
            case 2:
                printf("So far status has changed %d times\n", status_changes);
                status = -1;
                break;
            case 3:
                printf("Received exit signal! Exiting...\n");
                exit(0);
                break;
            default:
                break;
        }
    }

    return 0;
}