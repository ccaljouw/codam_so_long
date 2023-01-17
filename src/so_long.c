/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:05:38 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/17 15:41:10 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (1);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x_pos = 0;
	player->y_pos = 0;
	player->x_npos = 0;
	player->y_npos = 0;
	return (player);
}

void	init_window(t_gameboard *gb)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	mlx_image_to_window(gb->mlx, gb->imgs->background, 0, 0);
	mlx_image_to_window(gb->mlx, gb->imgs->wall, 0, 0);
	while (gb->map->arr[y])
	{
		while (gb->map->arr[y][x])
		{
			render_map(gb, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	render_sidebar(gb);
	mlx_image_to_window(gb->mlx, gb->imgs->side, gb->map->map_width * gb->text->empty->width, 0);
	mlx_image_to_window(gb->mlx, gb->imgs->side_text, gb->map->map_width * gb->text->empty->width, 0);
	mlx_image_to_window(gb->mlx, gb->imgs->coll_count, gb->map->map_width * gb->text->empty->width + ((gb->imgs->side->width - gb->imgs->moves_count->width) / 2), ((gb->nums[0]->height *3) / 2));
	mlx_image_to_window(gb->mlx, gb->imgs->moves_count, gb->map->map_width * gb->text->empty->width + ((gb->imgs->side->width - gb->imgs->coll_count->width) / 2), (gb->imgs->side->height / 2) + ((gb->nums[0]->height *3) / 2));
}

int main(int argc, char **argv)
{	
	t_gameboard *gb;
	t_map		*map;
	
	if (!check_input(argc, argv))
		return (ft_printf("incorrect arguments"));
	map = init_map(argv[1]);
	gb = init_gameboard(map);
	init_window(gb);
	mlx_key_hook(gb->mlx, key_hook, gb);
	mlx_loop(gb->mlx);
	mlx_terminate(gb->mlx);
	return (0);
}
