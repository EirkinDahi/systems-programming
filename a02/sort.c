#include <stdio.h>
#include <stdlib.h>
 #include <time.h>

void swap(int *x, int *y);
void selectionSort(int arr[],int n);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

const int SIZE = 10;
const int LENGTH = 10; 

int main(int argc, char *argv[]){
    clock_t start, end;
    double cpu_time_used;
    int i= 0;
    int a[SIZE];
    int b[SIZE];
    // int *ptr = &a;
    // int *ptr_b = &b;

    // printf("%d ", *(ptr + 1));
    for(i = 0; i < SIZE; i++){
        *(a + i) = rand() % SIZE + 1;
        // printf("%d \n", *(a + i));
    }

    for(i = 0; i < SIZE; i++){
        *(b + i) = *(a+ i); 
        // printf("%d \n", *(b+ i));
    }




    start = clock();
    quickSort(b, 0, SIZE -1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("It takes %.6f seconds to sort the array by quick sort.\n",cpu_time_used);


   for(i = 0; i < SIZE; i++){
        *(b + i) = *(a+ i); 
        // printf("%d \n", *(b+ i));
    }

    start = clock();
    selectionSort(b, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("It takes %.6f seconds to sort the array by selection sort.\n",cpu_time_used);

    // for(i = 0; i < SIZE; i++){
    //     printf("%d \n", *(b+ i));
    // }

    return 0;
}


void print_array(int *ptr) {
    for (int i = 0; i<LENGTH; i++) {
        printf(" %d", ptr[i]);
    }
    printf("\n");
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

void operation_0(int *ptr, int *ptr2) {

    /*
    store random numbers (between 1-100) into array a[]
    copy array a[] to array b[]
    sort array b[] using quick sort
    calculate the average of those numbers and print the average in proper format
    */

   //generating random numbers between 1-100 into array a[]
        float avg;
        float sum;

        //random integers in array A, copy to array B
        for (int i = 0; i < LENGTH; i++) {
            ptr[i] = 1 + (rand() % 100);
            ptr2[i] = ptr[i];
        }

        printf("Array A:");
        print_array(ptr);

        printf("Array B:");
        print_array(ptr2);

        printf("Selection sort:");
        selectionSort(ptr2, LENGTH);
        print_array(ptr2);

        //copying array a to array b
        for (int i = 0; i < LENGTH; i++) {
            ptr2[i] = ptr[i];
            sum += ptr[i];
        }
        printf("Copying Array A to Array B...\n");
        printf("Array B:");
        print_array(ptr2);

        printf("Quick sort:");
        quickSort(ptr2, 0, LENGTH - 1);
        print_array(ptr2);

        //calculating the average 
        avg = sum/LENGTH;
    
        //printing average
        printf("Average is: %.2f", avg);
        

}