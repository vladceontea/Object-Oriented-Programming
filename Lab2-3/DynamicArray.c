//
// Created by Vlad on 13/03/2021.
//

#include <string.h>
#include "DynamicArray.h"
#include <stdlib.h>
#include <assert.h>

DynamicArray* createDynamicArray(int capacity)
{
    DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (da == NULL)
        return NULL;

    da->capacity = capacity;
    da->length = 0;

    da->elems = (TElement*)malloc(capacity * sizeof(TElement));
    if (da->elems == NULL)
        return NULL;

    return da;
}

void destroy(DynamicArray* arr)
{
    if (arr == NULL)
        return;

    free(arr->elems);
    free(arr);
}


// Resizes the array, allocating more space.
void resize(DynamicArray* arr)
{
    if (arr==NULL){
        return;
    }

    TElement* new_arr = (TElement*)malloc(2*arr->capacity*sizeof(TElement));
    if (new_arr==NULL){
        return;
    }

    arr->capacity = arr->capacity*2;
    int i;
    for(i=0;i<arr->length;i++){
        new_arr[i] = arr->elems[i];
    }

    free(arr->elems);
    arr->elems = new_arr;
}



void add(DynamicArray* arr, TElement t)
{
    if (arr == NULL)
        return;
    if (arr->elems == NULL)
        return;

    // resize the array, if necessary
    if (arr->length == arr->capacity)
        resize(arr);
    arr->elems[arr->length] = t;
    arr->length++;
}


void remove_element(DynamicArray* arr, char address[])
{
    if (arr == NULL)
        return;
    if (arr->elems == NULL)
        return;


    int i, ok = 0;
    for(i=0;i<arr->length;i++){

        if (strcmp(arr->elems[i].address,address) == 0){
            arr->elems[i] = arr->elems[i+1];

            ok = 1;
        }
        if(ok==1){
            arr->elems[i] = arr->elems[i+1];
        }
    }

    arr->length--;
}

int length(DynamicArray* arr){

    return arr->length;
}

void DeepCopyArray(DynamicArray* arr1, DynamicArray* arr2){
    int i;
    for(i=0;i<arr2->length;i++){
        strcpy(arr1->elems[i].type, arr2->elems[i].type);
        strcpy(arr1->elems[i].address, arr2->elems[i].address);
        arr1->elems[i].surface = arr2->elems[i].surface;
        arr1->elems[i].price = arr2->elems[i].price;

    }
}

void testsDynamicArray(){

    DynamicArray* da = createDynamicArray(2);
    if (da == NULL)
        assert(0);

    assert(da->capacity == 2);
    assert(da->length == 0);

    Estate e1 = createEstate("house", "328 Tanglewood Road", 324, 475000);
    add(da, e1);
    assert(da->length == 1);

    Estate e2 = createEstate("apartment", "3176 Washburn Street", 56, 90000);
    add(da, e2);
    assert(da->length == 2);

    Estate e3 = createEstate("house", "1615 Lucky Duck Drive", 140, 150000);
    add(da, e3);
    assert(da->length == 3);
    assert(da->capacity == 4);

    remove_element(da, "3176 Washburn Street");
    assert(da->length == 2);

    destroy(da);
}
