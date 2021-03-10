#include <stdio.h>

int binarySearch(int arr[], int size, int element){
    int low,mid,high;
    mid = (low + high)/2;
    if(arr[mid] == element){
        return mid;
    }
    if(arr[mid] > element){
        high = mid - 1;
    }
    else{
        low = mid + 1;
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(int);
    int element = 3;
    int index = binarySearch(arr,size,element);
    printf("The element %d is at %d index\n",element,index);
    return 0;
}