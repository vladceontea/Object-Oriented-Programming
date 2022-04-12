//
// Created by Vlad on 20/03/2021.
//

#include "Service.h"
#include <string>
#include <assert.h>
#include <iostream>

Service::Service(){

    this->repo = new Repository;
}
Service::~Service(){

    delete this->repo;
    this->repo = NULL;
}

void Service::add_tutorial_service(std::string title, std::string presenter, int minutes, int seconds, int likes, std::string link, int& message){

    std::string duration = std::to_string(minutes);
    std::string seconds_s = std::to_string(seconds);
    if (seconds<10){
        duration = duration + ":0";
    }
    else{
        duration= duration+":";
    }
    duration= duration+seconds_s;

    Tutorial t{title, presenter, duration, likes, link};

    this->repo->add_tutorial_repository(t, message);

}

void Service::remove_tutorial_service(std::string link, int &message){

    this->repo->remove_tutorial_repository(link, message);
}

void Service::update_tutorial_service(std::string link, int option1, int option2, int option3, int option4, std::string new_title, std::string new_presenter, int new_minutes, int new_seconds, int new_likes, int &message){

    std::string new_duration = "";
    if (new_minutes!=-1){
        std::string minutes_s = std::to_string(new_minutes);
        std::string seconds_s = std::to_string(new_seconds);
        if (new_seconds<10){
            minutes_s = minutes_s + ":0";
        }
        else{
            minutes_s = minutes_s + ":";
        }

        new_duration = minutes_s + seconds_s;
    }

    this->repo->update_tutorial_repository(link, option1, option2, option3, option4, new_title, new_presenter, new_duration, new_likes, message);
}

Repository* Service::getRepository() {

    return this->repo;
}

int Service::search_tutorials_service(Tutorial show_list[], std::string text){

    int i, j = 0;
    for(i=0;i<this->getRepository()->return_repo_length();i++) {
        if(this->getRepository()->return_repo_element(i)->getPresenter().find(text)!=std::string::npos){
            show_list[j] = *this->getRepository()->return_repo_element(i);
            j++;
        }
    }

    return j;
}

void Service::add_to_watchlist(DynamicArray<Tutorial>* watchlist, Tutorial t, int &message){

    int i;
    bool found = false;
    for(i=0; i<watchlist->returnLength(); i++){
        if (watchlist->getElement(i)->getLink() == t.getLink()){
            found = true;
        }
    }

    if(!found){
            watchlist->add(t);
    }
    else{
        message = 1;
    }
}

void Service::delete_watchlist_tutorials(DynamicArray<Tutorial>* watchlist, Tutorial* t){

    watchlist->remove(t);
}

void Service::increase_like_service(Tutorial* t){

    this->repo->increase_like_repo(t);
}

