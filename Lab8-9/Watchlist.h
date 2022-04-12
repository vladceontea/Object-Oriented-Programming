//
// Created by Vlad on 18/04/2021.
//

#ifndef A67_912_CEONTEA_VLADCALIN_WATCHLIST_H
#define A67_912_CEONTEA_VLADCALIN_WATCHLIST_H


#include "Tutorial.h"

class Watchlist {

protected:
    std::vector<Tutorial> data;

public:

    /// Adds a tutorial to the watchlist
    /// \param t the tutorial to be added
    /// \param message 1 if the tutorial is already in the watchlist, 0 otherwise
    void add_element(Tutorial t);

    /// Deletes a tutorial from the watchlist
    /// \param t the tutorial to be deleted
    void delete_element(Tutorial t);

    virtual void write() = 0;

    virtual void open() = 0;

    std::vector<Tutorial> &getData() {return data;}

};


class HTMLWatchlist: public Watchlist{

    void write() override;

    void open() override;
};

class CSVWatchlist: public Watchlist{

    void write() override;

    void open() override;
};


#endif //A67_912_CEONTEA_VLADCALIN_WATCHLIST_H
