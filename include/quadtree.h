/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** quadtree
*/

#pragma once

#include <stdbool.h>

#define MAXCOL 1024

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

typedef struct qt_collision
{
    int distance_left;
    int distance_right;
    int distance_top;
    int distance_down;
} qt_collision;

struct quadtree
{
    qt_intrect rect;
    int capacity;
    void *objects;
};

quadtree *qt_create(qt_intrect rect, int capacity);
int qt_add(quadtree *tree, qt_object obj);
qt_collision collision_get_info(quadtree *tree, int entity_id);
bool qt_collide(qt_intrect r1, qt_intrect r2);
qt_object *qt_getobj(quadtree *tree, int id);
int qt_update(quadtree *tree, qt_object obj);