//
// Created by Vlad on 07/03/2021.
//

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "UI.h"


void initial_values(Repository* repo){
    Estate e1 = createEstate("house", "328 Tanglewood Road", 324, 475000);
    Estate e2 = createEstate("apartment", "3176 Washburn Street", 56, 90000);
    Estate e3 = createEstate("house", "1615 Lucky Duck Drive", 140, 150000);
    Estate e4 = createEstate("apartment", "4497 Lamberts Branch Road", 100, 187000);
    Estate e5 = createEstate("penthouse", "3906 Pickens Way", 120, 345000);
    Estate e6 = createEstate("penthouse", "4216 Gladwell Street", 72, 235000);
    Estate e7 = createEstate("apartment", "2717 Red Bud Lane", 103, 220000);
    Estate e8 = createEstate("house", "798 Deans Lane", 300, 300000);
    Estate e9 = createEstate("penthouse", "4750 Roosevelt Street", 145, 565000);
    Estate e10 = createEstate("apartment", "2120 Goldleaf Lane", 47, 78000);
    add(repo->estates, e1);
    add(repo->estates, e2);
    add(repo->estates, e3);
    add(repo->estates, e4);
    add(repo->estates, e5);
    add(repo->estates, e6);
    add(repo->estates, e7);
    add(repo->estates, e8);
    add(repo->estates, e9);
    add(repo->estates, e10);
}

int main(){

    testsDynamicArray();
    testsRepository();
    testsService();


    Repository* repo = createRepo();
    Service* service = createService(repo);
    UI* ui = createUI(service);

    initial_values(repo);
    start(ui);

    //destroy(ui->service->repo->estates);
    //free(repo);
    //free(service);
    //destroy_undo(ui->undo);
    //free(ui);

    printf("\nAre there memory leaks?\n");
    printf("%d", _CrtDumpMemoryLeaks());
    return 0;

}



