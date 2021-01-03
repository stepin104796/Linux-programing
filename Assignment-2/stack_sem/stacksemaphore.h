#ifndef STACKSEMAPHORE_H
#define STACKSEMAPHORE_H

#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
void* push(void* pv);
void* pop(void* pv);
#endif

