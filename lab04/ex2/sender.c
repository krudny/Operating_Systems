#include <signal.h>
#include <sys/types.h>

#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief simple handler for SIGUSR1 signal
 *
 * @param signo number of the signal that was risen
*/
void SIGUSR1_handler(int signo) {
    printf("Confirmation received\n");
}

/**
 * argv[0] - execution command - always passed as default
 * argv[1] - pid of the catcher program
 * argv[2] - mode that will be send to catcher
*/
int main(int argc, char** argv) {
    if(argc < 3) {
        printf("Usage: %s <signal_pid> <signal_argument>\n", argv[0]);
        return -1;
    }

    printf("Sender PID: %d\n", getpid());

    signal(SIGUSR1, SIGUSR1_handler);

    long signal_pid = strtol(argv[1], NULL, 10);
    long signal_argument = strtol(argv[2], NULL, 10);

    union sigval value = {signal_argument};

    sigqueue(signal_pid, SIGUSR1, value);
    printf("Signal sent with argument: %ld\n", signal_argument);

    sigset_t mask;
    sigfillset(&mask);

    sigdelset(&mask, SIGUSR1);
    sigdelset(&mask, SIGINT);

    sigsuspend(&mask);
    return 0;
}