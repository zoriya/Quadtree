/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** test_collide
*/

#include <criterion/criterion.h>
#include "quadtree.h"

Test(collide, yes)
{
    qt_intrect r1 = {0, 0, 10, 10};
    qt_intrect r2 = {0, 0, 100, 100};

    cr_assert_eq(qt_collide(r1, r2), true);
}

Test(collide, no)
{
    qt_intrect r1 = {0, 0, -10, -10};
    qt_intrect r2 = {0, 0, 100, 100};

    cr_assert_eq(qt_collide(r1, r2), false);
}