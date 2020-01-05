/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** quadtree_internal
*/

#pragma once

#include "quadtree.h"
#include <stddef.h>

void *my_calloc(int capacity, int size);

quadtree *qt_split(quadtree *tree);

bool collision_overlapx(qt_intrect r1, qt_intrect r2);
bool collision_overlapy(qt_intrect r1, qt_intrect r2);

bool collision_can_see(int l1, int l2);

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) < (y) ? (y) : (x))

#define CAN_BE_SEEN 0b10
#define CAN_SEE 0b01

#define TREEOBJ_AT(x) (&((qt_object *)tree->objects)[i])

#define COLLISION_MAX ((qt_collision){MAXCOL, MAXCOL, MAXCOL, MAXCOL, NULL})