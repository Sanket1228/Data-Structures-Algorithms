#include <stdio.h>

void display(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");    
}

int indInsertion(int arr[], int size, int element, int capacity ,int index){
    if(size>=capacity){             //it check whether the size of array is less than its capacity or not
        return -1;
    }
    for (int i = size-1; i >= index; i--)       //here for loop start from last element till the index at which we want to insert element
    {
        arr[i+1] = arr[i];          //giving value to next address and making position for index for which insertion is to be performed
    }
    arr[index] = element;       
    return 1;
    
}

int main(){
    int arr[50] = {1,4,5,32,3};
    int size = 5;
    int element = 43, index = 2;
    indInsertion(arr,size,element,50,index);
    size += 1;
    display(arr,size);
    return 0;
}