//
// Created by Vlad on 19/03/2021.
//

#ifndef A23_912_CEONTEA_VLADCALIN_UNDOREDO_H
#define A23_912_CEONTEA_VLADCALIN_UNDOREDO_H

#endif //A23_912_CEONTEA_VLADCALIN_UNDOREDO_H

#pragma once
#include "Repository.h"

typedef struct {

    Repository** matrix_undo;
    int index;
    int capacity;
    int available_undoes;
}Undo;

/// Creates the undo matrix of repositories
/// \return the undo matrix
Undo* createUndo();

/// \param undo the undo matrix
/// \param repo the repo we will update
/// \return 1 if there is any undo, -1 if not
int undo(Undo* undo, Repository* repo);

/// \param redo the undo matrix
/// \param repo the repo we will update
/// \return 1 if there is any redo, -1 if not
int redo(Undo* redo, Repository* repo);

int GetIndex(Undo* undo);

int GetCap(Undo* undo);

int GetLen(Undo* undo);

/// Adds the latest repository to the Undo matrix
/// \param undo the undo matrix
/// \param repo the repo to be added
void MatrixAdd(Undo* undo, Repository* repo);

/// Resizes the undo matrix
/// \param undo the undo matrix
void resize_mat(Undo* undo);

/// Destroys the undo matrix
/// \param undo the undo matrix
void destroy_undo(Undo* undo);
