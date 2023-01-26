/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:05:38 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/26 17:57:05 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		error(FT_NOFILE, NULL);
	while (argv[1][i] != '\0')
		i++;
	if (ft_strncmp(argv[1] + (i - 4), ".ber", 5) != 0)
		error(FT_INVEXT, NULL);
}

t_gameboard	*init_gameboard(void)
{	
	t_gameboard	*gb;

	gb = malloc(sizeof(t_gameboard));
	if (!gb)
		error(FT_MEMFAIL, NULL);
	gb->errors = NULL;
	gb->map = NULL;
	gb->imgs = NULL;
	gb->text = NULL;
	gb->mlx = NULL;
	gb->player = NULL;
	gb->patrol = NULL;
	gb->coll = 0;
	gb->moves = 0;
	gb->width = 0;
	gb->height = 0;
	gb->coll_time = 0;
	return (gb);
}

void	system_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{	
	t_gameboard	*gb;

	atexit(system_leaks);
	check_args(argc, argv);
	gb = init_gameboard();
	init_map(argv[1], gb);
	init_textures(gb);
	init_window(gb);
	init_images(gb);
	init_characters(gb);
	render_window(gb);
	check_map_content(gb);
	mlx_loop_hook(gb->mlx, frame_hook, gb);
	mlx_key_hook(gb->mlx, key_hook, gb);
	mlx_loop(gb->mlx);
	free_all(gb);
	return (0);
}
