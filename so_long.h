/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:12:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/13 16:17:32 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE 1
# endif

int parse_map(char *file);

#endif