#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void merge_asc(int *arr, int start, int middle, int end) {
    int n1 = middle-start+1;
    int n2 = end-middle;
    int left[n1];
    int right[n2];
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < n1; i++) {
        left[i] = arr[start+i];
    }
    for (i = 0; i < n2; i++) {
        right[i] = arr[middle + i + 1];
    }

    i = 0;
    k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void merge_dsc(int *arr, int start, int middle, int end) {
    int n1 = middle-start+1;
    int n2 = end-middle;
    int left[n1];
    int right[n2];
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; i < n1; i++) {
        left[i] = arr[start+i];
    }
    for (i = 0; i < n2; i++) {
        right[i] = arr[middle + i + 1];
    }

    i = 0;
    k = start;
    while (i < n1 && j < n2) {
        if (left[i] >= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}
void asc(int *arr, int start, int end) {
    if (start < end) {
        int middle = (start + end)/2;
        asc(arr, start, middle);
        asc(arr, middle+1, end);
        merge_asc(arr,start,middle,end);
    }
}
void dsc(int *arr, int start, int end) {
    if (start < end) {
        int middle = (start + end)/2;
        dsc(arr, start, middle);
        dsc(arr, middle+1, end);
        merge_dsc(arr,start,middle,end);
    }

}

void merge_sort(int *arr, int size, void (*fn)(int*, int, int)) {
    fn(arr, 0, size);
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
    printf("\nMerge Sort!");
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
    merge_sort(arr,total,fptr[0]);
    merge_sort(arr,total,fptr[1]);
}
