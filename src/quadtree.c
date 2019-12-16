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
    tree->objects = my_calloc(capacity, sizeof(qt_object));
    if (!tree->objects) {
        free(tree);
        return (NULL);
    }
    return (tree);
}

int qt_add(quadtree *tree, qt_object obj)
{
    int i = 0;

    if (tree->capacity > 0) {
        while (i < tree->capacity && ((qt_object *)tree->objects)[i].id != -1)
            i++;
        if (i < tree->capacity)
            ((qt_object *)tree->objects)[i] = obj;
        else {
            qt_split(tree);
            qt_add(tree, obj);
        }
        return (0);
    }
    for (i = 0; i < 4; i++) {
        if (qt_collide(((quadtree *)tree->objects)[i].rect, obj.rect))
            qt_add(&((quadtree *)tree->objects)[i], obj);
    }
    return (0);
}

qt_object *qt_getobj(quadtree *tree, int id)
{
    qt_object *obj;
    int cap = tree->capacity;

    if (tree->capacity == -1) {
        for (int i = 0; i < 4; i++) {
            obj = qt_getobj(((quadtree **)tree->objects)[i], id);
            if (obj)
                return (obj);
        }
        return (NULL);
    }
    for (int i = 0; i < cap && ((qt_object *)tree->objects)[i].id != -1; i++) {
        if (((qt_object *)tree->objects)[i].id == id)
            return (&((qt_object *)tree->objects)[i]);
    }
    return (NULL);
}

int qt_remove(quadtree *tree, int id)
{
    int last = tree->capacity - 1;
    qt_object *objects;

    if (tree->capacity == -1) {
        for (int i = 0; i < 4; i++) {
            qt_remove(&((quadtree *)tree->objects)[i], id);
        }
        return (0);
    }
    objects = (qt_object *)tree->objects;
    while (last > 0 && ((qt_object *)tree->objects)[last].id == -1)
        last--;
    for (int i = 0; i < tree->capacity && objects[i].id != -1; i++) {
        if (objects[i].id == id) {
            objects[i] = objects[last];
            objects[last] = (qt_object){-1, {-1, -1, -1, -1}};
        }
    }
    return (0);
}

int qt_update(quadtree *tree, qt_object obj)
{
    qt_remove(tree, obj.id);
    return (qt_add(tree, obj));
}