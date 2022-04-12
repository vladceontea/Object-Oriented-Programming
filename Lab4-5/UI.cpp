//
// Created by Vlad on 20/03/2021.
//

#include<iostream>
#include "UI.h"

UI::UI(){

    this->service = new Service;
}

UI::~UI(){

    delete this->service;
    this->service = NULL;

}

void UI::add_tutorial_ui() {

    std::string title, presenter, link;
    int likes, minutes = -1, seconds = -1, message = 0;
    std::cout<<"Enter the title: ";
    std::getline(std::cin >> std::ws, title);
    std::cout<<std::endl<<"Enter the presenter: ";
    std::getline(std::cin >> std::ws, presenter);
    while (minutes < 0){
        std::cout<<std::endl<<"Enter the minutes of the tutorial: ";
        std::cin>>minutes;
        if (minutes<0){
            std::cout<<std::endl<<"Not a valid amount of minutes.";
        }
    }
    while (seconds < 0 || seconds>59){
        std::cout<<std::endl<<"Enter the seconds of the tutorial: ";
        std::cin>>seconds;
        if (seconds<0 || seconds>59){
            std::cout<<std::endl<<"Not a valid amount of seconds.";
        }
    }
    std::cout<<std::endl<<"Enter the number of likes: ";
    std::cin>>likes;
    std::cout<<std::endl<<"Enter the link: ";
    std::cin>>link;

    this->service->add_tutorial_service(title, presenter, minutes, seconds, likes, link, message);

    if(message == 1){
        std::cout<<std::endl<<"This element already exists."<<std::endl;
    }
}

void UI::remove_tutorial_ui() {

    int message = 0;
    std::string link;
    std::cout<<std::endl<<"Enter the link of the element you wish to delete: ";
    std::cin>>link;

    this->service->remove_tutorial_service(link, message);

    if(message == 0){
        std::cout<<std::endl<<"This element does not exist."<<std::endl;
    }


}

void UI::update_tutorial_ui() {

    int message = 0, option1 = 0, option2 = 0, option3 = 0, option4 = 0, new_minutes = -1, new_seconds = -1, new_likes = 0;
    std::string link, new_title = "", new_presenter = "";
    std::cout<<std::endl<<"Enter the link of the element you wish to update: ";
    std::cin>>link;

    std::cout<<std::endl<<"Do you want to change the title?(1 if yes, 0 if no)";
    std::cin>>option1;
    if (option1==1){
        std::cout<<std::endl<<"Enter the new title: ";
        std::getline(std::cin >> std::ws, new_title);
    }
    else{
        option1 = 0;
    }

    std::cout<<std::endl<<"Do you want to change the presenter?(1 if yes, 0 if no)";
    std::cin>>option2;
    if (option2==1){
        std::cout<<std::endl<<"Enter the new presenter: ";
        std::getline(std::cin >> std::ws, new_presenter);
    }
    else{
        option2 = 0;
    }

    std::cout<<std::endl<<"Do you want to change the duration?(1 if yes, 0 if no)";
    std::cin>>option3;
    if (option3==1){
        while (new_minutes < 0){
            std::cout<<std::endl<<"Enter the minutes of the tutorial: ";
            std::cin>>new_minutes;
            if (new_minutes<0){
                std::cout<<std::endl<<"Not a valid amount of minutes.";
            }
        }
        while (new_seconds < 0 || new_seconds>59){
            std::cout<<std::endl<<"Enter the seconds of the tutorial: ";
            std::cin>>new_seconds;
            if (new_seconds<0 || new_seconds>59){
                std::cout<<std::endl<<"Not a valid amount of seconds.";
            }
        }
    }
    else{
        option3 = 0;
    }

    std::cout<<std::endl<<"Do you want to change the number of likes?(1 if yes, 0 if no)";
    std::cin>>option4;
    if (option4==1){
        std::cout<<std::endl<<"Enter the new number of likes: ";
        std::cin>>new_likes;
    }
    else{
        option4 = 0;
    }

    this->service->update_tutorial_service(link, option1, option2, option3, option4, new_title, new_presenter, new_minutes, new_seconds, new_likes, message);

    if (message==0){
        std::cout<<std::endl<<"This element does not exist."<<std::endl;
    }

}

void UI::show_all_tutorials() {

    int i;
    for(i=0; i<this->service->getRepository()->return_repo_length();i++){
        std::string buffer1, buffer2;
        buffer1 = this->service->getRepository()->return_repo_element(i)->to_string1();
        buffer2 = this->service->getRepository()->return_repo_element(i)->to_string2();
        std::cout<<buffer1<<std::endl<<buffer2<<std::endl<<std::endl;
    }

}

