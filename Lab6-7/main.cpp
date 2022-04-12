//
// Created by Vlad on 20/03/2021.
//

#include <iostream>
#include "UI.h"

#pragma once


int main()
{

    UI ui;
    ui.getService()->getRepository()->read_file();

    ui.start_ui();

    return 0;
}


