/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:12:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/16 17:52:31 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "MLX42.h"

typedef struct s_images
{	
	mlx_texture_t	*empty;
	mlx_texture_t	*wall;
	mlx_texture_t	*coll;
	mlx_texture_t	*exit;
	mlx_texture_t	*plr;
	mlx_texture_t	*plrr;
	mlx_texture_t	*enemy;
	mlx_image_t		*pl;
}	t_images;

typedef struct s_map
{
	char		**arr;
	uint32_t	map_width;
	uint32_t	map_height;
	int			npos_x;
	int			npos_y;
}	t_map;

typedef struct s_gameboard
{
	t_map		*map;
	t_images	*imgs;
	mlx_t		*mlx;
	int			moves;
	int			pl_x;
	int			pl_y;
} 	t_gameboard;

int		check_input(int argc, char **argv, t_map *map);
int		parse_map(char *file, t_map *map);
void	render_map(t_gameboard *gb, int x, int y);
void	hook(struct mlx_key_data keypress, void *param);
int 	check_map_pos(t_gameboard *gb, int x_pl, int y_pl);
void	change_direction(keys_t key, t_images *imgs);
void	get_collectable(t_gameboard *gb, int x_pl, int y_pl);
void	move_player(t_gameboard *gb, int pl_x, int pl_y);
#endif