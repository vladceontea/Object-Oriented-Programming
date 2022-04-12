//
// Created by Vlad on 20/03/2021.
//

#include "DynamicArray.h"
#pragma once

#ifndef A45_912_CEONTEA_VLADCALIN_REPOSITORY_H
#define A45_912_CEONTEA_VLADCALIN_REPOSITORY_H

#endif //A45_912_CEONTEA_VLADCALIN_REPOSITORY_H


class Repository{

private:
    DynamicArray<Tutorial>* tutorials;

public:

    /// Constructor of the repo
    Repository();

    /// Destructor of the repo
    ~Repository();

    /// Adds a tutorial to the repo
    /// \param t the tutorial to be added
    /// \param message 0 if element exists already, 1 if not
    void add_tutorial_repository(Tutorial t, int &message);

    /// Removes a tutorial from the repo
    /// \param link the link of the tutorial to be removed
    /// \param message 0 if element does not exist, 1 if it does
    void remove_tutorial_repository(std::string link, int &message);

    /// Updates the values of a tutorial
    /// \param link the link of the tutorial to be removed
    /// \param option1 1 if we change the title, 0 if not
    /// \param option2 1 if we change the presenter, 0 if not
    /// \param option3 1 if we change the duration, 0 if not
    /// \param option4 1 if we change the number of likes, 0 if not
    /// \param new_title the new title of the tutorial
    /// \param new_presenter the new presenter of the tutorial
    /// \param new_duration the new duration of the tutorial
    /// \param new_likes the new number of likes for the tutorial
    /// \param message 0 if element does not exist, 1 if it does
    void update_tutorial_repository(std::string link, int option1, int option2, int option3, int option4, std::string new_title, std::string new_presenter, std::string new_duration, int  new_likes, int &message);

    /// Returns the length of the repo
    /// \return the length of the repo
    int return_repo_length();

    /// Returns an element with a particular index
    /// \param i the index
    /// \return the element we look for
    Tutorial* return_repo_element(int i);

    /// Returns the dynamic array containing all the elements
    /// \return the dynamic array
    DynamicArray<Tutorial>* getElements();

    /// Increases the number of likes of a tutorial by 1
    /// \param t the tutorial having the number of likes increased
    void increase_like_repo(Tutorial* t);

};