void UI::search_tutorials_ui(DynamicArray<Tutorial>* watchlist) {

    std::string text;

    Tutorial* show_list = new Tutorial[this->service->getRepository()->return_repo_length()];

    int j, i = 0, k = 0;

    std::cout<<std::endl<<"Search for presenters: ";
    std::cin.ignore();
    std::getline(std::cin, text);

    j = this->service->search_tutorials_service(show_list, text);

    while(i<j){
        std::string buffer1, buffer2;
        buffer1 = show_list[i].to_string1();
        buffer2 = show_list[i].to_string2();
        std::cout<<buffer1<<std::endl<<buffer2<<std::endl<<std::endl;

        int answer;

        std::cout<<std::endl<<"Add this tutorial to the watchlist?(1.Yes 0.No)";
        std::cin>>answer;
        if(answer == 1){
            int message = 0;
            this->service->add_to_watchlist(watchlist, show_list[i], message);
            if (message == 1){
                std::cout<<std::endl<<"This tutorial is already in the watchlist.";
            }
        }

        std::cout<<std::endl<<"See the next tutorial?(1.Yes 0.No)";
        std::cin>>answer;
        if (answer == 1){
            i++;
            if(i == j){
                i = 0;
            }
        }
        if (answer == 0){
            i = j;
        }
    }
    delete[] show_list;
}

void UI::show_watchlist(DynamicArray<Tutorial>* watchlist) {

    int i;
    if( watchlist->returnLength() == 0){
        std::cout<<std::endl<<"Your watchlist is empty";
    }
    else{
        for(i=0; i<watchlist->returnLength(); i++){
            std::string buffer1, buffer2;
            buffer1 = watchlist->getElement(i)->to_string1();
            buffer2 = watchlist->getElement(i)->to_string2();
            std::cout<<buffer1<<std::endl<<buffer2<<std::endl<<std::endl;
        }
    }
}

void UI::delete_watchlist_tutorials_ui(DynamicArray<Tutorial>* watchlist){

    int i;
    if( watchlist->returnLength() == 0){
        std::cout<<std::endl<<"Your watchlist is empty";
    }
    else{
        for(i=0; i<watchlist->returnLength(); i++){
            std::string buffer1, buffer2;
            buffer1 = watchlist->getElement(i)->to_string1();
            buffer2 = watchlist->getElement(i)->to_string2();
            std::cout<<buffer1<<std::endl<<buffer2<<std::endl<<std::endl;

            int answer, like;

            std::cout<<std::endl<<"Delete this watchlist?(1.Yes 0.No)";
            std::cin>>answer;


            if (answer == 1){
                std::cout<<std::endl<<"Like this tutorial?(1.Yes 0.No)";
                std::cin>>like;

                if (like==1){
                    this->service->increase_like_service(watchlist->getElement(i));
                }

                this->service->delete_watchlist_tutorials(watchlist, watchlist->getElement(i));
                i--;
            }
        }
    }

}

void UI::initial_values(){

    int message = 0;
    Tutorial t1{"Recursion In C++","Anastasia Broughton","5:37", 12345, "https://www.youtube.com/watch?v=fVMgnmi2D1w"};
    Tutorial t2{"Type Conversions In C++","Robin Millar","3:42", 4345, "https://www.youtube.com/watch?v=mhCcWFapO30"};
    Tutorial t3{"Object-Oriented Programming In C++","Sana Khan","16:05", 62363, "https://www.youtube.com/watch?v=1mLZ9A5dJZk"};
    Tutorial t4{"Sorting Techniques In C++","Poppy-Mae Cameron","8:39", 19135, "https://www.youtube.com/watch?v=phZipjxiTBR"};
    Tutorial t5{"Python Vs C++ | Top 16 Differences Between C++ And Python","Bret Dougherty","23:56", 112585, "https://www.youtube.com/watch?v=L5YHQ9AY6Bs"};
    Tutorial t6{"Polymorphism In C++","Bret Dougherty","3:12", 1345, "https://www.youtube.com/watch?v=wfIUD8AUwyX"};
    Tutorial t7{"Exception Handling In C++","Nigel Kaufman","2:05", 50345, "https://www.youtube.com/watch?v=YHQ6E7FGMUz"};
    Tutorial t8{"Constants In C++","Jarred Blackburn","7:01", 17845, "https://www.youtube.com/watch?v=cCjlGDSOHvP"};
    Tutorial t9{"Classes And Objects In C++","Theresa Ferrell","12:34", 234567, "https://www.youtube.com/watch?v=5CUOBUGHqcu"};
    Tutorial t10{"C Vs C++: 39 Main Differences Between C And C++ With Examples","Eugene Hale","35:37", 187632, "https://www.youtube.com/watch?v=0glTOqnJTD2"};

    this->getService()->getRepository()->add_tutorial_repository(t1, message);
    this->getService()->getRepository()->add_tutorial_repository(t2, message);
    this->getService()->getRepository()->add_tutorial_repository(t3, message);
    this->getService()->getRepository()->add_tutorial_repository(t4, message);
    this->getService()->getRepository()->add_tutorial_repository(t5, message);
    this->getService()->getRepository()->add_tutorial_repository(t6, message);
    this->getService()->getRepository()->add_tutorial_repository(t7, message);
    this->getService()->getRepository()->add_tutorial_repository(t8, message);
    this->getService()->getRepository()->add_tutorial_repository(t9, message);
    this->getService()->getRepository()->add_tutorial_repository(t10, message);


}

Service* UI::getService(){

    return this->service;
}
