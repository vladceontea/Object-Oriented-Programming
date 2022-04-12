//
// Created by Vlad on 07/03/2021.
//

#include "Estate.h"
#include <string.h>
#include <stdio.h>

Estate createEstate(char type[], char address[], int surface, int price)
{
    Estate e;
    strcpy(e.type, type);
    strcpy(e.address, address);
    e.surface = surface;
    e.price = price;

    return e;
}

char* getType(Estate* e)
{
    return e->type;
}

char* getAddress(Estate* e)
{
    return e->address;
}

int getSurface(Estate* e)
{
    return e->surface;
}

int getPrice(Estate* e)
{
    return e->price;
}

void setType(Estate* e, char* type[]){
    strcpy(e->type, *type);
}

void setAddress(Estate* e, char* address[]){
    strcpy(e->address, *address);
}

void setSurface(Estate* e, int* surface){
    e->surface = *surface;
}

void setPrice(Estate* e, int* price){
    e->price = *price;
}

void toString(Estate e, char str[]) {
    sprintf(str, "Type: %s     Address: %s     Surface: %dm2     Price: %d$.", e.type, e.address, e.surface, e.price);
}
