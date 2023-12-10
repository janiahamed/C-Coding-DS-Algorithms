#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void asc(int *arr, int size) {
    int min_idx = 0;
    for (int i = 0; i < size; i++) {
        min_idx = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}
void dsc(int *arr, int size) {
        int min_idx = 0;
    for (int i = 0; i < size; i++) {
        min_idx = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] > arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
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
    printf("\nSelection Sort!");
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
