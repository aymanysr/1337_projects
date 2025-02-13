#include "so_long.h"

void    cp_map(t_game *game)
{
    int     i;
    size_t  j;
    size_t  len;

    game->copied_map = malloc(sizeof(char *) * game->map_length + 1);
    i = 0;
    while (i < game->map_length)
    {
        len = ft_strlen(game->map[i]);
        j = 0;
        game->copied_map[i] = malloc(sizeof(char) * (len + 1));
        while (j < len)
        {
            game->copied_map[i][j] = game->map[i][j];
            j++;
        }
        game->copied_map[i][j] = '\0';
        i++;
    }
    game->copied_map[i] = NULL;
}

void	fill_map(t_game *game, int y, int x)
{
    if (!(game->copied_map[y][x + 1] == '1'))
    {
        game->copied_map[y][x + 1] = '1';
        fill_map(game, y , x + 1);
    }
    if (!(game->copied_map[y][x - 1] == '1'))
    {
        game->copied_map[y][x - 1] = '1';
        fill_map(game, y , x - 1);
    }
    if (!(game->copied_map[y + 1][x] == '1'))
    {
        game->copied_map[y + 1][x] = '1';
        fill_map(game, y + 1 , x);
    }
    if (!(game->copied_map[y - 1][x] == '1'))
    {
        game->copied_map[y - 1][x] = '1';
        fill_map(game, y - 1, x);
    }
}

int checkunreached(t_game *game)
{
    int     i;

    i = 0;
    cp_map(game);
    fill_map(game, game->player.y_pos, game->player.x_pos);
    while (i < game->map_length)
    {
        if (contains(game->copied_map[i], 'E') || contains(game->copied_map[i], 'C'))
        {
            map_free(game->copied_map);
            return (0);
        }
        i++;
    }
    map_free(game->copied_map);
    return (1);
}