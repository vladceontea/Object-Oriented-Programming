//
// Created by Vlad on 17/04/2021.
//

#ifndef A67_912_CEONTEA_VLADCALIN_EXCEPTIONS_H
#define A67_912_CEONTEA_VLADCALIN_EXCEPTIONS_H

#include <string>

class Exceptions {

private:
    std::string message;

public:

    explicit Exceptions(std::string text);

    std::string getMessage();

};


#endif //A67_912_CEONTEA_VLADCALIN_EXCEPTIONS_H
