/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:12:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/16 14:21:16 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "MLX42.h"

typedef struct s_images
{	
	mlx_texture_t *empty_text;
	mlx_texture_t *wall_text;
	mlx_image_t	*background;
	mlx_image_t	*empty;
	mlx_image_t	*wall;
	mlx_image_t	*coll;
	mlx_image_t	*exit;
	mlx_image_t	*pl;
	mlx_image_t	*plr;
	mlx_image_t	*plrr;
	mlx_image_t	*enemy;
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
