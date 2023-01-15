/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 13:17:48 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/14 10:09:53 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;	

	if ((!s1 && !s2) || n == 0)
		return (0);
	cs1 = (unsigned char *) s1;
	cs2 = (unsigned char *) s2;
	i = 0;
	while (i < n - 1 && cs1[i] == cs2[i])
		i++;
	return (cs1[i] - cs2[i]);
}

// NAME
//      memcmp -- compare byte string

// LIBRARY
//      Standard C Library (libc, -lc)

// SYNOPSIS
//      #include <string.h>
//      int	memcmp(const void *s1, const void *s2, size_t n);

// DESCRIPTION
//      The memcmp() function compares byte string s1 against byte string s2.
// 		Both strings are assumed to be n bytes long.

// RETURN VALUES
//      The memcmp() function returns zero if the two strings are identical, 
// 		otherwise returns the difference between the first two differing
//      bytes (treated as unsigned char values, so that `\200' is greater than 
// 		`\0', for example).  Zero-length strings are always identical.
//      This behavior is not required by C and portable code should only depend
// 		on the sign of the returned value.