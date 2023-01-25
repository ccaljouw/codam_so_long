/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 19:05:54 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/25 09:29:30 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->arr)
	{
		while (map->arr[i])
		{
			free(map->arr[i]);
			i++;
		}
		free(map->arr);
	}
	free(map);
}

void	free_textures(t_textures *text)
{
	free_sprite(text->player);
	free_sprite(text->patrol);
	free_sprite(text->nums);
	if (text->side)
		mlx_delete_texture(text->side);
	if (text->lives_title)
		mlx_delete_texture(text->lives_title);
	if (text->moves_title)
		mlx_delete_texture(text->moves_title);
	if (text->empty)
		mlx_delete_texture(text->empty);
	if (text->coll)
		mlx_delete_texture(text->coll);
	if (text->wall)
		mlx_delete_texture(text->wall);
	if (text->exit_open)
		mlx_delete_texture(text->exit_open);
	if (text->exit_closed)
		mlx_delete_texture(text->exit_closed);
	if (text->win)
		mlx_delete_texture(text->win);
	if (text->lose)
		mlx_delete_texture(text->lose);
	if (text->moves_exc)
		mlx_delete_texture(text->moves_exc);
	free(text);
}

void	free_sprite(mlx_texture_t **sprite)
{
	int	i;

	i = 0;
	if (!sprite)
		return ;
	while (sprite[i])
	{
		mlx_delete_texture(sprite[i]);
		i++;
	}
	free(sprite);
}

void	free_images(t_images *imgs)
{
	if (imgs->sprites)
		free(imgs->sprites);
	free(imgs);
}

void	free_all(t_gameboard *gb)
{
	if (gb)
	{
		if (gb->map)
			free_map(gb->map);
		if (gb->imgs)
			free_images(gb->imgs);
		if (gb->player)
			free(gb->player);
		if (gb->patrol)
			free(gb->patrol);
		if (gb->text)
			free_textures(gb->text);
		free(gb);
	}
}
