/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** qt_getcollide
*/

#include "quadtree.h"
#include "quadtree_internal.h"
#include "array.h"

qt_collision check_collisions(qt_object *obj1, qt_object *obj2, int *colwith)
{
    qt_intrect r1 = obj1->rect;
    qt_intrect r2 = obj2->rect;
    qt_collision col = COLLISION_MAX;

    if (collision_overlapy(r1, r2)) {
        if (r1.x <= r2.x)
            col.distance_right = r2.x - (r1.x + r1.w);
        if (r2.x <= r1.x)
            col.distance_left = r1.x - (r2.x + r2.w);
    }
    if (collision_overlapx(r1, r2)) {
        if (r1.y >= r2.y)
            col.distance_down = r1.y - r2.y - r1.h;
        if (r2.y >= r1.y)
            col.distance_top = r2.y - r1.y - r2.h;
    }
    if (col.distance_right == 0 || col.distance_down == 0 ||
        col.distance_left == 0 || col.distance_right == 0)
        arr_add(colwith, obj2->id);
    return (col);
}

qt_collision sum_col(qt_collision col1, qt_collision col2)
{
    col1.distance_down = MAX(0, MIN(col1.distance_down, col2.distance_down));
    col1.distance_top = MAX(0, MIN(col1.distance_top, col2.distance_top));
    col1.distance_left = MAX(0, MIN(col1.distance_left, col2.distance_left));
    col1.distance_right = MAX(0, MIN(col1.distance_right, col2.distance_right));
    return (col1);
}

qt_collision collrec(quadtree *tree, int id, qt_collision col, int *collidewith)
{
    qt_object *obj;
    qt_object *tmp;
    quadtree *child;

    if (tree->capacity == -1) {
        for (int i = 0; i < 4; i++) {
            child = &((quadtree *)tree->objects)[i];
            col = collrec(child, id, col, collidewith);
        }
        return (col);
    }
    obj = qt_getobj(tree, id);
    if (!obj)
        return (col);
    for (int i = 0; i < tree->capacity && TREEOBJ_AT(i)->id != -1; i++) {
        tmp = TREEOBJ_AT(i);
        if (tmp->id == id || !collision_can_see(obj->layer, tmp->layer))
            continue;
        col = sum_col(col, check_collisions(obj, tmp, collidewith));
    }
    return (col);
}

qt_collision collision_get_info(quadtree *tree, int id)
{
    qt_collision col = COLLISION_MAX;
    static int collidewith[MAX_ENTITY + 1];

    collidewith[0] = -1;
    col = collrec(tree, id, col, collidewith);
    col.collide_with = collidewith;
    return (col);
}