/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:08:47 by jhelbig           #+#    #+#             */
/*   Updated: 2025/07/24 15:02:44 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>

# define ESC 65307 

typedef struct s_map
{
    int     lines;      //giving the complete size
    int     col;
    char    **map;     //actual map
    
}   t_map;

typedef struct s_RGB
{
    int  R;
    int  G;
    int  B;
}   t_RGB;

typedef struct s_game
{
    t_map   *map;
    int     player_x;   //start but also later current pos
    int     player_y;
    int     player_orient_start; // just for the start N E S W
                                //later orientation will be incremental aka complicated    
    t_RGB   floor_color;
    t_RGB   ceiling_color;
    void	*mlx_ptr;
	void	*win_ptr;
    void    *north_path;
    void    *south_path;
    void    *west_path;
    void    *east_path;
	void	*img_ptr[4];        //ein image pro Wandausrichtung?    
}   t_game;


//destroy.c
int	on_destroy(t_game *game);

//error.c
void    print_error(char *msg);

//free.c
void	free_split(char **split);

//keypress.c
int	on_keypress(int key, t_game *game);

//find_colors.c
bool    find_colors(t_game *game, char *line, char c);

//parser.c
bool    parse_map(t_game *game, char *map_name);

#endif