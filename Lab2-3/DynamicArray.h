//
// Created by Vlad on 13/03/2021.
//

#ifndef A23_912_CEONTEA_VLADCALIN_DYNAMICARRAY_H
#define A23_912_CEONTEA_VLADCALIN_DYNAMICARRAY_H

#endif //A23_912_CEONTEA_VLADCALIN_DYNAMICARRAY_H

#pragma once
#include "Estate.h"

typedef Estate TElement;

typedef struct
{
    TElement* elems;
    int length;
    int capacity;
} DynamicArray;

/// Creates the dynamic array
/// \param capacity the initial capacity of the array
/// \return the dynamic array
DynamicArray* createDynamicArray(int capacity);

/// Destroys the dynamic array
/// \param arr the dynamic array to be destroyed
void destroy(DynamicArray* arr);

/// Adds an element to the dynamic array
/// \param arr the dynamic array
/// \param t the element to be added
void add(DynamicArray* arr, TElement t);

/// Removes an element of the array
/// \param arr The dynamic array
/// \param address The address of the estate we want to remove
void remove_element(DynamicArray* arr, char address[]);


/// Resizes the dynamic array
/// \param arr
void resize(DynamicArray* arr);

int length(DynamicArray* arr);

void DeepCopyArray(DynamicArray* arr1, DynamicArray* arr2);

/// Tests
void testsDynamicArray();