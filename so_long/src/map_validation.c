#include "../includes/so_long.h"

int	check_rectangularity(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	line = game->map[i];
	++i;
	while (i < game->map_length)
	{
		if (!(ft_gnl_strlen(line) == ft_gnl_strlen(game->map[i])))
			return (0);
		i++;
	}
	game->image.width = ft_gnl_strlen(line);
	game->image.height = game->map_length;
	return (1);
}

int	check_walls(t_game *game)
{
	int	i;
	int	j;
	int	len;

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
			if (!(contains("MPEC10", game->map[i][j])))
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

int	check_unreached(t_game *game)
{
	int	i;

	i = 0;
	cp_map(game);
	fill_map(game, game->player.y_pos, game->player.x_pos);
	while (i < game->map_length)
	{
		if (contains(game->copied_map[i], 'E')
			|| contains(game->copied_map[i], 'C'))
		{
			map_free(game->copied_map);
			game->copied_map = NULL;
			return (0);
		}
		i++;
	}
	map_free(game->copied_map);
	game->copied_map = NULL;
	return (1);
}

int	components_checker(t_game *game)
{
	if (!parse_map(game))
		ft_game_errors("[!!!] Failed to open the map file.", game);
	map_size(game);
	if (!check_rectangularity(game))
		ft_game_errors("[!!!] The map is not rectangular.", game);
	if (!check_walls(game))
		ft_game_errors("[!!!] The map is not fully surrounded by walls.", game);
	if (!check_items(game))
		ft_game_errors("[!!!] There might be an odd, dup or missed char.",
			game);
	if (!check_unreached(game))
		ft_game_errors("[!!!] Invalid path.", game);
	return (1);
}
