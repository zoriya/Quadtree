/*
** EPITECH PROJECT, 2019
** quadtree
** File description:
** calloc
*/

#include <stdlib.h>
#include <string.h>

void *my_calloc(int capacity, int size)
{
    void *alloc = malloc(capacity * size);

    if (!alloc)
        return (NULL);
    memset(alloc, 0, capacity * size);
    return (alloc);
}