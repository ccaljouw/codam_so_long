/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 10:42:42 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/14 10:53:33 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (0);
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (i < n - 1 && us1[i] == us2[i] && us1[i] != '\0')
		i++;
	return (us1[i] - us2[i]);
}

// NAME
//      strcmp, strncmp -- compare strings

// LIBRARY
//      Standard C Library (libc, -lc)

// SYNOPSIS
//      #include <string.h>

//      int	strcmp(const char *s1, const char *s2);

//      int	strncmp(const char *s1, const char *s2, size_t n);

// DESCRIPTION
//      The strcmp() and strncmp() functions lexicographically compare the 
// 		null-terminated strings s1 and s2.

//      The strncmp() function compares not more than n characters.  Because 
// 		strncmp() is designed for comparing strings rather than binary
//      data, characters that appear after a `\0' character are not compared.

// RETURN VALUES
//      The strcmp() and strncmp() functions return an integer greater than,
// 		equal to, or less than 0, according as the string s1 is greater
//      than, equal to, or less than the string s2.  The comparison is done 
// 		using unsigned characters, so that `\200' is greater than `\0'.

// SEE ALSO
//      bcmp(3), memcmp(3), strcasecmp(3), strcoll(3), strxfrm(3), wcscmp(3)
