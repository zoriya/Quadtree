/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** quadtree_internal
*/

#pragma once

void *my_calloc(int capacity, int size);

quadtree **qt_split(quadtree *tree);

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) < (y) ? (y) : (x))