/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 21:27:06 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/20 11:35:43 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// Parameters       c: The character to output.
//                  fd: The file descriptor on which to write.
// Return value     None
// External functs. write
// 
// Description Outputs the character ’c’ to the given file descriptor.
