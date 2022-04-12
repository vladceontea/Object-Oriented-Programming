//
// Created by Vlad on 20/03/2021.
//

#include <iostream>
#include "Repository.h"
#include <assert.h>

Repository::Repository(){

    this->tutorials = new DynamicArray<Tutorial>();

}
Repository::~Repository(){

    delete this->tutorials;
    this->tutorials = NULL;
}

void Repository::add_tutorial_repository(Tutorial t, int &message){

    int i;
    for(i=0;i<this->tutorials->returnLength();i++){
        if(this->tutorials->getElement(i)->getLink() == t.getLink()){
            message = 1;
        }
    }
    if (message==0){
        this->tutorials->add(t);
    }
}

void Repository::remove_tutorial_repository(std::string link, int &message){

    int i;
    Tutorial* t;
    for(i=0;i<this->tutorials->returnLength();i++){
        if(this->tutorials->getElement(i)->getLink() == link){
            message = 1;
            t = this->tutorials->getElement(i);
        }
    }

    if (message == 1){
        this->tutorials->remove(t);
    }
}

void Repository::update_tutorial_repository(std::string link, int option1, int option2, int option3, int option4, std::string new_title, std::string new_presenter, std::string new_duration, int  new_likes, int &message) {

    int i, j;
    Tutorial t;
    for(i=0;i<this->tutorials->returnLength();i++){
        if(this->tutorials->getElement(i)->getLink() == link){
            message = 1;
            j = i;
        }
    }

    if (message==1){
        if (option1==1){
            this->tutorials->getElement(j)->setTitle(&new_title);
        }
        if (option2==1){
            this->tutorials->getElement(j)->setPresenter(&new_presenter);
        }
        if (option3==1){
            this->tutorials->getElement(j)->setDuration(&new_duration);
        }
        if (option4==1){
            this->tutorials->getElement(j)->setLikes(&new_likes);
        }
    }

}

int Repository::return_repo_length(){

    return this->tutorials->returnLength();
}

Tutorial* Repository::return_repo_element(int i) {

    return this->tutorials->getElement(i);
}

DynamicArray<Tutorial>* Repository::getElements() {

    return this->tutorials;
}

void Repository::increase_like_repo(Tutorial* t){

    int i, new_likes;

    for(i=0;i<this->tutorials->returnLength();i++){
        if(this->tutorials->getElement(i)->getLink() == t->getLink()){
            new_likes = this->tutorials->getElement(i)->getLikes();
            new_likes++;
            this->tutorials->getElement(i)->setLikes(&new_likes);
        }
    }
}