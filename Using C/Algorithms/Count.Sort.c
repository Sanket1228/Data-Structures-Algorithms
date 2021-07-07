#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


void printArray(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}



int maximum(int *arr, int n){
    int max = INT_MIN;
    for(int i=0; i<n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int *arr, int n){
    int i,j;
    int max = maximum(arr, n);
    int * count  = (int *)malloc((max+1) * sizeof(int));
    
    for(i=0; i<max+1; i++){
        count[i] = 0;
    }

    for(i=0; i<n; i++){
        count[arr[i]] = count[arr[i]] + 1;
    }

    i=0;
    j=0;

    while (i <= max)   
    {
        if(count[i] > 0){
            arr[j] = i;
            count[i] = count[i] - 1;
            j++; 
        }
        else{
            i++;
        }
    }
}


int main(){
    int arr[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(arr,n);
    printf("Sorting using Count Sort...\n");
    countSort(arr,n);
    printArray(arr,n);
    return 0;
}