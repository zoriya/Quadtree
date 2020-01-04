/*
** EPITECH PROJECT, 2020
** Twac
** File description:
** qt_layer
*/

#include "quadtree.h"
#include <stdbool.h>

bool collision_can_see(int l1, int l2)
{
    int can_see = CAN_SEE;
    int can_be_seen = CAN_BE_SEEN;

    for (int i = 0; i < 4; i++) {
        if (l1 & can_see && l2 & can_be_seen)
            return (true);
        can_see <<= 2;
        can_be_seen <<= 2;
    }
    return (false);
}