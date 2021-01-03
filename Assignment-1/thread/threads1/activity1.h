#ifndef __ACTIVITY1_H
#define __ACTIVITY1_H
#include<pthread.h>
#include<stdio.h>

int val=10000;

int final_sum=1000;

void* task_body1(void* pv)
{
    
	for(int i=1;i<=10000;i++)
        val++;
}
void* task_body2(void* pv)
{
    
	for(int i=1;i<=10000;i++)
        val--;
}
int print()
{
	pthread_t ptr1,ptr2;
    pthread_create(&ptr1,NULL,task_body1,NULL);
    pthread_create(&ptr2,NULL,task_body1,NULL);

    pthread_join(ptr1,NULL);
    pthread_join(ptr2,NULL);

	printf("final sum is %d\n",final_sum);
	return 0;
}
#endif

