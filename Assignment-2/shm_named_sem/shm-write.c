/* File Mapping */
#include<unistd.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<semaphore.h>


int main()
{
	int filesz=4096; //find the length and round
			 		 //to multiples of 4096
	int fd,offset=0;
	sem_t *ps,*qs;
	ps=sem_open("/s1",O_CREAT, 0777, 1);
	qs=sem_open("/s2",O_CREAT, 0777, 0);
	fd=shm_open("/shm1",O_CREAT|O_RDWR,0666);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
    ftruncate(fd, filesz);
	void *pbase;
	pbase=mmap(0,filesz, PROT_WRITE, MAP_SHARED,fd,offset);
	if(pbase==MAP_FAILED)
	{
		fprintf(stderr,"mapping failed\n");
		//close(fd);
		exit(1);
	}
	char buf[64];
    char str[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
       sem_wait(ps);
	strncpy(pbase,str,20);	
	sem_post(ps);
	sem_post(qs);
	printf("buf=%s\n",str);
	//sem_unlink("s1");
	//sem_unlink("s2");
	//for loop
    /*strncpy(buf,pbase,10);
	printf("buf=%s\n",buf);
	strcpy(buf,pbase+10);
	printf("buf=%s\n",buf);*/
	munmap(pbase,filesz);
    //shm_unlink("/shm1");
	return 0;
}
		









