#include <stdio.h>

int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,4,2,5,6,7,8};
    int size = sizeof(arr)/sizeof(int);
    int element = 5;
    int index = linearSearch(arr,size,element);
    printf("The element %d is at %d index\n",element,index);
    return 0;
}