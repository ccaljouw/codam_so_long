/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:45:41 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/24 16:28:22 by ccaljouw      ########   odam.nl         */
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
	if (gb->imgs->pl->enabled == 1)
		gb->moves += 1;
	if (gb->moves > 999)
		end_game(gb, 3);
	set_movescore(gb->moves, gb);
	return (1);
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

	line = NULL;
	gb->map = malloc(sizeof(t_map));
	gb->map->arr = NULL;
	if (!gb->map)
		error(FT_MEMFAIL, gb);
	gb->map->coll_count = 0;
	gb->map->start_count = 1;
	gb->map->exit_count = 0;
	gb->map->map_width = 0;
	gb->map->map_height = 0;
	line = read_file(line, file);
	if (!line)
		error(FT_INVFILE, gb);
	gb->map->arr = ft_split(line, '\n');
	if (!gb->map->arr)
		error(FT_MEMFAIL, gb);
	check_rectangle(gb);
	free(line);
}