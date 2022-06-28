#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

#define N 5

pthread_mutex_t lock;
unsigned int var;
int b[N],c[N];

void* thread1(void* p)
{
        int k=0;
        printf("Thread1 id=%ld\n",pthread_self());
        int *a=(int *)p;
        var=pthread_mutex_lock(&lock);
        if(var)
                printf("Lock is not acquired\n");
        else
        {
                for(int i=0;i<N;i++)
                {
                        if(a[i]% 2 == 0)
                        {
                                b[k]=a[i];
                                k++;
                        }
                }
                for(int j=0;j<k;j++)
                {
                        printf("%d ",*(b+j));
                }
                pthread_mutex_unlock(&lock);
        }
        printf("\nthread1 terminated\n");
        pthread_exit(NULL);//terminating the calling thread(removing the all the resoureces allocated the thread)
}

void* thread2(void *p)
{
        int l=0;
        printf("Thread2 id=%ld\n",pthread_self());
        int *a=(int *)p;
        var=pthread_mutex_lock(&lock);
        if(var)
                printf("Lock is not acquired\n");
        else
       {
                for(int i=0;i<N;i++)
                {
                        if(a[i]%2!= 0)
                        {
                                c[l]=a[i];
                                l++;
                        }
                }
                for(int j=0;j<l;j++)
                {
                        printf("%d ",*(c+j));
                }
                pthread_mutex_unlock(&lock);
        }
        printf("\nthread2 terminated\n");
        pthread_exit(NULL);//terminating the calling thread(removing the all the resoureces allocated the thread)
}

int main()
{
        int arr[N]={10,51,48,12,30};
        pthread_t t1,t2;//default type for thread variables
        pthread_create(&t1,0,thread1,(void *)arr);//to create the thread,thread id,thread attributes,thread handler,arguments to the threaad handler
        pthread_create(&t2,0,thread2,(void *)arr);
        pthread_join(t1,NULL);//wait for particular thread termination
        pthread_join(t2,NULL);//wait for particular thread termination

}