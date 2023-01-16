/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:05:38 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/17 00:13:28 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

t_textures *init_textures(void)
{
	t_textures	*text;

	text = malloc(sizeof(t_textures));
	if (!text)
		return (NULL);						//handle with error message
	text->empty = mlx_load_png("./images/background.png");
	text->wall = mlx_load_png("./images/wall.png");
	text->pl = mlx_load_png("./images/flashman64.png");
	text->pll = mlx_load_png("./images/flashman64.png");
	text->plr = mlx_load_png("./images/flashman64r.png");
	if (!text->empty || !text->wall || !text->pll || !text->plr)
		ft_printf("error loading textures");
	return (text);
}

t_map *init_map(char *file)
{
	t_map	*map;
	char	*line;
	int		i;
	int		j;
	
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);												//handle with error message and exit
	line = NULL;
	i = 0;
	j = 0;
	line = read_file(line, file);
	if (!line)
		return (NULL);
	map->arr = ft_split(line, '\n');
	while (map->arr[j][i])
		i++;
	map->map_width = i;		
	while (map->arr[j])
		j++;
	map->map_height = j;
	check_map(map->arr);
	return (map);
}

t_player	*init_player()
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->x_pos = 0;
	player->x_pos = 0;
	return (player);
}

t_gameboard	*init_gameboard(t_textures *text, t_map *map, t_player *pl)
{	
	t_gameboard	*gb;
	int	title_h;

	title_h = 64;
	gb = malloc(sizeof(t_gameboard));
	if (!gb)
		return (NULL);											//handle with error message and exit
	gb->player = pl;
	gb->text = text;
	gb->map	= map;
	gb->moves = 0;
	gb->mlx = mlx_init(gb->map->map_width * text->empty->width, (gb->map->map_height * text->empty->height) + title_h, "So long!\t\t\tmoves: 0", false);
	if (!gb->mlx)
		exit(EXIT_FAILURE);											//handle with error message and exit
	return (gb);
}

void	init_images(mlx_t *mlx, t_textures *text, t_map *map, t_gameboard *gb)   // herschrijven
{
	t_images	*imgs;
	
	imgs = malloc(sizeof(t_images));
	if (!imgs)
		ft_printf("error initiating ims"); 													//handle with error message and exit
	imgs->coll = mlx_texture_to_image(mlx, mlx_load_png("./images/coll64.png"));
	imgs->exit = mlx_texture_to_image(mlx, mlx_load_png("./images/exit64.png"));
	imgs->pl = mlx_texture_to_image(mlx, text->pl);
	imgs->wall = mlx_new_image(mlx, map->map_width * text->empty->width, map-> map_height * text->empty->height); 
	imgs->background = mlx_new_image(mlx, map->map_width * text->empty->width, map-> map_height * text->empty->height);
	if (!imgs->background || !imgs->wall || !imgs->pl || !imgs->coll || !imgs->exit)
		ft_printf("error loading images");
	gb->imgs = imgs;
}

int main(int argc, char **argv)
{	
	t_textures	*text;
	t_map		*map;
	t_player	*player;
	t_gameboard *gb;
	
	if (!check_input(argc, argv))
		return (ft_printf("incorrect arguments"));
	text = init_textures();
	map = init_map(argv[1]);
	player = init_player();
	gb = init_gameboard(text, map, player);
	init_images(gb->mlx, gb->text, gb->map, gb);
	init_window(gb);
	mlx_key_hook(gb->mlx, hook, gb);
	mlx_loop(gb->mlx);
	mlx_terminate(gb->mlx);
	return (0);
}
