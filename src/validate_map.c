
#include "libft.h"
#include "so_long.h"

void validate_map(t_game *game)
{
    if (game->total_collectibles == 0)
    {
        ft_putstr_fd("Error\nThe map contains NO collectibles", 1);
    }

}

char    **copy_the_map(t_game *game)
{
    int i = 0;
    int z;
    char **map_copy;
    
    map_copy = malloc(game->map_height * sizeof(char *));
    if(!map_copy)
    {
        ft_putchar_fd("Failed to allocate memory for map_copy", 1);
        exit(EXIT_FAILURE);
    }
    while (i < game->map_height)
    {
        map_copy[i] = malloc((game->map_width+1) * sizeof(char));
        if(!map_copy)
        {
            ft_putchar_fd("Failed to allocate memory for map_copy row", 1);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    i = 0;
    while(i < game->map_height)
    {
        z = 0;
        while(z< game->map_width)
        {
            map_copy[i] = ft_strdup(game->map[i]);
            z++;
        }        
        i++;
    }

    return(map_copy);
}

void flood_fill(t_game *game, int y, int x)
{
    char **copy_map;
    copy_map = copy_the_map(game);
    int collectibles_c;
    int reached_exit;

    collectibles_c = 0;
    reached_exit = 0;
    if(copy_map[y][x] == '1' || copy_map[y][x] == 'V' 
            || y >= game->map_height || x >= game->map_width)
    {
        return;
    }

    if(copy_map[y][x] == '0' || copy_map[y][x] == 'C' || copy_map[y][x] == 'E')
    {
        if(copy_map[y][x] == 'C')
        {
            collectibles_c++;
        }
        if(copy_map[y][x] == 'E')
        {
            reached_exit++;
        }
        copy_map[y][x] = 'V';
    }

    flood_fill(game, y + 1, x);
    flood_fill(game, y, x + 1);
    flood_fill(game, y - 1, x);
    flood_fill(game, y, x - 1);
    
    if(collectibles_c == game->total_collectibles && reached_exit == 1)
        return (1);
    return(0);
}
