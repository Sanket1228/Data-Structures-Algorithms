#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q){
    if(q->r == q->size - 1){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int val){
    if(isFull(q)){
        printf("Queue Overflow !\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct Queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow !\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct Queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
    enqueue(&q,6);

    printf("Element : %d\n",dequeue(&q));
    printf("Element : %d\n",dequeue(&q));
    printf("Element : %d\n",dequeue(&q));
    printf("Element : %d\n",dequeue(&q));

    enqueue(&q,3);
    return 0;
}