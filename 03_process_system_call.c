#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> // Include this header for fork() and getpid()

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        // Error handling for fork failure
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process - PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("Parent process - PID: %d, PPID: %d\n", getpid(), getppid());
    }

    return 0;
}
