/*
** EPITECH PROJECT, 2020
** Twac
** File description:
** qt_position_overlap
*/

#include "quadtree.h"

//X1 is on the line or X2 is on the line or both X are on each side of the map 
bool collision_overlapx(qt_intrect r1, qt_intrect r2)
{
    if (r1.x > r2.x && r1.x < r2.x + r2.w)
        return (true);
    if (r1.x + r1.w > r2.x && r1.x + r1.w < r2.x + r2.w)
        return (true);
    if (r1.x < r2.x && r1.x + r1.w > r2.x + r2.w)
        return (true);
    if (r1.x == r2.x)
        return (true);
    return (false);
}

bool collision_overlapy(qt_intrect r1, qt_intrect r2)
{
    if (r1.y - r1.h < r2.y && r1.y - r1.h > r2.y - r2.h)
        return (true);
    if (r1.y < r2.y && r1.y - r1.h > r2.y - r2.h)
        return (true);
    if (r1.y < r2.y && r1.y > r2.y - r2.h)
        return (true);
    if (r1.y == r2.y)
        return (true);
    return (false);
}