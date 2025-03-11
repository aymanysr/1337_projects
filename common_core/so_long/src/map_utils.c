#include "so_long.h"

void	counter(t_game *game, char c, int i, int j)
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

int check_invalid_line(char *s)
{
	int len;
	int i;
	len = ft_strlen(s);
	if (s[len - 1] == '\n' || s[0] == '\n')
		return (1);
	i = 1;
	while (i < len - 1)
	{
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (1);
		++i;
	}
	return (0);
}

