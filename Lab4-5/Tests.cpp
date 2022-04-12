//
// Created by Vlad on 27/03/2021.
//

#include "Tests.h"
#include <assert.h>
#include <iostream>

#pragma once

void testsDynamicArray(){

    DynamicArray<Tutorial> da;

    assert(da.returnCapacity() == 2);
    assert(da.returnLength() == 0);

    Tutorial t1{"Recursion In C++","Anastasia Broughton","5:37", 12345, "https://www.youtube.com/watch?v=fVMgnmi2D1w"};
    Tutorial t2{"Type Conversions In C++","Robin Millar","3:42", 4345, "https://www.youtube.com/watch?v=mhCcWFapO30"};
    Tutorial t3{"Object-Oriented Programming In C++","Sana Khan","16:05", 62363, "https://www.youtube.com/watch?v=1mLZ9A5dJZk"};
    da.add(t1);
    assert(da.returnLength() == 1);

    da.add(t2);
    assert(da.returnLength() == 2);

    da.add(t3);
    assert(da.returnLength()== 3);
    assert(da.returnCapacity() == 4);

    da.remove(&t2);
    assert(da.returnLength() == 2);

}

void testsService(){

    Service service;

    assert(service.getRepository()->getElements()->returnCapacity() == 2);
    assert(service.getRepository()->getElements()->returnLength() == 0);

    int message = 0;

    service.add_tutorial_service("Recursion In C++","Anastasia Broughton",5, 37, 12345, "https://www.youtube.com/watch?v=fVMgnmi2D1w" ,message);
    assert(service.getRepository()->getElements()->returnLength() == 1);

    service.add_tutorial_service("Type Conversions In C++","Robin Millar", 3, 42, 4345, "https://www.youtube.com/watch?v=mhCcWFapO30", message);
    assert(service.getRepository()->getElements()->returnLength() == 2);

    service.add_tutorial_service("Object-Oriented Programming In C++","Sana Khan", 16, 5, 62363, "https://www.youtube.com/watch?v=1mLZ9A5dJZk", message);
    assert(service.getRepository()->getElements()->returnLength()== 3);
    assert(service.getRepository()->getElements()->returnCapacity() == 4);

    service.remove_tutorial_service("https://www.youtube.com/watch?v=mhCcWFapO30", message);
    assert(service.getRepository()->getElements()->returnLength() == 2);

    int new_likes = 2233, new_minutes = 10, new_seconds = 12;
    std::string new_title = "C++ Introduction", new_presenter = "John Johnson", new_duration = "10:12";

    service.update_tutorial_service(service.getRepository()->return_repo_element(0)->getLink(), 1, 1, 1, 1, new_title, new_presenter, new_minutes, new_seconds, new_likes, message);
    assert(service.getRepository()->return_repo_element(0)->getLikes() == new_likes);
    assert(service.getRepository()->return_repo_element(0)->getPresenter() == new_presenter);
    assert(service.getRepository()->return_repo_element(0)->getDuration() == new_duration);
    assert(service.getRepository()->return_repo_element(0)->getTitle() == new_title);

    Tutorial show_list[10];

    assert(service.search_tutorials_service(show_list, "h") == 2);

    DynamicArray<Tutorial>* watchlist = new DynamicArray<Tutorial>[2];

    service.add_to_watchlist(watchlist, show_list[0], message);
    service.add_to_watchlist(watchlist, show_list[1], message);
    service.add_to_watchlist(watchlist, show_list[0], message);
    assert(message == 1);
    assert(watchlist->returnLength() == 2);

    service.delete_watchlist_tutorials(watchlist, &show_list[1]);
    assert(watchlist->returnLength() == 1);

    Tutorial t{"Object-Oriented Programming In C++","Sana Khan", "16:05", 62363, "https://www.youtube.com/watch?v=1mLZ9A5dJZk"};

    service.increase_like_service(&t);
    assert(service.getRepository()->return_repo_element(1)->getLikes() == 62364);


}

