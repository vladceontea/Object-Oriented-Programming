//
// Created by Vlad on 29/03/2021.
//

#ifndef A45_912_CEONTEA_VLADCALIN_USERSERVICE_H
#define A45_912_CEONTEA_VLADCALIN_USERSERVICE_H

#pragma once
#include "Repository.h"

class UserService {

private:

    Repository* repo;
public:

    /// Constructor for the service
    UserService();

    /// Destructor for the service
    ~UserService();

    /// Searches for tutorials whose presenters contain a certain string
    /// \param show_list the list which will show all the tutorials resulting in the search
    /// \param text the string to search through the presenters
    /// \return the length of the resulting list
    int search_tutorials_service(Tutorial show_list[], std::string text);

    /// Adds a tutorial from the watchlist
    /// \param watchlist the list of tutorials to be watched later
    /// \param the tutorial to be added
    void add_to_watchlist(DynamicArray<Tutorial>* watchlist, Tutorial t);

    /// Deletes a tutorial from the watchlist
    /// \param watchlist the list of tutorials to be watched later
    /// \param the tutorial to be deleted
    void delete_watchlist_tutorials(DynamicArray<Tutorial>* watchlist, Tutorial* t);

    /// Increases the number of likes of a tutorial
    /// \param t the tutorial having its number of likes increased
    void increase_like_service(Tutorial* t);

    /// Returns the repo
    /// \return the repo
    Repository* getRepository();

};


#endif //A45_912_CEONTEA_VLADCALIN_USERSERVICE_H
