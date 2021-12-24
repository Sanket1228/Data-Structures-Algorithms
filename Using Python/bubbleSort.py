def bubbleSort(arr):
    for i in range(len(arr)):
        swapped = True
        for j in range(len(arr)-1-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = False
        if swapped:
            break
    for i in range(len(arr)):
        print(arr[i], end=" ")

if __name__ == "__main__":
    arr = [1,2,3,4,5]
    bubbleSort(arr)