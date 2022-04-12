//
// Created by Vlad on 29/03/2021.
//

#include "UserService.h"


UserService::UserService(){

    this->repo = new Repository;
}
UserService::~UserService(){

    delete this->repo;
    this->repo = NULL;
}

int UserService::search_tutorials_service(Tutorial show_list[], std::string text){

    int i, j = 0;
    for(i=0;i<this->getRepository()->return_repo_length();i++) {
        if(this->getRepository()->return_repo_element(i)->getPresenter().find(text)!=std::string::npos){
            show_list[j] = *this->getRepository()->return_repo_element(i);
            j++;
        }
    }

    return j;
}

void UserService::add_to_watchlist(DynamicArray<Tutorial>* watchlist, Tutorial t){

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
}

void UserService::delete_watchlist_tutorials(DynamicArray<Tutorial>* watchlist, Tutorial* t){

    watchlist->remove(t);

}

void UserService::increase_like_service(Tutorial* t){

    this->repo->increase_like_repo(t);
}

Repository* UserService::getRepository() {

    return this->repo;
}