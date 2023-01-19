/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:45:41 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/19 16:39:50 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	check_map_pos(t_gameboard *gb, int map_x, int map_y)
{
	if (gb->map->arr[map_y][map_x] == '1')
		return (0);
	if (gb->map->arr[map_y][map_x] == 'C')
		get_collectable(gb, map_x, map_y);
	if (gb->map->arr[map_y][map_x] == 'E' && gb->coll == 0)
	{
		gb->imgs->pl->enabled = 0;
		//create image that the game has ended
	}
	if (gb->imgs->pl->enabled == 1)
		gb->moves += 1;
	set_movescore(gb->moves, gb);
	return (1);
}


void	render_map(t_gameboard *gb, int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = x * gb->text->empty->width;
	y_pos = y * gb->text->empty->height;
	mlx_draw_texture(gb->imgs->background, gb->text->empty, x_pos, y_pos);
	if (gb->map->arr[y][x] == '1')
		mlx_draw_texture(gb->imgs->wall, gb->text->wall, x_pos, y_pos);
	else if (gb->map->arr[y][x] == 'C')
	{
		mlx_image_to_window(gb->mlx, gb->imgs->coll, x_pos, y_pos);
		//change patrol hook
		mlx_image_to_window(gb->mlx, gb->imgs->patrol, x_pos, y_pos);
	}
	else if (gb->map->arr[y][x] == 'P')
	{
		check_map(gb, x, y);
		mlx_image_to_window(gb->mlx, gb->imgs->pl, x_pos, y_pos);
		gb->player->x_pos = x_pos;
		gb->player->y_pos = y_pos;
	}
	else if (gb->map->arr[y][x] == 'E')
		mlx_image_to_window(gb->mlx, gb->imgs->exit, x_pos, y_pos);
	else if (gb->map->arr[y][x] != '0')
		ft_printf("Invallid map");
}

char	*read_file(char *line, char *file)
{
	char	buffer[BUFFER_SIZE + 1];
	int		fd;
	ssize_t	count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			if (line)
				free(line);
			return (NULL);
		}
		if (count == 0)
			return (line);
		buffer[count] = '\0';
		line = ft_strjoin_free_s1(line, buffer);
		if (!line || !*buffer)
			return (NULL);
	}
	close(fd);
	return (line);
}

t_map	*init_map(char *file)
{
	t_map	*map;
	char	*line;
	int		i;
	int		j;

	//check map is rectangular here?
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
	map->coll_count = 0;
	map->start_count = 1;
	map->exit_count = 0;
	return (map);
}
