#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

#define N 5

pthread_mutex_t lock;
unsigned int var;

void* thread1(void* p)
{
     printf("Thread1 id=%ld\n",pthread_self());
     int *a=(int *)p;
     var=pthread_mutex_lock(&lock);
     if(var)
        printf("Lock is not acquired\n");
     else
     {
        int i,j,flag,temp;
        for(i=0;i<N-1;i++)
        {
                flag=0;
                for(j=0;j<N-1-i;j++)
                {
                        if(a[j]>a[j+1])
                        {
                                temp=a[j];
                                a[j]=a[j+1];
                                a[j+1]=temp;
                                flag=1;
                        }
                }
                if(flag==0)
                        break;
        }
        printf("The sorted array:\n");
        for(i=0;i<N;i++)
        {
                printf("%d ",*(a+i));
        }
        pthread_mutex_unlock(&lock);
     }
     printf("\nthread1 terminated\n");
     pthread_exit(NULL);//terminating the calling thread(removing the all the resoureces allocated the thread)
}

void* thread2(void *p)
{
     printf("\n");
     var=pthread_mutex_lock(&lock);
     if(var)
         printf("Lock is not acquired\n");
     else
     {
         printf("Thread2 id=%ld\n",pthread_self());
         int *a=(int *)p;
         int i,j,flag,temp;
         for(i=0;i<N-1;i++)
         {
                flag=0;
                for(j=0;j<N-1-i;j++)
                {
                        if(a[j]<a[j+1])
                        {
                                temp=a[j];
                                a[j]=a[j+1];
                                a[j+1]=temp;
                                flag=1;
                        }
                }
                if(flag==0)
                        break;
          }
          printf("The sorted array:\n");
          for(i=0;i<N;i++)
          {
                printf("%d ",*(a+i));
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