#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int run_now = 1;
int count = 0;

void *mythread(void *msg)
{
	printf("pthread is starting : %s\n", (char *) msg);
	while(count < 20)
	{
		if(run_now == 2)
		{
			count++;
			printf("2\n");
			run_now = 1;
		} else
		{
			sleep(1);
		}
	}
	sleep(15);
	pthread_exit("Hello return");
}

int main()
{
	int fd;
	pthread_t th;
	void *msg_return;
	if(pthread_create(&th, NULL, mythread, "hey thread") != 0)
	{
		printf("Thread creation failed");
		exit(-1);
	}
	else
	{
		printf("Thread creation sucessfull");
	}
	
	while(count < 20)
	{
		if(run_now == 1)
		{
			count++;
			printf("1\n");
			run_now = 2;
		} else
		{
			sleep(1);
		}
	}

	pthread_join(th, &msg_return);	
	printf("thread returned with : %s\n", (char *) msg_return);
	return 0;
}

