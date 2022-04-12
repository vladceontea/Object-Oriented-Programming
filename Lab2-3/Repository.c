//
// Created by Vlad on 07/03/2021.
//

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Repository.h"

Repository* createRepo(){

    Repository *repo = malloc(sizeof(Repository));
    repo->estates = createDynamicArray(100);
    return repo;
}

void add_estate_repository(Repository* repo, Estate e){

    add(repo->estates, e);
}

void remove_estate_repository(Repository* repo, char address[]){

    remove_element(repo->estates, address);
}

void update_estate_repository(Repository* repo, char address[], int option1, int option2, int option3, int option4, char new_type[], char new_address[], int new_surface, int new_price){

    int i;
    for (i=0;i<repo->estates->length;i++){
        if (strcmp(address, getAddress(&repo->estates->elems[i]))==0){
            if (option1==1){
                setType(&repo->estates->elems[i], &new_type);
            }
            if (option2==1){
                setAddress(&repo->estates->elems[i], &new_address);
            }
            if (option3==1){
                setSurface(&repo->estates->elems[i], &new_surface);
            }
            if (option4==1){
                setPrice(&repo->estates->elems[i], &new_price);
            }
        }
    }
}

void copy_repo(Repository* repo1, Repository* repo2){

    DeepCopyArray(repo1->estates, repo2->estates);
}

void testsRepository(){

    Repository* repo = createRepo();
    if (repo == NULL)
        assert(0);

    //assert(repo->estates->capacity == 2);
    assert(repo->estates->length == 0);

    Estate e1 = createEstate("house", "328 Tanglewood Road", 324, 475000);
    add_estate_repository(repo, e1);
    assert(repo->estates->length == 1);

    Estate e2 = createEstate("apartment", "3176 Washburn Street", 56, 90000);
    add_estate_repository(repo, e2);
    assert(repo->estates->length == 2);

    Estate e3 = createEstate("house", "1615 Lucky Duck Drive", 140, 150000);
    add_estate_repository(repo, e3);
    assert(repo->estates->length == 3);
    //assert(repo->estates->capacity == 4);

    remove_estate_repository(repo, "3176 Washburn Street");
    assert(repo->estates->length == 2);

    update_estate_repository(repo,"328 Tanglewood Road", 0, 0, 1, 0, " ", " ", 350, 0);
    assert(repo->estates->elems[0].surface == 350);

    destroy(repo->estates);
    free(repo);
}