#include "../includes/so_long.h"

void update_game(void *param)
{
    t_game *game = (t_game *)param;
    update_animation(game);   /* Updates the animation frame */
    game_renderer(game);      /* Renders the complete frame (map, player, enemies, move count) */
}