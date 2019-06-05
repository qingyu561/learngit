#include <stdio.h>
extern void bubbleSort(int* arr, int size);
extern void quickSort(int *arr, int left, int right);
extern void insertSort(int* arr, int size);
extern void selectSort(int* arr, int size);
int main(int argc ,char *argv[]){

    int arr[]={8,4,5,2,1,3,6,9,7,0},i;
    //bubbleSort(arr, 10);
    //quickSort(arr, 0, 9);
    //insertSort(arr, 10);
    selectSort(arr, 10);
    for ( i = 0; i < 10; i++)
    {
        printf("--[%d]--\n",arr[i]);
    }
    return 0;
}