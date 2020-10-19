/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_lem_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkuusist <jkuusist@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 10:53:00 by jkuusist          #+#    #+#             */
/*   Updated: 2020/09/17 10:53:00 by jkuusist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	destroy_maps(t_map *map)
{
//	ft_printf("got to start of destroy_maps. map is %p\n", map);

	t_map *next;

//	ft_printf("in destroy_map. current line is: %s\n", map->line);

	next = map->next;
	if (map->line)
		free(map->line);

//	ft_printf("1111 map is %p\n", map);

	free(map);

//	ft_printf("2222\n");

	if (next)
		destroy_maps(next);
}

static void	destroy_rooms(t_room *room)
{
//	ft_printf("got to start of destroy_rooms. room is %p\n", room);

	t_room *next;

	next = room->next;
	free(room->name);
	free(room);
	if (next)
		destroy_rooms(next);
}

static void	destroy_links(t_link *link)
{
//	ft_printf("got to start of destroy_links. link is %p\n", link);

	t_link *next;

	next = link->next;
	free(link);
	if (next)
		destroy_links(next);
}

void	destroy_lem_in(t_lem_in *lem_in)
{
//	ft_printf("got to start of destroy\n");

	destroy_maps(lem_in->map_start);
	destroy_rooms(lem_in->room);
	destroy_links(lem_in->link);
	free(lem_in);

//	ft_printf("got to end of destroy\n");
}
