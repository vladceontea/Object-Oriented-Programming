//
// Created by Vlad on 07/03/2021.
//

#ifndef A23_912_CEONTEA_VLADCALIN_UI_H
#define A23_912_CEONTEA_VLADCALIN_UI_H

#endif //A23_912_CEONTEA_VLADCALIN_UI_H

#include "Service.h"
#include "UndoRedo.h"

typedef struct
{
    Service* service;
    Undo* undo;
}UI;


UI* createUI(Service* service);
void main_menu();
void add_estate_ui(UI* ui);
void remove_estate_ui(UI* ui);
void update_estate_ui(UI* ui);
void search_estates_ui(UI* ui);
void show_estates(UI* ui);
void show_filtered_estates(UI* ui);
void undo_ui(UI* ui);
void redo_ui(UI* ui);
void start();