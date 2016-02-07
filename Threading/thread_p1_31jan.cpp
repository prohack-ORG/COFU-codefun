/*

Author : Siddheshwar P Sharma
Date   : 3rd Feb 2016

*/
// Program to create threads and check their functionality

#include <pthread.h>
#include <iostream>
#include <stdlib.h>

#define NU_THREAD 10 

using namespace std;

struct Person{
	char const *name;
	long ph_number;
};

void *call_function(void *arg){
	Person temp = *(Person *)arg;
	cout<<"\nName is: "<<(temp.name)<<" and contact is "<<(temp.ph_number);
	pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NU_THREAD];
	int status;
	Person work_friend;
	work_friend.name = "Raman Jaiswal";
	work_friend.ph_number = 9008400968;

	cout<<endl;
	for(int arg=0 ; arg<NU_THREAD ; arg++){
	status = pthread_create(&threads[arg],NULL,call_function,(void *)&work_friend);
		if(status){
			cout<<"\nProblem encountered while creating thread";
			exit(-1);
		}
	}
	pthread_exit(NULL);
    return 0;
}
