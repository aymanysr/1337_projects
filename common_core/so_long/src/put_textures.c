#include "../includes/so_long.h"

void load_elements(t_game *game)
{
    int x;
    int y;
    

    x = game->image.width * 50;
    y = game->image.height * 50;
    game->textures.collectibles = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
        "./textures/collectible1.xpm", &x, &y);
    game->textures.walls = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
        "./textures/walls.xpm", &x, &y);
    game->textures.background = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
        "./textures/walls.xpm", &x, &y);
    game->textures.exit = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
        "./textures/exit.xpm", &x, &y);
}

void load_player(t_game *game)
{
    int x;
    int y;

    x = game->image.width * 50;
    y = game->image.height * 50;
    game->textures.player_right = mlx_xpm_file_to_image(game->image.img_ptr,
        "./textures/player_right.xpm", &x, &y);
    game->textures.player_left = mlx_xpm_file_to_image(game->image.img_ptr,
        "./textures/player_left.xpm", &x, &y);
    game->textures.player_front = mlx_xpm_file_to_image(game->image.img_ptr,
        "./textures/player_down.xpm", &x, &y);
    game->textures.player_back = mlx_xpm_file_to_image(game->image.img_ptr,
        "./textures/player_up.xpm", &x, &y);
}

void put_image_on_window(t_game *game, void *img, int x, int y)
{
    mlx_image_to_window(game->mlx.mlx_ptr, game->image.img_ptr, x * 50, y * 50);
}

void player_dir_check(t_game *game, int x, int y)
{
    if (game->player.direction == 'r')
        put_image_on_window(game, game->image.img_ptr, x, y);
    if (game->player.direction == 'l')
        put_image_on_window(game, game->image.img_ptr, x, y);
    if (game->player.direction == 'u')
        put_image_on_window(game, game->image.img_ptr, x, y);
    if (game->player.direction == 'd')
        put_image_on_window(game, game->image.img_ptr, x, y);
}

void renderer(t_game *game, int x, int y)
{
    while (game->map[y][x])
    {
        if (game->map[y][x] == '1' || game->map[y][x] == 'C' ||
            game->map[y][x] == 'P' || game->map[y][x] == 'E')
            put_image_on_window(game, game->textures.background, x, y);
        if (game->map[y][x] == '1')
			put_image_on_window(game, game->textures.walls, x, y);
		if (game->map[y][x] == '0')
			put_image_on_window(game, game->textures.background, x, y);
		if (game->map[y][x] == 'P')
            player_dir_check(game, x, y); // to be changed to DOWN DIRECTION
		if (game->map[y][x] == 'E')
			put_image_on_window(game, game->textures.exit, x, y);
		if (game->map[y][x] == 'C')
			put_image_on_window(game, game->textures.collectibles, x, y);
        x++;
    }
}