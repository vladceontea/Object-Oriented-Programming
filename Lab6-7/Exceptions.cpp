//
// Created by Vlad on 17/04/2021.
//

#include "Exceptions.h"

Exceptions::Exceptions(std::string text): message(text) {}

std::string Exceptions::getMessage() {

    return this->message;
}

