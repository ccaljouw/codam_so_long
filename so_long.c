/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:05:38 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/11 16:28:03 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "MLX42.h"
#include "so_long.h"

int main()
{
	char *line;
	char **arr;
	
	line = NULL;
	line = read_file(line);
	ft_printf("%s\n", line);
	arr = ft_split(line, '\n');
	while (*arr)
	{
		ft_printf("%s", *arr);
		arr++;
	}
	return (0);
}