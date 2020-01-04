/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** quadtree_internal
*/

#pragma once

void *my_calloc(int capacity, int size);

quadtree *qt_split(quadtree *tree);
bool collision_can_see(int l1, int l2);

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) < (y) ? (y) : (x))