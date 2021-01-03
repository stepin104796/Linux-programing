#include<unistd.h>
#include<stdio.h> 
#include<fcntl.h>
#include<string.h> 
#include<stdlib.h> 
void main() 
{
    int f1;
    f1 = mkfifo("pipeA",0666);
    if(f1<0)
        printf("\npipeA was not created");
    else
        printf("\npipeA created");
    int f2;
    f2 = mkfifo("pipeB",0666);
    if(f2<0)
        printf("\npipeB was not created");
    else
        printf("\npipeB is created\n");
}