#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int g_ticket=100;
pthread_mutex_t mutex;

void* route(void* arg)
{
   
    char *thread=(char*)arg;
    
    while (1)
    {
           //pthread_mutex_lock(&mutex);
       if(g_ticket>0)
       {
           printf("%s=%d\n",thread,g_ticket);
           g_ticket--;
           //pthread_mutex_unlock(&mutex);
       }else
       {
          // pthread_mutex_unlock(&mutex);
           break;

       }
       
       usleep(10000);
    }
    
}
int main()
{
    pthread_t t1,t2,t3,t4;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&t1,NULL,route,"thread1");
    pthread_create(&t2,NULL,route,"thread2");
    pthread_create(&t3,NULL,route,"thread3");
    pthread_create(&t4,NULL,route,"thread4");
   
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    pthread_mutex_destroy(&mutex);
}