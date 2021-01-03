#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int ret,nbytes1;
	mqd_t mqid;
	mqd_t mqid1;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqid=mq_open("/mque",O_WRONLY|O_CREAT,0666,&attr);
	mqid1=mq_open("/mque1",O_RDONLY|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	if(mqid1<0)
	{
		perror("mq_open");
		exit(1);
	}
	char str[]="Hello Message queue";
	int len=strlen(str);
	ret=mq_send(mqid,str,len+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	char buf[8192];
	int maxlen=256,prio;
	nbytes1=mq_receive(mqid1,buf,maxlen,&prio);
	if(nbytes1<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes1]='\0';
	printf("receive msg:%s,nbytes=%d,prio=%d\n",buf,nbytes1,prio);
	

	mq_close(mqid);
	mq_close(mqid1);
	return 0;
}

