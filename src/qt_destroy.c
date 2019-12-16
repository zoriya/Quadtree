/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** qt_destroy
*/

#include "quadtree.h"
#include <stdlib.h>

void qt_child_destroy(quadtree *tree)
{
    if (tree->capacity < 0) {
        for (int i = 0; i < 4; i++) {
            qt_child_destroy(&((quadtree *)tree->objects)[i]);
        }
    }
    free(tree->objects);
}

void qt_destroy(quadtree *tree)
{
    qt_child_destroy(tree);
    free(tree);
}