/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 09:27:50 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/18 14:31:28 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = dst_len;
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	while (src[i] && (dst_len + i) < (dstsize - 1))
		dst[j++] = src[i++];
	dst[j++] = '\0';
	return (dst_len + src_len);
}

// NAME
//      strlcpy, strlcat -- size-bounded string copying and concatenation

// LIBRARY
//      Standard C Library (libc, -lc)

// SYNOPSIS (prototyes use char * restrict but not allowed for libft)
//      #include <string.h>
// size_t	strlcpy(char * dst, const char * src, size_t dstsize);
// size_t	strlcat(char * dst, const char * src, size_t dstsize);

// DESCRIPTION
//      The strlcpy() and strlcat() functions copy and concatenate strings with 
// 		the same input parameters and output result as snprintf(3).
//      They are designed to be safer, more consistent, and less error prone 
// 		replacements for the easily misused functions strncpy(3) and
//      strncat(3).

//      strlcpy() and strlcat() take the full size of the destination buffer 
// 		and guarantee NUL-termination if there is room.  Note that room
//      for the NUL should be included in dstsize.

//      strlcpy() copies up to dstsize - 1 characters from the string src to 
// 		dst, NUL-terminating the result if dstsize is not 0.

//      strlcat() appends string src to the end of dst.  It will append at most 
// 		dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, 
// 		unless dstsize is 0 or the original dst string was longer than dstsize 
// 		(in practice this should not happen as it means that
//      either dstsize is incorrect or that dst is not a proper string).

//      If the src and dst strings overlap, the behavior is undefined.

// RETURN VALUES
//      Besides quibbles over the return type (size_t versus int) and signal 
// 		handler safety (snprintf(3) is not entirely safe on some systems),
//      the following two are equivalent:

//            n = strlcpy(dst, src, len);
//            n = snprintf(dst, len, "%s", src);

//      Like snprintf(3), the strlcpy() and strlcat() functions return the total
// 		length of the string they tried to create.  For strlcpy() that
//      means the length of src.  For strlcat() that means the initial length 
// 		of dst plus the length of src.

//      If the return value is >= dstsize, the output string has been truncated.
// 		It is the caller's responsibility to handle this.

// EXAMPLES
//      The following code fragment illustrates the simple case:

//            char *s, *p, buf[BUFSIZ];

//            ...

//            (void)strlcpy(buf, s, sizeof(buf));
//            (void)strlcat(buf, p, sizeof(buf));

//      To detect truncation, perhaps while building a pathname, something like 
// 		the following might be used:

//            char *dir, *file, pname[MAXPATHLEN];