#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define size 99


int minNum = 0;
int maxNum = 0;
float avgNum  = 0.0;
pthread_mutex_t lock;
/* this data is shared by the thread(s) */

void *avg(); /* the thread */
void *min();
void *max();
int arr[size];
int n;


int main(int argc, char *argv[])
{
pthread_t tid1; /* the thread identifier */
pthread_t tid2;
pthread_t tid3;
pthread_attr_t attr1;
pthread_attr_t attr2;
pthread_attr_t attr3;/* set of attributes for the thread */

int counter;

if (atoi(argv[1]) < 0) {
	fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
	/*exit(1);*/
	return -1;
}
 
    int i;
    
    for (i = 1; i < argc && i < size; i++)
    {
        arr[i] = atoi(argv[i]);
        counter++;
    }
    n = counter;

/* get the default attributes */
pthread_attr_init(&attr1);
pthread_create(&tid1,&attr1,max,NULL);
pthread_join(tid1,NULL);
printf("The maximum value is %d\n",maxNum);

pthread_attr_init(&attr2);
pthread_create(&tid2,&attr2,min,NULL);
pthread_join(tid2,NULL);
printf("The minimum value is %d\n",minNum);

pthread_attr_init(&attr3);
pthread_create(&tid3,&attr3,avg,NULL);
pthread_join(tid3,NULL);

printf("The average value is  %f\n",avgNum);
} 

/**
 * The thread will begin control in this function
 */
void *max()
{
	int i;
	maxNum = arr[1];
	pthread_mutex_lock(&lock);
	for (i = 1; i < n; i++){
        if (arr[i] > maxNum)
            maxNum = arr[i];
	}
	
    
    
 pthread_mutex_unlock(&lock);
    pthread_exit(0);
}
void *min()
{
	int i;
	minNum = arr[1];
	pthread_mutex_lock(&lock);
	for (i = 1; i <= n; i++){
        if (arr[i] < minNum)
            minNum = arr[i];
	}
	
    
    
     pthread_mutex_unlock(&lock);
    pthread_exit(0);
}

void *avg()
{
    int i, sum=0;
    pthread_mutex_lock(&lock);
    for(i = 1; i <= n; i++){
        sum = sum + arr[i];
    }
    avgNum = sum / n;

     pthread_mutex_unlock(&lock);
    pthread_exit(0);
    
}
