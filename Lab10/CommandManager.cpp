//
// Created by Vlad on 29/05/2021.
//

#include <algorithm>
#include <iostream>
#include "CommandManager.h"

void CommandManager::executeCommand(BaseCommand* command) {

    this->redoStack = std::stack<BaseCommand*>();
    command->execute();
    this->undoStack.push(command);
}

void CommandManager::undo(){

    this->undoStack.top()->undo();
    this->redoStack.push(this->undoStack.top());
    this->undoStack.pop();
}

void CommandManager::redo() {

    this->redoStack.top()->redo();
    this->undoStack.push(this->redoStack.top());
    this->redoStack.pop();
}

int CommandManager::undoSize() {

    return this->undoStack.size();
}

int CommandManager::redoSize() {

    return this->redoStack.size();
}

void AddCommand::execute() {
    this->tutorials->push_back(t);
}

void AddCommand::undo() {

    std::string link = t.getLink();

    auto it = std::find_if(this->tutorials->begin(), this->tutorials->end(), [&link](Tutorial& tutorial){
        return tutorial.getLink() == link;
    });
    this->tutorials->erase(it);
}

void AddCommand::redo() {
    this->tutorials->push_back(t);
}

void RemoveCommand::execute(){

    t = this->tutorials->at(index);
    this->tutorials->erase(this->tutorials->begin()+index);
}

void RemoveCommand::undo() {

    this->tutorials->push_back(t);
}

void RemoveCommand::redo() {

    std::string link = t.getLink();

    auto it = std::find_if(this->tutorials->begin(), this->tutorials->end(), [&link](Tutorial& tutorial){
        return tutorial.getLink() == link;
    });
    this->tutorials->erase(it);
}

void UpdateCommand::execute(){
    this->tutorials->push_back(new_t);
    old_t = this->tutorials->at(index);
    this->tutorials->erase(this->tutorials->begin()+index);

}

void UpdateCommand::undo() {

    std::string link = new_t.getLink();

    auto it = std::find_if(this->tutorials->begin(), this->tutorials->end(), [&link](Tutorial& tutorial){
        return tutorial.getLink() == link;
    });
    this->tutorials->erase(it);

    this->tutorials->push_back(old_t);
}

void UpdateCommand::redo() {

    this->tutorials->push_back(new_t);

    std::string link = old_t.getLink();

    auto it = std::find_if(this->tutorials->begin(), this->tutorials->end(), [&link](Tutorial& tutorial){
        return tutorial.getLink() == link;
    });
    this->tutorials->erase(it);
}