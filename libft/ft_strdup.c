/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 13:41:13 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/20 11:34:41 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1) + 1;
	ptr = ft_calloc(len, sizeof(char));
	if (ptr == 0)
		return (NULL);
	while (len-- > 0)
		ptr[len] = s1[len];
	return (ptr);
}

// NAME
//      strdup, strndup -- save a copy of a string

// LIBRARY
//      Standard C Library (libc, -lc)

// SYNOPSIS
//      #include <string.h>
//      char *strdup(const char *s1);
//      char *strndup(const char *s1, size_t n);

// DESCRIPTION
//      The strdup() function allocates sufficient memory for a copy of the 
// 		string s1, does the copy, and returns a pointer to it.  The pointer
//      may subsequently be used as an argument to the function free(3).
//      If insufficient memory is available, NULL is returned and errno is 
// 		set to ENOMEM. The strndup() function copies at most n characters from 
// 		the string s1 always NUL terminating the copied string.

// SEE ALSO
//      free(3), malloc(3)