#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

unsigned int var;
pthread_mutex_t lock;

void *capital(void *ptr)
{
        char ch=65;
        printf("Thread1 id=%ld\n",pthread_self());
        var=pthread_mutex_lock(&lock);
        if(var)
                printf("Lock is not acquired\n");
        else
        {
                while(ch <= 90)
                {
                        printf("%c ", ch);
                        ch++;

                }
        }
        pthread_mutex_unlock(&lock);
        pthread_exit(NULL);
}

void *small(void *ptr)
{
        printf("\nThread2 id=%ld\n",pthread_self());
        int ch=97;
        var=pthread_mutex_lock(&lock);
        if(var)
                printf("Lock is not acquired\n");
        else
        {
                while(ch <= 122)
                {
                        printf("%c ", ch);
                        ch++;
                }
        }
        printf("\n");
        pthread_mutex_unlock(&lock);
        pthread_exit(NULL);
}

int main()
{

        pthread_t thread[2];
        pthread_create(&thread[0], NULL, &capital, NULL);
        pthread_create(&thread[1], NULL, &small, NULL);
        pthread_join(thread[0], NULL);
        pthread_join(thread[1], NULL);
        return 0;
}