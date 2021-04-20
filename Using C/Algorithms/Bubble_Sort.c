#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n)
{

    int temp;
    for (int i = 0; i < n - 1; i++)                     //loop for pass
    {
        printf("Pass : %d\n", i);
        for (int j = 0; j < n - 1 - i; j++)             //loop for comparison
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int arr[], int n)
{
    int temp;
    int sorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("Pass : %d\n", i);
        sorted = 1;                     //variable to see if array is sort or not
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = 0;
            }
        }
        if (sorted)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {65, 23, 1, 6, 7, 43, 21, 7};
    int n = 8;
    printArray(arr, n);
    bubbleSort(arr, n);                     //for normal bubble sort
    // bubbleSortAdaptive(arr, n);          //for saving time and pass for bubble sort
    printArray(arr, n);
    return 0;
}