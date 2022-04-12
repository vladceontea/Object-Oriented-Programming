//
// Created by Vlad on 29/05/2021.
//

#ifndef A10_912_CEONTEA_VLADCALIN_1_COMMANDMANAGER_H
#define A10_912_CEONTEA_VLADCALIN_1_COMMANDMANAGER_H


#include <memory>
#include <stack>
#include <utility>
#include <vector>
#include "Tutorial.h"

class BaseCommand {

public:

    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;

};

class AddCommand: public BaseCommand{

private:

    std::vector<Tutorial> *tutorials;
    Tutorial t;

public:
    AddCommand(std::vector<Tutorial> *_tutorials, Tutorial _t): tutorials(_tutorials), t(_t){}

    void execute();
    void undo();
    void redo();

};

class RemoveCommand: public BaseCommand{

    std::vector<Tutorial> *tutorials;
    Tutorial t;
    int index;

public:

    RemoveCommand(std::vector<Tutorial> *_tutorials, int _index): tutorials(_tutorials), index(_index){}

    void execute();
    void undo();
    void redo();

};

class UpdateCommand: public BaseCommand{

    std::vector<Tutorial> *tutorials;
    Tutorial new_t;
    Tutorial old_t;
    int index;

public:

    UpdateCommand(std::vector<Tutorial> *_tutorials, int _index, Tutorial _t): tutorials(_tutorials), index(_index), new_t(_t){}

    void execute();
    void undo();
    void redo();
};

class CommandManager{

private:

    std::stack<BaseCommand*> undoStack;
    std::stack<BaseCommand*> redoStack;

public:

     CommandManager(){};

     void executeCommand(BaseCommand* command);

     void undo();

     void redo();

     int undoSize();

     int redoSize();
};


#endif //A10_912_CEONTEA_VLADCALIN_1_COMMANDMANAGER_H
