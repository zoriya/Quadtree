/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** qt_split
*/

#include "quadtree.h"
#include "quadtree_internal.h"
#include <stdlib.h>

qt_object **qt_filter_objects(quadtree *tree, qt_intrect rect)
{
    qt_object **objs = my_calloc(tree->capacity, sizeof(qt_object *));
    int len = 0;

    for (int i = 0; tree->objects[i]; i++) {
        if (qt_collide(((qt_object *)tree->objects[i])->rect, rect))
            objs[len++] = (qt_object *)tree->objects[i];
    }
    return (objs);
}

quadtree **qt_split(quadtree *tree)
{
    quadtree **ret = malloc(sizeof(quadtree *) * 4);

    if (!ret)
        return (NULL);
    for (int i = 0; i < 4; i++) {
        ret[i] = malloc(sizeof(quadtree));
        if (!ret[i])
            return (NULL);
        ret[i]->capacity = tree->capacity;
        ret[i]->rect.h = tree->rect.h / 2;
        ret[i]->rect.w = tree->rect.w / 2;
        ret[i]->rect.x = !(i % 2) ? tree->rect.x : tree->rect.x + tree->rect.w;
        ret[i]->rect.y = !(i > 1) ? tree->rect.y : tree->rect.y + tree->rect.h;
        ret[i]->objects = (void **)qt_filter_objects(tree, ret[i]->rect);
    }
    tree->capacity = -1;
    tree->objects = (void **)ret;
    return (ret);
}