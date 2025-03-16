#include "so_long.h"

void load_enemy_textures(t_game *game)
{
    game->textures.xpm_enemy_left = mlx_load_xpm42("./textures/enemy_left.xpm42");
    if (game->textures.xpm_enemy_left)
        game->textures.enemy_left = &game->textures.xpm_enemy_left->texture;
    
    game->textures.img_enemy_left = mlx_texture_to_image(
        game->mlx.mlx_ptr, game->textures.enemy_left);
    if (!game->textures.img_enemy_left)
        ft_game_errors("failed to create enemy left image", game);

    game->textures.xpm_enemy_right = mlx_load_xpm42("./textures/enemy_right.xpm42");
    if (game->textures.xpm_enemy_right)
        game->textures.enemy_right = &game->textures.xpm_enemy_right->texture;
    
    game->textures.img_enemy_right = mlx_texture_to_image(
        game->mlx.mlx_ptr, game->textures.enemy_right);
    if (!game->textures.img_enemy_right)
        ft_game_errors("failed to create enemy right image", game);
}