#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->f == q->r){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct queue *q){
    if(q->r == q->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueueR(struct queue *q, int val){
    if(isFull(q)){
        printf("Your queue is full");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

void enqueueF(struct queue *q, int val){
    if(isFull(q)){
        printf("Your queue is full");
    }
    else{
        q->arr[q->f] = val;
        q->f--;
    }
}

int dequeueR(struct queue *q){
    int val = -1;
    if(isEmpty(q)){
        printf("Your queue is empty");
    }
    else
    {
        val = q->arr[q->r];
        q->r--;
    }  
    return val;
}

int dequeueF(struct queue *q){
    int val = -1;
    if(isEmpty(q)){
        printf("Your queue is empty");
    }
    else
    {
        q->f++;
        val = q->arr[q->f];
    } 
    return val; 
}

int main(){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));  
    enqueueR(q,10); 
    enqueueR(q,12); 
    enqueueF(q,19); 
    printf("Element at F : %d\n",dequeueF(q)); 
    printf("Element at R : %d\n",dequeueR(q)); 
    printf("Element at R : %d\n",dequeueR(q)); 
    return 0;
}