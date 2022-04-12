//
// Created by Vlad on 20/03/2021.
//

#include <iostream>
#include "Tests.h"


void main_menu(){

    std::cout<<std::endl;
    std::cout<<"1. Add a new tutorial."<<std::endl;
    std::cout<<"2. Remove a tutorial."<<std::endl;
    std::cout<<"3. Update a tutorial."<<std::endl;
    std::cout<<"4. Show all tutorials."<<std::endl;
    std::cout<<"0. Exit the app."<<std::endl;

}

void main_menu_user(){

    std::cout<<std::endl;
    std::cout<<"1. Search for tutorials."<<std::endl;
    std::cout<<"2. Delete tutorials you have seen."<<std::endl;
    std::cout<<"3. See the watch list"<<std::endl;
    std::cout<<"0. Exit the app."<<std::endl;

}


int main()
{
    testsDynamicArray();
    testsTutorial();
    testsRepo();
    testsService();

    UI ui;
    int mode = -1, command = -1, ok = 0;
    while (ok == 0){
        std::cout<<"Choose the mode: (1. Administrator. 2.User)"<<std::endl;
        std::cin>>mode;

        if (mode==1){
            ok = 1;
        }
        if (mode==2){
            ok =2;
        }
        if(mode!=1 && mode!=2){

            std::cout<<"Not a valid mode."<<std::endl;
        }

    }
    ui.initial_values();

    while(ok==1){
        main_menu();
        std::cout<<"Enter the command: "<<std::endl;
        std::cin>>command;

        if (command==0){
            ok = 0;
        }
        if (command == 1) {
            ui.add_tutorial_ui();
        }
        if (command == 2) {
            ui.remove_tutorial_ui();
        }
        if (command == 3) {
            ui.update_tutorial_ui();
        }
        if (command==4) {
            ui.show_all_tutorials();
        }
        if (command <0 || command >4){
            std::cout<<"Not a valid command."<<std::endl;
        }
    }

    if(ok==2){
        DynamicArray<Tutorial>* watchlist = new DynamicArray<Tutorial>[2];

        while(ok==2){
            main_menu_user();
            std::cout<<"Enter the command: "<<std::endl;
            std::cin>>command;

            if(command == 0){
                ok = 0;
            }
            if (command == 1){
                ui.search_tutorials_ui(watchlist);
            }
            if (command == 2){
                ui.delete_watchlist_tutorials_ui(watchlist);
            }
            if(command == 3){
                ui.show_watchlist(watchlist);
            }
            if (command <0 || command >3){
                std::cout<<"Not a valid command."<<std::endl;
            }
        }
    }

    return 0;
}


