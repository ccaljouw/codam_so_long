/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:05:38 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/14 12:24:37 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	init_gameboard(t_gameboard *gb, t_images *imgs)
{	
	int x;
	int y;
	int count;

	gb->imgs = imgs;
	gb->collectables = 0;
	gb->moves = 0;
	x = 0;
	y = 0;
	count = 0;
	while (gb->map[y])
	{
		while (gb->map[y][x])
		{
			render_map(gb, x, y, count);
			x++;
			count++;
		}
		x = 0;
		y++;
	}
}

void	init_images(mlx_t *mlx, t_images *imgs)
{
	// protect for segfault if image does not exist
	mlx_texture_t *empty;
	mlx_texture_t *wall;
	mlx_texture_t *player;
	mlx_texture_t *collectable;
	empty= mlx_load_png("./images/background.png");
	wall = mlx_load_png("./images/wall.png");
	player = mlx_load_png("./images/spiderman.png");
	collectable = mlx_load_png("./images/collectable.png");
	imgs->empty = mlx_texture_to_image(mlx, empty);
	imgs->wall = mlx_texture_to_image(mlx, wall);
	imgs->pl = mlx_texture_to_image(mlx, player);
	imgs->coll = mlx_texture_to_image(mlx, collectable);
	
}

int		check_input(int argc, char **argv, t_gameboard *gb)
{
	int i;

	i = 0;
	if (argc > 2)
		return (0);
	while (argv[1][i] != '.')
		i++;
	if (ft_strncmp(argv[1] + i, ".ber", 5) != 0)
		return (0);	
	return (parse_map(argv[1], gb));
}

int main(int argc, char **argv)
{	
	t_gameboard *gb;
	t_images	*imgs;
	
	// check_input(argc, argv)
	gb = malloc(sizeof(t_gameboard));
	imgs = malloc(sizeof(t_images));
	// check_input(argc, argv, gb);
	// error handling needt to be redone
	if (!check_input(argc, argv, gb) || !gb || !imgs)
	{
		ft_printf("error");
		exit(0);
	}
	gb->mlx = mlx_init(gb->map_width * 64, gb->map_height *64, "so long!", true);
	if (!gb->mlx)
		exit(EXIT_FAILURE);
	init_images(gb->mlx, imgs);
	init_gameboard(gb, imgs);
	mlx_key_hook(gb->mlx,f_move, gb);
	mlx_loop(gb->mlx);
	mlx_terminate(gb->mlx);
	return (0);
}
