//
// Created by Vlad on 20/03/2021.
//

#ifndef A45_912_CEONTEA_VLADCALIN_UI_H
#define A45_912_CEONTEA_VLADCALIN_UI_H

#endif //A45_912_CEONTEA_VLADCALIN_UI_H

#include "Service.h"
#include "Watchlist.h"

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

    void search_tutorials_ui(Watchlist* watchlist);

    void show_watchlist(Watchlist* boringWatchlist);

    void delete_watchlist_tutorials_ui(Watchlist* watchlist);

    void main_menu();

    void main_menu_user();

    void start_ui();

    Service* getService();

};
