/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:12:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/13 22:15:58 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "MLX42.h"

// # ifndef BUFFER_SIZE
// #  define  BUFFER_SIZE 1
// # endif

typedef struct s_images
{	
	mlx_image_t	*empty;
	mlx_image_t	*wall;
	mlx_image_t	*collectable;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}	t_images;

typedef struct s_gameboard
{
	char		**map;
	t_images	*images;
	mlx_t		*mlx;
	uint32_t	map_width;
	uint32_t	map_height;
	int			exit[2];
	uint32_t	collectables;
	uint32_t	moves;
} 	t_gameboard;

int 	parse_map(char *file, t_gameboard *gb);
void	render_map(t_gameboard *gb, int x, int y);
#endif