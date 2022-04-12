//
// Created by Vlad on 20/03/2021.
//

#include "Service.h"
#include <string>
#include <assert.h>
#include <iostream>
#include <algorithm>

#pragma once

Service::Service(){

    this->repo = new Repository;
}
Service::~Service(){

    delete this->repo;
    this->repo = NULL;
}

void Service::add_tutorial_service(std::string title, std::string presenter, std::string minutes, std::string seconds, std::string likes, std::string link){

    std::string duration = minutes;


    int lik = stoi(likes);
    if (stoi(seconds)<10){
        duration = duration + ":0";
    }
    else{
        duration= duration+":";
    }
    duration= duration+seconds;

    Tutorial t{title, presenter, duration, lik, link};

    this->repo->add_tutorial_repository(t);

}

void Service::remove_tutorial_service(std::string link){

    this->repo->remove_tutorial_repository(link);
}

void Service::update_tutorial_service(std::string link, int option1, int option2, int option3, int option4, std::string new_title, std::string new_presenter, std::string new_minutes, std::string new_seconds, std::string new_likes){

    std::string new_duration = new_minutes;


    int new_lik = stoi(new_likes);
    if (stoi(new_seconds)<10){
        new_duration = new_duration + ":0";
    }
    else{
        new_duration= new_duration+":";
    }
    new_duration= new_duration+new_seconds;

    this->repo->update_tutorial_repository(link, option1, option2, option3, option4, new_title, new_presenter, new_duration, new_lik);
}

Repository* Service::getRepository() {

    return this->repo;
}

void Service::search_tutorials_service(std::vector<Tutorial> &show_list, std::string text){

    for(auto i: this->getRepository()->getElements()) {
        if(i.getPresenter().find(text)!=std::string::npos){
            show_list.push_back(i);
        }
    }
}

void Service::increase_like_service(Tutorial t){

    this->repo->increase_like_repo(t);
}

