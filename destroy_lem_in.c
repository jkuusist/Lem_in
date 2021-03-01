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

static void destroy_ants(t_ant* ant)
{
	t_ant *next;

	next = ant->next;
	free(ant);
	if (next)
		destroy_ants(next);
}

static void	destroy_maps(t_map *map)
{
	t_map *next;

	next = map->next;
	if (map->line)
		free(map->line);

	free(map);

	if (next)
		destroy_maps(next);
}

static void	destroy_rooms(t_room *room)
{
	t_room			*next;
	t_connection	*temp;

	next = room->next;
	free(room->name);

	while (room->connection)
	{
		temp = room->connection;
		room->connection = (room->connection)->next;
		if (temp)
			free(temp);
	}
	free(room);
	if (next)
		destroy_rooms(next);
}


static void	destroy_links(t_link *link)
{
	t_link *next;

	next = link->next;
	free(link);
	if (next)
		destroy_links(next);
}

void	destroy_lem_in(t_lem_in *lem_in)
{
	destroy_ants(lem_in->ant);
	destroy_maps(lem_in->map_start);
	destroy_rooms(lem_in->room);
	destroy_links(lem_in->link);
	if (lem_in->paths)
		free_path_array(lem_in->paths);
	free(lem_in);
}