void testsRepo(){

    Repository repo;

    assert(repo.getElements()->returnCapacity() == 2);
    assert(repo.getElements()->returnLength() == 0);

    int message = 0;
    Tutorial t1{"Recursion In C++","Anastasia Broughton","5:37", 12345, "https://www.youtube.com/watch?v=fVMgnmi2D1w"};
    Tutorial t2{"Type Conversions In C++","Robin Millar","3:42", 4345, "https://www.youtube.com/watch?v=mhCcWFapO30"};
    Tutorial t3{"Object-Oriented Programming In C++","Sana Khan","16:05", 62363, "https://www.youtube.com/watch?v=1mLZ9A5dJZk"};
    repo.add_tutorial_repository(t1, message);
    assert(repo.getElements()->returnLength() == 1);

    std::string buffer1 = repo.return_repo_element(0)->to_string1();
    std::string buffer2 = repo.return_repo_element(0)->to_string2();

    std::string buffer3 = t1.to_string1();
    std::string buffer4= t1.to_string2();

    assert(buffer1 == buffer3);
    assert(buffer2 == buffer4);

    repo.add_tutorial_repository(t2, message);
    assert(repo.getElements()->returnLength() == 2);

    repo.add_tutorial_repository(t3, message);
    assert(repo.getElements()->returnLength()== 3);
    assert(repo.getElements()->returnCapacity() == 4);

    repo.remove_tutorial_repository("https://www.youtube.com/watch?v=mhCcWFapO30", message);
    assert(repo.getElements()->returnLength() == 2);

    assert(repo.return_repo_length() == 2);

    repo.increase_like_repo(&t1);

    assert(repo.return_repo_element(0)->getLikes() == 12346);

    message = 0;
    int new_likes = 2233;
    std::string new_title = "C++ Introduction", new_presenter = "John Johnson", new_duration = "2:33";

    repo.update_tutorial_repository(repo.return_repo_element(0)->getLink(), 1, 1, 1, 1, new_title, new_presenter, new_duration, new_likes, message);
    assert(repo.return_repo_element(0)->getLikes() == new_likes);
    assert(repo.return_repo_element(0)->getPresenter() == new_presenter);
    assert(repo.return_repo_element(0)->getDuration() == new_duration);
    assert(repo.return_repo_element(0)->getTitle() == new_title);

}

void testsTutorial(){

    Tutorial t1{"Recursion In C++","Anastasia Broughton","5:37", 12345, "https://www.youtube.com/watch?v=fVMgnmi2D1w"};
    Tutorial t2{"Type Conversions In C++","Robin Millar","3:42", 4345, "https://www.youtube.com/watch?v=mhCcWFapO30"};
    Tutorial t3{"Object-Oriented Programming In C++","Sana Khan","16:05", 62363, "https://www.youtube.com/watch?v=1mLZ9A5dJZk"};

    assert(t1==t2 == false);
    assert(t1.getLikes() == 12345);
    assert(t1.getLink() == "https://www.youtube.com/watch?v=fVMgnmi2D1w");
    assert(t2.getPresenter() == "Robin Millar");
    assert(t3.getDuration() == "16:05");
    assert(t3.getTitle() == "Object-Oriented Programming In C++");

    int new_likes = 2233;
    std::string new_title = "C++ Introduction", new_presenter = "John Johnson", new_duration = "2:33", new_link = "https://www.youtube.com/watch?v=0glTOqnJTD2";

    t1.setLikes(&new_likes);
    t1.setLink(&new_link);
    t2.setPresenter(&new_presenter);
    t3.setDuration(&new_duration);
    t3.setTitle(&new_title);

    assert(t1.getLikes() == new_likes);
    assert(t1.getLink() == new_link);
    assert(t2.getPresenter() == new_presenter);
    assert(t3.getDuration() == new_duration);
    assert(t3.getTitle() == new_title);

    assert(t1.to_string1() == "Title: Recursion In C++    Presenter: Anastasia Broughton    Duration: 5:37");
    assert(t2.to_string2() == "Likes: 4345    Link: https://www.youtube.com/watch?v=mhCcWFapO30");

}
