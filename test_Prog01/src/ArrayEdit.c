#include "ArrayEdit.h"
/*Add value*/
void
ArrayAddValue(int value, int* arr, int* SizeOfArray) {
    arr[(*SizeOfArray)++] = value;
}
/*Array Sort Ascending*/
void
ArraySortAscending(int* arr, int SizeOfArray) {
    int i;
    int j;
    int temp;
    // Sort the numbers using bubble sort
    for (i = 0; i < SizeOfArray; i++) {
        for (j = i + 1; j < SizeOfArray; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
/*Array Sort Descending bubble sort*/
void
ArraySortDescending(int* arr, int SizeOfArray) {
    int i;
    int j;
    int temp;
    // Sort the numbers using bubble sort
    for (i = 0; i < SizeOfArray; i++) {
        for (j = i + 1; j < SizeOfArray; j++) {
            if (arr[j] > arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
/*Delate element*/
void
ArrayDeleteElement(int position, int* arr, int* SizeOfArray) {
    if (position < 1 || position > *SizeOfArray) {
        printf("Error position\n");
    } else
        for (int i = position - 1; i < (*SizeOfArray) - 1; i++) {
            arr[i] = arr[i + 1];
        }
    (*SizeOfArray)--;
}