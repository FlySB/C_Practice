#include <stdio.h>

//冒泡排序
void bubbleSort(int *array, int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

// 快速排序
int partition(int *array, int low, int high){
    int pivot = array[low];
    while (low<high){
        while (low<high && array[high]>pivot) --high;
        array[low] = array[high];
        while (low<high && array[low]<pivot) ++low;
        array[high] = array[low];
    }
    array[low] = pivot;
    return low;
}


void quickSort(int *array, int low, int high){
    if(low < high){
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot-1);
        quickSort(array, pivot+1, high);
    }
}

int main() {
    int arr[] = { 10,6,5,2,3,8,7,4,9,1 };
    int n = sizeof(arr) / sizeof(int);
//    bubbleSort(arr, n);
    quickSort(arr,0,n);
    printf("排序后的数组为：\n");
    for (int j = 0; j<n; j++)
        printf("%d ", arr[j]);
    printf("\n");
    return 0;
}
