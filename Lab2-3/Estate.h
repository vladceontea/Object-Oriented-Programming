//
// Created by Vlad on 07/03/2021.
//

#ifndef A23_912_CEONTEA_VLADCALIN_ESTATE_H
#define A23_912_CEONTEA_VLADCALIN_ESTATE_H

#endif //A23_912_CEONTEA_VLADCALIN_ESTATE_H
#pragma once

typedef struct
{
    char type[50];
    char address[50];
    int surface;
    int price;
} Estate;

/// Creates the estate structure
/// \param type the type of estate
/// \param address the address of the estate
/// \param surface the surface of the estate
/// \param price the price of the estate
/// \return the newly-created estate
Estate createEstate(char type[], char address[], int surface, int price);
char* getType(Estate* e);
char* getAddress(Estate* e);
int getSurface(Estate* e);
int getPrice(Estate* e);

void setType(Estate* e, char* type[]);
void setAddress(Estate* e, char* address[]);
void setSurface(Estate* e, int* surface);
void setPrice(Estate* e, int* price);

void toString(Estate e, char str[]);