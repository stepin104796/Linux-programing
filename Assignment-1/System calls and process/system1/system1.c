#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd,nbytes;
	fd=open("alpha.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes=read(fd,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
    close(fd);
	//buf[nbytes]='\0';
	//printf("nbytes=%d,buf=%s\n",nbytes,buf);
    fd=open("sample.txt",O_WRONLY|O_CREAT, 0666);
	nbytes=write(fd,buf,nbytes);
    if(nbytes<0)
	{
		perror("write");
		exit(2);
	}
	printf("written successfully,nbytes=%d\n",nbytes);
	close(fd);
	close(fd);
	return 0;	//exit(0);
}
		




