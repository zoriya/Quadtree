/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** quadtree
*/

#include "quadtree.h"
#include "quadtree_internal.h"
#include <stdlib.h>
#include <stdbool.h>

quadtree *qt_create(qt_intrect rect, int capacity)
{
    quadtree *tree = malloc(sizeof(quadtree));

    if (!tree)
        return (NULL);
    tree->rect = rect;
    tree->capacity = capacity;
    tree->objects = my_calloc(capacity, sizeof(*tree->objects));
    if (!tree->objects) {
        free(tree);
        return (NULL);
    }
    return (tree);
}

bool qt_collide(qt_intrect r1, qt_intrect r2)
{
    if (r1.x + r1.w < r2.x || r2.x + r2.w < r1.x)
        return (false);
    if (r1.y + r1.h < r2.y || r2.y + r2.h < r1.y)
        return (false);
    return (true);
}

int qt_add(quadtree *tree, qt_object *obj)
{
    int i = 0;

    if (tree->capacity > 0) {
        while (tree->objects[i++]);
        if (i < tree->capacity)
            tree->objects[i] = obj;
        else
            qt_split(tree);
        return (0);
    }
    for (i = 0; i < 4; i++) {
        if (qt_collide(((qt_object *)tree->objects[i])->rect, obj->rect))
            qt_add((quadtree *)tree->objects[i], obj);
    }
    return (0);
}

qt_object *qt_getobj(quadtree *tree, int id)
{
    qt_object *obj;

    if (tree->capacity == -1) {
        for (int i = 0; i < 4; i++) {
            obj = qt_getobj(tree->objects[i], id);
            if (obj)
                return (obj);
        }
        return (NULL);
    }
    for (int i = 0; tree->objects[i]; i++) {
        if (((qt_object *)tree->objects[i])->id == id)
            return ((qt_object *)tree->objects[i]);
    }
    return (NULL);
}

int qt_update(quadtree *tree, qt_object *obj)
{
    qt_object *o = qt_getobj(tree, obj->id);

    if (!o)
        return (-1);
    *o = *obj;
    return (0);
}