/* 
   NAME: LUNGADEKIRAN
   ROLL NO.: 39
   PRACTICAL NO.: 03
   TITLE: ORPHAN PROCESS USING SLEEP()
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        printf("Before Sleep!!\n");
        printf("Child process ID is \"%d\" and my parent process ID is \"%d\"\n\n", getpid(), getppid());
        sleep(10);
        printf("After Sleep!!\n");
        printf("Child process ID is \"%d\" and my parent process ID is \"%d\"\n\n", getpid(), getppid());
    } else {
        _exit(0);
    }

    return 0;
}
