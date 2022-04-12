//
// Created by Vlad on 13/03/2021.
//

#ifndef A23_912_CEONTEA_VLADCALIN_SERVICE_H
#define A23_912_CEONTEA_VLADCALIN_SERVICE_H

#endif //A23_912_CEONTEA_VLADCALIN_SERVICE_H

#include "Repository.h"

typedef struct
{
    Repository *repo;

}Service;

/// Creates the service
/// \param repo the repo of estates
/// \return the service
Service * createService(Repository* repo);

/// Adds a new estate
/// \param type the type of estate
/// \param address the address of the estate
/// \param surface the surface of the estate
/// \param price the price of the estate
/// \param service the service of estates
void add_estate_service(char type[], char address[], int surface, int price, Service* service);

/// Removes an estate
/// \param service the service of estates
/// \param address the addres of the estate we wish to remove
void remove_estate_service(Service* service, char address[]);

/// Updates certain values of a specified estate
/// \param service the service of estates
/// \param address the address of the estate we want to update
/// \param option1 answer whether we want to update the type of estate or not
/// \param option2 answer whether we want to update the address of the estate or not
/// \param option3 answer whether we want to update the surface of the estate or not
/// \param option4 answer whether we want to update the price of the estate or not
/// \param new_type the new type of the estate
/// \param new_address the new address of the estate
/// \param new_surface the new surface of the estate
/// \param new_price the new price of the estate
void update_estate_service(Service* service, char address[], int option1, int option2, int option3, int option4, char new_type[], char new_address[], int new_surface, int new_price);

/// Searches for the estates which have a certain string in their addresses
/// \param service the service of estates
/// \param print_list the list of estates containing the string
/// \param str the string
/// \param option the way we wish to sort the results
/// \return the number of results
int search_estates_service(Service* service, Estate print_list[], char str[], int option);

/// Filters the estates by type and surface
/// \param service the service of estates
/// \param print_list the list of results
/// \param type the type of estates we wish to see
/// \param min_surface the minimum surface of the estates we wish to see
/// \return the number of results
int show_filtered_estates_service(Service* service, Estate print_list[], char type[], int min_surface);

/// Tests
void testsService();
