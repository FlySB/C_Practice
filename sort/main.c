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

//简单插入排序
void insertSort(int *array, int n){
    int temp = 0;
    int i,j;
    for(i = 1; i<n; i++){
        if(array[i] < array[i-1]){
            temp = array[i];
            for(j = i-1; temp<array[j]; j--){
                array[j+1] = array[j];
            }
            array[j+1] = temp;
        }
    }
}

// 简单选择排序

void selectSort(int *array, int n){
    int min,temp;
    for(int i=0; i<n-1; i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if (array[j] < array[min])
                min = j;
        }
        printf("%d",min);
        if (min!=i){
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

int main() {
    int arr[] = { 10,6,5,2,3,8,7,4,9,1 };
    int n = sizeof(arr) / sizeof(int);
//    bubbleSort(arr, n);
//    quickSort(arr,0,n);
//    insertSort(arr,n);
    selectSort(arr, n);
    printf("排序后的数组为：\n");
    for (int j = 0; j<n; j++)
        printf("%d ", arr[j]);
    printf("\n");
    return 0;
}
