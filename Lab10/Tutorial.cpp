//
// Created by Vlad on 20/03/2021.
//

#include <Tutorial.h>
#include <iostream>
#include <sstream>

Tutorial::Tutorial(){

}

Tutorial::Tutorial(std::string title, std::string presenter, std::string duration, int likes, std::string link){

    this->title = title;
    this->presenter = presenter;
    this->duration = duration;
    this->likes = likes;
    this->link = link;
}

std::string Tutorial::getTitle() const {
    return this->title;
}
std::string Tutorial::getPresenter() const {
    return this->presenter;
}
std::string Tutorial::getDuration() const {
    return this->duration;
}
int Tutorial::getLikes() const{
    return this->likes;
}
std::string Tutorial::getLink() const {
    return this->link;
}

void Tutorial::setTitle(std::string* new_title){
    this->title = *new_title;

}
void Tutorial::setPresenter(std::string* new_presenter){
    this->presenter = *new_presenter;
}
void Tutorial::setDuration(std::string* new_duration){
    this->duration = *new_duration;
}
void Tutorial::setLikes(int* new_likes){
    this->likes = *new_likes;
}
void Tutorial::setLink(std::string* new_link){
    this->link = *new_link;
}

std::string Tutorial::to_string1() {

    std::string buffer;
    buffer = "Title: " + this->getTitle() + "    Presenter: " + this->getPresenter() + "    Duration: " + this->getDuration();
    return buffer;
}

std::string Tutorial::to_string2() {

    std::string buffer, likes_s = std::to_string(this->getLikes());
    buffer = "Likes: " + likes_s + "    Link: " + this->getLink();
    return buffer;
}

std::istream &operator>>(std::istream &is, Tutorial &t){
    std::string line;
    getline(is, line);

    std::vector<std::string> tokens = tokenize(line, ',');
    if (tokens.size() != 5)
        return is;
    t.title = tokens[0];
    t.presenter = tokens[1];
    t.duration = tokens[2];
    t.likes = std::stoi(tokens[3]);
    t.link = tokens[4];

    return is;
}

std::ostream &operator<<(std::ostream &os, const Tutorial &t){
    os<<t.title<<","<<t.presenter<<","<<t.duration<<","<<t.likes<<","<<t.link<<std::endl;
    return os;
}


std::vector<std::string> tokenize(std::string str, char delimiter){
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;

    while(getline(ss, token, delimiter)){
        result.push_back(token);
    }
    return result;
}

bool operator== (Tutorial &t1 , Tutorial &t2){
    return (t1.getTitle() == t2.getTitle() && t1.getDuration() == t2.getDuration() && t1.getLikes() == t2.getLikes() && t1.getPresenter() == t2.getPresenter() && t1.getLink() == t2.getLink());
}








