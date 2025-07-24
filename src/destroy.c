#include "cube.h"

int	on_destroy(t_game *game)
{
    //destroy images
    //mlx_destroy_image(game->mlx_ptr, game->img_ptr[0]); ...

    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	
    //frees
    free(game->mlx_ptr);
	exit(0);
	return (0);
}