/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:23:37 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/14 10:09:45 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ichar;
	unsigned char	*cs;
	size_t			i;

	if (n == 0)
		return (NULL);
	ichar = (unsigned char) c;
	cs = (unsigned char *) s;
	i = 0;
	while (cs[i] != ichar && i < n - 1)
		i++;
	if (cs[i] != ichar)
		return (NULL);
	return (cs + i);
}

// NAME
//      memchr -- locate byte in byte string
// LIBRARY
//      Standard C Library (libc, -lc)
// SYNOPSIS
//      #include <string.h>
//      void	*memchr(const void *s, int c, size_t n);
// DESCRIPTION
//      The memchr() function locates the first occurrence of c (converted to 
// 		an unsigned char) in string s.
// RETURN VALUES
//      The memchr() function returns a pointer to the byte located, or NULL if 
// 		no such byte exists within n bytes.