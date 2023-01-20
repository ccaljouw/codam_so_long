/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 19:05:54 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/20 22:14:12 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	free_map(t_map *map)
{
	free(map->arr);
	free(map);
}

void	delete_content(void *param)
{
	t_pos	*content;

	content = param;
	if (content)
		free(content);
}

void	delete_list_pointer(void)
{
	return ;
}

void	free_textures(t_textures *text)
{
	free(text->player);
	free(text->patrol);
	free(text->nums);	
	free(text);
}

void	free_all(t_gameboard *gb)
{
	if (gb)
	{
		if (gb->mlx)
			mlx_terminate(gb->mlx);
		if (gb->map)
			free_map(gb->map);
		if (gb->imgs)
			free(gb->imgs);
		if (gb->text)
			free_textures(gb->text);
		if (gb->player)
			free(gb->player);
		if (gb->patrol)
			free(gb->patrol);
		if (gb->mlx)
			free(gb->mlx);
		free(gb);
	}
}
