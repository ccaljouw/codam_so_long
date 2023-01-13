/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/12 14:24:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/13 09:19:16 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include <stdlib.h>

char	*get_remaining_buf(char *str, char **remaining_buf)
{
	ssize_t	i;
	ssize_t	len;

	i = 0;
	if (str)
	{
		len = ft_strlen(str);
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n' && str[i + 1] != '\0')
		{
			i++;
			*remaining_buf = malloc(((len - i) + 1) * sizeof(char));
			if (!*remaining_buf)
			{
				str = NULL;
				return (NULL);
			}
			ft_strlcpy(*remaining_buf, str + i, (len - i) + 1);
			str[i] = '\0';
		}
	}
	return (str);
}

char	*read_fd(int fd, char *line, char **remaining_buf)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	count;

	while (!*remaining_buf)
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
		get_remaining_buf(buffer, remaining_buf);
		if (*buffer)
			line = ft_strjoin_free_s1(line, buffer);
		if (!line || !*buffer)
			return (NULL);
		if (buffer[count - 1] == '\n')
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*remaining_buf;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = remaining_buf;
	if (line)
		remaining_buf = NULL;
	get_remaining_buf(line, &remaining_buf);
	if (line && line[ft_strlen(line) - 1] == '\n')
		return (line);
	line = read_fd(fd, line, &remaining_buf);
	if (!line)
	{
		if (remaining_buf)
			free(remaining_buf);
		remaining_buf = NULL;
	}
	return (line);
}
