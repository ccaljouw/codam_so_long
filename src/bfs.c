/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 15:53:49 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/19 17:09:27 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_coord(t_map *map, t_pos *pos)
{
	if (!ft_strchr("0CPE1", map->arr[pos->y][pos->x]))
		ft_printf("invallid map\n"); //handle with error message
	if (map->arr[pos->y][pos->x] == '1')
		return (0);
	if (map->arr[pos->y][pos->x] == 'C')
	{
		map->coll_count += 1;
		ft_printf("coll at %d, %d\n", pos->x, pos->y);
	}
	if (map->arr[pos->y][pos->x] == 'P')
		map->start_count += 1;
	if (map->arr[pos->y][pos->x] == 'E')
		map->exit_count += 1;
	return (1);
}

int	check_set(t_map *map, t_list *set, int x, int y)
{
	t_pos	*pos;
	t_list	*list;

	list = set;
	if (x > map->map_width - 1 || y > map->map_height -1 \
		|| x < 0 || y < 0)
		ft_printf("invallid map");
	while (list)
	{
		pos = list->content;
		if (x == pos->x && y == pos->y)
			return (1);
		list = list->next;
	}
	return (0);
}

void	check_neighbor(t_map *map, t_list **reached, t_list **frontier, int x, int y)
{
	t_pos	*pos;
	if (!check_set(map, *reached, x, y))
	{
		pos = malloc(sizeof(t_pos));
		if (!pos)
			ft_printf("malloc fail");
		pos->x = x;
		pos->y = y;
		ft_lstadd_back(reached, ft_lstnew(pos));
		if (check_coord(map, pos))
			ft_lstadd_back(frontier, ft_lstnew(pos));
	}
}

void	bfs(t_map *map, t_list *frontier, t_list *reached)
{
	t_pos	*pos;
	
	if (!map || !frontier)
		return ;
	pos = frontier->content;
	frontier = frontier->next;
	check_neighbor(map, &reached, &frontier, pos->x + 1, pos->y);
	check_neighbor(map, &reached, &frontier, pos->x - 1, pos->y);
	check_neighbor(map, &reached, &frontier, pos->x, pos->y + 1);
	check_neighbor(map, &reached, &frontier, pos->x, pos->y - 1);
	bfs(map, frontier, reached);
}

int	check_map(t_gameboard *gb, int x, int y)
{
	t_list	*frontier;
	t_list	*reached;
	t_pos	*pos;

	pos = (t_pos *)malloc(sizeof(pos));
	pos->x = x;
	pos->y = y;
	frontier = NULL;
	reached = NULL;
	ft_lstadd_back(&reached, ft_lstnew(pos));
	ft_lstadd_back(&frontier, ft_lstnew(pos));
	bfs(gb->map, frontier, reached);
	ft_printf("p: %d, c: %d, e: %d\n", gb->map->start_count, gb->map->coll_count, gb->map->exit_count);
	return (1);
}