#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#define MAX 10
void* sort_arr(void *param){
    int *arr = (int *)param, i, temp;
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    /*for(i=0;i<5;i++){
        printf("%d ",arr[i]);
    }*/
    return NULL;
}

int main(){
    int ret, res;
    int arr[]={29,74,22,67,35};
    pthread_t t1;
    ret = pthread_create(&t1, NULL, sort_arr, (void *)arr);
    printf("Processing....\n");
    pthread_join(t1,NULL);

    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}