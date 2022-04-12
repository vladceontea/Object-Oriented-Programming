//
// Created by Vlad on 17/04/2021.
//

#ifndef A67_912_CEONTEA_VLADCALIN_VALIDATOR_H
#define A67_912_CEONTEA_VLADCALIN_VALIDATOR_H

#include <string>

class Validator {

public:
     void valid_title(const std::string &title);

     void valid_presenter(const std::string &presenter);

     void valid_minutes(std::string &minutes);

     void valid_seconds(std::string &seconds);

     void valid_likes(const std::string &likes);

     void valid_link(const std::string &link);

     void valid_integer(std::string &integer);

     void valid_option(std::string &option);

};


#endif //A67_912_CEONTEA_VLADCALIN_VALIDATOR_H
