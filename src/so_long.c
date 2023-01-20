/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:05:38 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/20 15:16:24 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		error(FT_NOFILE, NULL);
	while (argv[1][i] != '.')
		i++;
	if (ft_strncmp(argv[1] + i, ".ber", 5) != 0)
		error(FT_INVEXT, NULL);
	return (MLX_SUCCESS);
}

void	init_images(t_gameboard *gb)
{
	init_num_sprite(gb);
	init_patrol_sprite(gb);
	init_coll_sprite(gb);
	init_player_sprite(gb);
	load_images(gb->mlx, gb->text, gb);
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
	// handle errors
}

int	main(int argc, char **argv)
{	
	t_gameboard	*gb;

	check_input(argc, argv);
	gb = init_gameboard();
	init_map(argv[1], gb);
	init_window(gb);
	init_images(gb);
	render_window(gb);
	mlx_loop_hook(gb->mlx, hook, gb);
	mlx_key_hook(gb->mlx, key_hook, gb);
	mlx_loop(gb->mlx);
	mlx_terminate(gb->mlx);
	return (0);
}
