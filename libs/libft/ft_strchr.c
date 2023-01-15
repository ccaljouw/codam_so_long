/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 11:11:03 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/17 10:47:58 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ichar;
	char	*cs;

	ichar = (char) c;
	cs = (char *) s;
	while (*cs != '\0' && *cs != ichar)
		cs++;
	if (*cs != ichar)
		return (NULL);
	return (cs);
}

// NAME
//      strchr, strrchr -- locate character in string

// LIBRARY
//      Standard C Library (libc, -lc)

// SYNOPSIS
//      #include <string.h>
//      char *strchr(const char *s, int c);
//      char *strrchr(const char *s, int c);

// DESCRIPTION
//      The strchr() function locates the first occurrence of c (converted to a 
// 		char) in the string pointed to by s.  The terminating null character 
// 		is considered to be part of the string; therefore if c is `\0', the 
// 		functions locate the terminating `\0'.

//      The strrchr() function is identical to strchr(), except it locates the
// 		last occurrence of c.

// RETURN VALUES
//      The functions strchr() and strrchr() return a pointer to the located 
// 		character, or NULL if the character does not appear in the string.

// SEE ALSO
//      memchr(3), memmem(3), strcspn(3), strpbrk(3), strsep(3), strspn(3),
// 		strstr(3), strtok(3), wcschr(3)