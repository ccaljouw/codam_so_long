/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 21:30:21 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/20 11:36:05 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

// Parameters       s: The string to output.
//                  fd: The file descriptor on which to write.
// Return value     None
// External functs. write
// 
// Description Outputs the string ’s’ to the given file descriptor
// followed by a newline.