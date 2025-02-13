#include "so_long.h"

void    map_free(char **map)
{
    int i;

    i = 0;
    if (map)
    {
        while (map[i])
        {
            free(map[i]);
            i++;
        }
    }
    free(map);
}