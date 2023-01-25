/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/25 13:37:06 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/25 14:32:18 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_files(t_gameboard *gb, char *filepath, int count)
{
	int				i;
	char			*file;
	char			*filename;
	mlx_texture_t	*texture;
	t_list			*lst; //remove

	i = 0;
	lst = NULL;
	while (i < count)
	{
		file = ft_itoa(i);
		filename = ft_strjoin(filepath, file);
		filename = ft_strjoin_free_s1(filename, ".png");
		texture = mlx_load_png(filename);
		ft_lstadd_back(&gb->text->num, ft_lstnew(texture));
		free(file);
		free(filename);
		i++;
	}
}

void	init_numl_sprite(t_gameboard *gb)
{
	get_files(gb, "./images/numbers/lego", 10);
}