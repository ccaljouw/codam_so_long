/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 15:53:49 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/20 22:25:14 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_coord(t_map *map, t_pos *pos)
{
	//moet hier gb nog beschikbaar zijn voor free?
	if (!ft_strchr("0CPE1", map->arr[pos->y][pos->x]))
		error(FT_INVMAPCH, NULL);
	if (map->arr[pos->y][pos->x] == '1')
		return (0);
	if (map->arr[pos->y][pos->x] == 'C')
		map->coll_count += 1;
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
			error(FT_MEMFAIL, NULL);
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
	
	if (!frontier)
		return ;
	pos = frontier->content;
	check_neighbor(map, &reached, &frontier, pos->x + 1, pos->y);
	check_neighbor(map, &reached, &frontier, pos->x - 1, pos->y);
	check_neighbor(map, &reached, &frontier, pos->x, pos->y + 1);
	check_neighbor(map, &reached, &frontier, pos->x, pos->y - 1);
	frontier = frontier->next;
	bfs(map, frontier, reached);
}

int	check_map(t_gameboard *gb, int x, int y)
{
	t_list	*frontier;
	t_list	*reached;
	t_pos	*pos;

	pos = malloc(sizeof(pos));
	if (!pos)
		error(FT_MEMFAIL, gb);
	pos->x = x;
	pos->y = y;
	frontier = NULL;
	reached = NULL;
	ft_lstadd_back(&reached, ft_lstnew(pos));
	ft_lstadd_back(&frontier,ft_lstnew(pos));
	bfs(gb->map, frontier, reached);
	ft_lstclear(&reached, delete_content);
	ft_lstclear(&frontier, delete_list_pointer);
	return (1);
}