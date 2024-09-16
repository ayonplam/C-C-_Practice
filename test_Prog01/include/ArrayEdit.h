#ifndef ARRAY_EDIT_H
#define ARRAY_EDIT_H
#include <stdio.h>
#include <stdlib.h>
void ArrayAddValue(int value, int* arr, int* SizeOfArray);
void ArraySortAscending(int* arr, int SizeOfArray);
void ArraySortDescending(int* arr, int SizeOfArray);
void ArrayDeleteElement(int position, int* arr, int* SizeOfArray);
#endif /*ARRAY_EDIT_H*/