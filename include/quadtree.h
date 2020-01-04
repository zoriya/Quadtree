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
    float x;
    float y;
    int h;
    int w;
} qt_intrect;

typedef struct qt_object
{
    int id;
    qt_intrect rect;
    int layer;
} qt_object;

typedef struct qt_collision
{
    float distance_left;
    float distance_right;
    float distance_top;
    float distance_down;
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
void qt_destroy(quadtree *tree);


#define CAN_BE_SEEN 0b10
#define CAN_SEE 0b01