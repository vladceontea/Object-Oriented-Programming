//
// Created by Vlad on 20/03/2021.
//

#include <string>
#include "Repository.h"

#ifndef A45_912_CEONTEA_VLADCALIN_SERVICE_H
#define A45_912_CEONTEA_VLADCALIN_SERVICE_H

#endif //A45_912_CEONTEA_VLADCALIN_SERVICE_H


class Service{

private:

    Repository* repo;
public:

    /// Constructor for the service
    Service();

    /// Destructor for the service
    ~Service();

    /// Adds a new tutorial to the service
    /// \param title the title of the tutorial
    /// \param presenter the presenter of the tutorial
    /// \param minutes the number of minutes of the tutorial
    /// \param seconds the number of seconds of the tutorial
    /// \param likes the number of likes of the tutorial
    /// \param link the link of the tutorial
    /// \param message 0 if element exists already, 1 if not
    void add_tutorial_service(std::string title, std::string presenter, int minutes, int seconds, int likes, std::string link, int &message);

    /// Removes a tutorial from the service
    /// \param link the link of the tutorial to be removed
    /// \param message 0 if element does not exist, 1 if it does
    void remove_tutorial_service(std::string link, int &message);

    /// Updates the values of a tutorial
    /// \param link the link of the tutorial to be removed
    /// \param option1 1 if we change the title, 0 if not
    /// \param option2 1 if we change the presenter, 0 if not
    /// \param option3 1 if we change the duration, 0 if not
    /// \param option4 1 if we change the number of likes, 0 if not
    /// \param new_title the new title of the tutorial
    /// \param new_presenter the new presenter of the tutorial
    /// \param new_minutes the new number of minutes of the tutorial
    /// \param new_seconds the new number of seconds of the tutorial
    /// \param new_likes the new number of likes for the tutorial
    /// \param message 0 if element does not exist, 1 if it does
    void update_tutorial_service(std::string link, int option1, int option2, int option3, int option4, std::string new_title, std::string new_presenter, int new_minutes, int new_seconds, int new_likes, int &message);

    /// Returns the repo
    /// \return the repo
    Repository* getRepository();

    /// Searches for tutorials whose presenters contain a certain string
    /// \param show_list the list which will show all the tutorials resulting in the search
    /// \param text the string to search through the presenters
    /// \return the length of the resulting list
    int search_tutorials_service(Tutorial show_list[], std::string text);

    /// Adds a tutorial from the watchlist
    /// \param watchlist the list of tutorials to be watched later
    /// \param the tutorial to be added
    void add_to_watchlist(DynamicArray<Tutorial>* watchlist, Tutorial t, int &message);

    /// Deletes a tutorial from the watchlist
    /// \param watchlist the list of tutorials to be watched later
    /// \param the tutorial to be deleted
    void delete_watchlist_tutorials(DynamicArray<Tutorial>* watchlist, Tutorial* t);

    /// Increases the number of likes of a tutorial
    /// \param t the tutorial having its number of likes increased
    void increase_like_service(Tutorial* t);
};

