//
// Created by Vlad on 17/04/2021.
//

#include <algorithm>
#include <iostream>
#include "Validator.h"
#include "Exceptions.h"

#pragma once

void Validator::valid_title(std::string &title) {

    if (title.length() < 3){
        throw (Exceptions("The title is too short."));
    }
}

void Validator::valid_presenter(std::string &presenter){

    if (presenter.length() < 3){
        throw (Exceptions("The presenter is too short."));
    }
}

void Validator::valid_minutes(std::string &minutes) {

    if(!std::all_of(minutes.begin(), minutes.end(), ::isdigit)){
        throw(Exceptions("Not a number."));
    }

    int min = std::stoi(minutes);
    if ((min<0) || (min>59)){
        throw(Exceptions("Not a valid amount of minutes."));
    }

}

void Validator::valid_seconds(std::string &seconds) {

    if(!std::all_of(seconds.begin(), seconds.end(), ::isdigit)){
        throw(Exceptions("Not a number."));
    }

    int sec = std::stoi(seconds);
    if ((sec<0) || (sec>59)){
        throw(Exceptions("Not a valid amount of seconds."));
    }

}

void Validator::valid_likes(std::string &likes) {

    if(!std::all_of(likes.begin(), likes.end(), ::isdigit)){
        throw(Exceptions("Not a number."));
    }

    int nrLikes = std::stoi(likes);

    if (nrLikes < 0){
        throw(Exceptions("Not a valid amount of likes."));
    }

}

void Validator::valid_link(std::string &link){

    if (link.length() < 3){
        throw (Exceptions("The presenter is too short."));
    }
    std::string start = "https://www.youtube.com/watch?v=";
    if(start != link.substr(0, 32)){
        throw (Exceptions("The link is not written correctly."));
    }
}

void Validator::valid_integer(std::string &integer) {

    if(!std::all_of(integer.begin(), integer.end(), ::isdigit)){
        throw(Exceptions("Not a number."));
    }
}

void Validator::valid_option(std::string &option) {

    if(!std::all_of(option.begin(), option.end(), ::isdigit)){
        throw(Exceptions("Not a number."));
    }

    int nrOption = std::stoi(option);

    if (nrOption!=0 && nrOption!=1){
        throw(Exceptions("Not a valid option."));
    }
}

