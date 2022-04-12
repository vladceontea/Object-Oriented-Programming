//
// Created by Vlad on 20/03/2021.
//

/*
#include "DynamicArray.h"
#include <assert.h>

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
    for (i = 0; i<this->length; i++){
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


void testsDynamicArray(){

    DynamicArray da;

    assert(da.returnCapacity() == 2);
    assert(da.returnLength() == 0);

    Tutorial t1{"Recursion In C++","Anastasia Broughton","5:37", 12345, "https://www.youtube.com/watch?v=fVMgnmi2D1w"};
    Tutorial t2{"Type Conversions In C++","Robin Millar","3:42", 4345, "https://www.youtube.com/watch?v=mhCcWFapO30"};
    Tutorial t3{"Object-Oriented Programming In C++","Sana Khan","16:05", 62363, "https://www.youtube.com/watch?v=1mLZ9A5dJZk"};
    da.add(t1);
    assert(da.returnLength() == 1);

    da.add(t2);
    assert(da.returnLength() == 2);

    da.add(t3);
    assert(da.returnLength()== 3);
    assert(da.returnCapacity() == 4);

    da.remove(&t2);
    assert(da.returnLength() == 2);

}
 */