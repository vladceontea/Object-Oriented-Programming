//
// Created by Vlad on 07/03/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "UI.h"

UI* createUI(Service* service){
    UI *ui = malloc(sizeof(UI));
    ui->service = service;
    ui->undo = createUndo();

    return ui;
}


void main_menu(){
    printf("1. Add a new estate.\n");
    printf("2. Remove an estate.\n");
    printf("3. Update an estate.\n");
    printf("4. Search for estates.\n");
    printf("5. Show all estates.\n");
    printf("6. Show the estates of a type with a larger surface area.\n");
    printf("7. Undo.\n");
    printf("8. Redo.\n");
    printf("0. Exit.\n");
}

void add_estate_ui(UI* ui){
    char type[50], address[200] = " ", types[3][50] = {"house", "apartment", "penthouse"};
    int surface, price, i, ok = 1, ok2 = 0;
    while (ok2 == 0){
        printf("Enter the type of estate: \n");
        scanf("%s", type);
        for (i=0; i<3; i++){
            if (strcmp(type, types[i])==0){
                ok2 = 1;
            }
        }
        if (ok2==0){
            printf("Not a valid estate type.\n");
        }
    }
    while (ok==1) {
        ok = 0;
        printf("Enter the address of the estate: \n");
        if (strcmp(address, " ")== 0){
            getchar();
        }
        fgets(address, 50, stdin);
        address[strcspn(address, "\n")] = 0;
        for (i=0;i<ui->service->repo->estates->length;i++){
            if (strcmp(getAddress(&ui->service->repo->estates->elems[i]), address)==0){
                ok = 1;
            }
        }
        if (ok==1) {
            printf("This address already exists.\n");
        }
    }
    printf("Enter the surface of the estate: \n");
    scanf("%d", &surface);
    printf("Enter the price of the estate: \n");
    scanf("%d", &price);

    add_estate_service(type, address, surface, price, ui->service);
    MatrixAdd(ui->undo, ui->service->repo);

}

void remove_estate_ui(UI* ui){
    int i, ok = 0;
    char address[50] = " ";
    while (ok==0) {
        printf("Enter the address of the estate you wish to delete: \n");
        if (strcmp(address, " ")== 0){
            getchar();
        }
        fgets(address, 50, stdin);
        address[strcspn(address, "\n")] = 0;
        for (i=0;i<ui->service->repo->estates->length;i++){
            if (strcmp(getAddress(&ui->service->repo->estates->elems[i]), address)==0){
                ok = 1;
            }
        }
        if (ok==0){
            printf("This address does not exist.\n");
        }
    }

    remove_estate_service(ui->service, address);
    MatrixAdd(ui->undo, ui->service->repo);

}

void update_estate_ui(UI* ui){
    char address[50]=" ", new_address[50]=" ", new_type[50]=" ", types[3][50] = {"house", "apartment", "penthouse"};
    int option1, option2, option3, option4, new_surface = 0, new_price = 0, ok = 0, i, ok2 = 0;
    while (ok==0) {
        printf("Enter the address of the estate you wish to update: \n");
        if (strcmp(address, " ")== 0){
            getchar();
        }
        fgets(address, 50, stdin);
        address[strcspn(address, "\n")] = 0;
        for (i=0;i<ui->service->repo->estates->length;i++){
            if (strcmp(getAddress(&ui->service->repo->estates->elems[i]), address)==0){
                ok = 1;
            }
        }
        if (ok==0){
            printf("This address does not exist.\n");
        }
    }
    printf("Do you want to change the type of the estate?(Answer 0 for no, 1 for yes)\n");
    scanf("%d", &option1);
    if (option1==1){
        while (ok2 == 0){
            printf("Enter the type of estate: \n");
            scanf("%s", new_type);
            for (i=0; i<3; i++){
                if (strcmp(new_type, types[i])==0){
                    ok2 = 1;
                }
            }
            if (ok2==0){
                printf("Not a valid estate type.\n");
            }
        }
    }
    printf("Do you want to change the address of the estate?(Answer 0 for no, 1 for yes)\n");
    scanf("%d", &option2);
    if (option2==1){
        printf("Enter the new address: \n");
        getchar();
        fgets(new_address, 50, stdin);
        new_address[strcspn(new_address, "\n")] = 0;
    }
    printf("Do you want to change the surface of the estate?(Answer 0 for no, 1 for yes)\n");
    scanf("%d", &option3);
    if (option3==1){
        printf("Enter the new surface: \n");
        scanf("%d", &new_surface);
    }
    printf("Do you want to change the price of the estate?(Answer 0 for no, 1 for yes)\n");
    scanf("%d", &option4);
    if (option4==1){
        printf("Enter the new price: \n");
        scanf("%d", &new_price);
    }

    update_estate_service(ui->service, address, option1, option2, option3, option4, new_type, new_address, new_surface, new_price);
    MatrixAdd(ui->undo, ui->service->repo);

}

void search_estates_ui(UI* ui){
    int i, j, option;
    char str[200];
    Estate print_list[50];
    printf("Search for estates: ");
    scanf("%s", str);

    printf("How do you want to sort the estates? 1. Ascending by price. 2. Descending by area.\n");
    scanf("%d", &option);
    printf("\n");
    j = search_estates_service(ui->service, print_list, str, option);

    for (i=0; i<j; i++){
        char str2[200];
        toString(print_list[i], str2);
        printf("%s", str2);
        printf("\n");
    }
}

void show_filtered_estates_ui(UI* ui){
    char type[50];
    int min_surface, i, j;
    Estate print_list[50];
    printf("The type of estate you wish to see: \n");
    scanf("%s", type);
    printf("The minimum surface: \n");
    scanf("%d", &min_surface);

    j = show_filtered_estates_service(ui->service, print_list, type, min_surface);

    for (i=0; i<j; i++){
        char str2[200];
        toString(print_list[i], str2);
        printf("%s", str2);
        printf("\n");
    }
}

void show_estates(UI* ui){
    int i;
    for(i=0;i<ui->service->repo->estates->length;i++){
        char str[200];
        toString(ui->service->repo->estates->elems[i], str);
        printf("%s", str);
        printf("\n");
    }
}

void undo_ui(UI* ui){

    int message = undo(ui->undo, ui->service->repo);
    if (message==-1){
        printf("Nothing to undo.\n");
    }
}

void redo_ui(UI* ui){

    int message = redo(ui->undo, ui->service->repo);
    if (message==-1){
        printf("Nothing to redo.\n");
    }
}

void start(UI *ui){

    int ok = 1, command;
    MatrixAdd(ui->undo, ui->service->repo);
    while (ok==1) {
        main_menu();
        printf("Enter the command:");
        scanf("%d", &command);
        if (command == 0) {
            ok = 0;
        }
        if (command == 1) {
            add_estate_ui(ui);
        }
        if (command == 2) {
            remove_estate_ui(ui);
        }
        if (command == 3) {
            update_estate_ui(ui);
        }
        if (command == 4) {
            search_estates_ui(ui);
        }
        if (command == 5){
            show_estates(ui);
        }
        if (command == 6){
            show_filtered_estates_ui(ui);
        }
        if (command == 7){
            undo_ui(ui);
        }
        if (command == 8){
            redo_ui(ui);
        }
    }
}