/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** qt_getcollide
*/

#include "quadtree.h"
#include "quadtree_internal.h"

//X1 is on the line or X2 is on the line or both X are on each side of the map 
bool collision_overlapx(qt_intrect r1, qt_intrect r2)
{
    if (r1.x > r2.x && r1.x < r2.x + r2.w)
        return (true);
    if (r1.x + r1.w > r2.x && r1.x + r1.w < r2.x + r2.w)
        return (true);
    if (r1.x < r2.x && r1.x + r1.w > r2.x + r2.w)
        return (true);
    return (false);
}

bool collision_overlapy(qt_intrect r1, qt_intrect r2)
{
    if (r1.y > r2.y && r1.y < r2.y + r2.h)
        return (true);
    if (r1.y + r1.h > r2.y && r1.y + r1.h < r2.y + r2.h)
        return (true);
    if (r1.y < r2.y && r1.y + r1.h > r2.y + r2.h)
        return (true);
    return (false);
}

qt_collision collision_complete(qt_collision col, qt_intrect r1, qt_intrect r2)
{
    int PAD = 2000;

    if (collision_overlapy(r1, r2)) {
        if (r1.x < r2.x && r1.x + r1.w + PAD >= r2.x)
            col.distance_right = MIN(col.distance_right, r2.x - (r1.x + r1.w));
        if (r2.x < r1.x && r2.x + r2.w + PAD >= r1.x)
            col.distance_left = MIN(col.distance_left, r1.x - (r2.x + r2.w));
    }
    if (collision_overlapx(r1, r2)) {
        if (r1.y < r2.y && r1.y + r1.h + PAD >= r2.y)
            col.distance_top = MIN(col.distance_top, r1.y - (r2.y + r2.h));
        if (r2.y < r1.y && r2.y + r2.h + PAD >= r1.y)
            col.distance_down = MIN(col.distance_down, r1.y - (r2.y + r2.h));
    }
    col.distance_down = MAX(0, col.distance_down);
    col.distance_top = MAX(0, col.distance_top);
    col.distance_left = MAX(0, col.distance_left);
    col.distance_right = MAX(0, col.distance_right);
    return (col);
}

qt_collision collision_get_info(quadtree *tree, int id)
{
    qt_collision col = (qt_collision){MAXCOL, MAXCOL, MAXCOL, MAXCOL};
    qt_object *obj;
    qt_object *tmp;

    if (tree->capacity == -1) {
        for (int i = 0; i < 4; i++) {
            col = collision_get_info(((quadtree **)tree->objects)[i], id);
        }
        return ((qt_collision){MAXCOL, MAXCOL, MAXCOL, MAXCOL});
    }
    obj = qt_getobj(tree, id);
    if (!obj)
        return (col);
    for (int i = 0; ((qt_object *)tree->objects)[i].id != -1; i++) {
        tmp = &((qt_object *)tree->objects)[i];
        col = collision_complete(col, obj->rect, tmp->rect);
    }
    return (col);
}