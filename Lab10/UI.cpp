//
// Created by Vlad on 20/03/2021.
//

#include<iostream>
#include "UI.h"
#include "Validator.h"
#include "Exceptions.h"


UI::UI(){

    this->service = new Service;
}

UI::~UI(){

    delete this->service;
    this->service = nullptr;

}

void UI::add_tutorial_ui() {

    std::string title, presenter, link, likes, minutes, seconds;
    int ok;
    Validator valid;
    do {
        ok = 1;
        try {
            std::cout << std::endl << "Enter the title: ";
            std::getline(std::cin >> std::ws, title);
            valid.valid_title(title);

        }
        catch (Exceptions &ex) {
            std::cout << ex.getMessage() << std::endl;
            ok = 0;
        }
    } while (ok == 0);

    do {
        ok = 1;
        try {
            std::cout << std::endl << "Enter the presenter: ";
            std::getline(std::cin >> std::ws, presenter);
            valid.valid_presenter(presenter);

        }
        catch (Exceptions &ex) {
            std::cout << ex.getMessage() << std::endl;
            ok = 0;
        }
    } while (ok == 0);

    do {
        ok = 1;
        try {
            std::cout << std::endl << "Enter the minutes of the tutorial: ";
            std::getline(std::cin >> std::ws, minutes);
            valid.valid_minutes(minutes);

        }
        catch (Exceptions &ex) {
            std::cout << ex.getMessage() << std::endl;
            ok = 0;
        }
    } while (ok == 0);

    do {
        ok = 1;
        try {
            std::cout << std::endl << "Enter the seconds of the tutorial: ";
            std::getline(std::cin >> std::ws, seconds);
            valid.valid_seconds(seconds);

        }
        catch (Exceptions &ex) {
            std::cout << ex.getMessage() << std::endl;
            ok = 0;
        }
    } while (ok == 0);

    do {
        ok = 1;
        try {
            std::cout << std::endl << "Enter the number of likes: ";
            std::getline(std::cin >> std::ws, likes);
            valid.valid_likes(likes);

        }
        catch (Exceptions &ex) {
            std::cout << ex.getMessage() << std::endl;
            ok = 0;
        }
    } while (ok == 0);


    do {
        ok = 1;
        try {
            std::cout << std::endl << "Enter the link: ";
            std::getline(std::cin >> std::ws, link);
            valid.valid_link(link);

        }
        catch (Exceptions &ex) {
            std::cout << ex.getMessage() << std::endl;
            ok = 0;
        }
    } while (ok == 0);

    try {
        this->service->add_tutorial_service(title, presenter, minutes, seconds, likes, link);
    }
    catch(Exceptions& ex){
        std::cout<<ex.getMessage()<<std::endl;
    }
}


void UI::remove_tutorial_ui() {

    std::string link;
    int ok;
    Validator valid;
    do{
        ok = 1;
        try{
            std::cout<<std::endl<<"Enter the link: ";
            std::getline(std::cin>>std::ws, link);
            valid.valid_link(link);

        }
        catch(Exceptions& ex){
            std::cout<<ex.getMessage()<<std::endl;
            ok = 0;
        }
    }while(ok==0);

    try{
        this->service->remove_tutorial_service(link);
    }
    catch(Exceptions& ex){
        std::cout<<ex.getMessage()<<std::endl;
    }

}

