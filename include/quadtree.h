/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** quadtree
*/

#pragma once

#include <stdbool.h>

typedef struct quadtree quadtree;

typedef struct qt_intrect
{
    int x;
    int y;
    int h;
    int w;
} qt_intrect;

typedef struct qt_object
{
    int id;
    qt_intrect rect;
} qt_object;

struct quadtree
{
    qt_intrect rect;
    int capacity;
    void **objects;
};

int qt_add(quadtree *tree, qt_object *obj);
bool qt_collide(qt_intrect r1, qt_intrect r2);
qt_object *qt_getobj(quadtree *tree, int id);
int qt_update(quadtree *tree, qt_object *obj);