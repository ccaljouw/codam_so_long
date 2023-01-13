/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 15:45:41 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/13 10:05:41 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <fcntl.h>

char	*read_file(char *line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		fd;
	ssize_t	count;

	fd = open("./maps/simple.ber", O_RDONLY);
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
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (arr[j])
	{
		if (j == 0 || arr[j + 1] == NULL)
			{
				ft_printf("%s\n", arr[j]);
			}
		while (arr[j][i])
		{
			if (i == 0 || arr[j][i + 1] == '\0')
				ft_printf("%c\n", arr[j][i]);
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}

void parse_map(void)
{
	char *line;
	char **arr;
	
	line = NULL;
	line = read_file(line);
	arr = ft_split(line, '\n');
	check_map(arr);
}