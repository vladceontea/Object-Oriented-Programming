//
// Created by Vlad on 18/04/2021.
//

#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include "Watchlist.h"
#include "Exceptions.h"

void Watchlist::add_element(Tutorial t) {
    std::string link = t.getLink();

    auto it = std::find_if(this->data.begin(), this->data.end(), [&link](Tutorial& tutorial){
        return tutorial.getLink() == link;
    });

    if(it == this->data.end()){
        this->data.push_back(t);
    }
    else{
        throw (Exceptions("This tutorial is already in the wacthlist."));
    }
}

void Watchlist::delete_element(Tutorial t) {

    auto it = std::find_if(this->data.begin(), this->data.end(), [&t](Tutorial& tutorial){
        return tutorial == t;
    });
    this->data.erase(it);
}

void HTMLWatchlist::write(){

    std::ofstream f("Tutorials.html");

    if(!f.is_open()){
        return;
    }

    f<<"<!DOCTYPE html>"<<std::endl;
    f<<"<html>"<<std::endl;
    f<<"<head>"<<std::endl;
    f<<"    <title>Tutorials</title>"<<std::endl;
    f<<"</head>"<<std::endl;
    f<<"<body>"<<std::endl;
    f<<"<table border=\"1\">"<<std::endl;
    f<<"    <tr>"<<std::endl;
    f<<"        <td>Title</td>"<<std::endl;
    f<<"        <td>Presenter</td>"<<std::endl;
    f<<"        <td>Duration</td>"<<std::endl;
    f<<"        <td>Likes</td>"<<std::endl;
    f<<"        <td>Youtube link</td>"<<std::endl;
    f<<"    </tr>"<<std::endl;
    std::string text;
    for (auto& t: this->data){
        f<<"    <tr>"<<std::endl;
        text = "        <td>" + t.getTitle() + "</td>";
        f<<text<<std::endl;
        text = "        <td>" + t.getPresenter() + "</td>";
        f<<text<<std::endl;
        text = "        <td>" + t.getDuration() + "</td>";
        f<<text<<std::endl;
        text = "        <td>" + std::to_string(t.getLikes()) + "</td>";
        f<<text<<std::endl;
        text = "        <td><a href=\"" + t.getLink() + "\">Link</a></td>";
        f<<text<<std::endl;
    }
    f<<"</table>"<<std::endl;
    f<<"</body>"<<std::endl;
    f<<"</html>"<<std::endl;
    f.close();


}


void HTMLWatchlist::open() {

    std::string topic = "Tutorials.html";
    system(topic.c_str());
}


void CSVWatchlist::write(){

    std::ofstream f("Tutorials.csv");
    if(!f.is_open()){
        return;
    }
    for (const auto& t: this->data){
        f<<t;
    }
    f.close();

}


void CSVWatchlist::open(){

    std::string topic = "Tutorials.csv";
    system(topic.c_str());

}