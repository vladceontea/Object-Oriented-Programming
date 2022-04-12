//
// Created by Vlad on 20/03/2021.
//

#include <iostream>
#include "Repository.h"
#include <algorithm>
#include <fstream>
#include "Exceptions.h"

Repository::Repository(){

}
Repository::~Repository(){

}

void Repository::read_file() {
    std::ifstream f("Tutorials.txt");

    if(!f.is_open()){
        return;
    }
    Tutorial t;
    while(f>>t){
        this->tutorials.push_back(t);
    }
    f.close();
}

void Repository::write_file() {

    std::ofstream f("Tutorials.txt");
    if(!f.is_open()){
        return;
    }
    for (const auto& t: this->tutorials){
        f<<t;
    }
    f.close();

}

void Repository::add_tutorial_repository(Tutorial t){

    std::string link = t.getLink();

    auto it = std::find_if(this->tutorials.begin(), this->tutorials.end(), [&link](Tutorial& tutorial){
        return tutorial.getLink() == link;
    });
    if (it != this->tutorials.end()){
        throw (Exceptions("This tutorial already exists."));
    }
    else{
        this->tutorials.push_back(t);
    }

    write_file();
}

void Repository::remove_tutorial_repository(std::string link){

    auto it = std::find_if(this->tutorials.begin(), this->tutorials.end(), [&link](Tutorial& tutorial){
        return tutorial.getLink() == link;
    });

    if (it != this->tutorials.end()){
        this->tutorials.erase(it);
    }
    else{
        throw (Exceptions("This tutorial does not exist."));
    }
    write_file();
}

void Repository::update_tutorial_repository(std::string link, int option1, int option2, int option3, int option4, std::string new_title, std::string new_presenter, std::string new_duration, int  new_likes) {

    int ok = 0, j, k=0;
    Tutorial t;
    for(auto i: this->tutorials){
        if(i.getLink() == link){
            ok = 1;
            j = k;
        }
        k++;
    }

    if (ok==1){
        if (option1==1){
            this->tutorials[j].setTitle(&new_title);
        }
        if (option2==1){
            this->tutorials[j].setPresenter(&new_presenter);
        }
        if (option3==1){
            this->tutorials[j].setDuration(&new_duration);
        }
        if (option4==1){
            this->tutorials[j].setLikes(&new_likes);
        }
    }
    else{
        throw (Exceptions("This tutorial does not exist."));
    }
    write_file();
}

int Repository::return_repo_length(){

    return this->tutorials.size();
}

Tutorial* Repository::return_repo_element(int i) {

    return &this->tutorials[i];
}

std::vector<Tutorial> Repository::getElements() {

    return this->tutorials;
}

void Repository::increase_like_repo(Tutorial t){

    int new_likes, k = 0;

    for(auto i: this->tutorials){
        if(i.getLink() == t.getLink()){
            new_likes = i.getLikes();
            new_likes++;
            this->tutorials[k].setLikes(&new_likes);
        }
        k++;
    }

    write_file();
}