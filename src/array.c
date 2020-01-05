/*
** EPITECH PROJECT, 2020
** Twac
** File description:
** array
*/

#include "quadtree.h"

int arr_len(int *arr)
{
    int i = 0;

    while (arr[i] != -1)
        i++;
    return (i);
}

void arr_add(int *arr, int n)
{
    int new = arr_len(arr);

    if (new + 1 > MAX_ENTITY)
        return;
    arr[new] = n;
    arr[new + 1] = -1;
}