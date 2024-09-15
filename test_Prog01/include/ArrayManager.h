#ifndef ARRAY_MANAGER_H
#define ARRAY_MANAGER_H
#include <stdio.h>
#include <stdlib.h>
/*define max size of Array*/
#define MAX_SIZE 100
/*function list*/
int* CreateArray(int size); //Create array in heap memory
void PrintArray(int* arr, int SizeOfArray); //Print Array
int FindValue(int value, int* arr, int SizeOfArray); //Find value in Array
#endif /* ARRAY_MANAGER_H */