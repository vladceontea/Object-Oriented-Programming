//
// Created by Vlad on 20/03/2021.
//

#include <string>

#ifndef A45_912_CEONTEA_VLADCALIN_TUTORIAL_H
#define A45_912_CEONTEA_VLADCALIN_TUTORIAL_H

#endif //A45_912_CEONTEA_VLADCALIN_TUTORIAL_H
#pragma once


class Tutorial{

private:

    std::string title;
    std::string presenter;
    std::string duration;
    int likes;
    std::string link;

public:

    /// Default constructor
    Tutorial();

    /// Constructor with parameters
    /// \param title the title of the tutorial
    /// \param presenter the presenter of the tutorial
    /// \param duration the duration of the tutorial
    /// \param likes the number of likes for the tutorial
    /// \param link the link of the tutorial
    Tutorial(std::string title, std::string presenter, std::string duration, int likes, std::string link);

    std::string getTitle();
    std::string getPresenter();
    std::string getDuration();
    int getLikes() const;
    std::string getLink();

    void setTitle(std::string* new_title);
    void setPresenter(std::string* new_presenter);
    void setDuration(std::string* new_duration);
    void setLikes(int* new_likes);
    void setLink(std::string* new_link);
    std::string to_string1();
    std::string to_string2();

};

/// Verifies whether two tutorials are the same
/// \param t1
/// \param t2
/// \return
bool operator== (Tutorial &t1 , Tutorial &t2);