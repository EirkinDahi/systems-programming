#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
void selectionSort(int arr[],int n);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

const int SIZE = 10;

int main(int argc, char *argv[]){

    int i= 0;
    int a[SIZE];
    int b[SIZE];
    // int *ptr = &a;
    // int *ptr_b = &b;

    // printf("%d ", *(ptr + 1));
    for(i = 0; i < SIZE; i++){
        *(a + i) = rand() % SIZE + 1;
        printf("%d \n", *(a + i));
    }
    printf("\n");
    for(i = 0; i < SIZE; i++){
        *(b + i) = *(a+ i); 
        printf("%d \n", *(b+ i));
    }
    printf("\n");
    quickSort(b, 0, SIZE -1);
    for(i = 0; i < SIZE; i++){
        printf("%d \n", *(b+ i));
    }

    return 0;
}


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n){
    int i, j, min;
    for(i = 0; i < n-1; i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(*(arr + j) < *(arr + min)){
                min= j;
            }
        }
        swap(&arr[min], &arr[i]);   
    }

}

int partition(int arr[], int low, int high){
    int pivot = *(arr + high);
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (*(arr + j) <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high){
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}