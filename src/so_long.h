/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:12:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/17 00:15:43 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "MLX42.h"

typedef struct s_textures
{
	mlx_texture_t	*empty;
	mlx_texture_t	*wall;
	mlx_texture_t	*enemy;
	mlx_texture_t	*pl;
	mlx_texture_t	*plr;
	mlx_texture_t	*pll;
}	t_textures;

typedef struct s_images
{	
	mlx_image_t		*background;
	mlx_image_t		*wall;
	mlx_image_t		*coll;
	mlx_image_t		*exit;
	mlx_image_t		*pl;
	mlx_image_t		*enemy;
	
}	t_images;

typedef struct s_map
{
	char		**arr;
	int			map_width;
	int			map_height;
}	t_map;

typedef struct s_player
{
	mlx_image_t	**player_img;
	int			x_pos;
	int			y_pos;
}	t_player;

typedef struct s_gameboard
{
	t_map		*map;
	t_images	*imgs;
	t_textures	*text;
	t_player	*player;
	mlx_t		*mlx;
	int			moves;
} 	t_gameboard;

// int		check_input(int argc, char **argv);
void	init_window(t_gameboard *gb);
char	*read_file(char *line, char *file);
int		check_map(char **arr);
void	render_map(t_gameboard *gb, int x, int y);
void	hook(struct mlx_key_data keypress, void *param);
int 	check_map_pos(t_gameboard *gb, int map_x, int map_y);
void	change_direction(keys_t key, t_images *imgs, t_textures *text);
void	get_collectable(t_gameboard *gb, int map_x, int map_y);
void	move_player(t_gameboard *gb, int x_npos, int y_npos);
#endif
