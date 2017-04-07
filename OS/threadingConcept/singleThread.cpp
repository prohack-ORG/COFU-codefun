#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static int arr[20];


void * threadFuncA(void * arg)
{
	printf("Entering Thread Function\n");
//	usleep(1000*1000);
 	int *arg1 = (int*)arg;
        (*arg1)*=2;
        for(int i=0; i<(*arg1); i++)
	{
	printf("i= %d  a= %d\n", i, *arg1);
	arr[i]= i*2+(*arg1);
	}       
	printf("Exiting Thread Function\n");
	return NULL;
}

void * threadFuncB(void * arg){
	printf("thread B\n");
	
	for(int i=0; i< 15 ; i++){
		printf("arr[%d] : %d\n",i, arr[i]);
	}
        printf("Thread B completed \n");
        return NULL;
}

int main()
{

        pthread_t tid,tid1,tid2;
        
	printf("Thread Creation\n");
	
	int a=5; 
        
	int rc= pthread_create(&tid, NULL,threadFuncA,(void * )&a);
        
	pthread_join(tid, NULL);
        
        rc= pthread_create(&tid1, NULL,threadFuncB,NULL);

	pthread_join(tid1, NULL);
        
         printf("\n--------------------------------------\n");

	rc= pthread_create(&tid2, NULL,threadFuncA,(void * )&a);
	pthread_join(tid2, NULL);
	 rc= pthread_create(&tid1, NULL,threadFuncB,NULL);

	pthread_join(tid1, NULL);
	
	printf("Thread joined\n");
	return 0;

}

