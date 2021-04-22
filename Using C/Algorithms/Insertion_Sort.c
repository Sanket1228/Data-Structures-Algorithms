#include <stdio.h>

void printArray(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");    
}

void insertion_sort(int *arr, int n){
    int key,j;
    for (int i = 1; i <= n-1; i++)
    {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}

int main(){
    int arr[] = {22,4,5,6,77,2,1,3};
    int n = 8;
    insertion_sort(arr,n);
    printArray(arr,n);
    return 0;
}