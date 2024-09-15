#include <stdio.h>
#include <stdlib.h>
#include "ArrayManager.h"
#include "ArrayEdit.h"
int
main() {
    int* MyArray = NULL;
    int size = 0;
    char choice;
    /*Print instruction*/
    printf("\nArray Manager Program\n");
    printf("Enter 'c' to create Array\n");
    printf("Enter 'p' to print Array\n");
    printf("Enter 'i' to add an element to the end of Array\n");
    printf("Enter 'd' to delete 1 element at the k .th position\n");
    printf("Enter 's' to sort numbers in ascending order\n");
    printf("Enter 'x' to sort number in descending order\n");
    printf("Enter 't' to find if a number x is in Array or not\n");
    printf("Enter 'e' to exit program\n");
    /*Program Loop*/
    do {
        /*Get user request*/
        printf("Your Choice: ");
        scanf(" %c", &choice);
        /*Create Array*/
        if (choice == 'c') {
            /*Clear existed Array*/
            if (MyArray != NULL) {
                free(MyArray);
                printf("Free Array\n");
            }
            /*Enter size of array*/
            do {
                printf("Enter the size of array (n < 100):\n");
                scanf("%d", &size);
            } while (MAX_SIZE < size);
            /*Create Array*/
            MyArray = CreateArray(size);
        }
        /*Print Array*/
        else if (choice == 'p') {
            PrintArray(MyArray, size);
        }
        /*Add an element to the end of Array*/
        else if (choice == 'i') {
            if (size == 0) {
                MyArray = CreateArray(1);
                size++;
            } else if (size == MAX_SIZE) {
                printf("Can not add, Array is full\n");
            } else {
                int value = 0;
                printf("Enter the value you want to add:\n");
                scanf("%d", &value);
                ArrayAddValue(value, MyArray, &size);
            }
        }
        /*Sort numbers in ascending order*/
        else if (choice == 's') {
            ArraySortAscending(MyArray, size);
        }
        /*Sort numbers in Descending order*/
        else if (choice == 'x') {
            ArraySortDescending(MyArray, size);
        }
        /*Delete 1 element at the k .th position*/
        else if (choice == 'd') {
            int position = 0;
            printf("Enter the position you want to delete:\n");
            scanf("%d", &position);
            ArrayDeleteElement(position, MyArray, &size);
        }
        /*Find if a number x is in Array or not*/
        else if (choice == 't') {
            int value = 0;
            printf("Enter the value you want to find:\n");
            scanf("%d", &value);
            if (FindValue(value, MyArray, size)) {
                printf("%d is in Array\n", value);
            } else {
                printf("%d can not find in Array\n", value);
            }
        }
        /*Exit program*/
        else if (choice == 'e') {
            exit(0);
        }
        /*Invalid choice*/
        else {
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}