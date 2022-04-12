//
// Created by Vlad on 20/03/2021.
//

#ifndef A45_912_CEONTEA_VLADCALIN_UI_H
#define A45_912_CEONTEA_VLADCALIN_UI_H

#endif //A45_912_CEONTEA_VLADCALIN_UI_H

#include "Service.h"

class UI{

private:

    Service* service;

public:

    UI();

    ~UI();


    void add_tutorial_ui();

    void remove_tutorial_ui();

    void update_tutorial_ui();

    void show_all_tutorials();

    void initial_values();

    void search_tutorials_ui(DynamicArray<Tutorial>* watchlist);

    void show_watchlist(DynamicArray<Tutorial>* watchlist);

    void delete_watchlist_tutorials_ui(DynamicArray<Tutorial>* watchlist);

    Service* getService();

};
