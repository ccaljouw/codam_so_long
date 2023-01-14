/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:45:41 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/14 21:55:01 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

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
	return (line);
}

int	check_map(char **arr)
{
	if (arr)
		return (1);
	else
		return (0);
}

int parse_map(char *file, t_gameboard *gb)
{
	char	*line;
	int		i;
	int		j;
	
	line = NULL;
	i = 0;
	j = 0;
	line = read_file(line, file);
	if (!line)
		return (-1);
	gb->map = ft_split(line, '\n');
	while (gb->map[j][i])
		i++;
	gb->map_width = i;		
	while (gb->map[j])
		j++;
	gb->map_height = j;
	return (check_map(gb->map));
}

void	render_map(t_gameboard *gb, int x, int y, int count)
{
	mlx_image_to_window(gb->mlx, gb->imgs->empty, x * 64, y * 64);
	gb->imgs->empty->instances[count].z = 0;
	// count++;
	if (gb->map[y][x] == '1')
		mlx_image_to_window(gb->mlx, gb->imgs->wall, x * 64, y * 64);
	if (gb->map[y][x] == 'C')
	{
		mlx_image_to_window(gb->mlx, gb->imgs->coll, x * 64, y * 64);
		gb->collectables += 1;
	}
	if (gb->map[y][x] == 'P')
	{
		mlx_image_to_window(gb->mlx, gb->imgs->pl, x * 64, y * 64);
		mlx_image_to_window(gb->mlx, gb->imgs->plr, x * 64, y * 64);
	}
	if (gb->map[y][x] == 'E')
	{
		gb->exit[0] = x;
		gb->exit[1] = y;
		mlx_image_to_window(gb->mlx, gb->imgs->exit, x * 64, y * 64);
	}
}
