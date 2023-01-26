/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 14:29:51 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/26 11:25:42 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_file(char *filepath, int i)
{
	char			*file;
	char			*filename;

	file = ft_itoa(i);
	filename = ft_strjoin(filepath, file);
	filename = ft_strjoin_free_s1(filename, ".png");
	free(file);
	return (filename);
}

void	load_error(mlx_texture_t **sprite, int i)
{
	while (i > 1)
	{
		mlx_delete_texture(sprite[i - 1]);
		i--;
	}
}

mlx_texture_t	**init_num_sprite(t_gameboard *gb, int count)
{
	char			*filename;
	mlx_texture_t	**sprite;
	int				i;

	i = 0;
	sprite = malloc(sizeof(mlx_texture_t *) * count + 1);
	if (!sprite)
		error(FT_MEMFAIL, gb);
	while (i < count)
	{
		filename = get_file("./images/numbers/lego", i);
		sprite[i] = mlx_load_png(filename);
		if (!sprite[i])
		{
			load_error(sprite, i);
			error(FT_INVPNG, gb);
			free(sprite);
		}
		free(filename);
		i++;
	}
	sprite[i] = NULL;
	return (sprite);
}

mlx_texture_t	**init_patrol_sprite(t_gameboard *gb, int count)
{
	char			*filename;
	mlx_texture_t	**sprite;
	int				i;

	i = 0;
	sprite = malloc(sizeof(mlx_texture_t *) * count + 1);
	if (!sprite)
		error(FT_MEMFAIL, gb);
	while (i < count)
	{
		filename = get_file("./images/patrol1/", i);
		sprite[i] = mlx_load_png(filename);
		if (!sprite[i])
		{
			load_error(sprite, i);
			error(FT_INVPNG, gb);
			free(sprite);
		}
		free(filename);
		i++;
	}
	sprite[i] = NULL;
	return (sprite);
}

mlx_texture_t	**init_player_sprite(t_gameboard *gb, int count)
{
	char			*filename;
	mlx_texture_t	**sprite;
	int				i;

	i = 0;
	sprite = malloc(sizeof(mlx_texture_t *) * count + 1);
	if (!sprite)
		error(FT_MEMFAIL, gb);
	while (i < count)
	{
		filename = get_file("./images/player/", i);
		sprite[i] = mlx_load_png(filename);
		if (!sprite[i])
		{
			load_error(sprite, i);
			error(FT_INVPNG, gb);
			free(sprite);
		}
		free(filename);
		i++;
	}
	sprite[i] = NULL;
	return (sprite);
}
