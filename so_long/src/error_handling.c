#include "so_long.h"


void	img_destroyer(t_game *game, char *s, char *c)
{
	ft_printf("%s%s%s\n", c, s, W);
	cleanup_game(game);
	exit(0);
}

void	ft_game_errors(char *s)
{
	ft_printf("Error\n");
	ft_printf("%s\n", s);
	exit(0);
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