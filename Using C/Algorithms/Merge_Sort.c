#include <stdio.h>

void printArray(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int mid, int low, int high){
    int i,j,k,b[100];

    i = low;
    j = mid+1;
    k = low;

    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            b[k] = arr[i];
            i++;k++;
        }
        else{
            b[k] = arr[j];
            j++;k++;
        }
    }

    while (i <= mid)
    {
        b[k] = arr[i];
        i++;k++;
    }
    
    while (j <= high)
    {
        b[k] = arr[j];
        j++;k++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = b[i];
    }

}

void mergeSort(int arr[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,mid,low,high);    
    }
}


int main(){
    int arr[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(arr,n);
    printf("Sorting using Merge...\n");
    mergeSort(arr, 0, 6);
    printArray(arr,n);
    return 0;
}