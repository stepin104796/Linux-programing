#include"system.h"
int main()
{
	int fd,nbytes;
	fd=open("alpha.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	int k;
	k=execl("/usr/bin/wc", "wc", "alpha.txt",  NULL);
	
	if(k<0)
		{
			perror("execv");
			exit(1);
		}
		exit(0);
		
	close(fd);
	/*int maxlen=128;
	
	char buf[maxlen][maxlen];
	nbytes=read(fd,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	//buf[nbytes]='\0';
	//printf("nbytes=%d,buf=%s\n",nbytes,buf);
	write(1,buf,nbytes);
	close(fd);
	return 0;	//exit(0);*/
}
		




