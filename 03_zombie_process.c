/* 
   NAME: LUNGADEKIRAN
   ROLL NO.: 39
   PRACTICAL NO.: 03
   TITLE: ZOMBIE PROCESS USING _exit()
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
        _exit(0);
    } else {
        sleep(2);
    }

    return 0;
}
