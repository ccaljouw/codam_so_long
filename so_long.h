/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:12:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/15 19:21:17 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "MLX42.h"

typedef struct s_map
{
	char		**arr;
	uint32_t	map_width;
	uint32_t	map_height;
	uint32_t	pos_x;
	uint32_t	pos_y;
}	t_map;

typedef struct s_images
{	
	mlx_image_t	*empty;
	mlx_image_t	*wall;
	mlx_image_t	*coll;
	mlx_image_t	*exit;
	mlx_image_t	*pl;
	mlx_image_t	*plr;
	mlx_image_t	*plrr;
}	t_images;

typedef struct s_gameboard
{
	// char		**map;
	t_map		*map;
	t_images	*imgs;
	mlx_t		*mlx;
	// uint32_t	map_width;
	// uint32_t	map_height;
	uint32_t	moves;
} 	t_gameboard;

int 	parse_map(char *file, t_gameboard *gb);
void	render_map(t_gameboard *gb, int x, int y);
void	hook(struct mlx_key_data keypress, void *param);
void	change_direction(keys_t key, t_gameboard *gb);
void	get_collectable(t_gameboard *gb, int x_pl, int y_pl);
void	move_player(t_gameboard *gb, int pl_x, int pl_y);
#endif