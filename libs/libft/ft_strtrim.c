/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 16:09:02 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/18 09:36:29 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkchar(char c, char const *set)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (check);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;

	ptr = 0;
	start = 0;
	if (!s1)
		return (NULL);
	if (!set || *set == '\0' || *s1 == '\0')
		return (ft_strdup(s1));
	end = ft_strlen(s1);
	while (ft_checkchar((char) s1[start], set) == 1 && s1)
		start++;
	while (ft_checkchar((char) s1[end - 1], set) == 1)
		end--;
	ptr = ft_substr(s1, start, end - start);
	return (ptr);
}

// Parameters 
// 		s1: The string to be trimmed.
// 		set: The reference set of characters to trim.
// Return value 
// 		The trimmed string.
// 		NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a copy of ’s1’ with 
// the characters specified in ’set’ removed
// from the beginning and the end of the string.