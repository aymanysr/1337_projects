#include "so_long.h"

void    map_size(t_game *game)
{
    int i;

    i = 0;
    while (game->map[i])
        ++i ;
    game->map_length = i;
}