void UI::update_tutorial_ui() {

    int option1, option2, option3, option4, ok;
    std::string link, new_title = "", new_presenter = "", new_minutes = "", new_seconds = "", new_likes = "", opt1, opt2, opt3, opt4;
    Validator valid;

    do{
        ok = 1;
        try{
            std::cout<<std::endl<<"Enter the link: ";
            std::getline(std::cin>>std::ws, link);
            valid.valid_link(link);

        }
        catch(Exceptions& ex){
            std::cout<<ex.getMessage()<<std::endl;
            ok = 0;
        }
    }while(ok==0);

    do{
        ok = 1;
        try{
            std::cout<<std::endl<<"Do you want to change the title?(1 if yes, 0 if no)";
            std::cin>>opt1;
            valid.valid_option(opt1);

        }
        catch(Exceptions& ex){
            std::cout<<ex.getMessage()<<std::endl;
            ok = 0;
        }
    }while(ok==0);

    option1 = stoi(opt1);

    if (option1==1){
        do{
            ok = 1;
            try{
                std::cout<<std::endl<<"Enter the new title: ";
                std::getline(std::cin >> std::ws, new_title);
                valid.valid_title(new_title);

            }
            catch(Exceptions& ex){
                std::cout<<ex.getMessage()<<std::endl;
                ok = 0;
            }
        }while(ok==0);
    }

    do{
        ok = 1;
        try{
            std::cout<<std::endl<<"Do you want to change the presenter?(1 if yes, 0 if no)";
            std::cin>>opt2;
            valid.valid_option(opt2);

        }
        catch(Exceptions& ex){
            std::cout<<ex.getMessage()<<std::endl;
            ok = 0;
        }
    }while(ok==0);

    option2 = stoi(opt2);

    if (option2==1){
        do{
            ok = 1;
            try{
                std::cout<<std::endl<<"Enter the new presenter: ";
                std::getline(std::cin >> std::ws, new_presenter);
                valid.valid_presenter(new_presenter);

            }
            catch(Exceptions& ex){
                std::cout<<ex.getMessage()<<std::endl;
                ok = 0;
            }
        }while(ok==0);
    }

    do{
        ok = 1;
        try{
            std::cout<<std::endl<<"Do you want to change the duration?(1 if yes, 0 if no)";
            std::cin>>opt3;
            valid.valid_option(opt3);

        }
        catch(Exceptions& ex){
            std::cout<<ex.getMessage()<<std::endl;
            ok = 0;
        }
    }while(ok==0);

    option3 = stoi(opt3);

    if (option3==1){
        do{
            ok = 1;
            try{
                std::cout<<std::endl<<"Enter the new number of minutes of the tutorial: ";
                std::getline(std::cin>>std::ws, new_minutes);
                valid.valid_minutes(new_minutes);

            }
            catch(Exceptions& ex){
                std::cout<<ex.getMessage()<<std::endl;
                ok = 0;
            }
        }while(ok==0);

        do{
            ok = 1;
            try{
                std::cout<<std::endl<<"Enter the new number of seconds of the tutorial: ";
                std::getline(std::cin>>std::ws, new_seconds);
                valid.valid_seconds(new_seconds);

            }
            catch(Exceptions& ex){
                std::cout<<ex.getMessage()<<std::endl;
                ok = 0;
            }
        }while(ok==0);
    }

    do{
        ok = 1;
        try{
            std::cout<<std::endl<<"Do you want to change the number of likes?(1 if yes, 0 if no)";
            std::cin>>opt4;
            valid.valid_option(opt4);

        }
        catch(Exceptions& ex){
            std::cout<<ex.getMessage()<<std::endl;
            ok = 0;
        }
    }while(ok==0);

    option4 = stoi(opt4);

    if (option4==1){
        do{
            ok = 1;
            try{
                std::cout<<std::endl<<"Enter the new number of likes: ";
                std::getline(std::cin>>std::ws, new_likes);
                valid.valid_likes(new_likes);

            }
            catch(Exceptions& ex){
                std::cout<<ex.getMessage()<<std::endl;
                ok = 0;
            }
        }while(ok==0);
    }

    try{
        this->service->update_tutorial_service(link, option1, option2, option3, option4, new_title, new_presenter, new_minutes, new_seconds, new_likes);
    }
    catch(Exceptions& ex){
        std::cout<<ex.getMessage()<<std::endl;
    }

}

