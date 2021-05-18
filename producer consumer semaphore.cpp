#include<semaphore.h>
#include<pthread.h>
#include<bits/stdc++.h>
#define maxsize 5
#define buff_size 5
using namespace std;

sem_t empty; 
sem_t full;

int in=0;
int out=0;
int buff[buff_size];

pthread_mutex_t mutex;
void produce(){
	int item;
	for(int i=0;i<maxsize;i++)
	{
		item=rand();
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buff[in]=item;
		cout<<"producer produce ad item"<<buff[in]<<endl;
		in=(in+1)%buff_size;
		pthread_mutex_unlock(&mutex);
        sem_post(&full);
	}
	
}
void consumer(){
	 for(int i = 0; i <maxsize ; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buff[out];
        cout<<"consumer consume an item"<<item<<endl;
        out = (out+1)%buff_size;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
int main(){
	pthread_t p[5],c[5];
	pthread_mutex_init(&mutex,NULL);
	 sem_init(&empty,0,buff_size);
    sem_init(&full,0,0);
    int a[5] = {1,2,3,4,5}; 

    for(int i = 0; i < 5; i++) {
        pthread_create(&p[i], NULL, produce, a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&c[i], NULL, consumer, a[i]);
    }

    for(int i = 0; i < 5; i++) {
        pthread_join(p[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(c[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
