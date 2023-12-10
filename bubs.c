#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void asc(int *arr, int size) {
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < size; i++) {
        for (j = i+1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void dsc(int *arr, int size) {
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < size; i++) {
        for (j = i+1; j < size; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubble_sort(int *arr, int size, void (*fn)(int*, int)) {
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
    printf("\nBubble Sort!");
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
    bubble_sort(arr,total,fptr[0]);
    printf("\nHow many numbers do you want to sort? Enter :");
    scanf("%d",&total);
    i = 0;
    while (i < total) {
        printf("\nEnter the number");
        scanf("%d",&array[i]);
        i++;
    }

    printf("\nInput to be sorted is: ");
    for (i = 0; i < total; i++) {
        printf("%d ",array[i]);
    }
    bubble_sort(array,total,fptr[1]);

}
