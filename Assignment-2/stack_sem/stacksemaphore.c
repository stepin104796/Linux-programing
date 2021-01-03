#include"stacksemaphore.h"

//const int max=10;
int m_arr[20];
int m_top=-1;
sem_t s1;
sem_t s2;
//pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;


void* push(void* pv)	//consumer
{
    int val=(int*)pv;
	sem_wait(&s1);
   // pthread_mutex_lock(&m1);
	if(m_top<=18){
        m_arr[++m_top]=val;
         printf("pushed val:%d\n",val);
    }
    pthread_mutex_unlock(&m1);
    sem_post(&s1);
   sem_post(&s2);
   
}
void* pop(void* pv)	//producer
{
    int temp=0;
   sem_wait(&s2);
    sem_wait(&s1);
   // pthread_mutex_lock(&m1);
	if(m_top!=-1){
        //temp+=1;
        temp=m_arr[m_top--];
        printf("VAlue:%d\n",temp);
    }
    //pthread_mutex_unlock(&m1);
    sem_post(&s1);
	//pthread_exit(temp);
}
int main()
{

    int i,value;
	pthread_t pt1,pt2;	//thread handle
    sem_init(&s2,0,0);
    sem_init(&s1,0,0);
    for(i=0;i<10;i++){
           pthread_create(&pt1,NULL,push,(void*)i);
    }
	 for(i=0;i<10;i++){ 	
         pthread_create(&pt2,NULL,pop,NULL);
     }

	pthread_join(pt1,NULL);
	pthread_join(pt2, NULL );
   sem_destroy(&s1);
	sem_destroy(&s2);
   // pthread_mutex_destroy(&m1);
	//printf("VAlue:%d",value);
	return 0;	//exit(0);
}
