/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:12:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/15 16:56:02 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "MLX42.h"

typedef struct s_images
{	
	mlx_texture_t	*player; // kan er uit
	mlx_texture_t	*playerr; // kan er uit
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
	char		**map;
	t_images	*imgs;
	mlx_t		*mlx;
	uint32_t	map_width;
	uint32_t	map_height;
	uint32_t	moves;
} 	t_gameboard;

int 	parse_map(char *file, t_gameboard *gb);
void	render_map(t_gameboard *gb, int x, int y);
void	f_move(struct mlx_key_data keypress, void *param);
#endif