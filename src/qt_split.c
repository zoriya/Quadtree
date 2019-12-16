/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** qt_split
*/

#include "quadtree.h"
#include "quadtree_internal.h"
#include <stdlib.h>

bool qt_collide(qt_intrect r1, qt_intrect r2)
{
    if (r1.x + r1.w < r2.x || r2.x + r2.w < r1.x)
        return (false);
    if (r1.y + r1.h < r2.y || r2.y + r2.h < r1.y)
        return (false);
    return (true);
}

qt_object *qt_filter_objects(quadtree *tree, qt_intrect rect)
{
    qt_object *objs = my_calloc(tree->capacity, sizeof(qt_object));
    int len = 0;

    for (int i = 0; i < tree->capacity; i++) {
        if (qt_collide(((qt_object *)tree->objects)[i].rect, rect))
            objs[len++] = ((qt_object *)tree->objects)[i];
    }
    return (objs);
}

quadtree *qt_split(quadtree *tree)
{
    quadtree *ret = malloc(sizeof(quadtree) * 4);

    if (!ret)
        return (NULL);
    for (int i = 0; i < 4; i++) {
        ret[i].capacity = tree->capacity;
        ret[i].rect.h = tree->rect.h / 2;
        ret[i].rect.w = tree->rect.w / 2;
        ret[i].rect.x = tree->rect.x;
        if (i % 2)
            ret[i].rect.x += tree->rect.w / 2;
        ret[i].rect.y = tree->rect.y;
        if (i > 1)
            ret[i].rect.y += tree->rect.h / 2;
        ret[i].objects = (void *)qt_filter_objects(tree, ret[i].rect);
    }
    tree->capacity = -1;
    free(tree->objects);
    tree->objects = (void *)ret;
    return (ret);
}