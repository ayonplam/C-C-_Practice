#include "ArrayManager.h"
/*Create Array*/
int*
CreateArray(int size) {
    int* arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("Enter the value of element: %d\n", i + 1);
        scanf("%d", &arr[i]);
    }
    return arr;
}
/*Print Array*/
void
PrintArray(int* arr, int SizeOfArray) {
    if (SizeOfArray == 0) {
        printf("Array is empty\n");
    } else {
        printf("Array: \n");
        for (int i = 0; i < SizeOfArray; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
/*Find vaule*/
int
FindValue(int value, int* arr, int SizeOfArray) {
    if (SizeOfArray == 0) {
        printf("Array is empty\n");
    } else {
        for (int i = 0; i < SizeOfArray; i++) {
            if (arr[i] == value) {
                return 1;
            }
        }
        return 0;
    }
}