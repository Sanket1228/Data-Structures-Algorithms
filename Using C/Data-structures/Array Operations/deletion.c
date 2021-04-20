#include <stdio.h>

void display(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");    
}

int deletion(int arr[], int size,int index){
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i+1];
    } 
    return 1;   
}

int main(){
    int arr[50] = {1,4,5,32,3};
    int size = 5,index = 4;
    deletion(arr,size,index);
    size -= 1;
    display(arr,size);
    return 0;
}