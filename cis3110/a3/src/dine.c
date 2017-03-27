#include "dine.h"
pthread_mutex_t forks[1000];

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("not enough arguments, exiting...\n");
        exit(1);
    }
	
	char* p;
    int philosopherCount;
    int processCount;

    philosopherCount = strtol(argv[1], &p, 10);
    processCount = strtol(argv[2], &p, 10);

    pthread_t philosopherThread[philosopherCount];
    // pthread_mutex_t forks[philosopherCount];

    // printf("name: %s\n", name);
    for(int j = 1; j <= processCount; j++)
    {
        printf("Process %d\n", j);

        for(int i = 1; i <= philosopherCount; i++)
        {
            pthread_mutex_init(&forks[i], NULL);
        }

        for(int i = 1; i <= philosopherCount; i++)
        {
        	// printf("Process %d\n", i);
            pthread_create(&philosopherThread[i], NULL, philosopherFunction, (void *)i);
        }

        for(int i = 1; i <= philosopherCount; i++)
        {
            pthread_join(philosopherThread[i], NULL);
        }

        for(int i = 1; i < philosopherCount; i++)
        {
        	pthread_mutex_destroy(&forks[i]);
        }
    }
    return 0;
}

void *philosopherFunction(void* position)
{
    int eatPosition = (int) position;
    for(int i = 0; i < 1; i++)
    {
    pthread_mutex_lock(&forks[eatPosition]);
    pthread_mutex_lock(&forks[(eatPosition + 1) % 1000]);
    think(eatPosition);
    // sleep(1);
    pthread_mutex_unlock(&forks[eatPosition]);
    pthread_mutex_unlock(&forks[(eatPosition + 1) % 1000]);
    eat(eatPosition);
    // sleep(1);

	}
    pthread_exit(NULL);
}

void eat(int eatPosition)
{
    printf("philosopher %d is eating...\n", eatPosition);
}

void think(int thinkPosition)
{
    printf("philosopher %d is thinking...\n", thinkPosition);
}
