/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:05:38 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/16 17:08:08 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	init_gameboard(t_gameboard *gb, t_images *imgs)
{	
	int x;
	int y;

	gb->imgs = imgs;
	gb->moves = 0;
	x = 0;
	y = 0;
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
	mlx_image_to_window(gb->mlx, gb->imgs->wall, 0, 64);
}

void	init_background(mlx_t *mlx, t_images *imgs, t_map *map)
{
	imgs->empty_text = mlx_load_png("./images/background.png");
	imgs->empty = mlx_texture_to_image(mlx,imgs->empty_text);
	imgs->background = mlx_new_image(mlx, map->map_width * imgs->empty->width, (map->map_height + 1) * imgs->empty->height); 
	mlx_image_to_window(mlx, imgs->background, 0, 64);
}

void	init_images(mlx_t *mlx, t_images *imgs, t_map *map)
{
	init_background(mlx, imgs, map);
	imgs->wall_text =  mlx_load_png("./images/wall.png");
	imgs->wall = mlx_new_image(mlx, map->map_width * imgs->empty->width, map-> map_height * imgs->empty->height); 
	imgs->coll = mlx_texture_to_image(mlx, mlx_load_png("./images/coll64.png"));
	imgs->exit = mlx_texture_to_image(mlx, mlx_load_png("./images/exit64.png"));
	imgs->plr = mlx_texture_to_image(mlx, mlx_load_png("./images/flashman64r.png"));
	imgs->pl = mlx_texture_to_image(mlx, mlx_load_png("./images/flashman64.png"));
	if (!imgs->empty || !imgs->wall || !imgs->pl || !imgs->plr || !imgs->coll || !imgs->exit || !imgs->background)
		ft_printf("error loading images");
}

int		check_input(int argc, char **argv, t_map *map)
{
	int i;

	i = 0;
	if (argc > 2)
		return (0);
	while (argv[1][i] != '.')
		i++;
	if (ft_strncmp(argv[1] + i, ".ber", 5) != 0)
		return (0);	
	return (parse_map(argv[1], map));
}

int main(int argc, char **argv)
{	
	t_gameboard *gb;
	t_images	*imgs;
	t_map		*map;
	
	map = malloc(sizeof(t_map));
	imgs = malloc(sizeof(t_images));
	gb = malloc(sizeof(t_gameboard));
	gb->map = map;
	if (!check_input(argc, argv, map) || !gb || !imgs)
		ft_printf("error in main arguments");
	gb->mlx = mlx_init(gb->map->map_width * 64, (gb->map->map_height+1) * 64, "So long!\t\t\tmoves: 0", true);
	if (!gb->mlx)
		exit(EXIT_FAILURE);
	init_images(gb->mlx, imgs, gb->map);
	init_gameboard(gb, imgs);
	mlx_key_hook(gb->mlx, hook, gb);
	mlx_loop(gb->mlx);
	mlx_terminate(gb->mlx);
	return (0);
}
