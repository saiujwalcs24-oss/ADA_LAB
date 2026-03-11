/*WEEK 1 Analysis and Design Of Algorithms
write a C program demonstrating Merge_sort algorithm */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int arr[] , int left , int middle , int right){
    int n1 = middle - left + 1;
    int leftA[n1];
    for (int i = 0 ; i < n1 ; i++ ) {
        leftA[i] = arr[left + i];
    }
    int n2 = right - middle ;
    int rightA[n2];
    for (int j = 0; j < n2; j++) {
        rightA[j] = arr[middle + 1 + j];
    }
    int i =0 ,j = 0 , k = left;
    while (i < n1 && j < n2){
        if (leftA[i] <= rightA[j]) {
            arr[k] = leftA[i] ;
            i++;
        }
        else {
            arr[k] = rightA[j];
            j++;
        }
        k++;
    }
    while ( i < n1 ){
        arr[k] = leftA[i];
        i++;
        k++;
    }
    while ( j < n2 ){
        arr[k] = rightA[j];
        j++;
        k++;
    }
}
void Merge_sort(int left , int right , int arr[]){
    int middle;
    if (left < right) {
        middle = ( left + right ) / 2;
        Merge_sort(left , middle , arr);
        Merge_sort(middle + 1 , right , arr);
        Merge(arr,left , middle , right);
    }
}
int main() {


    int A[1000];

    // Seed random number generator
    srand(time(NULL));

    // Generate random numbers
    for (int i = 0; i < 1000; i++) {
        A[i] = rand() % 100000; // numbers between 0 and 99999
    }

    printf("Unsorted array ");
    for (int i = 0; i < 1000; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    Merge_sort(0, 999,A);

    printf("Sorted array (");
    for (int j = 0; j < 1000; j++) {
        printf("%d ", A[j]);
    }
    printf("\n");

    return 0;
}

