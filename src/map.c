/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:45:41 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/24 14:19:21 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	check_coord(t_gameboard *gb, t_pos *pos)
{
	if (!ft_strchr("0CPE1", gb->map->arr[pos->y][pos->x]))
		error(FT_INVMAPCH, gb);
	if (gb->map->arr[pos->y][pos->x] == '1')
		return (0);
	if (gb->map->arr[pos->y][pos->x] == 'C')
		gb->map->coll_count += 1;
	if (gb->map->arr[pos->y][pos->x] == 'P')
		gb->map->start_count += 1;
	if (gb->map->arr[pos->y][pos->x] == 'E')
		gb->map->exit_count += 1;
	return (1);
}

int	check_map_pos(t_gameboard *gb, int map_x, int map_y)
{
	if (gb->map->arr[map_y][map_x] == '1')
		return (0);
	if (gb->map->arr[map_y][map_x] == 'C')
		get_collectable(gb, map_x, map_y);
	if (gb->map->arr[map_y][map_x] == 'E' && gb->coll == 0)
		end_game(gb, 1);
	// change this
	if (gb->map->arr[map_y][map_x] == 'X')
		hit_patrol(gb);
	if (gb->imgs->pl->enabled == 1)
		gb->moves += 1;
	if (gb->moves > 999)
		end_game(gb, 3);
	set_movescore(gb->moves, gb);
	return (1);
}

void	render_map(t_gameboard *gb, int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = x * SIZE;
	y_pos = y * SIZE;
	mlx_draw_texture(gb->imgs->background, gb->text->empty, x_pos, y_pos);
	if (gb->map->arr[y][x] == '1')
		mlx_draw_texture(gb->imgs->wall, gb->text->wall, x_pos, y_pos);
	else if (gb->map->arr[y][x] == 'C')
		mlx_image_to_window(gb->mlx, gb->imgs->coll, x_pos, y_pos);
	else if (gb->map->arr[y][x] == 'P')
	{
		check_map(gb, x, y);
		mlx_image_to_window(gb->mlx, gb->imgs->pl, x_pos, y_pos);
		gb->player->x_pos = x_pos;
		gb->player->y_pos = y_pos;
	}
	else if (gb->map->arr[y][x] == 'E')
		mlx_image_to_window(gb->mlx, gb->imgs->exit, x_pos, y_pos);
	else if (gb->map->arr[y][x] == 'X')
		mlx_image_to_window(gb->mlx, gb->imgs->patrol, x_pos, y_pos);
	else if (gb->map->arr[y][x] != '0')
		error(FT_INVMAPCH, gb);
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
	}
	close(fd);
	return (line);
}

void	init_map(char *file, t_gameboard *gb)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = NULL;
	gb->map = malloc(sizeof(t_map));
	gb->map->arr = NULL;
	if (!gb->map)
		error(FT_MEMFAIL, gb);
	line = read_file(line, file);
	if (!line)
		error(FT_INVFILE, gb);
	gb->map->arr = ft_split(line, '\n');
	if (!gb->map->arr)
		error(FT_MEMFAIL, gb);
	// move these?
	while (gb->map->arr[j][i])
		i++;
	gb->map->map_width = i;
	while (gb->map->arr[j])
		j++;
	gb->map->map_height = j;
	gb->map->coll_count = 0;
	gb->map->start_count = 1;
	gb->map->exit_count = 0;
	free(line);
}
