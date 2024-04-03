#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int global = 0;

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Invalid arguments!\n", argv[0]);
        return -1;
    }

    printf("%s \n", strrchr(argv[0], '/') + 1);

    int local = 0;

    pid_t pid = fork();

    if (pid == 0) {
        printf("child process\n");
        global++;
        local++;

        printf("child pid = %d, parent pid = %d \n", getpid(), getppid());
        printf("child's local = %d, child's global = %d \n", local, global);

        int status = execl("/bin/ls", "ls", "-l", argv[1], NULL);

        exit(status);
    }

    int status = 0;
    wait(&status);
    int child_return_status = WEXITSTATUS(status);

    printf("parent process\n");
    printf("parent pid = %d, child pid = %d \n", getpid(), pid);
    printf("Child exit code: %d \n", child_return_status);
    printf("parent's local = %d, parent's global = %d \n", local, global);

    return child_return_status;
}