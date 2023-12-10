#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void asc(int *arr, int start, int size) {
    int pivot = start;
    int i = start+1;
    int j = size;
    int temp = 0;
    if (start >= size) return;
    while (i <= j) {
        while ((j >= start) && arr[j] >= arr[pivot]) j--;
        while ((i <= size) && arr[i] <= arr[pivot]) i++;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else {
            temp = arr[pivot];
            arr[pivot] = arr[j];
            arr[j] = temp;
        }
    }
    asc(arr,0, j-1);
    asc(arr,j+1, size);
}
void dsc(int *arr, int start, int size) {
    int pivot = start;
    int i = start+1;
    int j = size;
    int temp = 0;
    if (start >= size) return;
    while (i <= j) {
        while ((j > start) && arr[j] <= arr[pivot]) j--;
        while ((i <= size) && arr[i] >= arr[pivot]) i++;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else {
            temp = arr[pivot];
            arr[pivot] = arr[j];
            arr[j] = temp;
        }
    }
    dsc(arr,0, j-1);
    dsc(arr,j+1, size);
}

void quick_sort(int *arr, int size, void (*fn)(int*, int, int)) {
    fn(arr, 0, size-1);
    printf("\nSorted array is:");
    for (int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
}
void main() {
    int total = 0;
    int i = 0;
    int *arr;
    int array[10];
    void (*fptr[])(int *, int, int) =  {asc , dsc};
    printf("\nQuick Sort!");
    printf("\nHow many numbers do you want to sort? Enter :");
    scanf("%d",&total);
    arr = (int *)malloc(total*sizeof(int));
    while (i < total) {
        printf("\nEnter the number");
        scanf("%d",&arr[i]);
        i++;
    }
    printf("\nInput to be sorted is: ");
    for (i = 0; i < total; i++) {
        printf("%d ",arr[i]);
    }
    quick_sort(arr,total,fptr[0]);
    quick_sort(arr,total,fptr[1]);
}
