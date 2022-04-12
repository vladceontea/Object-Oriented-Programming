//
// Created by Vlad on 13/03/2021.
//

#include "Service.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Service * createService(Repository* repo){
    Service* service = malloc(sizeof(Service));
    service->repo = repo;

    return service;
}

void add_estate_service(char type[], char address[], int surface, int price, Service* service){
    Estate e;
    e = createEstate(type, address, surface, price);

    add_estate_repository(service->repo, e);

}

void remove_estate_service(Service* service, char address[]){

    remove_estate_repository(service->repo, address);

}

void update_estate_service(Service* service, char address[], int option1, int option2, int option3, int option4, char new_type[], char new_address[], int new_surface, int new_price){

    update_estate_repository(service->repo, address, option1, option2, option3, option4, new_type, new_address, new_surface, new_price);
}

int search_estates_service(Service* service, Estate print_list[], char str[], int option){
    int i, k, j = 0;
    Estate swap;
    for(i=0;i<service->repo->estates->length;i++) {
        if(strstr(getAddress(&service->repo->estates->elems[i]), str)!=NULL){
            print_list[j] = service->repo->estates->elems[i];
            j++;
        }
    }
    if (option==1){
        for (i = 0 ; i < j-1; i++)
        {
            for (k = 0 ; k < j - i - 1; k++)
            {
                if ((getPrice(&print_list[k])) > (getPrice(&print_list[k+1])))
                {
                    swap       = print_list[k];
                    print_list[k]   = print_list[k+1];
                    print_list[k+1] = swap;
                }
            }
        }
    }
    if (option==2){
        for (i = 0 ; i < j-1; i++)
        {
            for (k = 0 ; k < j - i - 1; k++)
            {
                if ((getSurface(&print_list[k])) < (getSurface(&print_list[k+1])))
                {
                    swap       = print_list[k];
                    print_list[k]   = print_list[k+1];
                    print_list[k+1] = swap;
                }
            }
        }
    }
    return j;
}

int show_filtered_estates_service(Service* service, Estate print_list[], char type[], int min_surface){
    int i, j = 0;
    for(i=0;i<service->repo->estates->length;i++){
        if((strcmp(getType(&service->repo->estates->elems[i]), type) == 0) && (getSurface(&service->repo->estates->elems[i])>min_surface)){
            print_list[j] = service->repo->estates->elems[i];
            j++;
        }
    }
    return j;
}

void testsService(){

    Repository* repo = createRepo();
    Service* service = createService(repo);
    if (service == NULL)
        assert(0);

    assert(service->repo->estates->capacity == 100);
    assert(service->repo->estates->length == 0);

    add_estate_service("house", "328 Tanglewood Road", 324, 475000, service);
    assert(service->repo->estates->length == 1);

    add_estate_service("apartment", "3176 Washburn Street", 56, 90000, service);
    assert(service->repo->estates->length == 2);

    add_estate_service("house", "1615 Lucky Goose Drive", 140, 150000, service);
    assert(service->repo->estates->length == 3);

    update_estate_service(service,"328 Tanglewood Road", 0, 0, 1, 0, " ", " ", 350, 0);
    assert(service->repo->estates->elems[0].surface == 350);

    remove_estate_service(service, "3176 Washburn Street");
    assert(service->repo->estates->length == 2);

    Estate print_list[50];
    search_estates_service(service, print_list, "oo", 1);
    assert(strcmp(print_list[0].address,"1615 Lucky Goose Drive")==0);

    destroy(service->repo->estates);
    free(repo);
    free(service);
}

