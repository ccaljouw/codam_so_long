/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:12:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/13 16:43:25 by cariencaljo   ########   odam.nl         */
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
	mlx_image_t	empty;
	mlx_image_t	wall;
	mlx_image_t	collectible;
	mlx_image_t	exit;
	mlx_image_t	player;
}	t_images;

typedef struct s_gameboard
{
	mlx_t		mlx;
	int			map_width;
	int			map_height;
	t_images	images;
} 	t_gameboard;

int parse_map(char *file);

#endif