void UI::show_all_tutorials() {

    for(auto i: this->service->getRepository()->getElements()){
        std::string buffer1, buffer2;
        buffer1 = i.to_string1();
        buffer2 = i.to_string2();
        std::cout<<buffer1<<std::endl<<buffer2<<std::endl<<std::endl;
    }

}

void UI::search_tutorials_ui(Watchlist* watchlist) {

    std::string text;

    std::vector<Tutorial> show_list;

    int i = 0, ok;
    Validator valid;

    std::cout<<std::endl<<"Search for presenters: ";
    //std::cin.ignore();
    std::getline(std::cin, text);

    this->service->search_tutorials_service(show_list, text);

    while(i<show_list.size()){
        std::string buffer1, buffer2;
        buffer1 = show_list[i].to_string1();
        buffer2 = show_list[i].to_string2();
        std::cout<<buffer1<<std::endl<<buffer2<<std::endl<<std::endl;

        std::string answer_text;
        int answer;
        do{
            ok = 1;
            try{
                std::cout<<std::endl<<"Add this tutorial to the watchlist?(1.Yes 0.No)";
                std::cin>>answer_text;
                valid.valid_option(answer_text);

            }
            catch(Exceptions& ex){
                std::cout<<ex.getMessage()<<std::endl;
                ok = 0;
            }
        }while(ok==0);

        answer = stoi(answer_text);

        if(answer == 1){
            try{
                watchlist->add_element(show_list[i]);
            }
            catch(Exceptions& ex){
                std::cout<<ex.getMessage()<<std::endl;
            }
        }

        do{
            ok = 1;
            try{
                std::cout<<std::endl<<"See the next tutorial?(1.Yes 0.No)";
                std::cin>>answer_text;
                valid.valid_option(answer_text);

            }
            catch(Exceptions& ex){
                std::cout<<ex.getMessage()<<std::endl;
                ok = 0;
            }
        }while(ok==0);

        answer = stoi(answer_text);

        if (answer == 1){
            i++;
            if(i == show_list.size()){
                i = 0;
            }
        }
        if (answer == 0){
            i = show_list.size();
        }
    }
}

void UI::show_watchlist(Watchlist* boringWatchlist) {


    if(boringWatchlist->getData().empty()){
        std::cout<<std::endl<<"Your watchlist is empty";
    }
    else{
        boringWatchlist->write();
        boringWatchlist->open();
        //std::cin.ignore();
    }

}

void UI::delete_watchlist_tutorials_ui(Watchlist* watchlist){

    Validator valid;
    if(watchlist->getData().empty()){
        std::cout<<std::endl<<"Your watchlist is empty";
    }
    else{
        auto i = std::begin(watchlist->getData());
        while(i != std::end(watchlist->getData())){
            std::string buffer1, buffer2;
            buffer1 = i->to_string1();
            buffer2 = i->to_string2();
            std::cout<<buffer1<<std::endl<<buffer2<<std::endl<<std::endl;

            std::string answer_text, like_text;
            int answer, like, ok;
            do{
                ok = 1;
                try{
                    std::cout<<std::endl<<"Delete this tutorial?(1.Yes 0.No)";
                    std::cin>>answer_text;
                    valid.valid_option(answer_text);

                }
                catch(Exceptions& ex){
                    std::cout<<ex.getMessage()<<std::endl;
                    ok = 0;
                }
            }while(ok==0);

            answer = stoi(answer_text);

            if (answer == 1){
                do{
                    ok = 1;
                    try{
                        std::cout<<std::endl<<"Like this tutorial?(1.Yes 0.No)";
                        std::cin>>like_text;
                        valid.valid_option(answer_text);

                    }
                    catch(Exceptions& ex){
                        std::cout<<ex.getMessage()<<std::endl;
                        ok = 0;
                    }
                }while(ok==0);

                like = stoi(like_text);

                if (like==1){
                    this->service->increase_like_service(*i);
                }

                watchlist->delete_element(*i);
            }
            else{
                ++i;
            }
        }
    }

}

Service* UI::getService(){

    return this->service;
}

