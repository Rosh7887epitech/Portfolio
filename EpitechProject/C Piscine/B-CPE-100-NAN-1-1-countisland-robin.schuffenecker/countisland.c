/*
** EPITECH PROJECT, 2023
** countisland
** File description:
** count the number of island in a .txt file
*/

#include <stddef.h>

int search_island(char **world, int y, int x, int island)
{
    if (x >= 0 && y >= 0 && world[y] != NULL &&
    world[y][x] != '\0' && world[y][x] == 'X') {
        world[y][x] = island + 48;
        search_island(world, y, x - 1, island);
        search_island(world, y, x + 1, island);
        search_island(world, y + 1, x, island);
        search_island(world, y - 1, x, island);
    }
}

int world_island(char **world, int y, int x, int island)
{
    if (world[y][x] == 'X') {
        search_island(world, y, x, island);
        island++;
    }
}

int count_island(char **world)
{
    int x = 0;
    int y = 0;
    int island = 0;

    while (world[y] != NULL) {
        x = 0;
        while (world[y][x] != '\0') {
            world_island(world, y, x, island);
            x++;
        }
        y++;
    }
}
