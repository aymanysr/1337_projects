#include "so_long.h"

void	mlx_initializer(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init(game->image.width * 50, game->image.height * 50, "so_long", false);
	if (!game->mlx.mlx_ptr)
	{
		ft_printf("Error: MLX initialization failed\n");
		exit(EXIT_FAILURE);
	}
}