void UI::main_menu(){

    std::cout<<std::endl;
    std::cout<<"1. Add a new tutorial."<<std::endl;
    std::cout<<"2. Remove a tutorial."<<std::endl;
    std::cout<<"3. Update a tutorial."<<std::endl;
    std::cout<<"4. Show all tutorials."<<std::endl;
    std::cout<<"0. Exit the app."<<std::endl;

}

void UI::main_menu_user(){

    std::cout<<std::endl;
    std::cout<<"1. Search for tutorials."<<std::endl;
    std::cout<<"2. Delete tutorials you have seen."<<std::endl;
    std::cout<<"3. See the watch list"<<std::endl;
    std::cout<<"0. Exit the app."<<std::endl;

}

void UI::start_ui(){

    Validator valid;
    int mode, command , ok = 0;
    std::string mode_text, command_text;
    while (ok == 0) {

        do{
            ok = 1;
            try{
                std::cout << "Choose the mode: (1. Administrator. 2.User)" << std::endl;
                std::getline(std::cin>>std::ws, mode_text);
                valid.valid_integer(mode_text);

            }
            catch(Exceptions& ex){
                std::cout<<ex.getMessage()<<std::endl;
                ok = 0;
            }
        }while(ok==0);

        ok = 0;

        mode = stoi(mode_text);

        if (mode == 1) {
            ok = 1;
        }
        if (mode == 2) {
            ok = 2;
        }
        if (mode != 1 && mode != 2) {

            std::cout << "Not a valid mode." << std::endl;
        }

    }

    while(ok==1){
        main_menu();

        do{
            ok = 1;
            try{
                std::cout<<"Enter the command: "<<std::endl;
                std::getline(std::cin>>std::ws, command_text);
                valid.valid_integer(command_text);

            }
            catch(Exceptions& ex){
                std::cout<<ex.getMessage()<<std::endl;
                ok = 0;
            }
        }while(ok==0);

        ok = 1;

        command = stoi(command_text);

        if (command==0){
            ok = 0;
        }
        if (command == 1) {
            this->add_tutorial_ui();
        }
        if (command == 2) {
            this->remove_tutorial_ui();
        }
        if (command == 3) {
            this->update_tutorial_ui();
        }
        if (command==4) {
            this->show_all_tutorials();
        }
        if (command <0 || command >4){
            std::cout<<"Not a valid command."<<std::endl;
        }
    }

    if(ok==2){

        Watchlist* boringWatchlist;

        std::string filetype;
        ok = 0;
        while(ok==0){
            std::cout<<"Enter the type of file you want to see the watchlist in: "<<std::endl;
            std::getline(std::cin>>std::ws, filetype);

            if (filetype == "CSV"){
                boringWatchlist = new CSVWatchlist();
                ok = 2;
            }
            if (filetype == "HTML"){
                boringWatchlist = new HTMLWatchlist();
                ok = 2;
            }
            if(filetype != "CSV" && filetype != "HTML"){
                std::cout<<"Not a valid file type."<<std::endl;
            }
        }

        while(ok==2){
            main_menu_user();

            do{
                ok = 1;
                try{
                    std::cout<<"Enter the command: "<<std::endl;
                    std::getline(std::cin>>std::ws, command_text);
                    valid.valid_integer(command_text);

                }
                catch(Exceptions& ex){
                    std::cout<<ex.getMessage()<<std::endl;
                    ok = 0;
                }
            }while(ok==0);

            ok = 2;

            command = stoi(command_text);

            if(command == 0){
                ok = 0;
            }
            if (command == 1){
                this->search_tutorials_ui(boringWatchlist);
            }
            if (command == 2){
                this->delete_watchlist_tutorials_ui(boringWatchlist);
            }
            if(command == 3){
                this->show_watchlist(boringWatchlist);

            }
            if (command <0 || command >3){
                std::cout<<"Not a valid command."<<std::endl;
            }
        }
        delete boringWatchlist;
    }
}
