/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:05:38 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/13 16:59:39 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	init_gameboard(t_gameboard *gb)
{		
	gb->map_height = 0;
	gb->map_width = 0;
}

// void	init_images(t_images *imgs)
// {
// }

int		check_input(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 2)
		return (0);
	while (argv[1][i] != '.')
		i++;
	if (ft_strncmp(argv[1] + i, ".ber", 5) != 0)
		return (0);	
	return (parse_map(argv[1]));
}

int main(int argc, char **argv)
{	
	t_gameboard *gb;
	t_images	*imgs;

	
	// check_input(argc, argv)
	gb = malloc(sizeof(t_gameboard));
	imgs = malloc(sizeof(t_images));
	check_input(argc, argv);
	if (!check_input(argc, argv) || !gb || !imgs)
	{
		ft_printf("error");
		exit(0);
	}
	init_gameboard(gb);
	// init_images(imgs);
	return (0);
}