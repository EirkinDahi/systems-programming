#include <stdio.h>
#include <stdlib.h>

const int LENGTH = 10; 

void print_array(int *ptr) {

    for (int i = 0; i<LENGTH; i++) {
        printf(" %d", ptr[i]);
    }
    printf("\n");
}

// void selection_sort(int *ptr) {
//     /*
//     selection sort array b
//     */
    
//     int min_index;
//     for (int i = 0; i<LENGTH; i++) {
//         min_index = i;

//         for (int j = i +1; j < LENGTH; j++) {
//             if(ptr[min_index] > ptr[j]){
//                 min_index = j;
//             }
//         }

//         if (min_index != 1) {
//             int temp = ptr[i];
//             ptr[i] = ptr[min_index];
//             ptr[min_index] = temp;
//         }
//     }
// }



    
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
        selection_sort(ptr2);
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
        quick_sort(ptr2);
        print_array(ptr2);

        //calculating the average 
        avg = sum/LENGTH;
    
        //printing average
        printf("Average is: %.2f", avg);
        

}
/*
int main() {
    int op;

    printf("Enter your selection (0 - operation 0, 1 - operation 1, 2 - exit): ");
    scanf("%d", &op);

    //operation 0 
    if (op == 0) {
        int a[LENGTH], b[LENGTH];
        int *ptr, *ptr2;
        ptr = &a[0];
        ptr2 = &b[0];

        operation_0(ptr, ptr2);
    }

    return 0;
}
*/



