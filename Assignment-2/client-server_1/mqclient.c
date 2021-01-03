#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void toggleChars(char str[])
{
    for (int i=0; str[i]!='\0'; i++)
    {
        if (str[i]>='A' && str[i]<='Z')
            str[i] = str[i] + 'a' - 'A';
        else if (str[i]>='a' && str[i]<='z')
            str[i] = str[i] + 'A' - 'a';
    }
}

int main()
{
	int ret,ret1,nbytes;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=10;
	mqd_t mqid;
	mqd_t mqid1;
	mqid=mq_open("/mque",O_RDONLY|O_CREAT,0666,&attr);
	mqid1=mq_open("/mque1",O_WRONLY|O_CREAT,0666,&attr);
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
	char buf[8192];
	int maxlen=256,prio;
	nbytes=mq_receive(mqid,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
	toggleChars(buf);
	printf("receive msg:%s,nbytes=%d,prio=%d\n",buf,nbytes,prio);
	int len=strlen(buf);
	ret1=mq_send(mqid1,buf,len+1,5);
	if(ret1<0)
	{
		perror("mq_send");
		exit(2);
	}
	//write(1,buf,nbytes);
	mq_close(mqid);
	mq_close(mqid1);
	return 0;
}

