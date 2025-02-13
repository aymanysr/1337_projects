#include "../includes/so_long.h"

/**
- This function checks if the map is valid by:
- Verifying the path file.
- Parsing the map file to ensure it's rectangular and surrounded by walls.
- Checking for correct item placement.
- Ensuring a unique player position, exit position, and at least one collectible.
 */


int components_checker(t_game *game)
{
    if (!is_ber_file(game->map_path))
        ft_game_errors("[!!!] Invalide path file.");
    if (!parse_map(game))
        ft_game_errors("[!!!] Failed to open the map file.");
    map_size(game);
    if (!check_rectangularity(game))
    {
        map_free(game->map);
        ft_game_errors("[!!!] The map is not rectangular.");
    }
    if (!check_walls(game))
    {
        map_free(game->map);
        ft_game_errors("[!!!] The map is not fully surrounded by walls.");
    }
    if (!check_items(game))
    {
        map_free(game->map);
        ft_game_errors("[!!!] There might be an odd, duplicated or missed character.");
    }
    if (!checkunreached(game))
    {
        map_free(game->map);
        ft_game_errors("[!!!] Invalid path.");
    }
    return (1);
}