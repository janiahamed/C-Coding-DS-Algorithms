#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void asc(int *arr, int size) {
    int j = 0;
    int key = 0;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void dsc(int *arr, int size) {
    int key = 0;
    int j = 0;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i-1;
        while (j >=0 && arr[j] < key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void insertion_sort(int *arr, int size, void (*fn)(int*, int)) {
    fn(arr, size);
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
    void (*fptr[])(int *, int) =  {asc , dsc};
    printf("\nInsertion Sort!");
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
    insertion_sort(arr,total,fptr[0]);
    insertion_sort(arr,total,fptr[1]);
}
