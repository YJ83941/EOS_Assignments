#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

struct bbls{
    int arr[6];
    int size;
};

void *bubble(void *param){
    int temp;
    struct bbls *ptr = (struct bbls*)param;
    for(int i=0;i<ptr->size;i++){
        for(int j=i+1;j<6;j++){
            if(ptr->arr[i]>ptr->arr[j]){
                temp=ptr->arr[i];
                ptr->arr[i]=ptr->arr[j];
                ptr->arr[j]=temp;
            }
        }
    }
    return NULL;
}

int main(){
    int ret, *result;
    struct bbls bs1 = {{12,34,353,2,43,67}, 6};
    pthread_t t1;
    
    ret = pthread_create(&t1, NULL, bubble, (void *)&bs1);
    pthread_join(t1, NULL);

    printf("Sorted thread: ");
    for(int i=0;i<bs1.size;i++){
        printf("%d ",bs1.arr[i]);
    }

    return 0;
}