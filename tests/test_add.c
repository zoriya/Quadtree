/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** test_add
*/

#include "quadtree.h"
#include "quadtree_internal.h"
#include <criterion/criterion.h>

Test(qt_add, without_split)
{
    quadtree *tree = qt_create((qt_intrect){0, 0, 1000, 1000}, 3);

    qt_add(tree, (qt_object){0, {0, 0, 100, 100}});
    qt_add(tree, (qt_object){1, {0, 0, 100, 100}});
    qt_add(tree, (qt_object){2, {0, 0, 100, 100}});
    cr_assert_eq(tree->capacity, 3);
    cr_assert_eq(((qt_object *)tree->objects)[0].id, 0);
    cr_assert_eq(((qt_object *)tree->objects)[1].id, 1);
    cr_assert_eq(((qt_object *)tree->objects)[2].id, 2);
}

Test(qt_add, with_split)
{
    quadtree *tree = qt_create((qt_intrect){0, 0, 1000, 1000}, 3);
    quadtree *child;

    qt_add(tree, (qt_object){0, {0, 0, 100, 100}});
    qt_add(tree, (qt_object){1, {0, 0, 100, 100}});
    qt_add(tree, (qt_object){2, {0, 0, 100, 100}});
    qt_add(tree, (qt_object){4, {550, 0, 100, 100}});
    cr_assert_eq(tree->capacity, -1);
    child  = &((quadtree *)tree->objects)[0];
    cr_assert_eq(((qt_object *)child->objects)[0].id, 0);
    cr_assert_eq(((qt_object *)child->objects)[1].id, 1);
    cr_assert_eq(((qt_object *)child->objects)[2].id, 2);
    child  = &((quadtree *)tree->objects)[1];
    cr_assert_eq(((qt_object *)child->objects)[0].id, 4);
}