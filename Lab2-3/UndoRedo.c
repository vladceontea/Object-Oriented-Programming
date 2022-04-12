//
// Created by Vlad on 19/03/2021.
//


#include "UndoRedo.h"
#include <stdlib.h>
#include <stdio.h>

Undo* createUndo()
{
    Undo* undo = (Undo*)malloc(sizeof(Undo));

    if (undo == NULL)
    {
        return NULL;
    }

    undo->available_undoes = 0;
    undo->capacity = 100;
    undo->index = -1;

    undo->matrix_undo = (Repository**)malloc(sizeof(Repository*) * undo->capacity);
    for (int i = 0; i < undo->capacity; i++)
        undo->matrix_undo[i] = createRepo();

    if (undo->matrix_undo == NULL)
        return NULL;

    return undo;
}

int undo(Undo* undo, Repository* repo)
{
    if (GetIndex(undo) <= 0)
        return -1;

    undo->index -= 1;
    DeepCopyArray(repo->estates, undo->matrix_undo[GetIndex(undo)]->estates);
    repo->estates->length = length(undo->matrix_undo[GetIndex(undo)]->estates);

    return 1;
}

int redo(Undo* redo, Repository* repo)
{
    if (GetIndex(redo) == GetLen(redo) - 1)
        return -1;

    redo->index += 1;
    DeepCopyArray(repo->estates, redo->matrix_undo[GetIndex(redo)]->estates);
    repo->estates->length = length(redo->matrix_undo[GetIndex(redo)]->estates);
    return 1;
}

void resize_mat(Undo* undo)
{
    undo->capacity = undo->capacity * 2;
    Repository** new_matrix = (Repository**)malloc(sizeof(Repository*) * undo->capacity);

    int i;
    for (i = 0; i < GetCap(undo); i++)
        new_matrix[i] = createRepo();

    for (i = 0; i < GetLen(undo); i++)
    {
        new_matrix[i] =  undo->matrix_undo[i];
        new_matrix[i]->estates->length = undo->matrix_undo[i]->estates->length;
        new_matrix[i]->estates->capacity = undo->matrix_undo[i]->estates->capacity;
    }

    for (i = 0; i < undo->capacity; i++)
        free(undo->matrix_undo[i]);
    free(undo->matrix_undo);
    undo->matrix_undo = new_matrix;
}

void MatrixAdd(Undo* undo, Repository* r)
{

    if (undo->capacity == undo->available_undoes)
        resize_mat(undo);
    while (undo->index + 1 < undo->available_undoes)
        undo->available_undoes -= 1;
    copy_repo(undo->matrix_undo[GetLen(undo)], r);
    undo->matrix_undo[undo->available_undoes]->estates->length = r->estates->length;
    undo->matrix_undo[undo->available_undoes]->estates->capacity = r->estates->capacity;
    undo->index += 1;
    undo->available_undoes += 1;

}

int GetIndex(Undo* undo)
{
    return undo->index;
}

int GetCap(Undo* undo)
{
    return undo->capacity;
}

int GetLen(Undo* undo)
{
    return undo->available_undoes;
}

void destroy_undo(Undo* undo)
{
    for (int i = 0; i < GetCap(undo); ++i)
    {
        destroy(undo->matrix_undo[i]->estates);
        free(undo->matrix_undo[i]);
        undo->matrix_undo[i] = NULL;
    }

    free(undo->matrix_undo);
    undo->matrix_undo = NULL;
    free(undo);

}


