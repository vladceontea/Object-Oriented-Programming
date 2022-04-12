//
// Created by Vlad on 07/03/2021.
//

#ifndef A23_912_CEONTEA_VLADCALIN_REPOSITORY_H
#define A23_912_CEONTEA_VLADCALIN_REPOSITORY_H

#endif //A23_912_CEONTEA_VLADCALIN_REPOSITORY_H

#pragma once
#include "DynamicArray.h"

typedef struct
{
    DynamicArray* estates;

}Repository;

/// Creates the repo
/// \return the repo
Repository * createRepo();

/// Adds an estate to the repo
/// \param repo the repo of estates
/// \param e the added estate
void add_estate_repository(Repository* repo, Estate e);

/// Removes an estate with a certain address from the repo
/// \param repo the repo of estates
/// \param address the address of the estate we want to remove
void remove_estate_repository(Repository* repo, char address[]);

/// Updates certain values of a specified estate
/// \param repo the repo of estates
/// \param address the address of the estate we want to update
/// \param option1 answer whether we want to update the type of estate or not
/// \param option2 answer whether we want to update the address of the estate or not
/// \param option3 answer whether we want to update the surface of the estate or not
/// \param option4 answer whether we want to update the price of the estate or not
/// \param new_type the new type of the estate
/// \param new_address the new address of the estate
/// \param new_surface the new surface of the estate
/// \param new_price the new price of the estate
void update_estate_repository(Repository* repo, char address[], int option1, int option2, int option3, int option4, char new_type[], char new_address[], int new_surface, int new_price);

///
/// \param repo1
/// \param repo2
void copy_repo(Repository* repo1, Repository* repo2);

/// Tests
void testsRepository();
