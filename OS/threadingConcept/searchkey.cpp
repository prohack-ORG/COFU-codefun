#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREAD 1
#define MIN(X, Y) X<Y ? X : Y 

typedef struct threadParam{ 
    int key; 
    int l; int r;
    int *arr;
} infoParam;

void * threadFunc(void * arg)
{
    infoParam * param= (infoParam* ) arg;

    printf("\nThread running for [%d , %d]\n", param->l,param->r);

    int ret = searchKey(param->arr, param->key, param->l, param->r);

    if(ret!=-1){
        printf(" Val = %d is found in ranges [%d,%d] of arr\n",param->key,param->l, param->r );
    }else{
        printf(" Val not available in ranges [%d,%d] of arr\n",param->l, param->r );
    }

    return NULL;
}


class threading{
    private:
        int *arr;
        int len;
    public:
        pthread_t threadID[NUM_THREAD];
        threading(int l)
        {    
            len= l;
            arr= new int[len];
        } 

        void init(int k){
            for(int i=0; i<len; i++)
            {
                arr[i] = (i*2+len)%len;
            }

            infoParam info[NUM_THREAD];
            int lembda = len/NUM_THREAD;
            info[0].l  = 0;
            info[0].r  = lembda-1;

            for(int i=0; i<NUM_THREAD; i++)
            {
                info[i].key = k;
                info[i].arr = arr;
                if(i>0){
                    info[i].l = info[i-1].r + 1;
                    info[i].r =  MIN( info[i].l + lembda - 1, len-1);
                }

                printf("part[%d]  l : %d r: %d \n",i+1, info[i].l, info[i].r );

                //// Laucnhing the thread 

                pthread_create(&threadID[i], NULL, threadFunc, (void *) info[i]);
            }
        }

        int searchKey(int *arr, int key ,int l, int r)
        {
            for(int i=l; i<=r; i++)
            {
                if(arr[i] == key) 
                    return i; 
            }
            return -1;
        }

        void deinit()
        {
            for(int i = 0 ; i < NUM_THREAD; i++)
            {
                pthread_join(threadID[i], NULL);
            }

            delete arr;
        }
};


int main ()
{

    //pthread_t tid; 
    //pthread_create(&tid, NULL, threadFunc, NULL);
    int num, keyval;
    scanf("%d%d",&num,&keyval);

    threading th(num);
    th.init(keyval);
    th.deinit();
    return 0;
}

