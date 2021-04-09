#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if((q->r + 1) % q->size == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("Queue Overflow !\n");
    }
    else{
        q->r = (q->r + 1) % q->size;     //circular increment
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow !\n");
    }
    else{
        q->f = (q->f + 1) % q->size;        //circular increment
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue *q;
    q->size = 5;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);
    enqueue(q,0);
    // enqueue(q,8);

    // printf("Element : %d\n",dequeue(q));
    // printf("Element : %d\n",dequeue(q));
    // printf("Element : %d\n",dequeue(q));
    // printf("Element : %d\n",dequeue(q));
    // printf("Element : %d\n",dequeue(q));

    

    // printf("Element : %d\n",dequeue(q));
    
    
    return 0;
}