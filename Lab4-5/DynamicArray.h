//
// Created by Vlad on 20/03/2021.
//

#ifndef A45_912_CEONTEA_VLADCALIN_DYNAMICARRAY_H
#define A45_912_CEONTEA_VLADCALIN_DYNAMICARRAY_H

#endif //A45_912_CEONTEA_VLADCALIN_DYNAMICARRAY_H

#include "Tutorial.h"
#include <iostream>
#pragma once


template<typename TElement>
class DynamicArray{

private:

    int capacity;
    int length;
    TElement* elements;

    void resize();

public:

    /// Constructor for the dynamic array
    DynamicArray();

    /// Destructor for the dynamic array
    ~DynamicArray();

    /// Adds a new element to the array
    /// \param t the new tutorial
    void add(TElement t);

    /// Removes an element from the tutorial
    void remove(TElement* t);

    /// Returns the current length of the array
    /// \return the length of the array
    int returnLength() const;

    /// Returns the capacity of the array
    /// \return the capacity of the array
    int returnCapacity() const;

    /// Returns an element with a particular index
    /// \param i the index of the element
    /// \return the element
    TElement* getElement(int i);
};

template<typename TElement>
DynamicArray<TElement>::DynamicArray() {

    this->length = 0;
    this->capacity = 2;
    this->elements = new TElement[this->capacity];
}

template<typename TElement>
DynamicArray<TElement>::~DynamicArray() {

    delete[] this ->elements;
    this->elements = NULL;
}

template<typename TElement>
void DynamicArray<TElement>::resize() {

    this->capacity *= 2;
    TElement* new_list = new TElement[this->capacity];

    int i;
    for(i=0; i<this->length; i++){
        new_list[i] = this->elements[i];
    }

    delete[] this->elements;

    this->elements = new_list;

}

template<typename TElement>
void DynamicArray<TElement>::add(TElement t){

    if(this->length == this->capacity) {
        this->resize();
    }
    this->elements[this->length++] = t;
}

template<typename TElement>
void DynamicArray<TElement>::remove(TElement* t){

    int i, ok = 0;
    for (i = 0; i<this->length-1; i++){
        if (&this->elements[i] == t){
            this->elements[i] = this->elements[i+1];

            ok = 1;
        }
        if (ok == 1){
            this->elements[i] = this->elements[i+1];
        }
    }

    this->length--;
};

template<typename TElement>
int DynamicArray<TElement>::returnLength() const{

    return this->length;
}

template<typename TElement>
int DynamicArray<TElement>::returnCapacity() const{

    return this->capacity;
}

template<typename TElement>
TElement* DynamicArray<TElement>::getElement(int i) {

    return &this->elements[i];
}
