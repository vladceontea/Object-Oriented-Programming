//
// Created by Vlad on 20/03/2021.
//

#include <iostream>
//#include "UI.h"
#include <QtWidgets/QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include "QtGUI.h"

#pragma once

std::vector<Tutorial> read_file(std::vector<Tutorial> tutorials){
    std::ifstream f("Tutorials.txt");

    Tutorial t;
    while(f>>t){
        tutorials.push_back(t);
    }
    f.close();

    return tutorials;
}


int main(int argc, char* argv[])
{

    QApplication a(argc, argv);
    std::vector<Tutorial> tutorials;
    tutorials = read_file(tutorials);
    GUI myGUI{tutorials};
    myGUI.show();
    //UI ui;
    //ui.getService()->getRepository()->read_file();

    //ui.start_ui();

    return a.exec();
}


