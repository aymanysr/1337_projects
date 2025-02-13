#include "so_long.h"

int check_rectangularity(t_game *game)
{
    char    *line;
    int     i;

    i = 0;
    line = game->map[i];
    ++i;
    while (i < game->map_length)
    {
        if(!(ft_gnl_strlen(line) == ft_gnl_strlen(game->map[i])))
            return (0);
        i++;
    }
    game->image.width = ft_gnl_strlen(line);
    game->image.height = game->map_length;
    return (1);
}

int check_walls(t_game *game)
{
    int i;
    int j;
    int len;

    i = 0;
    while (game->map[0][i] && game->map[game->map_length - 1][i])
    {
        if (game->map[0][i] != '1' || game->map[game->map_length - 1][i] != '1')
            return (0);
        ++i;
    }
    j = 1;
    while (j < game->map_length - 1)
    {
        len = ft_strlen(game->map[j]);
        if (game->map[j][0] != '1' || game->map[j][len - 1] != '1')
            return (0);
        ++j;
    }
    return (1);
}
int	contains(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		++s;
	}
	return (0);
}

static void	counter(t_game *game, char c, int i, int j)
{
	if (c == 'P')
	{
		game->player.y_pos = i;
		game->player.x_pos = j;
		game->players += 1;
	}
	else if (c == 'E')
	{
		game->exit.y_pos = i;
		game->exit.x_pos = j;
		game->exits += 1;
	}
	else if (c == 'C')
		game->collectibles += 1;
}

int	check_items(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_length)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!(contains("PEC10", game->map[i][j])))
				return (0);
			counter(game, game->map[i][j], i, j);
			++j;
		}
		++i;
	}
	if (game->players == 1 && game->collectibles >= 1 && game->exits == 1)
		return (1);
	return (0);
}