/* 
   NAME: LUNGADEKIRAN
   ROLL NO.: 39
   PRACTICAL NO.: 04
   TITLE: PROCESS SCHEDULING ALGORITHM
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

pthread_t philosopher[5];
pthread_mutex_t chopstick[5];

void *func(void *val) {
    int n = (long)val;

    printf("Philosopher %d is thinking\n", n);
    pthread_mutex_trylock(&chopstick[n]);
    pthread_mutex_trylock(&chopstick[(n + 1) % 5]);

    printf("Philosopher %d is eating\n", n);
    sleep(3);

    int sleeptime = rand() % 10;
    pthread_mutex_unlock(&chopstick[n]);
    pthread_mutex_unlock(&chopstick[(n + 1) % 5]);

    printf("Philosopher %d finished eating in %d seconds\n", n, sleeptime);

    return NULL;
}

int main() {
    srand(time(NULL));

    int i;
    for (i = 0; i < 5; i++)
        pthread_create(&philosopher[i], NULL, func, (void *)(long)i);

    for (i = 0; i < 5; i++)
        pthread_join(philosopher[i], NULL);

    return 0;
}

/**************** OUTPUT ***************** 
   Philosopher 1 is thinking
   Philosopher 1 is eating
   Philosopher 3 is thinking
   Philosopher 3 is eating
   Philosopher 4 is thinking
   Philosopher 4 is eating
   Philosopher 0 is thinking
   Philosopher 0 is eating
   Philosopher 5 is thinking
   Philosopher 2 is thinking
*/
